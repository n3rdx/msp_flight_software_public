/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.1 at Sat Sep 22 20:28:34 2018. */

#ifndef PB_ACCELEROMETERREADING_PB_H_INCLUDED
#define PB_ACCELEROMETERREADING_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _AccelerometerReading {
    float x;
    float y;
    float z;
    uint64_t timestamp_ms;
/* @@protoc_insertion_point(struct:AccelerometerReading) */
} AccelerometerReading;

/* Default values for struct fields */
extern const float AccelerometerReading_x_default;
extern const float AccelerometerReading_y_default;
extern const float AccelerometerReading_z_default;
extern const uint64_t AccelerometerReading_timestamp_ms_default;

/* Initializer values for message structs */
#define AccelerometerReading_init_default        {-9999, -9999, -9999, 0ull}
#define AccelerometerReading_init_zero           {0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define AccelerometerReading_x_tag               1
#define AccelerometerReading_y_tag               2
#define AccelerometerReading_z_tag               3
#define AccelerometerReading_timestamp_ms_tag    4

/* Struct field encoding specification for nanopb */
extern const pb_field_t AccelerometerReading_fields[5];

/* Maximum encoded size of messages (where known) */
#define AccelerometerReading_size                24

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define ACCELEROMETERREADING_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
