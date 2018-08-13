/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.1 at Mon Aug 13 19:46:19 2018. */

#ifndef PB_BMSREADINGS_PB_H_INCLUDED
#define PB_BMSREADINGS_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _BmsReadings {
    double battery_voltage;
    double battery_current;
    double system_voltage;
    double input_voltage;
    double input_current;
    double die_temperature;
    double battery_temperature;
    uint32_t jeita_region;
    uint32_t system_status;
    uint32_t charger_state;
    uint32_t charge_indicator;
    double recharge_threshold;
    uint32_t charger_config;
    uint32_t c_x_threshold;
    uint32_t v_charge_setting;
    uint32_t i_charge_target;
    uint32_t configuration;
    uint32_t q_count;
    uint32_t q_count_scale_factor;
    bool telemetry_valid;
/* @@protoc_insertion_point(struct:BmsReadings) */
} BmsReadings;

/* Default values for struct fields */

/* Initializer values for message structs */
#define BmsReadings_init_default                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define BmsReadings_init_zero                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define BmsReadings_battery_voltage_tag          1
#define BmsReadings_battery_current_tag          2
#define BmsReadings_system_voltage_tag           3
#define BmsReadings_input_voltage_tag            4
#define BmsReadings_input_current_tag            5
#define BmsReadings_die_temperature_tag          6
#define BmsReadings_battery_temperature_tag      7
#define BmsReadings_jeita_region_tag             8
#define BmsReadings_system_status_tag            9
#define BmsReadings_charger_state_tag            10
#define BmsReadings_charge_indicator_tag         11
#define BmsReadings_recharge_threshold_tag       12
#define BmsReadings_charger_config_tag           13
#define BmsReadings_c_x_threshold_tag            14
#define BmsReadings_v_charge_setting_tag         15
#define BmsReadings_i_charge_target_tag          16
#define BmsReadings_configuration_tag            17
#define BmsReadings_q_count_tag                  18
#define BmsReadings_q_count_scale_factor_tag     19
#define BmsReadings_telemetry_valid_tag          20

/* Struct field encoding specification for nanopb */
extern const pb_field_t BmsReadings_fields[21];

/* Maximum encoded size of messages (where known) */
#define BmsReadings_size                         145

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define BMSREADINGS_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
