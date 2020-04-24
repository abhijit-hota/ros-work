#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <iostream>
#define PI 3.14159265358979323846


using namespace std;

ros::Publisher velocity_publisher;
ros::Subscriber pose_subscriber;

turtlesim::Pose turtlesim_pose;
geometry_msgs::Twist vel_msg;

double radToDeg(double radian){
    return (radian * (180 / PI));
}

void poseCallback(const turtlesim::Pose::ConstPtr &pose_message)
{
    turtlesim_pose.x = pose_message->x;
    turtlesim_pose.y = pose_message->y;
    turtlesim_pose.theta = pose_message->theta;
}
void mow()
{
    ROS_INFO("%lf", 11 - turtlesim_pose.x);
    bool flag = (turtlesim_pose.x == 0) ? false : true;

    if (turtlesim_pose.x >= 10)
    {
        if (radToDeg(turtlesim_pose.theta) < 180)
        {
            vel_msg.linear.x = 3;
            vel_msg.angular.z = 3;
        }
    }
    else if (turtlesim_pose.x < 1)
    {
        if (turtlesim_pose.theta > 0)
        {
            vel_msg.linear.x = 3;
            vel_msg.angular.z = -3;
        }
    }
    else
    {
        vel_msg.linear.x = 3;
        vel_msg.angular.z = 0;
    }

    velocity_publisher.publish(vel_msg);
}
int main(int argc, char **argv)
{

    ros::init(argc, argv, "lawnmower");
    ros::NodeHandle n;

    ros::Rate loop_rate(30);

    velocity_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    pose_subscriber = n.subscribe("/turtle1/pose", 10, poseCallback);
    loop_rate.sleep();

    while (ros::ok())
    {
        loop_rate.sleep();
        ros::spinOnce();
        mow();
    }

    return 0;
}