#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char** argv)
{
	//Creating a node called "publish_it" and NodeHandle nh
	ros::init(argc, argv, "publish_it");
	ros::NodeHandle nh;

	//Create a publisher that publishes on the topic "welcome_messsage"
	ros::Publisher pub = nh.advertise<std_msgs::String>("welcome_message", 1000);
	
	//Wait for subscribers to get connected
	//Had to implement this as we're relaying on one message and the time for the subscriber
	//to connect to the topic is not sufficient
	ros::Rate loop_rate(100);
	while(pub.getNumSubscribers() == 0)
    loop_rate.sleep();
	
	//publishing the message on the topic
	std_msgs::String mesg;
	mesg.data = "Welcome to Abhiyaan";
	pub.publish(mesg);
	
	ros::spinOnce();
	loop_rate.sleep();

	return 0;
}