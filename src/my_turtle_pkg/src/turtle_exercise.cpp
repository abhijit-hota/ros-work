
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>

#include <iostream>
#include <math.h>

using namespace std;

ros::Publisher velocity_publisher;
ros::Subscriber pose_subscriber;
nav_msgs::Odometry turtlesim_pose;

const double PI = 3.14159265359;

double getDistance(double x1, double y1, double x2, double y2);
void move(double speed, double distance, bool isForward)
{
    geometry_msgs::Twist vel_msg;

    if (isForward)
        vel_msg.linear.x = abs(speed);
    else
        vel_msg.linear.x = -abs(speed);
    vel_msg.linear.y = 0;
    vel_msg.linear.z = 0;

    vel_msg.angular.x = 0;
    vel_msg.angular.y = 0;
    vel_msg.angular.z = 0;

    double t0 = ros::Time::now().toSec();
    double current_distance = 0.0;
    ros::Rate loop_rate(100);
    do
    {
        velocity_publisher.publish(vel_msg);
        double t1 = ros::Time::now().toSec();
        current_distance = speed * (t1 - t0);
        ros::spinOnce();
        loop_rate.sleep();

    } while (current_distance < distance);
    vel_msg.linear.x = 0;
    velocity_publisher.publish(vel_msg);
}

void rotate(double angular_speed, double relative_angle, bool clockwise)
{

    geometry_msgs::Twist vel_msg;

    vel_msg.linear.x = 0;
    vel_msg.linear.y = 0;
    vel_msg.linear.z = 0;

    vel_msg.angular.x = 0;
    vel_msg.angular.y = 0;
    if (clockwise)
        vel_msg.angular.z = -abs(angular_speed);
    else
        vel_msg.angular.z = abs(angular_speed);

    double t0 = ros::Time::now().toSec();
    double current_angle = 0.0;
    ros::Rate loop_rate(1000);
    do
    {
        velocity_publisher.publish(vel_msg);
        double t1 = ros::Time::now().toSec();
        current_angle = angular_speed * (t1 - t0);
        ros::spinOnce();
        loop_rate.sleep();

    } while (current_angle < relative_angle);
    vel_msg.angular.z = 0;
    velocity_publisher.publish(vel_msg);
}

double degrees2radians(double angle_in_degrees)
{
    return angle_in_degrees * PI / 180.0;
}

double setDesiredOrientation(double desired_angle_radians)
{
    double relative_angle_radians = desired_angle_radians - turtlesim_pose.theta;

    bool clockwise = ((relative_angle_radians < 0) ? true : false);

    rotate(abs(relative_angle_radians), abs(relative_angle_radians), clockwise);
}

void poseCallback(const nav_msgs::Odometry::ConstPtr &pose_message)
{
    target_pose.pose.pose.position.x = pose_message->pose.pose.position.x;
    target_pose.pose.pose.position.y = pose_message->pose.pose.position.y;
    turtlesim_pose.theta = pose_message->theta;
}
// void desCallback(const nav_msgs::Odometry::ConstPtr &pose_message)
// {
//     target_pose.pose.pose.position.x = pose_message->pose.pose.position.x;
//     target_pose.pose.pose.position.y = pose_message->pose.pose.position.y;
// }

void moveGoal(nav_msgs::Odometry goal_pose, double distance_tolerance)
{

    geometry_msgs::Twist vel_msg;

    ros::Rate loop_rate(10);
    do
    {
        vel_msg.linear.x = 1.5 * getDistance(turtlesim_pose.x, turtlesim_pose.y, goal_pose.x, goal_pose.y);
        vel_msg.linear.y = 0;
        vel_msg.linear.z = 0;

        vel_msg.angular.x = 0;
        vel_msg.angular.y = 0;
        vel_msg.angular.z = 4 * (atan2(goal_pose.y - turtlesim_pose.y, goal_pose.x - turtlesim_pose.x) - turtlesim_pose.theta);

        velocity_publisher.publish(vel_msg);

        ros::spinOnce();
        loop_rate.sleep();

    } while (getDistance(turtlesim_pose.x, turtlesim_pose.y, goal_pose.x, goal_pose.y) > distance_tolerance);
    cout << "end move goal" << endl;
    vel_msg.linear.x = 0;
    vel_msg.angular.z = 0;
    velocity_publisher.publish(vel_msg);
}

double getDistance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

int main(int argc, char **argv)
{

    ros::init(argc, argv, "turtlesim_cleaner");
    ros::NodeHandle n;
    double speed, angular_speed;
    double distance, angle;
    bool isForward, clockwise;

    velocity_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
    pose_subscriber = n.subscribe("/odom", 10, poseCallback);

    while(destination_sub.getNumPublishers() == 0)
    loop_rate.sleep();

    ROS_INFO("\n\n\n ********START TESTING*********\n");
    
    nav_msgs::Odometry goal_pose;
    cin >> goal_pose.pose.pose.position.x >> goal_pose.pose.pose.position.y;
    moveGoal(goal_pose, 0.01);

    ros::spin();

    return 0;
}
