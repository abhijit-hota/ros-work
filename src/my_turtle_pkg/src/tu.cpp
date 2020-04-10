#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"

#include <iostream>
#include <math.h>

bool STOP = true;
turtlesim::Pose CurrPos;
geometry_msgs::Twist vel_msg;

void callbackCurr(const turtlesim::Pose::ConstPtr& msg)
{ 	
	CurrPos.x = msg->x;
	CurrPos.y = msg->y;
	CurrPos.theta = msg->theta;	
	return; 
}
void callbackDes(const geometry_msgs::Pose2D::ConstPtr& msg)
{	
	STOP = false;
	DesPose.x = msg->x;
	DesPose.y = msg->y;
	return; 
}

double getDistance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

CurrPos.theta findTheta()
{
	CurrPos.theta presentTheta = atan((10-CurrPos.x)/(10-CurrPos.y));
	return presentTheta;
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "turtle_exercise");
	ros::NodeHandle nh;

	ros::Subscriber CurrPos_sub = nh.subscribe("/turtle1/pose", 10, callbackCurr);
	ros::Subscriber DesPos_sub = nh.subscribe("/abhiyaan/pose", 10 , callbackDes);

	ros::Publisher move_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 100);

	Curr
	while()
	ros::spinOnce();
	ros::Rate loop_rate(1);

	while (ros::ok() && nh.ok() )										// while ros and the node are ok
	{
		ros::spinOnce();
		if (STOP == false)												// and no stop command
		{
			std::cout << "Processing...\n";
		}
		else
		{
			std::cout << "Waiting...\n" ;
		}
		loop_rate.sleep();												// sleep to maintain loop rate
	}
}