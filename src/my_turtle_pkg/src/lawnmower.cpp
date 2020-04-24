#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <iostream>
#include <math.h>
using namespace std;

ros::Publisher velocity_publisher;

ros::Subscriber pose_subscriber;
ros::Subscriber destination_sub;

double turtlesim_pose_x, turtlesim_pose_y, turtlesim_pose_theta;
double target_pose_x, target_pose_y;

ros::Rate loop_rate(10);

const double PI = 3.14159265359;

geometry_msgs::Twist vel_msg;

double getDistance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void poseCallback(const turtlesim::Pose::ConstPtr &pose_message)
{
    turtlesim_pose_x = pose_message->x;
    turtlesim_pose_y = pose_message->y;
    turtlesim_pose_theta = pose_message->theta;
}

int main(int argc, char **argv)
{

    ros::init(argc, argv, "turtlesim_cleaner");
    ros::NodeHandle n;

    double speed, angular_speed;
    double distance, angle;
    bool isForward, clockwise;

    velocity_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    pose_subscriber = n.subscribe("/turtle1/pose", 10, poseCallback);
    loop_rate.sleep();
    
    while(ros::ok()){
        loop_rate.sleep();
    	distance = getDistance(turtlesim_pose_x, turtlesim_pose_y, target_pose_x, target_pose_y);
        cout << turtlesim_pose_x;
    }

    ros::spin();

    return 0;
}