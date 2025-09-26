// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from cooperative_localization:msg/DatasetStatus.idl
// generated code does not contain a copyright notice
#ifndef COOPERATIVE_LOCALIZATION__MSG__DETAIL__DATASET_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define COOPERATIVE_LOCALIZATION__MSG__DETAIL__DATASET_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "cooperative_localization/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "cooperative_localization/msg/detail/dataset_status__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cooperative_localization
bool cdr_serialize_cooperative_localization__msg__DatasetStatus(
  const cooperative_localization__msg__DatasetStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cooperative_localization
bool cdr_deserialize_cooperative_localization__msg__DatasetStatus(
  eprosima::fastcdr::Cdr &,
  cooperative_localization__msg__DatasetStatus * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cooperative_localization
size_t get_serialized_size_cooperative_localization__msg__DatasetStatus(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cooperative_localization
size_t max_serialized_size_cooperative_localization__msg__DatasetStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cooperative_localization
bool cdr_serialize_key_cooperative_localization__msg__DatasetStatus(
  const cooperative_localization__msg__DatasetStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cooperative_localization
size_t get_serialized_size_key_cooperative_localization__msg__DatasetStatus(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cooperative_localization
size_t max_serialized_size_key_cooperative_localization__msg__DatasetStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cooperative_localization
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, cooperative_localization, msg, DatasetStatus)();

#ifdef __cplusplus
}
#endif

#endif  // COOPERATIVE_LOCALIZATION__MSG__DETAIL__DATASET_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
