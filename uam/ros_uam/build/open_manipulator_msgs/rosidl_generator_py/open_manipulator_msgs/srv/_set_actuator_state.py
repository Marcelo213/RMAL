# generated from rosidl_generator_py/resource/_idl.py.em
# with input from open_manipulator_msgs:srv/SetActuatorState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetActuatorState_Request(type):
    """Metaclass of message 'SetActuatorState_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('open_manipulator_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'open_manipulator_msgs.srv.SetActuatorState_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_actuator_state__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_actuator_state__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_actuator_state__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_actuator_state__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_actuator_state__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetActuatorState_Request(metaclass=Metaclass_SetActuatorState_Request):
    """Message class 'SetActuatorState_Request'."""

    __slots__ = [
        '_set_actuator_state',
    ]

    _fields_and_field_types = {
        'set_actuator_state': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.set_actuator_state = kwargs.get('set_actuator_state', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.set_actuator_state != other.set_actuator_state:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def set_actuator_state(self):
        """Message field 'set_actuator_state'."""
        return self._set_actuator_state

    @set_actuator_state.setter
    def set_actuator_state(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'set_actuator_state' field must be of type 'bool'"
        self._set_actuator_state = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_SetActuatorState_Response(type):
    """Metaclass of message 'SetActuatorState_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('open_manipulator_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'open_manipulator_msgs.srv.SetActuatorState_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_actuator_state__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_actuator_state__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_actuator_state__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_actuator_state__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_actuator_state__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetActuatorState_Response(metaclass=Metaclass_SetActuatorState_Response):
    """Message class 'SetActuatorState_Response'."""

    __slots__ = [
        '_is_planned',
    ]

    _fields_and_field_types = {
        'is_planned': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.is_planned = kwargs.get('is_planned', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.is_planned != other.is_planned:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def is_planned(self):
        """Message field 'is_planned'."""
        return self._is_planned

    @is_planned.setter
    def is_planned(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_planned' field must be of type 'bool'"
        self._is_planned = value


class Metaclass_SetActuatorState(type):
    """Metaclass of service 'SetActuatorState'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('open_manipulator_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'open_manipulator_msgs.srv.SetActuatorState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__set_actuator_state

            from open_manipulator_msgs.srv import _set_actuator_state
            if _set_actuator_state.Metaclass_SetActuatorState_Request._TYPE_SUPPORT is None:
                _set_actuator_state.Metaclass_SetActuatorState_Request.__import_type_support__()
            if _set_actuator_state.Metaclass_SetActuatorState_Response._TYPE_SUPPORT is None:
                _set_actuator_state.Metaclass_SetActuatorState_Response.__import_type_support__()


class SetActuatorState(metaclass=Metaclass_SetActuatorState):
    from open_manipulator_msgs.srv._set_actuator_state import SetActuatorState_Request as Request
    from open_manipulator_msgs.srv._set_actuator_state import SetActuatorState_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')