#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <iostream>
#include <math.h>
using namespace std;

ros::Publisher velocity_publisher;

ros::Subscriber pose_subscriber;
ros::Subscriber destination_sub;

turtlesim::Pose turtlesim_pose;

const double PI = 3.14159265359;

geometry_msgs::Twist vel_msg;

double getDistance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void poseCallback(const turtlesim::Pose::ConstPtr &pose_message)
{
    turtlesim_pose.x = pose_message->x;
    turtlesim_pose.y = pose_message->y;
    turtlesim_pose.theta = pose_message->theta;
}
void mow(){
    ROS_INFO("%lf", 11 - turtlesim_pose.x);
    if(11 - turtlesim_pose.x > 1 ){
        vel_msg.linear.x = 5;
        vel_msg.angular.z = 0;
    } else {
        vel_msg.linear.x = 0;
        vel_msg.angular.z = 5;
    }
    velocity_publisher.publish(vel_msg);
}
int main(int argc, char **argv)
{

    ros::init(argc, argv, "lawnmower");
    ros::NodeHandle n;

    ros::Rate loop_rate(30);
    double speed, angular_speed;
    double distance, angle;
    bool isForward, clockwise;

    velocity_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    pose_subscriber = n.subscribe("/turtle1/pose", 10, poseCallback);
    loop_rate.sleep();
    
    while(ros::ok()){
        loop_rate.sleep();
    	mow();
    }

    ros::spin();

    return 0;
}