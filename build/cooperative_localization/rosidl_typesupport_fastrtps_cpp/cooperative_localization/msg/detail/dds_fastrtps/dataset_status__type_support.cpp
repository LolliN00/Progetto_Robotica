// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from cooperative_localization:msg/DatasetStatus.idl
// generated code does not contain a copyright notice
#include "cooperative_localization/msg/detail/dataset_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "cooperative_localization/msg/detail/dataset_status__functions.h"
#include "cooperative_localization/msg/detail/dataset_status__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: robot_id
  cdr << ros_message.robot_id;

  // Member: finished
  cdr << (ros_message.finished ? true : false);

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cooperative_localization
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  cooperative_localization::msg::DatasetStatus & ros_message)
{
  // Member: robot_id
  cdr >> ros_message.robot_id;

  // Member: finished
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.finished = tmp ? true : false;
  }

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cooperative_localization
get_serialized_size(
  const cooperative_localization::msg::DatasetStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: robot_id
  {
    size_t item_size = sizeof(ros_message.robot_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: finished
  {
    size_t item_size = sizeof(ros_message.finished);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cooperative_localization
max_serialized_size_DatasetStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: robot_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: finished
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = cooperative_localization::msg::DatasetStatus;
    is_plain =
      (
      offsetof(DataType, finished) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cooperative_localization
cdr_serialize_key(
  const cooperative_localization::msg::DatasetStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: robot_id
  cdr << ros_message.robot_id;

  // Member: finished
  cdr << (ros_message.finished ? true : false);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cooperative_localization
get_serialized_size_key(
  const cooperative_localization::msg::DatasetStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: robot_id
  {
    size_t item_size = sizeof(ros_message.robot_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: finished
  {
    size_t item_size = sizeof(ros_message.finished);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cooperative_localization
max_serialized_size_key_DatasetStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: robot_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: finished
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = cooperative_localization::msg::DatasetStatus;
    is_plain =
      (
      offsetof(DataType, finished) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _DatasetStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const cooperative_localization::msg::DatasetStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _DatasetStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<cooperative_localization::msg::DatasetStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _DatasetStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const cooperative_localization::msg::DatasetStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _DatasetStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_DatasetStatus(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _DatasetStatus__callbacks = {
  "cooperative_localization::msg",
  "DatasetStatus",
  _DatasetStatus__cdr_serialize,
  _DatasetStatus__cdr_deserialize,
  _DatasetStatus__get_serialized_size,
  _DatasetStatus__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _DatasetStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_DatasetStatus__callbacks,
  get_message_typesupport_handle_function,
  &cooperative_localization__msg__DatasetStatus__get_type_hash,
  &cooperative_localization__msg__DatasetStatus__get_type_description,
  &cooperative_localization__msg__DatasetStatus__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace cooperative_localization

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_cooperative_localization
const rosidl_message_type_support_t *
get_message_type_support_handle<cooperative_localization::msg::DatasetStatus>()
{
  return &cooperative_localization::msg::typesupport_fastrtps_cpp::_DatasetStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cooperative_localization, msg, DatasetStatus)() {
  return &cooperative_localization::msg::typesupport_fastrtps_cpp::_DatasetStatus__handle;
}

#ifdef __cplusplus
}
#endif
