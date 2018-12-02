#include <src/board/board.h>
#include <src/board/i2c/i2c.h>
#include <src/board/i2c/multiplexers/i2c_multiplexer.h>
#include <src/config/satellite.h>
#include <src/sensors/i2c_sensors/rtc.h>
#include <src/util/msp_exception.h>
#include <src/util/runnable_time_source.h>
#include <src/util/satellite_time_source.h>
#include <src/util/task_utils.h>
#include <xdc/runtime/Log.h>

fnptr RunnableTimeSource::GetRunnablePointer() {
    return &RunnableTimeSource::UpdateSatelliteTime;
}

void RunnableTimeSource::UpdateSatelliteTime() {
    I2c bus(I2C_BUS_A);
    I2cMultiplexer multiplexer(&bus, kMuxAddress);
    Rtc rtc(&bus, kRtcAddress, &multiplexer, I2cMultiplexer::kMuxChannel0);
    while (1) {
        try {
            RTime time;
            try {
                time = rtc.GetTime();
            } catch (MspException& e) {
                MspException::LogException(e, kUpdateSatelliteTimeCatch);
                Log_error0("Unable to retrieve time from RTC");
                TaskUtils::SleepMilli(kTimeUpdatePeriodMs);
                continue;
            }

            if (rtc.ValidTime(time)) {
                SatelliteTimeSource::SetTime(time);
            }

            TaskUtils::SleepMilli(kTimeUpdatePeriodMs);
        } catch (MspException& e) {
            // TODO(crozone): Hack for dealing with strange (aka fucked, maybe
            // compiler bug) try catch behaviour. The below code should really
            // have already run in the above try catch.
            MspException::LogException(e, kUpdateSatelliteTimeCatch);
            Log_error0("Unable to retrieve time from RTC");
            TaskUtils::SleepMilli(kTimeUpdatePeriodMs);
            continue;

            // TODO(crozone): Correct code which shouldn't be needed:
            // MspException::LogTopLevelException(e, kRunnableTimeSourceCatch);
        }
    }
}
