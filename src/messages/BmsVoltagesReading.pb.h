/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.1 at Wed Sep 26 22:30:44 2018. */

#ifndef PB_BMSVOLTAGESREADING_PB_H_INCLUDED
#define PB_BMSVOLTAGESREADING_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _BmsVoltagesReading {
    double battery_voltage;
    double system_voltage;
    double input_voltage;
    uint64_t timestamp_ms;
/* @@protoc_insertion_point(struct:BmsVoltagesReading) */
} BmsVoltagesReading;

/* Default values for struct fields */
extern const double BmsVoltagesReading_battery_voltage_default;
extern const double BmsVoltagesReading_system_voltage_default;
extern const double BmsVoltagesReading_input_voltage_default;
extern const uint64_t BmsVoltagesReading_timestamp_ms_default;

/* Initializer values for message structs */
#define BmsVoltagesReading_init_default          {-9999, -9999, -9999, 0ull}
#define BmsVoltagesReading_init_zero             {0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define BmsVoltagesReading_battery_voltage_tag   1
#define BmsVoltagesReading_system_voltage_tag    2
#define BmsVoltagesReading_input_voltage_tag     3
#define BmsVoltagesReading_timestamp_ms_tag      4

/* Struct field encoding specification for nanopb */
extern const pb_field_t BmsVoltagesReading_fields[5];

/* Maximum encoded size of messages (where known) */
#define BmsVoltagesReading_size                  36

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define BMSVOLTAGESREADING_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif