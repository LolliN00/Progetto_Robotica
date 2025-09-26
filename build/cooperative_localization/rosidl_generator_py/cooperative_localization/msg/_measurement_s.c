// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cooperative_localization:msg/Measurement.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "cooperative_localization/msg/detail/measurement__struct.h"
#include "cooperative_localization/msg/detail/measurement__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool builtin_interfaces__msg__time__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * builtin_interfaces__msg__time__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool cooperative_localization__msg__measurement__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[54];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("cooperative_localization.msg._measurement.Measurement", full_classname_dest, 53) == 0);
  }
  cooperative_localization__msg__Measurement * ros_message = _ros_message;
  {  // stamp
    PyObject * field = PyObject_GetAttrString(_pymsg, "stamp");
    if (!field) {
      return false;
    }
    if (!builtin_interfaces__msg__time__convert_from_py(field, &ros_message->stamp)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // observer_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "observer_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->observer_id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // subject_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "subject_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->subject_id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // range
    PyObject * field = PyObject_GetAttrString(_pymsg, "range");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->range = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bearing
    PyObject * field = PyObject_GetAttrString(_pymsg, "bearing");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bearing = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cooperative_localization__msg__measurement__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Measurement */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cooperative_localization.msg._measurement");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Measurement");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cooperative_localization__msg__Measurement * ros_message = (cooperative_localization__msg__Measurement *)raw_ros_message;
  {  // stamp
    PyObject * field = NULL;
    field = builtin_interfaces__msg__time__convert_to_py(&ros_message->stamp);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "stamp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // observer_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->observer_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "observer_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // subject_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->subject_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "subject_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // range
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->range);
    {
      int rc = PyObject_SetAttrString(_pymessage, "range", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bearing
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bearing);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bearing", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
