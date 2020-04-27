#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Spawn.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "my_tf_listener");

  ros::NodeHandle node;

  ros::service::waitForService("spawn");
  ros::ServiceClient add_turtle =
      node.serviceClient<turtlesim::Spawn>("spawn");
  turtlesim::Spawn srv;
  add_turtle.call(srv);

  ros::Publisher turtle_vel =
      node.advertise<geometry_msgs::Twist>("turtle2/cmd_vel", 10);

  tf::TransformListener listener;

  ros::Rate rate(10.0);
  while (node.ok())
  {
    tf::StampedTransform transform;
    try
    {
      //RELEVANT METHOD FOR PASSING THE TIMESTAMP. Time(0) means it will fetch the latest transform in the tree. Time::now() will cause an error as the transform wouldn't have been 'loaded' in the tf tree.
      listener.lookupTransform("/turtle2", "/turtle1", ros::Time(0), transform);

      //(The following is just to explain the time differences in transforms)
      //To use Time::now(), use this: waitForTransform
      // The waitForTransform() takes four arguments:
      // 1.Wait for the transform from this frame...
      // 2.... to this frame,
      // 3.at this time, and
      // 4.timeout: don't wait for longer than this maximum duration
      // ros::Time now = ros::Time::now();
      // listener.waitForTransform("/turtle2", "/turtle1",
      //                           now , ros::Duration(3));
      // listener.lookupTransform("/turtle2", "/turtle1",
      //                          now , transform);
    }
    catch (tf::TransformException &ex)
    {
      ROS_ERROR("%s", ex.what());
      ros::Duration(1.0).sleep();
      continue;
    }

    geometry_msgs::Twist vel_msg;
    vel_msg.angular.z = 4.0 * atan2(transform.getOrigin().y(),
                                    transform.getOrigin().x());
    vel_msg.linear.x = 0.5 * sqrt(pow(transform.getOrigin().x(), 2) +
                                  pow(transform.getOrigin().y(), 2));
    turtle_vel.publish(vel_msg);

    rate.sleep();
  }
  return 0;
};
