/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.1 at Sun Sep 09 23:35:47 2018. */

#ifndef PB_MAGNETOMETERREADING_PB_H_INCLUDED
#define PB_MAGNETOMETERREADING_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _MagnetometerReading {
    double x;
    double y;
    double z;
    uint64_t timestamp_millis_unix_epoch;
/* @@protoc_insertion_point(struct:MagnetometerReading) */
} MagnetometerReading;

/* Default values for struct fields */
extern const double MagnetometerReading_x_default;
extern const double MagnetometerReading_y_default;
extern const double MagnetometerReading_z_default;
extern const uint64_t MagnetometerReading_timestamp_millis_unix_epoch_default;

/* Initializer values for message structs */
#define MagnetometerReading_init_default         {-9999, -9999, -9999, 0ull}
#define MagnetometerReading_init_zero            {0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define MagnetometerReading_x_tag                1
#define MagnetometerReading_y_tag                2
#define MagnetometerReading_z_tag                3
#define MagnetometerReading_timestamp_millis_unix_epoch_tag 4

/* Struct field encoding specification for nanopb */
extern const pb_field_t MagnetometerReading_fields[5];

/* Maximum encoded size of messages (where known) */
#define MagnetometerReading_size                 36

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define MAGNETOMETERREADING_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
