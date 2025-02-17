// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from open_manipulator_msgs:srv/GetJointPosition.idl
// generated code does not contain a copyright notice
#include "open_manipulator_msgs/srv/detail/get_joint_position__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "open_manipulator_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "open_manipulator_msgs/srv/detail/get_joint_position__struct.h"
#include "open_manipulator_msgs/srv/detail/get_joint_position__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // planning_group
#include "rosidl_runtime_c/string_functions.h"  // planning_group

// forward declare type support functions


using _GetJointPosition_Request__ros_msg_type = open_manipulator_msgs__srv__GetJointPosition_Request;

static bool _GetJointPosition_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _GetJointPosition_Request__ros_msg_type * ros_message = static_cast<const _GetJointPosition_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: planning_group
  {
    const rosidl_runtime_c__String * str = &ros_message->planning_group;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _GetJointPosition_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _GetJointPosition_Request__ros_msg_type * ros_message = static_cast<_GetJointPosition_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: planning_group
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->planning_group.data) {
      rosidl_runtime_c__String__init(&ros_message->planning_group);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->planning_group,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'planning_group'\n");
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_open_manipulator_msgs
size_t get_serialized_size_open_manipulator_msgs__srv__GetJointPosition_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GetJointPosition_Request__ros_msg_type * ros_message = static_cast<const _GetJointPosition_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name planning_group
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->planning_group.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _GetJointPosition_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_open_manipulator_msgs__srv__GetJointPosition_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_open_manipulator_msgs
size_t max_serialized_size_open_manipulator_msgs__srv__GetJointPosition_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: planning_group
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _GetJointPosition_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_open_manipulator_msgs__srv__GetJointPosition_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_GetJointPosition_Request = {
  "open_manipulator_msgs::srv",
  "GetJointPosition_Request",
  _GetJointPosition_Request__cdr_serialize,
  _GetJointPosition_Request__cdr_deserialize,
  _GetJointPosition_Request__get_serialized_size,
  _GetJointPosition_Request__max_serialized_size
};

static rosidl_message_type_support_t _GetJointPosition_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GetJointPosition_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, open_manipulator_msgs, srv, GetJointPosition_Request)() {
  return &_GetJointPosition_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "open_manipulator_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "open_manipulator_msgs/srv/detail/get_joint_position__struct.h"
// already included above
// #include "open_manipulator_msgs/srv/detail/get_joint_position__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "open_manipulator_msgs/msg/detail/joint_position__functions.h"  // joint_position

// forward declare type support functions
size_t get_serialized_size_open_manipulator_msgs__msg__JointPosition(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_open_manipulator_msgs__msg__JointPosition(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, open_manipulator_msgs, msg, JointPosition)();


using _GetJointPosition_Response__ros_msg_type = open_manipulator_msgs__srv__GetJointPosition_Response;

static bool _GetJointPosition_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _GetJointPosition_Response__ros_msg_type * ros_message = static_cast<const _GetJointPosition_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: joint_position
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, open_manipulator_msgs, msg, JointPosition
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->joint_position, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _GetJointPosition_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _GetJointPosition_Response__ros_msg_type * ros_message = static_cast<_GetJointPosition_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: joint_position
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, open_manipulator_msgs, msg, JointPosition
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->joint_position))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_open_manipulator_msgs
size_t get_serialized_size_open_manipulator_msgs__srv__GetJointPosition_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GetJointPosition_Response__ros_msg_type * ros_message = static_cast<const _GetJointPosition_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name joint_position

  current_alignment += get_serialized_size_open_manipulator_msgs__msg__JointPosition(
    &(ros_message->joint_position), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _GetJointPosition_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_open_manipulator_msgs__srv__GetJointPosition_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_open_manipulator_msgs
size_t max_serialized_size_open_manipulator_msgs__srv__GetJointPosition_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: joint_position
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_open_manipulator_msgs__msg__JointPosition(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _GetJointPosition_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_open_manipulator_msgs__srv__GetJointPosition_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_GetJointPosition_Response = {
  "open_manipulator_msgs::srv",
  "GetJointPosition_Response",
  _GetJointPosition_Response__cdr_serialize,
  _GetJointPosition_Response__cdr_deserialize,
  _GetJointPosition_Response__get_serialized_size,
  _GetJointPosition_Response__max_serialized_size
};

static rosidl_message_type_support_t _GetJointPosition_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GetJointPosition_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, open_manipulator_msgs, srv, GetJointPosition_Response)() {
  return &_GetJointPosition_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "open_manipulator_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "open_manipulator_msgs/srv/get_joint_position.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t GetJointPosition__callbacks = {
  "open_manipulator_msgs::srv",
  "GetJointPosition",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, open_manipulator_msgs, srv, GetJointPosition_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, open_manipulator_msgs, srv, GetJointPosition_Response)(),
};

static rosidl_service_type_support_t GetJointPosition__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &GetJointPosition__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, open_manipulator_msgs, srv, GetJointPosition)() {
  return &GetJointPosition__handle;
}

#if defined(__cplusplus)
}
#endif
