#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <iostream>
#include <cmath>
#include <ros/topic_manager.h>

turtlesim::Pose turtle1_pose;
turtlesim::Pose follower_pose;

ros::Subscriber pose_subscriber;
ros::Subscriber destination_sub;

ros::Publisher velocity_publisher;

geometry_msgs::Twist vel_msg;

double getDistance(double x1, double y1, double x2, double y2){
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void poseCallback(const turtlesim::Pose::ConstPtr &pose_message){
    turtle1_pose.x = pose_message->x;
    turtle1_pose.y = pose_message->y;
    turtle1_pose.theta = pose_message->theta;
}

void desCallback(const turtlesim::Pose::ConstPtr &tar_message){
    follower_pose.x = tar_message->x;
    follower_pose.y = tar_message->y;
    follower_pose.theta = tar_message->theta; 
}

void follow(){
    ros::Rate loop_rate(100);

    double target_theta = atan2((turtle1_pose.y - follower_pose.y),
                                (turtle1_pose.x - follower_pose.x));

    if (target_theta < 0) target_theta += 2 * M_PI;

    if (abs(target_theta - follower_pose.theta) < 0.1){
        vel_msg.linear.x = 5;
        vel_msg.angular.z = 0;
        velocity_publisher.publish(vel_msg);

    } else {
        vel_msg.linear.x = 0;
        vel_msg.angular.z = 3;
        velocity_publisher.publish(vel_msg);
    }
    loop_rate.sleep();
}

void caught() {

    vel_msg.linear.x = 0;
    vel_msg.angular.z = 0;
    velocity_publisher.publish(vel_msg);

    // std::cout << "\n=====================" << std::endl;
    // std::cout << "\n Caught You \n";

}

void go(){

    ros::Rate loop_rate(30);
    double distance;

    while(ros::ok()){

        distance = getDistance(turtle1_pose.x, turtle1_pose.y, follower_pose.x, follower_pose.y);

        bool flag = (distance == 0) ? false : true;

        if(distance < 0.2 && flag) caught();
        else {
            ROS_INFO("turtle1 is %lf units far", distance);
            follow();
        }

        loop_rate.sleep();
        ros::spinOnce();
    }

}

int main(int argc, char **argv){

    ros::init(argc, argv, "follow");
    ros::NodeHandle nh;

    pose_subscriber = nh.subscribe("/turtle1/pose", 1, poseCallback);
    destination_sub = nh.subscribe("/turtle2/pose" , 1 , desCallback);
    velocity_publisher = nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel", 10);

    // ros::TopicManager topic_man;
    // size_t ncd = topic_man.getNumSubscriptions();
    // while(topic_man.getNumSubscriptions() < 1 && topic_man.getNumSubscribers("/turtle1/pose") < 1)
    //     ROS_INFO("%d",topic_man.getNumSubscriptions());
    //     ROS_INFO("%d",topic_man.getNumSubscribers("/turtle1/pose"));
    //     loop_rate.sleep();

    go();

    return 0;
}