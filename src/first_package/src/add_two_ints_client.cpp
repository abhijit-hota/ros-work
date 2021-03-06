#include "ros/ros.h"
#include "first_package/TwoInts.h"
#include <cstdlib>

int main(int argc, char** argv){

	ros::init(argc, argv, "add_two_ints_client");
	if(argc != 3){
		ROS_INFO("Usage: add_two_ints_client x y");
		return -1;
	}

	ros::NodeHandle nh;
	ros::ServiceClient client = nh.serviceClient<first_package::TwoInts>("add_two_ints");

	first_package::TwoInts srv;
	srv.request.a = atoll(argv[1]);
	srv.request.b = atoll(argv[2]);

	if(client.call(srv)){
		ROS_INFO("Sum: %ld", (long int)srv.response.sum);
	}
	else{
		ROS_INFO("Failed to call service add_two_ints");
		return -1;
	}

	return 0;
}