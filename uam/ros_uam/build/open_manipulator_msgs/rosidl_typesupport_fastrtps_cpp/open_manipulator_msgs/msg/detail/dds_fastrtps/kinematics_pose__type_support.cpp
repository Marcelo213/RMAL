// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from open_manipulator_msgs:msg/KinematicsPose.idl
// generated code does not contain a copyright notice
#include "open_manipulator_msgs/msg/detail/kinematics_pose__rosidl_typesupport_fastrtps_cpp.hpp"
#include "open_manipulator_msgs/msg/detail/kinematics_pose__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace geometry_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Pose &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  geometry_msgs::msg::Pose &);
size_t get_serialized_size(
  const geometry_msgs::msg::Pose &,
  size_t current_alignment);
size_t
max_serialized_size_Pose(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace geometry_msgs


namespace open_manipulator_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_open_manipulator_msgs
cdr_serialize(
  const open_manipulator_msgs::msg::KinematicsPose & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: pose
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.pose,
    cdr);
  // Member: max_accelerations_scaling_factor
  cdr << ros_message.max_accelerations_scaling_factor;
  // Member: max_velocity_scaling_factor
  cdr << ros_message.max_velocity_scaling_factor;
  // Member: tolerance
  cdr << ros_message.tolerance;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_open_manipulator_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  open_manipulator_msgs::msg::KinematicsPose & ros_message)
{
  // Member: pose
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.pose);

  // Member: max_accelerations_scaling_factor
  cdr >> ros_message.max_accelerations_scaling_factor;

  // Member: max_velocity_scaling_factor
  cdr >> ros_message.max_velocity_scaling_factor;

  // Member: tolerance
  cdr >> ros_message.tolerance;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_open_manipulator_msgs
get_serialized_size(
  const open_manipulator_msgs::msg::KinematicsPose & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: pose

  current_alignment +=
    geometry_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.pose, current_alignment);
  // Member: max_accelerations_scaling_factor
  {
    size_t item_size = sizeof(ros_message.max_accelerations_scaling_factor);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: max_velocity_scaling_factor
  {
    size_t item_size = sizeof(ros_message.max_velocity_scaling_factor);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tolerance
  {
    size_t item_size = sizeof(ros_message.tolerance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_open_manipulator_msgs
max_serialized_size_KinematicsPose(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: pose
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        geometry_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Pose(
        full_bounded, current_alignment);
    }
  }

  // Member: max_accelerations_scaling_factor
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: max_velocity_scaling_factor
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: tolerance
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _KinematicsPose__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const open_manipulator_msgs::msg::KinematicsPose *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _KinematicsPose__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<open_manipulator_msgs::msg::KinematicsPose *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _KinematicsPose__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const open_manipulator_msgs::msg::KinematicsPose *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _KinematicsPose__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_KinematicsPose(full_bounded, 0);
}

static message_type_support_callbacks_t _KinematicsPose__callbacks = {
  "open_manipulator_msgs::msg",
  "KinematicsPose",
  _KinematicsPose__cdr_serialize,
  _KinematicsPose__cdr_deserialize,
  _KinematicsPose__get_serialized_size,
  _KinematicsPose__max_serialized_size
};

static rosidl_message_type_support_t _KinematicsPose__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_KinematicsPose__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace open_manipulator_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_open_manipulator_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<open_manipulator_msgs::msg::KinematicsPose>()
{
  return &open_manipulator_msgs::msg::typesupport_fastrtps_cpp::_KinematicsPose__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, open_manipulator_msgs, msg, KinematicsPose)() {
  return &open_manipulator_msgs::msg::typesupport_fastrtps_cpp::_KinematicsPose__handle;
}

#ifdef __cplusplus
}
#endif
