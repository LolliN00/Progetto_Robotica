// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from cooperative_localization:msg/Measurement.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cooperative_localization/msg/measurement.h"


#ifndef COOPERATIVE_LOCALIZATION__MSG__DETAIL__MEASUREMENT__FUNCTIONS_H_
#define COOPERATIVE_LOCALIZATION__MSG__DETAIL__MEASUREMENT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "cooperative_localization/msg/rosidl_generator_c__visibility_control.h"

#include "cooperative_localization/msg/detail/measurement__struct.h"

/// Initialize msg/Measurement message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cooperative_localization__msg__Measurement
 * )) before or use
 * cooperative_localization__msg__Measurement__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cooperative_localization
bool
cooperative_localization__msg__Measurement__init(cooperative_localization__msg__Measurement * msg);

/// Finalize msg/Measurement message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cooperative_localization
void
cooperative_localization__msg__Measurement__fini(cooperative_localization__msg__Measurement * msg);

/// Create msg/Measurement message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cooperative_localization__msg__Measurement__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cooperative_localization
cooperative_localization__msg__Measurement *
cooperative_localization__msg__Measurement__create(void);

/// Destroy msg/Measurement message.
/**
 * It calls
 * cooperative_localization__msg__Measurement__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cooperative_localization
void
cooperative_localization__msg__Measurement__destroy(cooperative_localization__msg__Measurement * msg);

/// Check for msg/Measurement message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cooperative_localization
bool
cooperative_localization__msg__Measurement__are_equal(const cooperative_localization__msg__Measurement * lhs, const cooperative_localization__msg__Measurement * rhs);

/// Copy a msg/Measurement message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_cooperative_localization
bool
cooperative_localization__msg__Measurement__copy(
  const cooperative_localization__msg__Measurement * input,
  cooperative_localization__msg__Measurement * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_cooperative_localization
const rosidl_type_hash_t *
cooperative_localization__msg__Measurement__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_cooperative_localization
const rosidl_runtime_c__type_description__TypeDescription *
cooperative_localization__msg__Measurement__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_cooperative_localization
const rosidl_runtime_c__type_description__TypeSource *
cooperative_localization__msg__Measurement__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_cooperative_localization
const rosidl_runtime_c__type_description__TypeSource__Sequence *
cooperative_localization__msg__Measurement__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/Measurement messages.
/**
 * It allocates the memory for the number of elements and calls
 * cooperative_localization__msg__Measurement__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cooperative_localization
bool
cooperative_localization__msg__Measurement__Sequence__init(cooperative_localization__msg__Measurement__Sequence * array, size_t size);

/// Finalize array of msg/Measurement messages.
/**
 * It calls
 * cooperative_localization__msg__Measurement__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cooperative_localization
void
cooperative_localization__msg__Measurement__Sequence__fini(cooperative_localization__msg__Measurement__Sequence * array);

/// Create array of msg/Measurement messages.
/**
 * It allocates the memory for the array and calls
 * cooperative_localization__msg__Measurement__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cooperative_localization
cooperative_localization__msg__Measurement__Sequence *
cooperative_localization__msg__Measurement__Sequence__create(size_t size);

/// Destroy array of msg/Measurement messages.
/**
 * It calls
 * cooperative_localization__msg__Measurement__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cooperative_localization
void
cooperative_localization__msg__Measurement__Sequence__destroy(cooperative_localization__msg__Measurement__Sequence * array);

/// Check for msg/Measurement message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cooperative_localization
bool
cooperative_localization__msg__Measurement__Sequence__are_equal(const cooperative_localization__msg__Measurement__Sequence * lhs, const cooperative_localization__msg__Measurement__Sequence * rhs);

/// Copy an array of msg/Measurement messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_cooperative_localization
bool
cooperative_localization__msg__Measurement__Sequence__copy(
  const cooperative_localization__msg__Measurement__Sequence * input,
  cooperative_localization__msg__Measurement__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // COOPERATIVE_LOCALIZATION__MSG__DETAIL__MEASUREMENT__FUNCTIONS_H_
