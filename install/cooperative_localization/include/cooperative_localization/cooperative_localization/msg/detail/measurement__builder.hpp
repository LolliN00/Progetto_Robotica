// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cooperative_localization:msg/Measurement.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cooperative_localization/msg/measurement.hpp"


#ifndef COOPERATIVE_LOCALIZATION__MSG__DETAIL__MEASUREMENT__BUILDER_HPP_
#define COOPERATIVE_LOCALIZATION__MSG__DETAIL__MEASUREMENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cooperative_localization/msg/detail/measurement__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cooperative_localization
{

namespace msg
{

namespace builder
{

class Init_Measurement_bearing
{
public:
  explicit Init_Measurement_bearing(::cooperative_localization::msg::Measurement & msg)
  : msg_(msg)
  {}
  ::cooperative_localization::msg::Measurement bearing(::cooperative_localization::msg::Measurement::_bearing_type arg)
  {
    msg_.bearing = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cooperative_localization::msg::Measurement msg_;
};

class Init_Measurement_range
{
public:
  explicit Init_Measurement_range(::cooperative_localization::msg::Measurement & msg)
  : msg_(msg)
  {}
  Init_Measurement_bearing range(::cooperative_localization::msg::Measurement::_range_type arg)
  {
    msg_.range = std::move(arg);
    return Init_Measurement_bearing(msg_);
  }

private:
  ::cooperative_localization::msg::Measurement msg_;
};

class Init_Measurement_subject_id
{
public:
  explicit Init_Measurement_subject_id(::cooperative_localization::msg::Measurement & msg)
  : msg_(msg)
  {}
  Init_Measurement_range subject_id(::cooperative_localization::msg::Measurement::_subject_id_type arg)
  {
    msg_.subject_id = std::move(arg);
    return Init_Measurement_range(msg_);
  }

private:
  ::cooperative_localization::msg::Measurement msg_;
};

class Init_Measurement_observer_id
{
public:
  explicit Init_Measurement_observer_id(::cooperative_localization::msg::Measurement & msg)
  : msg_(msg)
  {}
  Init_Measurement_subject_id observer_id(::cooperative_localization::msg::Measurement::_observer_id_type arg)
  {
    msg_.observer_id = std::move(arg);
    return Init_Measurement_subject_id(msg_);
  }

private:
  ::cooperative_localization::msg::Measurement msg_;
};

class Init_Measurement_stamp
{
public:
  Init_Measurement_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Measurement_observer_id stamp(::cooperative_localization::msg::Measurement::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_Measurement_observer_id(msg_);
  }

private:
  ::cooperative_localization::msg::Measurement msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cooperative_localization::msg::Measurement>()
{
  return cooperative_localization::msg::builder::Init_Measurement_stamp();
}

}  // namespace cooperative_localization

#endif  // COOPERATIVE_LOCALIZATION__MSG__DETAIL__MEASUREMENT__BUILDER_HPP_
