// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cooperative_localization:msg/Measurement.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cooperative_localization/msg/detail/measurement__rosidl_typesupport_introspection_c.h"
#include "cooperative_localization/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cooperative_localization/msg/detail/measurement__functions.h"
#include "cooperative_localization/msg/detail/measurement__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cooperative_localization__msg__Measurement__rosidl_typesupport_introspection_c__Measurement_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cooperative_localization__msg__Measurement__init(message_memory);
}

void cooperative_localization__msg__Measurement__rosidl_typesupport_introspection_c__Measurement_fini_function(void * message_memory)
{
  cooperative_localization__msg__Measurement__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember cooperative_localization__msg__Measurement__rosidl_typesupport_introspection_c__Measurement_message_member_array[5] = {
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cooperative_localization__msg__Measurement, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "observer_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cooperative_localization__msg__Measurement, observer_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "subject_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cooperative_localization__msg__Measurement, subject_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "range",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cooperative_localization__msg__Measurement, range),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bearing",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cooperative_localization__msg__Measurement, bearing),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cooperative_localization__msg__Measurement__rosidl_typesupport_introspection_c__Measurement_message_members = {
  "cooperative_localization__msg",  // message namespace
  "Measurement",  // message name
  5,  // number of fields
  sizeof(cooperative_localization__msg__Measurement),
  false,  // has_any_key_member_
  cooperative_localization__msg__Measurement__rosidl_typesupport_introspection_c__Measurement_message_member_array,  // message members
  cooperative_localization__msg__Measurement__rosidl_typesupport_introspection_c__Measurement_init_function,  // function to initialize message memory (memory has to be allocated)
  cooperative_localization__msg__Measurement__rosidl_typesupport_introspection_c__Measurement_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cooperative_localization__msg__Measurement__rosidl_typesupport_introspection_c__Measurement_message_type_support_handle = {
  0,
  &cooperative_localization__msg__Measurement__rosidl_typesupport_introspection_c__Measurement_message_members,
  get_message_typesupport_handle_function,
  &cooperative_localization__msg__Measurement__get_type_hash,
  &cooperative_localization__msg__Measurement__get_type_description,
  &cooperative_localization__msg__Measurement__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cooperative_localization
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cooperative_localization, msg, Measurement)() {
  cooperative_localization__msg__Measurement__rosidl_typesupport_introspection_c__Measurement_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!cooperative_localization__msg__Measurement__rosidl_typesupport_introspection_c__Measurement_message_type_support_handle.typesupport_identifier) {
    cooperative_localization__msg__Measurement__rosidl_typesupport_introspection_c__Measurement_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cooperative_localization__msg__Measurement__rosidl_typesupport_introspection_c__Measurement_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
