/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.1 at Tue Oct 30 15:35:55 2018. */

#ifndef PB_ENABLEDATALOGGERUPLINKPAYLOAD_PB_H_INCLUDED
#define PB_ENABLEDATALOGGERUPLINKPAYLOAD_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _EnableDataloggerUplinkPayload {
    bool datalogger_enabled;
/* @@protoc_insertion_point(struct:EnableDataloggerUplinkPayload) */
} EnableDataloggerUplinkPayload;

/* Default values for struct fields */
extern const bool EnableDataloggerUplinkPayload_datalogger_enabled_default;

/* Initializer values for message structs */
#define EnableDataloggerUplinkPayload_init_default {true}
#define EnableDataloggerUplinkPayload_init_zero  {0}

/* Field tags (for use in manual encoding/decoding) */
#define EnableDataloggerUplinkPayload_datalogger_enabled_tag 1

/* Struct field encoding specification for nanopb */
extern const pb_field_t EnableDataloggerUplinkPayload_fields[2];

/* Maximum encoded size of messages (where known) */
#define EnableDataloggerUplinkPayload_size       2

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define ENABLEDATALOGGERUPLINKPAYLOAD_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
