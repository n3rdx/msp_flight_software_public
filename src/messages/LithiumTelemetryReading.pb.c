/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.9.1 at Tue Nov 27 19:57:18 2018. */

#include "LithiumTelemetryReading.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

const uint32_t LithiumTelemetryReading_op_counter_default = 0u;
const uint32_t LithiumTelemetryReading_msp430_temp_default = 0u;
const LithiumTelemetryReading_time_count_t LithiumTelemetryReading_time_count_default = {0, {0}};
const uint32_t LithiumTelemetryReading_rssi_default = 0u;
const uint32_t LithiumTelemetryReading_bytes_received_default = 0u;
const uint32_t LithiumTelemetryReading_bytes_transmitted_default = 0u;
const uint64_t LithiumTelemetryReading_timestamp_ms_default = 0ull;


const pb_field_t LithiumTelemetryReading_fields[8] = {
    PB_FIELD(  1, FIXED32 , REQUIRED, STATIC  , FIRST, LithiumTelemetryReading, op_counter, op_counter, &LithiumTelemetryReading_op_counter_default),
    PB_FIELD(  2, FIXED32 , REQUIRED, STATIC  , OTHER, LithiumTelemetryReading, msp430_temp, op_counter, &LithiumTelemetryReading_msp430_temp_default),
    PB_FIELD(  3, BYTES   , REQUIRED, STATIC  , OTHER, LithiumTelemetryReading, time_count, msp430_temp, &LithiumTelemetryReading_time_count_default),
    PB_FIELD(  4, FIXED32 , REQUIRED, STATIC  , OTHER, LithiumTelemetryReading, rssi, time_count, &LithiumTelemetryReading_rssi_default),
    PB_FIELD(  5, FIXED32 , REQUIRED, STATIC  , OTHER, LithiumTelemetryReading, bytes_received, rssi, &LithiumTelemetryReading_bytes_received_default),
    PB_FIELD(  6, FIXED32 , REQUIRED, STATIC  , OTHER, LithiumTelemetryReading, bytes_transmitted, bytes_received, &LithiumTelemetryReading_bytes_transmitted_default),
    PB_FIELD(  7, FIXED64 , REQUIRED, STATIC  , OTHER, LithiumTelemetryReading, timestamp_ms, bytes_transmitted, &LithiumTelemetryReading_timestamp_ms_default),
    PB_LAST_FIELD
};


/* @@protoc_insertion_point(eof) */
