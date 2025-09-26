// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cooperative_localization:msg/DatasetStatus.idl
// generated code does not contain a copyright notice
#include "cooperative_localization/msg/detail/dataset_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
cooperative_localization__msg__DatasetStatus__init(cooperative_localization__msg__DatasetStatus * msg)
{
  if (!msg) {
    return false;
  }
  // robot_id
  // finished
  return true;
}

void
cooperative_localization__msg__DatasetStatus__fini(cooperative_localization__msg__DatasetStatus * msg)
{
  if (!msg) {
    return;
  }
  // robot_id
  // finished
}

bool
cooperative_localization__msg__DatasetStatus__are_equal(const cooperative_localization__msg__DatasetStatus * lhs, const cooperative_localization__msg__DatasetStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_id
  if (lhs->robot_id != rhs->robot_id) {
    return false;
  }
  // finished
  if (lhs->finished != rhs->finished) {
    return false;
  }
  return true;
}

bool
cooperative_localization__msg__DatasetStatus__copy(
  const cooperative_localization__msg__DatasetStatus * input,
  cooperative_localization__msg__DatasetStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_id
  output->robot_id = input->robot_id;
  // finished
  output->finished = input->finished;
  return true;
}

cooperative_localization__msg__DatasetStatus *
cooperative_localization__msg__DatasetStatus__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cooperative_localization__msg__DatasetStatus * msg = (cooperative_localization__msg__DatasetStatus *)allocator.allocate(sizeof(cooperative_localization__msg__DatasetStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cooperative_localization__msg__DatasetStatus));
  bool success = cooperative_localization__msg__DatasetStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cooperative_localization__msg__DatasetStatus__destroy(cooperative_localization__msg__DatasetStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cooperative_localization__msg__DatasetStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cooperative_localization__msg__DatasetStatus__Sequence__init(cooperative_localization__msg__DatasetStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cooperative_localization__msg__DatasetStatus * data = NULL;

  if (size) {
    data = (cooperative_localization__msg__DatasetStatus *)allocator.zero_allocate(size, sizeof(cooperative_localization__msg__DatasetStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cooperative_localization__msg__DatasetStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cooperative_localization__msg__DatasetStatus__fini(&data[i - 1]);
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
cooperative_localization__msg__DatasetStatus__Sequence__fini(cooperative_localization__msg__DatasetStatus__Sequence * array)
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
      cooperative_localization__msg__DatasetStatus__fini(&array->data[i]);
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

cooperative_localization__msg__DatasetStatus__Sequence *
cooperative_localization__msg__DatasetStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cooperative_localization__msg__DatasetStatus__Sequence * array = (cooperative_localization__msg__DatasetStatus__Sequence *)allocator.allocate(sizeof(cooperative_localization__msg__DatasetStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cooperative_localization__msg__DatasetStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cooperative_localization__msg__DatasetStatus__Sequence__destroy(cooperative_localization__msg__DatasetStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cooperative_localization__msg__DatasetStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cooperative_localization__msg__DatasetStatus__Sequence__are_equal(const cooperative_localization__msg__DatasetStatus__Sequence * lhs, const cooperative_localization__msg__DatasetStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cooperative_localization__msg__DatasetStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cooperative_localization__msg__DatasetStatus__Sequence__copy(
  const cooperative_localization__msg__DatasetStatus__Sequence * input,
  cooperative_localization__msg__DatasetStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cooperative_localization__msg__DatasetStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cooperative_localization__msg__DatasetStatus * data =
      (cooperative_localization__msg__DatasetStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cooperative_localization__msg__DatasetStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cooperative_localization__msg__DatasetStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cooperative_localization__msg__DatasetStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
