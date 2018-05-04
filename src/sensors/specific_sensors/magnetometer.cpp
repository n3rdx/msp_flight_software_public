#include <Board.h>
#include <external/etl/exception.h>
#include <external/nanopb/pb_decode.h>
#include <external/nanopb/pb_encode.h>
#include <src/adcs/controllers/b_dot_controller.h>
#include <src/adcs/state_estimators/b_dot_estimator.h>
#include <src/config/unit_tests.h>
#include <src/data_dashboard/runnable_data_dashboard.h>
#include <src/debug_interface/debug_stream.h>
#include <src/messages/MagnetometerReading.pb.h>
#include <src/messages/TorqueOutputReading.pb.h>
#include <src/sensors/generic_measurable.h>
#include <src/sensors/specific_sensors/magnetometer.h>
#include <src/util/message_codes.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <xdc/runtime/Log.h>

MPU9250MotionTracker *Magnetometer::imu_a;
I2cMultiplexer *Magnetometer::multiplexer_a;

const char Magnetometer::kCalibrationReadingsBufferAFileName[] = "magcal_a.pb";
// const char Magnetometer::kCalibrationReadingsBufferBFileName[] =
// "magcal_b.pb";

Magnetometer::Magnetometer(I2c *bus_a) {
    // Direct bus access to be replaced with I2cMeasureableManager
  multiplexer_a = new I2cMultiplexer(bus_a, 0x76);
    // imu_b(new I2c(I2C_BUS_B), kImuAddress, "imu_b") {
  multiplexer_a->OpenChannel(I2cMultiplexer::kMuxChannel1);
  imu_a = new MPU9250MotionTracker(bus_a, kImuAddress, "imu_a");
  multiplexer_a->CloseAllChannels();

  //I2c test_i2c_bus(I2C_BUS_A);

  //I2cMultiplexer multiplexer(&test_i2c_bus, 0x76);
  //multiplexer.OpenChannel(I2cMultiplexer::kMuxChannel1);

  //MPU9250MotionTracker test_imu(&test_i2c_bus, kImuAddress, "blah");

  //MagnetometerReading magnetometer_reading;
  //test_imu.TakeMagnetometerReading(magnetometer_reading);
  //multiplexer.CloseAllChannels();

    CircularBufferNanopb(MagnetometerReading)::Create(
        kCalibrationReadingsBufferAFileName, kCalibrationReadingsBufferSize);
    // CircularBufferNanopb(MagnetometerReading)::Create(kCalibrationReadingsBufferBFileName,
    //                               kCalibrationReadingsBufferSize);
};

// Get readings from the hardware magnetometer and the simulation.
// Use the simulation readings for the controller, but echo the hardware
// readings to the DebugClient to show that it's working.
//////////////////////////////////////////////////
// For hardware tests, make sure to store the hardware readings
// for calibration.
// For HIL tests, store the simulation readings for calibration.
bool Magnetometer::TakeReading() {
    MagnetometerReading magnetometer_a_reading;
    //    MagnetometerReading magnetometer_b_reading;
    try {
        multiplexer_a->OpenChannel(I2cMultiplexer::kMuxChannel1);
        imu_a->TakeMagnetometerReading(magnetometer_a_reading);
        multiplexer_a->CloseAllChannels();

        //Log_warning3("\nRaw magnetometer reading 'a', x: %f, y: %f, z: %f",
        //             floatToArg(magnetometer_a_reading.x),
        //             floatToArg(magnetometer_a_reading.y),
        //             floatToArg(magnetometer_a_reading.z));

    } catch (etl::exception e) {
        magnetometer_a_reading.x = 0;
        magnetometer_a_reading.y = 0;
        magnetometer_a_reading.z = 0;
    }

    RunnableDataDashboard::TransmitMessage(
        kMagnetometerReadingCode, MagnetometerReading_size,
        MagnetometerReading_fields, &magnetometer_a_reading);
    // try {
    //    imu_b.TakeMagnetometerReading(magnetometer_b_reading);
    //    Log_info3("Raw magnetometer reading 'a', x: %d, y: %d, z: %d",
    //              magnetometer_b_reading.x, magnetometer_b_reading.y,
    //              magnetometer_b_reading.z);
    //} catch (etl::exception e) {
    //    magnetometer_b_reading.x = 0;
    //    magnetometer_b_reading.y = 0;
    //    magnetometer_b_reading.z = 0;
    //}

    ///////////////////////// calibration stuff

    try {
        CircularBufferNanopb(MagnetometerReading)::WriteMessage(
            kCalibrationReadingsBufferAFileName, magnetometer_a_reading);
        // CircularBufferNanopb(MagnetometerReading)::WriteMessage(kCalibrationReadingsBufferBFileName,
        // magnetometer_b_reading);
    } catch (etl::exception &e) {
        // TODO (rskew) catch exceptions for pb encode error, sdcard write
        // error,
        throw e;
    }


    magnetometer_calibration_a.Apply(magnetometer_a_reading);
    RunnableDataDashboard::TransmitMessage(
        kCalibratedMagnetometerReadingCode, MagnetometerReading_size,
        MagnetometerReading_fields, &magnetometer_a_reading);

    //Log_warning3("\nCalibrated magnetometer reading 'a', x: %f, y: %f, z: %f",
    //             floatToArg(magnetometer_a_reading.x),
    //             floatToArg(magnetometer_a_reading.y),
    //             floatToArg(magnetometer_a_reading.z));
    // magnetometer_calibration_b.Apply(magnetometer_b_reading);
    // Log_info3("Calibrated magnetometer reading 'b', x: %d, y: %d, z: %d",
    //          magnetometer_b_reading.x, magnetometer_b_reading.y,
    //          magnetometer_b_reading.z);

    // Average readings from IMUs
    // reading.x = (magnetometer_a_reading.x + magnetometer_b_reading.x) / 2;
    // reading.y = (magnetometer_a_reading.y + magnetometer_b_reading.y) / 2;
    // reading.z = (magnetometer_a_reading.z + magnetometer_b_reading.z) / 2;
    reading.x = magnetometer_a_reading.x;
    reading.y = magnetometer_a_reading.y;
    reading.z = magnetometer_a_reading.z;

    // TODO (rskew) combine noise from hardware readings with simulated readings

    // HIL reading is returned for hardware tests so that controller can
    // activate magnetorquers in response to simulated tumbling
    bool success;
    if (hil_enabled) {
      // This is slow for some reason!!!
      //success = TakeReadingHil();
    }

    return success;
}

