// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from cooperative_localization:msg/Measurement.idl
// generated code does not contain a copyright notice

#include "cooperative_localization/msg/detail/measurement__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_cooperative_localization
const rosidl_type_hash_t *
cooperative_localization__msg__Measurement__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x22, 0xd0, 0x68, 0xbe, 0xa3, 0x8a, 0xb0, 0xbe,
      0x47, 0x7c, 0xb4, 0xfb, 0x4c, 0x33, 0x12, 0x45,
      0xa2, 0xcd, 0xde, 0x27, 0x54, 0x23, 0xa9, 0x2b,
      0xe1, 0x60, 0x38, 0xcd, 0xb7, 0x74, 0x2f, 0xb4,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
#endif

static char cooperative_localization__msg__Measurement__TYPE_NAME[] = "cooperative_localization/msg/Measurement";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";

// Define type names, field names, and default values
static char cooperative_localization__msg__Measurement__FIELD_NAME__stamp[] = "stamp";
static char cooperative_localization__msg__Measurement__FIELD_NAME__observer_id[] = "observer_id";
static char cooperative_localization__msg__Measurement__FIELD_NAME__subject_id[] = "subject_id";
static char cooperative_localization__msg__Measurement__FIELD_NAME__range[] = "range";
static char cooperative_localization__msg__Measurement__FIELD_NAME__bearing[] = "bearing";

static rosidl_runtime_c__type_description__Field cooperative_localization__msg__Measurement__FIELDS[] = {
  {
    {cooperative_localization__msg__Measurement__FIELD_NAME__stamp, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
  {
    {cooperative_localization__msg__Measurement__FIELD_NAME__observer_id, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {cooperative_localization__msg__Measurement__FIELD_NAME__subject_id, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {cooperative_localization__msg__Measurement__FIELD_NAME__range, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {cooperative_localization__msg__Measurement__FIELD_NAME__bearing, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription cooperative_localization__msg__Measurement__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
cooperative_localization__msg__Measurement__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {cooperative_localization__msg__Measurement__TYPE_NAME, 40, 40},
      {cooperative_localization__msg__Measurement__FIELDS, 5, 5},
    },
    {cooperative_localization__msg__Measurement__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "builtin_interfaces/Time stamp\n"
  "int32 observer_id\n"
  "int32 subject_id\n"
  "float64 range\n"
  "float64 bearing";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
cooperative_localization__msg__Measurement__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {cooperative_localization__msg__Measurement__TYPE_NAME, 40, 40},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 95, 95},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
cooperative_localization__msg__Measurement__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *cooperative_localization__msg__Measurement__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
