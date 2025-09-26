// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cooperative_localization:msg/DatasetStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cooperative_localization/msg/dataset_status.hpp"


#ifndef COOPERATIVE_LOCALIZATION__MSG__DETAIL__DATASET_STATUS__BUILDER_HPP_
#define COOPERATIVE_LOCALIZATION__MSG__DETAIL__DATASET_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cooperative_localization/msg/detail/dataset_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cooperative_localization
{

namespace msg
{

namespace builder
{

class Init_DatasetStatus_finished
{
public:
  explicit Init_DatasetStatus_finished(::cooperative_localization::msg::DatasetStatus & msg)
  : msg_(msg)
  {}
  ::cooperative_localization::msg::DatasetStatus finished(::cooperative_localization::msg::DatasetStatus::_finished_type arg)
  {
    msg_.finished = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cooperative_localization::msg::DatasetStatus msg_;
};

class Init_DatasetStatus_robot_id
{
public:
  Init_DatasetStatus_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DatasetStatus_finished robot_id(::cooperative_localization::msg::DatasetStatus::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_DatasetStatus_finished(msg_);
  }

private:
  ::cooperative_localization::msg::DatasetStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cooperative_localization::msg::DatasetStatus>()
{
  return cooperative_localization::msg::builder::Init_DatasetStatus_robot_id();
}

}  // namespace cooperative_localization

#endif  // COOPERATIVE_LOCALIZATION__MSG__DETAIL__DATASET_STATUS__BUILDER_HPP_
