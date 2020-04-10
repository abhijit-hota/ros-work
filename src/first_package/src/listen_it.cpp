#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& mesg)
{
  ROS_INFO("%s", mesg->data.c_str());
}

int main(int argc, char** argv){

	ros::init(argc, argv, "listen_it");
	ros::NodeHandle nh;

	ros::Subscriber sub = nh.subscribe("welcome_message", 1000, chatterCallback);
	ros::spin();

	return 0;
}