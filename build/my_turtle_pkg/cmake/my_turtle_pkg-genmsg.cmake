# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(WARNING "Invoking generate_messages() without having added any message or service file before.
You should either add add_message_files() and/or add_service_files() calls or remove the invocation of generate_messages().")
message(STATUS "my_turtle_pkg: 0 messages, 0 services")

set(MSG_I_FLAGS "-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(my_turtle_pkg_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_cpp(my_turtle_pkg
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_turtle_pkg
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(my_turtle_pkg_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(my_turtle_pkg_generate_messages my_turtle_pkg_generate_messages_cpp)

# add dependencies to all check dependencies targets

# target for backward compatibility
add_custom_target(my_turtle_pkg_gencpp)
add_dependencies(my_turtle_pkg_gencpp my_turtle_pkg_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS my_turtle_pkg_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_eus(my_turtle_pkg
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_turtle_pkg
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(my_turtle_pkg_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(my_turtle_pkg_generate_messages my_turtle_pkg_generate_messages_eus)

# add dependencies to all check dependencies targets

# target for backward compatibility
add_custom_target(my_turtle_pkg_geneus)
add_dependencies(my_turtle_pkg_geneus my_turtle_pkg_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS my_turtle_pkg_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_lisp(my_turtle_pkg
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_turtle_pkg
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(my_turtle_pkg_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(my_turtle_pkg_generate_messages my_turtle_pkg_generate_messages_lisp)

# add dependencies to all check dependencies targets

# target for backward compatibility
add_custom_target(my_turtle_pkg_genlisp)
add_dependencies(my_turtle_pkg_genlisp my_turtle_pkg_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS my_turtle_pkg_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_nodejs(my_turtle_pkg
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_turtle_pkg
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(my_turtle_pkg_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(my_turtle_pkg_generate_messages my_turtle_pkg_generate_messages_nodejs)

# add dependencies to all check dependencies targets

# target for backward compatibility
add_custom_target(my_turtle_pkg_gennodejs)
add_dependencies(my_turtle_pkg_gennodejs my_turtle_pkg_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS my_turtle_pkg_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services

### Generating Module File
_generate_module_py(my_turtle_pkg
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_turtle_pkg
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(my_turtle_pkg_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(my_turtle_pkg_generate_messages my_turtle_pkg_generate_messages_py)

# add dependencies to all check dependencies targets

# target for backward compatibility
add_custom_target(my_turtle_pkg_genpy)
add_dependencies(my_turtle_pkg_genpy my_turtle_pkg_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS my_turtle_pkg_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_turtle_pkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_turtle_pkg
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(my_turtle_pkg_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_turtle_pkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_turtle_pkg
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(my_turtle_pkg_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_turtle_pkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_turtle_pkg
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(my_turtle_pkg_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_turtle_pkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_turtle_pkg
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(my_turtle_pkg_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_turtle_pkg)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_turtle_pkg\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_turtle_pkg
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(my_turtle_pkg_generate_messages_py geometry_msgs_generate_messages_py)
endif()
