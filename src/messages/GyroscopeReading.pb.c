/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.9.1 at Sun Sep 09 23:54:44 2018. */

#include "GyroscopeReading.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

const float GyroscopeReading_x_default = -9999;
const float GyroscopeReading_y_default = -9999;
const float GyroscopeReading_z_default = -9999;
const uint64_t GyroscopeReading_timestamp_millis_unix_epoch_default = 0ull;


const pb_field_t GyroscopeReading_fields[5] = {
    PB_FIELD(  1, FLOAT   , REQUIRED, STATIC  , FIRST, GyroscopeReading, x, x, &GyroscopeReading_x_default),
    PB_FIELD(  2, FLOAT   , REQUIRED, STATIC  , OTHER, GyroscopeReading, y, x, &GyroscopeReading_y_default),
    PB_FIELD(  3, FLOAT   , REQUIRED, STATIC  , OTHER, GyroscopeReading, z, y, &GyroscopeReading_z_default),
    PB_FIELD(  4, FIXED64 , REQUIRED, STATIC  , OTHER, GyroscopeReading, timestamp_millis_unix_epoch, z, &GyroscopeReading_timestamp_millis_unix_epoch_default),
    PB_LAST_FIELD
};


/* @@protoc_insertion_point(eof) */
