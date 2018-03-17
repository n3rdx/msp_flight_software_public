/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.9 at Fri Mar 23 00:43:39 2018. */

#include "MagnetometerReading.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t MagnetometerReading_fields[5] = {
    PB_FIELD(  1, DOUBLE  , REQUIRED, STATIC  , FIRST, MagnetometerReading, x, x, 0),
    PB_FIELD(  2, DOUBLE  , REQUIRED, STATIC  , OTHER, MagnetometerReading, y, x, 0),
    PB_FIELD(  3, DOUBLE  , REQUIRED, STATIC  , OTHER, MagnetometerReading, z, y, 0),
    PB_FIELD(  4, FIXED64 , REQUIRED, STATIC  , OTHER, MagnetometerReading, timestamp_millis_unix_epoch, z, 0),
    PB_LAST_FIELD
};


/* On some platforms (such as AVR), double is really float.
 * These are not directly supported by nanopb, but see example_avr_double.
 * To get rid of this error, remove any double fields from your .proto.
 */
PB_STATIC_ASSERT(sizeof(double) == 8, DOUBLE_MUST_BE_8_BYTES)

/* @@protoc_insertion_point(eof) */
