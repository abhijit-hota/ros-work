#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Spawn.h>

int main(int argc, char **argv)
{

    ros::init(argc, argv, "abhiyaan_tf_listener");
    ros::NodeHandle nh;

    ros::service::waitForService("spawn");
    ros::ServiceClient add_turtle = nh.serviceClient<turtlesim::Spawn>("spawn");
    turtlesim::Spawn::Request req;
    turtlesim::Spawn::Response res;

    req.x = 10;
    req.y = 10;
    req.theta = 0;
    req.name = "abhiyaan";

    add_turtle.call(req, res);

    ros::Publisher turtle_vel =
        nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);

    tf::TransformListener listener;

    ros::Rate rate(10);

    while (nh.ok())
    {
        tf::StampedTransform transform;
        try
        {

            listener.lookupTransform("/turtle1", "/abhiyaan", ros::Time(0), transform);
        }
        catch (tf::TransformException &ex)
        {
            ROS_ERROR("%s", ex.what());
            ros::Duration(1).sleep();
            continue;
        }
        geometry_msgs::Twist vel_msg;
        vel_msg.angular.z = 4.0 * atan2(transform.getOrigin().y(),
                                        transform.getOrigin().x());
        vel_msg.linear.x = 0.5 * (sqrt(pow(transform.getOrigin().x(), 2) +
                                      pow(transform.getOrigin().y(), 2)) - 2);
        turtle_vel.publish(vel_msg);

        rate.sleep();
    }
    return 0;
}