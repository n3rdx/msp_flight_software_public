#include <src/config/unit_tests.h>
#include <src/sensors/specific_sensors/test_i2c_sensor.h>
#include <src/system/sensor_state_machines/battery_charge_state_machine.h>
#include <src/system/sensor_state_machines/battery_temp_state_machine.h>
#include <src/system/state_definitions.h>
#include <src/system/state_manager.h>
#include <src/system/system_state_machines/power_state_machine.h>
#include <test_runners/sensor_state_logic_tests.h>
#include <test_runners/unity.h>
#include <string>

void TestStateManager(void) {
    StateManager* state_manager = StateManager::GetStateManager();
    BatteryChargeStateMachine battery_charge_sm(state_manager);
    BatteryTempStateMachine battery_temp_sm(state_manager);
    PowerStateMachine power_sm(state_manager, &battery_charge_sm,
                               &battery_temp_sm);
    state_manager->AddSystemStateMachine(&power_sm);

    TestI2cSensor battery_charge_sensor("soc_sensor");
    battery_charge_sm.RegisterWithSensor(&battery_charge_sensor);

    // A reading of SOC = 0 should put power state machine into state
    // kPowerEverythingOff
    battery_charge_sensor.SetDummySensorData(0);
    battery_charge_sensor.TakeReading();

    state_manager->ProcessStateChanges();

    TEST_ASSERT_EQUAL_INT(kPowerEverythingOff, power_sm.GetCurrentState());

    state_manager->RemoveLastSystemStateMachine();
}