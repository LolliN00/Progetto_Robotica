// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cooperative_localization:msg/Measurement.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cooperative_localization/msg/measurement.hpp"


#ifndef COOPERATIVE_LOCALIZATION__MSG__DETAIL__MEASUREMENT__TRAITS_HPP_
#define COOPERATIVE_LOCALIZATION__MSG__DETAIL__MEASUREMENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cooperative_localization/msg/detail/measurement__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace cooperative_localization
{

namespace msg
{

inline void to_flow_style_yaml(
  const Measurement & msg,
  std::ostream & out)
{
  out << "{";
  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
    out << ", ";
  }

  // member: observer_id
  {
    out << "observer_id: ";
    rosidl_generator_traits::value_to_yaml(msg.observer_id, out);
    out << ", ";
  }

  // member: subject_id
  {
    out << "subject_id: ";
    rosidl_generator_traits::value_to_yaml(msg.subject_id, out);
    out << ", ";
  }

  // member: range
  {
    out << "range: ";
    rosidl_generator_traits::value_to_yaml(msg.range, out);
    out << ", ";
  }

  // member: bearing
  {
    out << "bearing: ";
    rosidl_generator_traits::value_to_yaml(msg.bearing, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Measurement & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }

  // member: observer_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "observer_id: ";
    rosidl_generator_traits::value_to_yaml(msg.observer_id, out);
    out << "\n";
  }

  // member: subject_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "subject_id: ";
    rosidl_generator_traits::value_to_yaml(msg.subject_id, out);
    out << "\n";
  }

  // member: range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range: ";
    rosidl_generator_traits::value_to_yaml(msg.range, out);
    out << "\n";
  }

  // member: bearing
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bearing: ";
    rosidl_generator_traits::value_to_yaml(msg.bearing, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Measurement & msg, bool use_flow_style = false)
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
  const cooperative_localization::msg::Measurement & msg,
  std::ostream & out, size_t indentation = 0)
{
  cooperative_localization::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cooperative_localization::msg::to_yaml() instead")]]
inline std::string to_yaml(const cooperative_localization::msg::Measurement & msg)
{
  return cooperative_localization::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cooperative_localization::msg::Measurement>()
{
  return "cooperative_localization::msg::Measurement";
}

template<>
inline const char * name<cooperative_localization::msg::Measurement>()
{
  return "cooperative_localization/msg/Measurement";
}

template<>
struct has_fixed_size<cooperative_localization::msg::Measurement>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<cooperative_localization::msg::Measurement>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<cooperative_localization::msg::Measurement>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COOPERATIVE_LOCALIZATION__MSG__DETAIL__MEASUREMENT__TRAITS_HPP_
