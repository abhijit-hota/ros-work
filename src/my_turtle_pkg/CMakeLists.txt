cmake_minimum_required(VERSION 2.8.3)
project(my_turtle_pkg)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  turtlesim
  tf
)
#generate_messages(DEPENDENCIES geometry_msgs)

catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

#add_executable(turtle_exercise src/turtle_exercise.cpp)
#target_link_libraries(turtle_exercise ${catkin_LIBRARIES})

add_executable(turtle_tf_broadcaster src/turtle_tf_broadcaster.cpp)
target_link_libraries(turtle_tf_broadcaster ${catkin_LIBRARIES})

add_executable(turtle_tf_listener src/turtle_tf_listener.cpp)
target_link_libraries(turtle_tf_listener ${catkin_LIBRARIES})

#add_executable(turtle_rotate_py.py src/turtle_rotate_py.py)
#target_link_libraries(turtle_rotate_py.py ${catkin_LIBRARIES})

add_executable(move_to_abhiyaan src/move_to_abhiyaan.cpp)
target_link_libraries(move_to_abhiyaan ${catkin_LIBRARIES})

add_executable(follow src/follow.cpp)
target_link_libraries(follow ${catkin_LIBRARIES})