bool Magnetometer::TakeReadingHil() {
    DebugStream *debug_stream = DebugStream::GetInstance();
    uint8_t buffer[MagnetometerReading_size];

    bool success = debug_stream->RequestMessageFromSimulator(
        kMagnetometerReadingRequestCode, buffer, MagnetometerReading_size);
    if (success) {
        pb_istream_t stream =
            pb_istream_from_buffer(buffer, MagnetometerReading_size);

        bool status = pb_decode(&stream, MagnetometerReading_fields, &reading);
        if (!status) {
            etl::exception e("pb_decode failed", __FILE__, __LINE__);
            throw e;
        }

        NotifyObservers();
    }

    return success;
}

bool Magnetometer::Calibrate() {
    for (uint32_t i = 0; i < kCalibrationReadingsBufferSize /
                                 MagnetometerCalibration::kBatchSize;
         i++) {
        // read data from circular buffer
        MagnetometerReading
            magnetometer_readings_batch_a[MagnetometerCalibration::kBatchSize];
        //MagnetometerReading
        //    magnetometer_readings_batch_b[MagnetometerCalibration::kBatchSize];
        for (uint8_t j = 0; j < MagnetometerCalibration::kBatchSize; j++) {
            try {
                magnetometer_readings_batch_a[j] =
                    CircularBufferNanopb(MagnetometerReading)::ReadMessage(
                        kCalibrationReadingsBufferAFileName);
                //magnetometer_readings_batch_b[j] =
                //    CircularBufferNanopb(MagnetometerReading)::ReadMessage(
                //        kCalibrationReadingsBufferBFileName);
            } catch (etl::exception e) {
                // TODO (rskew) if the Hamming decoding fails, discard the
                // message and read another one.
                // TODO (rskew) handle reaching the end of buffer early.
                // If the buffer runs out before reading ~150 messages,
                // calibration could be pretty bad, so return failure. > ~150
                // and the calibration is mayeb ok?
                throw e;
            }
        }
        // compute aggregated data in magnetometer calibration
        double magnetometer_readings_batch_matrix_a_data
          [MagnetometerCalibration::kBatchSize][3];
//        double magnetometer_readings_batch_matrix_b_data
//            [10][MagnetometerCalibration::kBatchSize];
        Matrix magnetometer_readings_batch_matrix_a(
            magnetometer_readings_batch_matrix_a_data);
        for (uint16_t i=0; i<MagnetometerCalibration::kBatchSize; i++) {
            magnetometer_readings_batch_matrix_a.Set(i,0, magnetometer_readings_batch_a[i].x);
            magnetometer_readings_batch_matrix_a.Set(i,1, magnetometer_readings_batch_a[i].y);
            magnetometer_readings_batch_matrix_a.Set(i,2, magnetometer_readings_batch_a[i].z);
        }
//        Matrix magnetometer_readings_batch_matrix_b(
//            magnetometer_readings_batch_matrix_b_data);
        magnetometer_calibration_a.AggregateReadings(
            magnetometer_readings_batch_matrix_a);
//        magnetometer_calibration_b.AggregateReadings(
//            magnetometer_readings_batch_matrix_b);
    }
    // compute calibration
    magnetometer_calibration_a.ComputeCalibrationParameters();
//    magnetometer_calibration_b.ComputeCalibrationParameters();

    return true;
}
