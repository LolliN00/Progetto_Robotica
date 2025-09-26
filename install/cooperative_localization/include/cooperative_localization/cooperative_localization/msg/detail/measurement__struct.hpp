// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cooperative_localization:msg/Measurement.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cooperative_localization/msg/measurement.hpp"


#ifndef COOPERATIVE_LOCALIZATION__MSG__DETAIL__MEASUREMENT__STRUCT_HPP_
#define COOPERATIVE_LOCALIZATION__MSG__DETAIL__MEASUREMENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cooperative_localization__msg__Measurement __attribute__((deprecated))
#else
# define DEPRECATED__cooperative_localization__msg__Measurement __declspec(deprecated)
#endif

namespace cooperative_localization
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Measurement_
{
  using Type = Measurement_<ContainerAllocator>;

  explicit Measurement_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->observer_id = 0l;
      this->subject_id = 0l;
      this->range = 0.0;
      this->bearing = 0.0;
    }
  }

  explicit Measurement_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->observer_id = 0l;
      this->subject_id = 0l;
      this->range = 0.0;
      this->bearing = 0.0;
    }
  }

  // field types and members
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _observer_id_type =
    int32_t;
  _observer_id_type observer_id;
  using _subject_id_type =
    int32_t;
  _subject_id_type subject_id;
  using _range_type =
    double;
  _range_type range;
  using _bearing_type =
    double;
  _bearing_type bearing;

  // setters for named parameter idiom
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }
  Type & set__observer_id(
    const int32_t & _arg)
  {
    this->observer_id = _arg;
    return *this;
  }
  Type & set__subject_id(
    const int32_t & _arg)
  {
    this->subject_id = _arg;
    return *this;
  }
  Type & set__range(
    const double & _arg)
  {
    this->range = _arg;
    return *this;
  }
  Type & set__bearing(
    const double & _arg)
  {
    this->bearing = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cooperative_localization::msg::Measurement_<ContainerAllocator> *;
  using ConstRawPtr =
    const cooperative_localization::msg::Measurement_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cooperative_localization::msg::Measurement_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cooperative_localization::msg::Measurement_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cooperative_localization::msg::Measurement_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cooperative_localization::msg::Measurement_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cooperative_localization::msg::Measurement_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cooperative_localization::msg::Measurement_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cooperative_localization::msg::Measurement_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cooperative_localization::msg::Measurement_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cooperative_localization__msg__Measurement
    std::shared_ptr<cooperative_localization::msg::Measurement_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cooperative_localization__msg__Measurement
    std::shared_ptr<cooperative_localization::msg::Measurement_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Measurement_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->observer_id != other.observer_id) {
      return false;
    }
    if (this->subject_id != other.subject_id) {
      return false;
    }
    if (this->range != other.range) {
      return false;
    }
    if (this->bearing != other.bearing) {
      return false;
    }
    return true;
  }
  bool operator!=(const Measurement_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Measurement_

// alias to use template instance with default allocator
using Measurement =
  cooperative_localization::msg::Measurement_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cooperative_localization

#endif  // COOPERATIVE_LOCALIZATION__MSG__DETAIL__MEASUREMENT__STRUCT_HPP_
