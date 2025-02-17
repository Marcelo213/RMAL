// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from open_manipulator_msgs:srv/SetJointPosition.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "open_manipulator_msgs/srv/detail/set_joint_position__rosidl_typesupport_introspection_c.h"
#include "open_manipulator_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "open_manipulator_msgs/srv/detail/set_joint_position__functions.h"
#include "open_manipulator_msgs/srv/detail/set_joint_position__struct.h"


// Include directives for member types
// Member `planning_group`
#include "rosidl_runtime_c/string_functions.h"
// Member `joint_position`
#include "open_manipulator_msgs/msg/joint_position.h"
// Member `joint_position`
#include "open_manipulator_msgs/msg/detail/joint_position__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void SetJointPosition_Request__rosidl_typesupport_introspection_c__SetJointPosition_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  open_manipulator_msgs__srv__SetJointPosition_Request__init(message_memory);
}

void SetJointPosition_Request__rosidl_typesupport_introspection_c__SetJointPosition_Request_fini_function(void * message_memory)
{
  open_manipulator_msgs__srv__SetJointPosition_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember SetJointPosition_Request__rosidl_typesupport_introspection_c__SetJointPosition_Request_message_member_array[3] = {
  {
    "planning_group",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(open_manipulator_msgs__srv__SetJointPosition_Request, planning_group),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joint_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(open_manipulator_msgs__srv__SetJointPosition_Request, joint_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "path_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(open_manipulator_msgs__srv__SetJointPosition_Request, path_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers SetJointPosition_Request__rosidl_typesupport_introspection_c__SetJointPosition_Request_message_members = {
  "open_manipulator_msgs__srv",  // message namespace
  "SetJointPosition_Request",  // message name
  3,  // number of fields
  sizeof(open_manipulator_msgs__srv__SetJointPosition_Request),
  SetJointPosition_Request__rosidl_typesupport_introspection_c__SetJointPosition_Request_message_member_array,  // message members
  SetJointPosition_Request__rosidl_typesupport_introspection_c__SetJointPosition_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  SetJointPosition_Request__rosidl_typesupport_introspection_c__SetJointPosition_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t SetJointPosition_Request__rosidl_typesupport_introspection_c__SetJointPosition_Request_message_type_support_handle = {
  0,
  &SetJointPosition_Request__rosidl_typesupport_introspection_c__SetJointPosition_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_open_manipulator_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, open_manipulator_msgs, srv, SetJointPosition_Request)() {
  SetJointPosition_Request__rosidl_typesupport_introspection_c__SetJointPosition_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, open_manipulator_msgs, msg, JointPosition)();
  if (!SetJointPosition_Request__rosidl_typesupport_introspection_c__SetJointPosition_Request_message_type_support_handle.typesupport_identifier) {
    SetJointPosition_Request__rosidl_typesupport_introspection_c__SetJointPosition_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &SetJointPosition_Request__rosidl_typesupport_introspection_c__SetJointPosition_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "open_manipulator_msgs/srv/detail/set_joint_position__rosidl_typesupport_introspection_c.h"
// already included above
// #include "open_manipulator_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "open_manipulator_msgs/srv/detail/set_joint_position__functions.h"
// already included above
// #include "open_manipulator_msgs/srv/detail/set_joint_position__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void SetJointPosition_Response__rosidl_typesupport_introspection_c__SetJointPosition_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  open_manipulator_msgs__srv__SetJointPosition_Response__init(message_memory);
}

void SetJointPosition_Response__rosidl_typesupport_introspection_c__SetJointPosition_Response_fini_function(void * message_memory)
{
  open_manipulator_msgs__srv__SetJointPosition_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember SetJointPosition_Response__rosidl_typesupport_introspection_c__SetJointPosition_Response_message_member_array[1] = {
  {
    "is_planned",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(open_manipulator_msgs__srv__SetJointPosition_Response, is_planned),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers SetJointPosition_Response__rosidl_typesupport_introspection_c__SetJointPosition_Response_message_members = {
  "open_manipulator_msgs__srv",  // message namespace
  "SetJointPosition_Response",  // message name
  1,  // number of fields
  sizeof(open_manipulator_msgs__srv__SetJointPosition_Response),
  SetJointPosition_Response__rosidl_typesupport_introspection_c__SetJointPosition_Response_message_member_array,  // message members
  SetJointPosition_Response__rosidl_typesupport_introspection_c__SetJointPosition_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  SetJointPosition_Response__rosidl_typesupport_introspection_c__SetJointPosition_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t SetJointPosition_Response__rosidl_typesupport_introspection_c__SetJointPosition_Response_message_type_support_handle = {
  0,
  &SetJointPosition_Response__rosidl_typesupport_introspection_c__SetJointPosition_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_open_manipulator_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, open_manipulator_msgs, srv, SetJointPosition_Response)() {
  if (!SetJointPosition_Response__rosidl_typesupport_introspection_c__SetJointPosition_Response_message_type_support_handle.typesupport_identifier) {
    SetJointPosition_Response__rosidl_typesupport_introspection_c__SetJointPosition_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &SetJointPosition_Response__rosidl_typesupport_introspection_c__SetJointPosition_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "open_manipulator_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "open_manipulator_msgs/srv/detail/set_joint_position__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers open_manipulator_msgs__srv__detail__set_joint_position__rosidl_typesupport_introspection_c__SetJointPosition_service_members = {
  "open_manipulator_msgs__srv",  // service namespace
  "SetJointPosition",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // open_manipulator_msgs__srv__detail__set_joint_position__rosidl_typesupport_introspection_c__SetJointPosition_Request_message_type_support_handle,
  NULL  // response message
  // open_manipulator_msgs__srv__detail__set_joint_position__rosidl_typesupport_introspection_c__SetJointPosition_Response_message_type_support_handle
};

static rosidl_service_type_support_t open_manipulator_msgs__srv__detail__set_joint_position__rosidl_typesupport_introspection_c__SetJointPosition_service_type_support_handle = {
  0,
  &open_manipulator_msgs__srv__detail__set_joint_position__rosidl_typesupport_introspection_c__SetJointPosition_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, open_manipulator_msgs, srv, SetJointPosition_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, open_manipulator_msgs, srv, SetJointPosition_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_open_manipulator_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, open_manipulator_msgs, srv, SetJointPosition)() {
  if (!open_manipulator_msgs__srv__detail__set_joint_position__rosidl_typesupport_introspection_c__SetJointPosition_service_type_support_handle.typesupport_identifier) {
    open_manipulator_msgs__srv__detail__set_joint_position__rosidl_typesupport_introspection_c__SetJointPosition_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)open_manipulator_msgs__srv__detail__set_joint_position__rosidl_typesupport_introspection_c__SetJointPosition_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, open_manipulator_msgs, srv, SetJointPosition_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, open_manipulator_msgs, srv, SetJointPosition_Response)()->data;
  }

  return &open_manipulator_msgs__srv__detail__set_joint_position__rosidl_typesupport_introspection_c__SetJointPosition_service_type_support_handle;
}
