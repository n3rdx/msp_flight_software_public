# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: MagnetometerReading.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='MagnetometerReading.proto',
  package='',
  syntax='proto2',
  serialized_pb=_b('\n\x19MagnetometerReading.proto\"d\n\x13MagnetometerReading\x12\x10\n\x01x\x18\x01 \x02(\x01:\x05-9999\x12\x10\n\x01y\x18\x02 \x02(\x01:\x05-9999\x12\x10\n\x01z\x18\x03 \x02(\x01:\x05-9999\x12\x17\n\x0ctimestamp_ms\x18\x04 \x02(\x06:\x01\x30')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_MAGNETOMETERREADING = _descriptor.Descriptor(
  name='MagnetometerReading',
  full_name='MagnetometerReading',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='x', full_name='MagnetometerReading.x', index=0,
      number=1, type=1, cpp_type=5, label=2,
      has_default_value=True, default_value=float(-9999),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='y', full_name='MagnetometerReading.y', index=1,
      number=2, type=1, cpp_type=5, label=2,
      has_default_value=True, default_value=float(-9999),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='z', full_name='MagnetometerReading.z', index=2,
      number=3, type=1, cpp_type=5, label=2,
      has_default_value=True, default_value=float(-9999),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='timestamp_ms', full_name='MagnetometerReading.timestamp_ms', index=3,
      number=4, type=6, cpp_type=4, label=2,
      has_default_value=True, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=29,
  serialized_end=129,
)

DESCRIPTOR.message_types_by_name['MagnetometerReading'] = _MAGNETOMETERREADING

MagnetometerReading = _reflection.GeneratedProtocolMessageType('MagnetometerReading', (_message.Message,), dict(
  DESCRIPTOR = _MAGNETOMETERREADING,
  __module__ = 'MagnetometerReading_pb2'
  # @@protoc_insertion_point(class_scope:MagnetometerReading)
  ))
_sym_db.RegisterMessage(MagnetometerReading)


# @@protoc_insertion_point(module_scope)
