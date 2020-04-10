#!/usr/bin/env python
import rospy
from turtlesim.msg import *
from geometry_msgs.msg import Twist
from math import atan2,pi, sqrt, pow
import sys

#Subscriber callbacks
def turtle1Pose(data):
    global turtle1x, turtle1y, turtle1theta
    turtle1x = data.x
    turtle1y = data.y
    turtle1theta = data.theta

def abhiyaanPose(data):
    global abhiyaan_x, abhiyaan_y
    abhiyaan_x = data.x
    abhiyaan_y = data.y

#Get the distance between two points on a plane.
def getDistance(x1, y1, x2, y2):
    return sqrt(pow((x2-x1),2) + pow((y2-y1),2))

#Rotate the turtle1 until it faces Abhiyaan, then move towards it 
def rotateAndMove():
    global vel_msg
    targetTheta = atan2(abhiyaan_y - turtle1y, abhiyaan_x - turtle1x)
    if (targetTheta<0):
        targetTheta += 2 * pi
    if (abs(targetTheta - turtle1theta) < 0.1):
        vel_msg.linear.x = 10 #the linear velocity
        vel_msg.angular.z = 0
    else:
        vel_msg.linear.x = 0
        vel_msg.angular.z = 5 #the angular velocity
    velocity_publisher.publish(vel_msg)

#Found Abhiyaan
def finishHunt():
    global vel_msg
    vel_msg.linear.x = 0
    vel_msg.angular.z = 0
    velocity_publisher.publish(vel_msg)
    sys.exit() #from the sys library. Exits the command

def goToAbhiyaan():
    global turtle1x, turtle1y, abhiyaan_x, abhiyaan_y
    rate.sleep()

    #Main Loop
    while not rospy.is_shutdown():
        #See how far away turtle1 is from abhiyaan, if it is less than 2, then stop else continue with the method
        distance = getDistance(turtle1x, turtle1y, abhiyaan_x, abhiyaan_y)
        if (distance <= 2):
            print "Found Abhiyaan"
            finishHunt()  
        else: 
            rotateAndMove()

#Driver function. Setting up the nodes, the two subscribers : one for each turtle's position 
#and a publisher that publishes to the cmd_vel topic of turtle1

if __name__ == '__main__':
    try:
        global pub, rate, vel_msg
        rospy.init_node('turtle_exercise', anonymous=True)
        velocity_publisher = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size = 10)

        rospy.Subscriber("/turtle1/pose", Pose, turtle1Pose) #turtle1 Pose subscriber

        #Publishing rate. You may need to decrease this if you get the error "NameError: global name 'turtle1x' is not defined"
        rate = rospy.Rate(10)
        rate.sleep()

        #while (rospy.Topic.get_num_connections(self) == 0):
        #Tried to sleep() the rate untill it got connected but couldn't implement it in python 

        rospy.Subscriber("/abhiyaan/pose", Pose, abhiyaanPose) #Getting the abhiyaan's Pose
        vel_msg = Twist() #The variable we send out to publish

        goToAbhiyaan()

    except rospy.ROSInterruptException:
        pass