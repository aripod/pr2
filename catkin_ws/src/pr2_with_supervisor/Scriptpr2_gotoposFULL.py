#!/usr/bin/env python

import roslib; roslib.load_manifest('move_base_msgs')
import rospy

#Brings in the SimpleActionClient
import actionlib

from move_base_msgs.msg import MoveBaseGoal, MoveBaseAction, MoveBaseActionResult
from geometry_msgs.msg import Pose, PoseStamped, Point, Quaternion
from pr2_gotopos.msg import subscriber_position
from std_msgs.msg import String #######


def callback(data):
    rospy.loginfo("x=%f y=%f w=%f",data.x,data.y,data.w)
    client = actionlib.SimpleActionClient('move_base', MoveBaseAction)
    client.wait_for_server()
    goal = MoveBaseGoal()
    goal.target_pose.pose.position.x = data.x
    goal.target_pose.pose.position.y = data.y
    goal.target_pose.pose.orientation.w = data.w
    goal.target_pose.header.frame_id = 'map'
    client.send_goal(goal)
    pub = rospy.Publisher('result_pr2_gotopos', String)########
    pub.publish("Sending goal.")########
    client.wait_for_result()

def callback_result(data):
    rospy.loginfo("Result: %s", data.status.text)
    pub = rospy.Publisher('result_pr2_gotopos', String)########
    pub.publish("Goal reached.")########

def pr2_gotoposSubscriber():
    rospy.init_node('Scriptpr2_gotoposFULL', anonymous=True)
    rospy.Subscriber("pr2_gotopos/Port", subscriber_position, callback)
    rospy.Subscriber("move_base/result", MoveBaseActionResult, callback_result)
    pub = rospy.Publisher('result_pr2_gotopos', String)########
    
    rospy.spin()

if __name__ == '__main__':
    pr2_gotoposSubscriber()
