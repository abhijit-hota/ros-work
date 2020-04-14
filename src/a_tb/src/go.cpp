#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "sensor_msgs/LaserScan.h"

#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

void OdomCallback(const sensor_msgs::LaserScan::ConstPtr &msg){
	double front = msg->ranges[0];
	double left = msg->ranges[90];
	double right = msg->ranges[270];
	double back = msg->ranges[359];
	//ROS_INFO("front : %f, left: %f", front, left);
}

class Move{

	private:
		geometry_msgs::Twist vel;
		ros::Publisher pub;
		ros::Subscriber sub;

	public:
		Move(ros::NodeHandle nh){
			pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 100);
			sub = nh.subscribe("/scan", 7, OdomCallback);
			ros::spinOnce();
		}	

		void publish_vel(){
			pub.publish(vel);
		 }
	    void forward(){      
			vel.linear.x++;
			vel.angular.z=0.0;
	    }
	    void backward(){     
	        vel.linear.x--;
	        vel.angular.z=0.0;
	    }
	    void rotate(){
	    	vel.linear.x = 0;
	    	vel.angular.z+=3;
	    }
	    void stop(){    
	        vel.linear.x=0;
	        vel.angular.z=0;
	    }
};


int main(int argc, char** argv){

	ros::init(argc, argv, "go");
	ros::NodeHandle nh;

	Move move_(nh);
	ros::Rate loop_rate(1);

	while(ros::ok()){
		int n = 0;
		int x, y;

		cin >> x >> y;

		move_.publish_vel();
		loop_rate.sleep();
	}
	
	return 0;
}