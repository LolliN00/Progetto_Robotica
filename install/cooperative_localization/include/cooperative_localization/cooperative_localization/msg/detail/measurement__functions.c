// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cooperative_localization:msg/Measurement.idl
// generated code does not contain a copyright notice
#include "cooperative_localization/msg/detail/measurement__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
cooperative_localization__msg__Measurement__init(cooperative_localization__msg__Measurement * msg)
{
  if (!msg) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    cooperative_localization__msg__Measurement__fini(msg);
    return false;
  }
  // observer_id
  // subject_id
  // range
  // bearing
  return true;
}

void
cooperative_localization__msg__Measurement__fini(cooperative_localization__msg__Measurement * msg)
{
  if (!msg) {
    return;
  }
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
  // observer_id
  // subject_id
  // range
  // bearing
}

bool
cooperative_localization__msg__Measurement__are_equal(const cooperative_localization__msg__Measurement * lhs, const cooperative_localization__msg__Measurement * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  // observer_id
  if (lhs->observer_id != rhs->observer_id) {
    return false;
  }
  // subject_id
  if (lhs->subject_id != rhs->subject_id) {
    return false;
  }
  // range
  if (lhs->range != rhs->range) {
    return false;
  }
  // bearing
  if (lhs->bearing != rhs->bearing) {
    return false;
  }
  return true;
}

bool
cooperative_localization__msg__Measurement__copy(
  const cooperative_localization__msg__Measurement * input,
  cooperative_localization__msg__Measurement * output)
{
  if (!input || !output) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  // observer_id
  output->observer_id = input->observer_id;
  // subject_id
  output->subject_id = input->subject_id;
  // range
  output->range = input->range;
  // bearing
  output->bearing = input->bearing;
  return true;
}

cooperative_localization__msg__Measurement *
cooperative_localization__msg__Measurement__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cooperative_localization__msg__Measurement * msg = (cooperative_localization__msg__Measurement *)allocator.allocate(sizeof(cooperative_localization__msg__Measurement), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cooperative_localization__msg__Measurement));
  bool success = cooperative_localization__msg__Measurement__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cooperative_localization__msg__Measurement__destroy(cooperative_localization__msg__Measurement * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cooperative_localization__msg__Measurement__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cooperative_localization__msg__Measurement__Sequence__init(cooperative_localization__msg__Measurement__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cooperative_localization__msg__Measurement * data = NULL;

  if (size) {
    data = (cooperative_localization__msg__Measurement *)allocator.zero_allocate(size, sizeof(cooperative_localization__msg__Measurement), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cooperative_localization__msg__Measurement__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cooperative_localization__msg__Measurement__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cooperative_localization__msg__Measurement__Sequence__fini(cooperative_localization__msg__Measurement__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cooperative_localization__msg__Measurement__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cooperative_localization__msg__Measurement__Sequence *
cooperative_localization__msg__Measurement__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cooperative_localization__msg__Measurement__Sequence * array = (cooperative_localization__msg__Measurement__Sequence *)allocator.allocate(sizeof(cooperative_localization__msg__Measurement__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cooperative_localization__msg__Measurement__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cooperative_localization__msg__Measurement__Sequence__destroy(cooperative_localization__msg__Measurement__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cooperative_localization__msg__Measurement__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cooperative_localization__msg__Measurement__Sequence__are_equal(const cooperative_localization__msg__Measurement__Sequence * lhs, const cooperative_localization__msg__Measurement__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cooperative_localization__msg__Measurement__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cooperative_localization__msg__Measurement__Sequence__copy(
  const cooperative_localization__msg__Measurement__Sequence * input,
  cooperative_localization__msg__Measurement__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cooperative_localization__msg__Measurement);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cooperative_localization__msg__Measurement * data =
      (cooperative_localization__msg__Measurement *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cooperative_localization__msg__Measurement__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cooperative_localization__msg__Measurement__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cooperative_localization__msg__Measurement__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
