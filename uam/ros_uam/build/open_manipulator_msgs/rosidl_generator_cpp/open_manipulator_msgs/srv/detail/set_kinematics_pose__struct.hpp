// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from open_manipulator_msgs:srv/SetKinematicsPose.idl
// generated code does not contain a copyright notice

#ifndef OPEN_MANIPULATOR_MSGS__SRV__DETAIL__SET_KINEMATICS_POSE__STRUCT_HPP_
#define OPEN_MANIPULATOR_MSGS__SRV__DETAIL__SET_KINEMATICS_POSE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'kinematics_pose'
#include "open_manipulator_msgs/msg/detail/kinematics_pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__open_manipulator_msgs__srv__SetKinematicsPose_Request __attribute__((deprecated))
#else
# define DEPRECATED__open_manipulator_msgs__srv__SetKinematicsPose_Request __declspec(deprecated)
#endif

namespace open_manipulator_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetKinematicsPose_Request_
{
  using Type = SetKinematicsPose_Request_<ContainerAllocator>;

  explicit SetKinematicsPose_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : kinematics_pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->planning_group = "";
      this->end_effector_name = "";
      this->path_time = 0.0;
    }
  }

  explicit SetKinematicsPose_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : planning_group(_alloc),
    end_effector_name(_alloc),
    kinematics_pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->planning_group = "";
      this->end_effector_name = "";
      this->path_time = 0.0;
    }
  }

  // field types and members
  using _planning_group_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _planning_group_type planning_group;
  using _end_effector_name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _end_effector_name_type end_effector_name;
  using _kinematics_pose_type =
    open_manipulator_msgs::msg::KinematicsPose_<ContainerAllocator>;
  _kinematics_pose_type kinematics_pose;
  using _path_time_type =
    double;
  _path_time_type path_time;

  // setters for named parameter idiom
  Type & set__planning_group(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->planning_group = _arg;
    return *this;
  }
  Type & set__end_effector_name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->end_effector_name = _arg;
    return *this;
  }
  Type & set__kinematics_pose(
    const open_manipulator_msgs::msg::KinematicsPose_<ContainerAllocator> & _arg)
  {
    this->kinematics_pose = _arg;
    return *this;
  }
  Type & set__path_time(
    const double & _arg)
  {
    this->path_time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    open_manipulator_msgs::srv::SetKinematicsPose_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const open_manipulator_msgs::srv::SetKinematicsPose_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<open_manipulator_msgs::srv::SetKinematicsPose_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<open_manipulator_msgs::srv::SetKinematicsPose_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      open_manipulator_msgs::srv::SetKinematicsPose_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<open_manipulator_msgs::srv::SetKinematicsPose_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      open_manipulator_msgs::srv::SetKinematicsPose_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<open_manipulator_msgs::srv::SetKinematicsPose_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<open_manipulator_msgs::srv::SetKinematicsPose_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<open_manipulator_msgs::srv::SetKinematicsPose_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__open_manipulator_msgs__srv__SetKinematicsPose_Request
    std::shared_ptr<open_manipulator_msgs::srv::SetKinematicsPose_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__open_manipulator_msgs__srv__SetKinematicsPose_Request
    std::shared_ptr<open_manipulator_msgs::srv::SetKinematicsPose_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetKinematicsPose_Request_ & other) const
  {
    if (this->planning_group != other.planning_group) {
      return false;
    }
    if (this->end_effector_name != other.end_effector_name) {
      return false;
    }
    if (this->kinematics_pose != other.kinematics_pose) {
      return false;
    }
    if (this->path_time != other.path_time) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetKinematicsPose_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetKinematicsPose_Request_

// alias to use template instance with default allocator
using SetKinematicsPose_Request =
  open_manipulator_msgs::srv::SetKinematicsPose_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace open_manipulator_msgs


#ifndef _WIN32
# define DEPRECATED__open_manipulator_msgs__srv__SetKinematicsPose_Response __attribute__((deprecated))
#else
# define DEPRECATED__open_manipulator_msgs__srv__SetKinematicsPose_Response __declspec(deprecated)
#endif

namespace open_manipulator_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetKinematicsPose_Response_
{
  using Type = SetKinematicsPose_Response_<ContainerAllocator>;

  explicit SetKinematicsPose_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_planned = false;
    }
  }

  explicit SetKinematicsPose_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_planned = false;
    }
  }

  // field types and members
  using _is_planned_type =
    bool;
  _is_planned_type is_planned;

  // setters for named parameter idiom
  Type & set__is_planned(
    const bool & _arg)
  {
    this->is_planned = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    open_manipulator_msgs::srv::SetKinematicsPose_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const open_manipulator_msgs::srv::SetKinematicsPose_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<open_manipulator_msgs::srv::SetKinematicsPose_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<open_manipulator_msgs::srv::SetKinematicsPose_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      open_manipulator_msgs::srv::SetKinematicsPose_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<open_manipulator_msgs::srv::SetKinematicsPose_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      open_manipulator_msgs::srv::SetKinematicsPose_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<open_manipulator_msgs::srv::SetKinematicsPose_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<open_manipulator_msgs::srv::SetKinematicsPose_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<open_manipulator_msgs::srv::SetKinematicsPose_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__open_manipulator_msgs__srv__SetKinematicsPose_Response
    std::shared_ptr<open_manipulator_msgs::srv::SetKinematicsPose_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__open_manipulator_msgs__srv__SetKinematicsPose_Response
    std::shared_ptr<open_manipulator_msgs::srv::SetKinematicsPose_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetKinematicsPose_Response_ & other) const
  {
    if (this->is_planned != other.is_planned) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetKinematicsPose_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetKinematicsPose_Response_

// alias to use template instance with default allocator
using SetKinematicsPose_Response =
  open_manipulator_msgs::srv::SetKinematicsPose_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace open_manipulator_msgs

namespace open_manipulator_msgs
{

namespace srv
{

struct SetKinematicsPose
{
  using Request = open_manipulator_msgs::srv::SetKinematicsPose_Request;
  using Response = open_manipulator_msgs::srv::SetKinematicsPose_Response;
};

}  // namespace srv

}  // namespace open_manipulator_msgs

#endif  // OPEN_MANIPULATOR_MSGS__SRV__DETAIL__SET_KINEMATICS_POSE__STRUCT_HPP_
