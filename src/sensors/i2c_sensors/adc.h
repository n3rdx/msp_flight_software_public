#ifndef SRC_SENSORS_I2C_SENSORS_ADC_H_
#define SRC_SENSORS_I2C_SENSORS_ADC_H_

#include <external/etl/array.h>
#include <src/board/i2c/i2c.h>
#include <src/sensors/i2c_sensors/i2c_device.h>
#include <src/util/data_types.h>

enum AdcOperationalStatus { kAdcNoConversion = 0, kAdcConversion = 1 };

enum AdcDataRate {
    kAdc8Sps = 0b000,
    kAdc16Sps = 0b001,
    kAdc32Sps = 0b010,
    kAdc64Sps = 0b011,
    kAdc128Sps = 0b100,
    kAdc250Sps = 0b101,
    kAdc475Sps = 0b110,
    kAdc860Sps = 0b111
};

enum AdcGainAmplifierLevel {
    kAdc6v144 = 0b000,
    kAdc4v096 = 0b001,
    kAdc2v048 = 0b010,
    kAdc1v024 = 0b011,
    kAdc0v512 = 0b100,
    kAdc0v256 = 0b101,
};

enum AdcOperatingMode { kAdcContinuousConversion = 0, kAdcSingleShot = 1 };

enum AdcComparatorMode {
    kAdcTraditionalComparator = 0,
    kAdcWindowComparator = 1
};

enum AdcComparatorPolarity { kAdcActiveLow = 0, kAdcActiveHigh = 1 };

enum AdcLatchingComparatorMode { kAdcNonLatching = 0, kAdcLatching = 1 };

enum AdcComparatorQueueMode {
    kAdcAssertOneConversion = 0b00,
    kAdcAssertTwoConversions = 0b01,
    kAdcAssertFourConversions = 0b10,
    kAdcDisableComparatorAlertHiZ = 0b11
};

enum AdcMuxMode {
    kAdcP0N1 = 0b000,
    kAdcP0N3 = 0b001,
    kAdcP1N3 = 0b010,
    kAdcP2N3 = 0b011,
    kAdcP0NGnd = 0b100,
    kAdcP1NGnd = 0b101,
    kAdcP2NGnd = 0b110,
    kAdcP3NGnd = 0b111
};

class Adc : public I2cDevice {
   public:
    Adc(const I2c* bus, int address, const I2cMultiplexer* multiplexer = NULL,
        I2cMultiplexer::MuxChannel channel = I2cMultiplexer::kMuxNoChannel);

    bool ReadConversionRegister(etl::array<byte, 2>& read_buffer);
    bool ReadConfigurationRegister(etl::array<byte, 2>& read_buffer);
    bool ReadLoThreshRegister(etl::array<byte, 2>& read_buffer);
    bool ReadHiThreshRegister(etl::array<byte, 2>& read_buffer);

    double TakeI2cReading();

    // Getter and setter methods.
    AdcOperationalStatus GetOperationalStatus() const;
    bool SetOperationalStatus(AdcOperationalStatus operational_status);
    AdcMuxMode GetMuxMode() const;
    bool SetMuxMode(AdcMuxMode mux_mode);
    AdcGainAmplifierLevel GetGainAmplifierLevel() const;
    bool SetGainAmplifierLevel(AdcGainAmplifierLevel gain_amplifier);
    AdcOperatingMode GetOperatingMode() const;
    bool SetOperatingMode(AdcOperatingMode operating_mode);
    AdcDataRate GetDataRate() const;
    bool SetDataRate(AdcDataRate data_rate);
    AdcComparatorMode GetComparatorMode() const;
    bool SetComparatorMode(AdcComparatorMode comparator_mode);
    AdcComparatorPolarity GetComparatorPolarity() const;
    bool SetComparatorPolarity(AdcComparatorPolarity comparator_polarity);
    AdcLatchingComparatorMode GetLatchingComparatorMode() const;
    bool SetLatchingComparatorMode(
        AdcLatchingComparatorMode latching_comparator);
    AdcComparatorQueueMode GetComparatorQueue() const;
    bool SetComparatorQueue(AdcComparatorQueueMode comparator_queue);

