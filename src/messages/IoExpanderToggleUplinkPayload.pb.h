/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.1 at Tue Oct 30 15:36:11 2018. */

#ifndef PB_IOEXPANDERTOGGLEUPLINKPAYLOAD_PB_H_INCLUDED
#define PB_IOEXPANDERTOGGLEUPLINKPAYLOAD_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _IoExpanderToggleUplinkPayload {
    uint32_t io_expander_id;
    uint32_t pin;
    uint32_t toggle_type;
    uint32_t toggle_duration;
/* @@protoc_insertion_point(struct:IoExpanderToggleUplinkPayload) */
} IoExpanderToggleUplinkPayload;

/* Default values for struct fields */
extern const uint32_t IoExpanderToggleUplinkPayload_io_expander_id_default;
extern const uint32_t IoExpanderToggleUplinkPayload_pin_default;
extern const uint32_t IoExpanderToggleUplinkPayload_toggle_type_default;
extern const uint32_t IoExpanderToggleUplinkPayload_toggle_duration_default;

/* Initializer values for message structs */
#define IoExpanderToggleUplinkPayload_init_default {0u, 0u, 0u, 0u}
#define IoExpanderToggleUplinkPayload_init_zero  {0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define IoExpanderToggleUplinkPayload_io_expander_id_tag 1
#define IoExpanderToggleUplinkPayload_pin_tag    2
#define IoExpanderToggleUplinkPayload_toggle_type_tag 3
#define IoExpanderToggleUplinkPayload_toggle_duration_tag 4

/* Struct field encoding specification for nanopb */
extern const pb_field_t IoExpanderToggleUplinkPayload_fields[5];

/* Maximum encoded size of messages (where known) */
#define IoExpanderToggleUplinkPayload_size       24

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define IOEXPANDERTOGGLEUPLINKPAYLOAD_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif