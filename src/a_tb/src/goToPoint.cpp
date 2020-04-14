#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "sensor_msgs/LaserScan.h"

#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

void OdomCallback(const sensor_msgs::LaserScan::ConstPtr &msg){
	double front = msg->ranges[0];
	double left = msg->ranges[90];
	double right = msg->ranges[270];
	double back = msg->ranges[359];
	ROS_INFO("front : %f, left: %f", front, left);
}

int main(int argc, char** argv){

	ros::init(argc, argv, "goToPoint");
	ros::NodeHandle nh;

	ros::Subscriber sub = nh.subscribe("scan", 10, OdomCallback);
	ros::spin();

	return 0;
}