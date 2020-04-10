#include "ros/ros.h"
#include "nav_msgs/Odometry.h"

#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

class Move{

	public:
		geometry_msgs::Twist vel;
		ros::Publisher pub;
		Move(ros::Publisher p){
			pub = p;
		}	

		void publish_vel(){
			pub.publish(vel);
		 }
	    void forward(){      
			vel.linear.x=1;
			vel.angular.z=0.0;
	    }
	    void backward(){     
	        vel.linear.x=-1;
	        vel.angular.z=0.0;
	    }
	    void rotate(){
	    	vel.linear.x = 0;
	    	vel.angular.z = 10;
	    }
	    void stop(){    
	        vel.linear.x=0;
	        vel.angular.z=0.0 ;
	    }
};

// void OdomCallback(const nav_msgs::Odometry::ConstPtr &msg){
// 	double x = msg->pose.pose.position.x;
// 	double y = msg->pose.pose.position.y;
// 	ROS_INFO("x : %f, y: %f",x, y);
// }

int main(int argc, char** argv){

	// ros::init(argc, argv, "go");
	// ros::NodeHandle nh;

	// //ros::Subscriber sub = nh.subscribe("odom", 10, OdomCallback);
	// ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 100);
	ros::init(argc, argv, "go");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 100);

	Move move_(pub);
	ros::Rate loop_rate(1);

	while(ros::ok()){
		int n = 0;
		cin >> n;

		switch(n){
			case 1:
			move_.forward();
			break;

			case 2:
			move_.backward();
			break;

			case 3:
			move_.stop();
			break;

			case 4:
			move_.rotate();
			break;
		}

		move_.publish_vel();
		loop_rate.sleep();
	}
	ros::spin();
	return 0;
}