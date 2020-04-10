#include "ros/ros.h"
#include "nav_msgs/Odometry.h"

#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

class move{
	

};

void OdomCallback(const nav_msgs::Odometry::ConstPtr &msg){
	double x = msg->pose.pose.position.x;
	double y = msg->pose.pose.position.y;
	ROS_INFO("x : %f, y: %f",x, y);
}

int main(int argc, char** argv){

	ros::init(argc, argv, "goToPoint");
	ros::NodeHandle nh;

	ros::Subscriber sub = nh.subscribe("odom", 10, OdomCallback);
	ros::spin();

	return 0;
}