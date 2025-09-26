// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from cooperative_localization:msg/DatasetStatus.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "cooperative_localization/msg/detail/dataset_status__functions.h"
#include "cooperative_localization/msg/detail/dataset_status__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace cooperative_localization
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void DatasetStatus_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) cooperative_localization::msg::DatasetStatus(_init);
}

void DatasetStatus_fini_function(void * message_memory)
{
  auto typed_message = static_cast<cooperative_localization::msg::DatasetStatus *>(message_memory);
  typed_message->~DatasetStatus();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DatasetStatus_message_member_array[2] = {
  {
    "robot_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cooperative_localization::msg::DatasetStatus, robot_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "finished",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cooperative_localization::msg::DatasetStatus, finished),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DatasetStatus_message_members = {
  "cooperative_localization::msg",  // message namespace
  "DatasetStatus",  // message name
  2,  // number of fields
  sizeof(cooperative_localization::msg::DatasetStatus),
  false,  // has_any_key_member_
  DatasetStatus_message_member_array,  // message members
  DatasetStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  DatasetStatus_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DatasetStatus_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DatasetStatus_message_members,
  get_message_typesupport_handle_function,
  &cooperative_localization__msg__DatasetStatus__get_type_hash,
  &cooperative_localization__msg__DatasetStatus__get_type_description,
  &cooperative_localization__msg__DatasetStatus__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace cooperative_localization


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cooperative_localization::msg::DatasetStatus>()
{
  return &::cooperative_localization::msg::rosidl_typesupport_introspection_cpp::DatasetStatus_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cooperative_localization, msg, DatasetStatus)() {
  return &::cooperative_localization::msg::rosidl_typesupport_introspection_cpp::DatasetStatus_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
