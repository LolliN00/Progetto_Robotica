// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cooperative_localization:msg/DatasetStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cooperative_localization/msg/dataset_status.hpp"


#ifndef COOPERATIVE_LOCALIZATION__MSG__DETAIL__DATASET_STATUS__STRUCT_HPP_
#define COOPERATIVE_LOCALIZATION__MSG__DETAIL__DATASET_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cooperative_localization__msg__DatasetStatus __attribute__((deprecated))
#else
# define DEPRECATED__cooperative_localization__msg__DatasetStatus __declspec(deprecated)
#endif

namespace cooperative_localization
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DatasetStatus_
{
  using Type = DatasetStatus_<ContainerAllocator>;

  explicit DatasetStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = 0l;
      this->finished = false;
    }
  }

  explicit DatasetStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = 0l;
      this->finished = false;
    }
  }

  // field types and members
  using _robot_id_type =
    int32_t;
  _robot_id_type robot_id;
  using _finished_type =
    bool;
  _finished_type finished;

  // setters for named parameter idiom
  Type & set__robot_id(
    const int32_t & _arg)
  {
    this->robot_id = _arg;
    return *this;
  }
  Type & set__finished(
    const bool & _arg)
  {
    this->finished = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cooperative_localization::msg::DatasetStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const cooperative_localization::msg::DatasetStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cooperative_localization::msg::DatasetStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cooperative_localization::msg::DatasetStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cooperative_localization::msg::DatasetStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cooperative_localization::msg::DatasetStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cooperative_localization::msg::DatasetStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cooperative_localization::msg::DatasetStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cooperative_localization::msg::DatasetStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cooperative_localization::msg::DatasetStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cooperative_localization__msg__DatasetStatus
    std::shared_ptr<cooperative_localization::msg::DatasetStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cooperative_localization__msg__DatasetStatus
    std::shared_ptr<cooperative_localization::msg::DatasetStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DatasetStatus_ & other) const
  {
    if (this->robot_id != other.robot_id) {
      return false;
    }
    if (this->finished != other.finished) {
      return false;
    }
    return true;
  }
  bool operator!=(const DatasetStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DatasetStatus_

// alias to use template instance with default allocator
using DatasetStatus =
  cooperative_localization::msg::DatasetStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cooperative_localization

#endif  // COOPERATIVE_LOCALIZATION__MSG__DETAIL__DATASET_STATUS__STRUCT_HPP_
