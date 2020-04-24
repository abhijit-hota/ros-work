#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <iostream>
#define PI 3.14159265358979323846

using namespace std;

ros::Publisher velocity_publisher;
ros::Subscriber pose_subscriber;
ros::Publisher pose_publisher;

turtlesim::Pose turtlesim_pose;
geometry_msgs::Twist vel_msg;

double init_x;

double radToDeg(double radian)
{
    return (radian * (180 / PI));
}

void poseCallback(const turtlesim::Pose::ConstPtr &pose_message)
{
    turtlesim_pose.x = pose_message->x;
    turtlesim_pose.y = pose_message->y;
    turtlesim_pose.theta = pose_message->theta;
}
void spiral()
{
    if (turtlesim_pose.theta < 0.1 && turtlesim_pose.theta > -0.1)
        vel_msg.linear.x *= 2;
    else
    {
        vel_msg.angular.z = 5;
        vel_msg.linear.x *= 1;
    }
    velocity_publisher.publish(vel_msg);
}
int main(int argc, char **argv)
{

    ros::init(argc, argv, "lawnmower");
    ros::NodeHandle n;

    ros::Rate loop_rate(1000);

    velocity_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    pose_subscriber = n.subscribe("/turtle1/pose", 10, poseCallback);
    pose_publisher = n.advertise<turtlesim::Pose>("/turtl1/pose", 100);
    
    turtlesim_pose.theta = 1;
    pose_publisher.publish(turtlesim_pose);

    while(ros::ok())
{
        spiral();
        ros::spinOnce();
    }

    return 0;
}