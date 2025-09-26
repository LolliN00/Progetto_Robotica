// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cooperative_localization:msg/Measurement.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cooperative_localization/msg/measurement.h"


#ifndef COOPERATIVE_LOCALIZATION__MSG__DETAIL__MEASUREMENT__STRUCT_H_
#define COOPERATIVE_LOCALIZATION__MSG__DETAIL__MEASUREMENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/Measurement in the package cooperative_localization.
typedef struct cooperative_localization__msg__Measurement
{
  builtin_interfaces__msg__Time stamp;
  int32_t observer_id;
  int32_t subject_id;
  double range;
  double bearing;
} cooperative_localization__msg__Measurement;

// Struct for a sequence of cooperative_localization__msg__Measurement.
typedef struct cooperative_localization__msg__Measurement__Sequence
{
  cooperative_localization__msg__Measurement * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cooperative_localization__msg__Measurement__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COOPERATIVE_LOCALIZATION__MSG__DETAIL__MEASUREMENT__STRUCT_H_
