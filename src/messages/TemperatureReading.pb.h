/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.1 at Sat Sep 22 20:28:34 2018. */

#ifndef PB_TEMPERATUREREADING_PB_H_INCLUDED
#define PB_TEMPERATUREREADING_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _TemperatureReading {
    float temp;
    uint64_t timestamp_ms;
/* @@protoc_insertion_point(struct:TemperatureReading) */
} TemperatureReading;

/* Default values for struct fields */
extern const float TemperatureReading_temp_default;
extern const uint64_t TemperatureReading_timestamp_ms_default;

/* Initializer values for message structs */
#define TemperatureReading_init_default          {-9999, 0ull}
#define TemperatureReading_init_zero             {0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define TemperatureReading_temp_tag              1
#define TemperatureReading_timestamp_ms_tag      2

/* Struct field encoding specification for nanopb */
extern const pb_field_t TemperatureReading_fields[3];

/* Maximum encoded size of messages (where known) */
#define TemperatureReading_size                  14

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define TEMPERATUREREADING_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
