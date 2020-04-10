cmake_minimum_required(VERSION 2.8.3)
project(first_package)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

add_service_files(
	FILES
	TwoInts.srv
)
add_message_files(
	FILES
	Num.msg
)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker first_package_generate_messages_cpp)

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener first_package_generate_messages_cpp)

add_executable(publish_it src/publish_it.cpp)
target_link_libraries(publish_it ${catkin_LIBRARIES})
add_dependencies(publish_it first_package_generate_messages_cpp)

add_executable(listen_it src/listen_it.cpp)
target_link_libraries(listen_it ${catkin_LIBRARIES})
add_dependencies(listen_it first_package_generate_messages_cpp)

add_executable(add_two_ints_server src/add_two_ints_server.cpp)
target_link_libraries(add_two_ints_server ${catkin_LIBRARIES})
add_dependencies(add_two_ints_server first_package_gencpp)

add_executable(add_two_ints_client src/add_two_ints_client.cpp)
target_link_libraries(add_two_ints_client ${catkin_LIBRARIES})
add_dependencies(add_two_ints_client first_package_gencpp)