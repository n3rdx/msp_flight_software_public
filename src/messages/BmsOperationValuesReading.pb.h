/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.1 at Wed Sep 26 21:59:31 2018. */

#ifndef PB_BMSOPERATIONVALUESREADING_PB_H_INCLUDED
#define PB_BMSOPERATIONVALUESREADING_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _BmsOperationValuesReading {
    double recharge_threshold;
    uint32_t c_over_x_threshold;
    int32_t q_count_prescale_factor;
    uint64_t timestamp_ms;
/* @@protoc_insertion_point(struct:BmsOperationValuesReading) */
} BmsOperationValuesReading;

/* Default values for struct fields */
extern const double BmsOperationValuesReading_recharge_threshold_default;
extern const uint32_t BmsOperationValuesReading_c_over_x_threshold_default;
extern const int32_t BmsOperationValuesReading_q_count_prescale_factor_default;
extern const uint64_t BmsOperationValuesReading_timestamp_ms_default;

/* Initializer values for message structs */
#define BmsOperationValuesReading_init_default   {-9999, 9999u, -9999, 0ull}
#define BmsOperationValuesReading_init_zero      {0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define BmsOperationValuesReading_recharge_threshold_tag 1
#define BmsOperationValuesReading_c_over_x_threshold_tag 2
#define BmsOperationValuesReading_q_count_prescale_factor_tag 3
#define BmsOperationValuesReading_timestamp_ms_tag 4

/* Struct field encoding specification for nanopb */
extern const pb_field_t BmsOperationValuesReading_fields[5];

/* Maximum encoded size of messages (where known) */
#define BmsOperationValuesReading_size           35

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define BMSOPERATIONVALUESREADING_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
