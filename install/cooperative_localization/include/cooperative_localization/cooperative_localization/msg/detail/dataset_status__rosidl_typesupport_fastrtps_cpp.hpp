// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from cooperative_localization:msg/DatasetStatus.idl
// generated code does not contain a copyright notice

#ifndef COOPERATIVE_LOCALIZATION__MSG__DETAIL__DATASET_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define COOPERATIVE_LOCALIZATION__MSG__DETAIL__DATASET_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "cooperative_localization/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "cooperative_localization/msg/detail/dataset_status__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace cooperative_localization
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cooperative_localization
cdr_serialize(
  const cooperative_localization::msg::DatasetStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cooperative_localization
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  cooperative_localization::msg::DatasetStatus & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cooperative_localization
get_serialized_size(
  const cooperative_localization::msg::DatasetStatus & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cooperative_localization
max_serialized_size_DatasetStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cooperative_localization
cdr_serialize_key(
  const cooperative_localization::msg::DatasetStatus & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cooperative_localization
get_serialized_size_key(
  const cooperative_localization::msg::DatasetStatus & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cooperative_localization
max_serialized_size_key_DatasetStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace cooperative_localization

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cooperative_localization
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cooperative_localization, msg, DatasetStatus)();

#ifdef __cplusplus
}
#endif

#endif  // COOPERATIVE_LOCALIZATION__MSG__DETAIL__DATASET_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
