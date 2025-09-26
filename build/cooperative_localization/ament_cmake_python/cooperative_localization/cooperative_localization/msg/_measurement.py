# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cooperative_localization:msg/Measurement.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Measurement(type):
    """Metaclass of message 'Measurement'."""

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
            module = import_type_support('cooperative_localization')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'cooperative_localization.msg.Measurement')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__measurement
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__measurement
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__measurement
            cls._TYPE_SUPPORT = module.type_support_msg__msg__measurement
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__measurement

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Measurement(metaclass=Metaclass_Measurement):
    """Message class 'Measurement'."""

    __slots__ = [
        '_stamp',
        '_observer_id',
        '_subject_id',
        '_range',
        '_bearing',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'stamp': 'builtin_interfaces/Time',
        'observer_id': 'int32',
        'subject_id': 'int32',
        'range': 'double',
        'bearing': 'double',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())
        self.observer_id = kwargs.get('observer_id', int())
        self.subject_id = kwargs.get('subject_id', int())
        self.range = kwargs.get('range', float())
        self.bearing = kwargs.get('bearing', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
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
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.stamp != other.stamp:
            return False
        if self.observer_id != other.observer_id:
            return False
        if self.subject_id != other.subject_id:
            return False
        if self.range != other.range:
            return False
        if self.bearing != other.bearing:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if self._check_fields:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value

    @builtins.property
    def observer_id(self):
        """Message field 'observer_id'."""
        return self._observer_id

    @observer_id.setter
    def observer_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'observer_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'observer_id' field must be an integer in [-2147483648, 2147483647]"
        self._observer_id = value

    @builtins.property
    def subject_id(self):
        """Message field 'subject_id'."""
        return self._subject_id

    @subject_id.setter
    def subject_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'subject_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'subject_id' field must be an integer in [-2147483648, 2147483647]"
        self._subject_id = value

    @builtins.property  # noqa: A003
    def range(self):  # noqa: A003
        """Message field 'range'."""
        return self._range

    @range.setter  # noqa: A003
    def range(self, value):  # noqa: A003
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'range' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'range' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._range = value

    @builtins.property
    def bearing(self):
        """Message field 'bearing'."""
        return self._bearing

    @bearing.setter
    def bearing(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'bearing' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'bearing' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._bearing = value
