// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cooperative_localization:msg/DatasetStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cooperative_localization/msg/dataset_status.h"


#ifndef COOPERATIVE_LOCALIZATION__MSG__DETAIL__DATASET_STATUS__STRUCT_H_
#define COOPERATIVE_LOCALIZATION__MSG__DETAIL__DATASET_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/DatasetStatus in the package cooperative_localization.
typedef struct cooperative_localization__msg__DatasetStatus
{
  int32_t robot_id;
  bool finished;
} cooperative_localization__msg__DatasetStatus;

// Struct for a sequence of cooperative_localization__msg__DatasetStatus.
typedef struct cooperative_localization__msg__DatasetStatus__Sequence
{
  cooperative_localization__msg__DatasetStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cooperative_localization__msg__DatasetStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COOPERATIVE_LOCALIZATION__MSG__DETAIL__DATASET_STATUS__STRUCT_H_
