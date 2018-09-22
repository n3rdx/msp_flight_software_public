#include <src/sensors/test_sensors/test_i2c_measurable.h>
#include <src/system/sensor_state_machines/battery_charge_state_machine.h>

BatteryChargeStateMachine::BatteryChargeStateMachine(
    StateManager* state_manager)
    : SensorStateMachine<TestI2cMeasurable>(state_manager, kBatteryChargeLow) {}

void BatteryChargeStateMachine::Update() {
    TestI2cMeasurable* sensor_with_reading = GetSensorWithReading();
    if (sensor_with_reading != NULL) {
        UpdateState(sensor_with_reading->GetReading().dummy_data);
    }
}

void BatteryChargeStateMachine::UpdateState(double soc) {
    switch (GetCurrentState()) {
        case kBatteryChargeCriticalLow:
            if (soc > kTwoEclipseCapacity + kHysteresis) {
                SetStateAndNotify(kBatteryChargeLow);
            }
            break;
        case kBatteryChargeLow:
            if (soc < kTwoEclipseCapacity) {
                SetStateAndNotify(kBatteryChargeCriticalLow);
            } else if (soc > kThreePassCapacity + kHysteresis) {
                SetStateAndNotify(kBatteryChargeNominal);
            }
            break;
        case kBatteryChargeNominal:
            if (soc < kThreePassCapacity) {
                SetStateAndNotify(kBatteryChargeLow);
            }
            break;
    }
}
