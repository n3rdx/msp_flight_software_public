/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.1 at Wed Aug 29 13:18:57 2018. */

#ifndef PB_SYSTEMRESETCOMMAND_PB_H_INCLUDED
#define PB_SYSTEMRESETCOMMAND_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _SystemResetCommand {
    uint32_t reset_enable;
/* @@protoc_insertion_point(struct:SystemResetCommand) */
} SystemResetCommand;

/* Default values for struct fields */

/* Initializer values for message structs */
#define SystemResetCommand_init_default          {0}
#define SystemResetCommand_init_zero             {0}

/* Field tags (for use in manual encoding/decoding) */
#define SystemResetCommand_reset_enable_tag      1

/* Struct field encoding specification for nanopb */
extern const pb_field_t SystemResetCommand_fields[2];

/* Maximum encoded size of messages (where known) */
#define SystemResetCommand_size                  5

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define SYSTEMRESETCOMMAND_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
