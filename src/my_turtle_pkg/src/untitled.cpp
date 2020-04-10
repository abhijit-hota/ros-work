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
turtlesim::Pose target_pose;

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
void desCallback(const turtlesim::Pose::ConstPtr &tar_message)
{
    target_pose.x = tar_message->x;
    target_pose.y = tar_message->y;
}
void reachAbhiyaan(){

	ros::Rate loop_rate(30);
	loop_rate.sleep();

	target_pose.theta = atan(target_pose.y - turtlesim_pose.y/target_pose.x - turtlesim_pose.x);
	if(target_pose.theta < turtlesim_pose.theta) target_pose.theta += 2*PI;
	if (abs(target_pose.theta - turtlesim_pose.theta) < 0.1){
        vel_msg.linear.x = 10;
        vel_msg.angular.z = 0;
    } else {
        vel_msg.linear.x = 0;
        vel_msg.angular.z = 3;
    }
    velocity_publisher.publish(vel_msg);
}

void finishHunt(){
    vel_msg.linear.x = 0;
    vel_msg.angular.z = 0;
    velocity_publisher.publish(vel_msg);
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
    ros::Rate loop_rate(1);
    loop_rate.sleep();

    //destination_sub = n.subscribe("/abhiyaan/pose" , 10 , desCallback);
    loop_rate.sleep();
    
    while(ros::ok()){
    	distance = getDistance(turtlesim_pose.x, turtlesim_pose.y, target_pose.x, target_pose.y);
    	if(distance < 2) finishHunt();
    	else reachAbhiyaan();	
    	cout << turtlesim_pose.x << endl;
    }

    ros::spin();

    return 0;
}