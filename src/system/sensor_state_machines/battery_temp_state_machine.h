#ifndef SRC_SYSTEM_SENSOR_STATE_MACHINES_BATTERY_TEMP_STATE_MACHINE_H_
#define SRC_SYSTEM_SENSOR_STATE_MACHINES_BATTERY_TEMP_STATE_MACHINE_H_

#include <src/system/sensor_state_machine.h>

class TestI2cSensor;

// TODO(wschuetz) Set correct type for sensor state machine when known
// Changes required at forward declaration, constructor, Update() and
// .cpp include
class BatteryTempStateMachine : public SensorStateMachine<TestI2cSensor> {
   public:
    explicit BatteryTempStateMachine(StateManager* state_manager);
    void Update();

   private:
    void UpdateState(double temp);

    static const uint8_t kTempBatteryOperationalLow = 5;
    static const uint8_t kTempBatteryOperationalHigh = 40;
    static const uint8_t kHysteresis = 1;
};

#endif  //  SRC_SYSTEM_SENSOR_STATE_MACHINES_BATTERY_TEMP_STATE_MACHINE_H_