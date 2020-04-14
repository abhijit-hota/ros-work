#include <ros/ros.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>
#include <iostream>

nav_msgs::Odometry turtlebot_pose;

void poseCallBack(const nav_msgs::Odometry::ConstPtr &msg){
    turtlebot_pose.pose.pose.position.x = msg->pose.pose.position.x;
    turtlebot_pose.pose.pose.position.y = msg->pose.pose.position.y;
    turtlebot_pose.pose.pose.orientation.w = msg->pose.pose.orientation.w;
}

int main (int argc, char** argv) 
{
    ros::init(argc, argv, "initialpose_pub");
    ros::NodeHandle nh;
    ros::Subscriber getTurtlePose = nh.subscribe("/odom", 10, poseCallBack);
    
    // while(){

    // }

    //Setting the initial position
    ros::Publisher initPosePub = nh.advertise<geometry_msgs::PoseWithCovarianceStamped>("initialpose", 2, true);
    
    ros::Time scanTime_ = ros::Time::now();   

    geometry_msgs::PoseWithCovarianceStamped initPose;

    initPose.header.stamp = scanTime_;
    initPose.header.frame_id = "map";

    //Because the bot starts at this position in the Turtlebot3 World

    initPose.pose.pose.position.x = -2.0;
    initPose.pose.pose.position.y = -0.5;
    
    // initPose.pose.pose.position.x = turtlebot_pose.pose.pose.position.x;
    // initPose.pose.pose.position.y = turtlebot_pose.pose.pose.position.y;
    initPose.pose.pose.position.z = 0;

    initPose.pose.pose.orientation.w =  1.0;

    initPosePub.publish(initPose);

    /////Publishing the goal

    ros::Publisher goalPosePub_ = nh.advertise<geometry_msgs::PoseStamped>("move_base_simple/goal", 2 , true);

    double x, y;

    geometry_msgs::PoseStamped goalPose_;

    while(ros::ok()){
        std::cin >> x >> y;

        scanTime_ = ros::Time::now();   

        goalPose_.header.stamp = scanTime_;
        goalPose_.header.frame_id = "map";
    
        goalPose_.pose.position.x = x;
        goalPose_.pose.position.y = y;
        goalPose_.pose.position.z = 0;
    
        goalPose_.pose.orientation.w = 1.0;
        
        goalPosePub_.publish(goalPose_);
    }
return 0;
}