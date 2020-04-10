#include "ros/ros.h"
#include "first_package/TwoInts.h"

bool addCallback(first_package::TwoInts::Request &req,
				 first_package::TwoInts::Response &res){

	res.sum = req.a + req.b;
	ROS_INFO("Request: x = %ld, y = %ld", (long int)req.a, (long int)req.b);
	ROS_INFO("Sending back respsonse: %ld", (long int)res.sum);
	return true;
}

int main(int argc, char** argv){

	ros::init(argc, argv, "add_two_ints_server");
	ros::NodeHandle nh;

	ros::ServiceServer service = nh.advertiseService("add_two_ints", addCallback);

	ROS_INFO("Let's add some stuff!");
	ros::spin();

	return 0;

}