    double GetAdcGainAmplifierFullScaleRange() const;
    bool SetAdcGainAmplifierFullScaleRange();

   private:
    static constexpr uint8_t kAdcNumInputs = 4;
    static constexpr uint8_t kAdcRegisterNumBits = 16;

    // Default values for initialisation on startup
    static constexpr AdcOperationalStatus kAdcDefaultOperationalStatus =
        kAdcNoConversion;
    static constexpr AdcMuxMode kAdcDefaultMuxMode = kAdcP0NGnd;
    static constexpr AdcGainAmplifierLevel kAdcDefaultGainAmplifierLevel =
        kAdc2v048;
    static constexpr AdcOperatingMode kAdcDefaultOperatingMode = kAdcSingleShot;
    static constexpr AdcDataRate kAdcDefaultDataRate = kAdc860Sps;
    static constexpr AdcComparatorMode kAdcDefaultComparatorMode =
        kAdcTraditionalComparator;
    static constexpr AdcComparatorPolarity kAdcDefaultComparatorPolarity =
        kAdcActiveLow;
    static constexpr AdcLatchingComparatorMode kAdcDefaultLatchingComparator =
        kAdcNonLatching;
    static constexpr AdcComparatorQueueMode kAdcDefaultComparatorQueue =
        kAdcDisableComparatorAlertHiZ;

    // Amounts to shift bits to store states in the configuration register.
    static constexpr uint8_t kAdcOperationalStatusBitShift = 7;
    static constexpr uint8_t kAdcInputStateBitShift = 4;
    static constexpr uint8_t kAdcGainAmplifierBitShift = 1;
    static constexpr uint8_t kAdcOperatingModeBitShift = 0;
    static constexpr uint8_t kAdcDataRateBitShift = 7;
    static constexpr uint8_t kAdcComparatorModeBitShift = 4;
    static constexpr uint8_t kAdcComparatorPolarityBitShift = 3;
    static constexpr uint8_t kAdcLatchingComparatorBitShift = 2;
    static constexpr uint8_t kAdcComparatorQueueBitShift = 0;

    // Full scale voltage ranges of the gain amplifier
    static constexpr double kAdcVoltage6v144 = 6.144;
    static constexpr double kAdcVoltage4v096 = 4.096;
    static constexpr double kAdcVoltage2v048 = 2.048;
    static constexpr double kAdcVoltage1v024 = 1.024;
    static constexpr double kAdcVoltage0v512 = 0.512;
    static constexpr double kAdcVoltage0v256 = 0.256;

    static const double AdcGainAmplifierFullScaleRangeVoltages[6];

    // Locations of internal ADC registers
    static constexpr byte kAdcConversionRegisterLocation = 0x00;
    static constexpr byte kAdcConfigurationRegisterLocation = 0x01;
    static constexpr byte kAdcLoThreshRegisterLocation = 0x02;
    static constexpr byte kAdcHiThreshRegisterLocation = 0x03;

    // States of the configuration variables on the ADC
    AdcOperationalStatus operational_status;
    AdcMuxMode mux_mode;
    AdcGainAmplifierLevel gain_amplifier_level;
    AdcOperatingMode operating_mode;
    AdcDataRate data_rate;
    AdcComparatorMode comparator_mode;
    AdcComparatorPolarity comparator_polarity;
    AdcLatchingComparatorMode latching_comparator;
    AdcComparatorQueueMode comparator_queue;

    double gain_amplifier_full_scale_range;

    bool ReadFromCurrentRegister(etl::array<byte, 2>& read_buffer);
    void SelectRegister(byte register_address_pointer);
    double ConvertReadingToVoltage(etl::array<byte, 2>& read_buffer);
    bool SetConfiguration();
};

#endif  // SRC_SENSORS_I2C_SENSORS_ADC_H_
