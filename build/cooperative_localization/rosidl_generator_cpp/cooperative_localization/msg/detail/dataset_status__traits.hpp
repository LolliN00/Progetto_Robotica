// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cooperative_localization:msg/DatasetStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cooperative_localization/msg/dataset_status.hpp"


#ifndef COOPERATIVE_LOCALIZATION__MSG__DETAIL__DATASET_STATUS__TRAITS_HPP_
#define COOPERATIVE_LOCALIZATION__MSG__DETAIL__DATASET_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cooperative_localization/msg/detail/dataset_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cooperative_localization
{

namespace msg
{

inline void to_flow_style_yaml(
  const DatasetStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << ", ";
  }

  // member: finished
  {
    out << "finished: ";
    rosidl_generator_traits::value_to_yaml(msg.finished, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DatasetStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << "\n";
  }

  // member: finished
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "finished: ";
    rosidl_generator_traits::value_to_yaml(msg.finished, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DatasetStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace cooperative_localization

namespace rosidl_generator_traits
{

[[deprecated("use cooperative_localization::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cooperative_localization::msg::DatasetStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  cooperative_localization::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cooperative_localization::msg::to_yaml() instead")]]
inline std::string to_yaml(const cooperative_localization::msg::DatasetStatus & msg)
{
  return cooperative_localization::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cooperative_localization::msg::DatasetStatus>()
{
  return "cooperative_localization::msg::DatasetStatus";
}

template<>
inline const char * name<cooperative_localization::msg::DatasetStatus>()
{
  return "cooperative_localization/msg/DatasetStatus";
}

template<>
struct has_fixed_size<cooperative_localization::msg::DatasetStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cooperative_localization::msg::DatasetStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cooperative_localization::msg::DatasetStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COOPERATIVE_LOCALIZATION__MSG__DETAIL__DATASET_STATUS__TRAITS_HPP_
