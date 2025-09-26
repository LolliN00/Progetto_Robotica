// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from cooperative_localization:msg/DatasetStatus.idl
// generated code does not contain a copyright notice

#include "cooperative_localization/msg/detail/dataset_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_cooperative_localization
const rosidl_type_hash_t *
cooperative_localization__msg__DatasetStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x84, 0x4e, 0xe0, 0x7c, 0x9f, 0x2d, 0xca, 0x03,
      0x81, 0x0e, 0xc5, 0x94, 0x7a, 0xaa, 0x9a, 0x2d,
      0x3b, 0x57, 0x46, 0x77, 0x38, 0x1b, 0xff, 0x5f,
      0x85, 0xdb, 0x3f, 0x43, 0x42, 0xa1, 0x3c, 0x08,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char cooperative_localization__msg__DatasetStatus__TYPE_NAME[] = "cooperative_localization/msg/DatasetStatus";

// Define type names, field names, and default values
static char cooperative_localization__msg__DatasetStatus__FIELD_NAME__robot_id[] = "robot_id";
static char cooperative_localization__msg__DatasetStatus__FIELD_NAME__finished[] = "finished";

static rosidl_runtime_c__type_description__Field cooperative_localization__msg__DatasetStatus__FIELDS[] = {
  {
    {cooperative_localization__msg__DatasetStatus__FIELD_NAME__robot_id, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {cooperative_localization__msg__DatasetStatus__FIELD_NAME__finished, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
cooperative_localization__msg__DatasetStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {cooperative_localization__msg__DatasetStatus__TYPE_NAME, 42, 42},
      {cooperative_localization__msg__DatasetStatus__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 robot_id\n"
  "bool finished";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
cooperative_localization__msg__DatasetStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {cooperative_localization__msg__DatasetStatus__TYPE_NAME, 42, 42},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 28, 28},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
cooperative_localization__msg__DatasetStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *cooperative_localization__msg__DatasetStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
