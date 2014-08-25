#!/usr/bin/env python

import roslib; roslib.load_manifest('control_msgs')
import rospy

#Brings in the SimpleActionClient
import actionlib

from control_msgs.msg import JointTrajectoryAction, JointTrajectoryGoal
from trajectory_msgs.msg import JointTrajectoryPoint
from pr2_torso.msg import subscriber_torso


def callback(data):
    rospy.loginfo("torso=%f time_to_finish=%f",data.torso, data.time_to_finish)
    client = actionlib.SimpleActionClient("/torso_lift_controller/joint_trajectory_action", JointTrajectoryAction)
    client.wait_for_server()

    goal = JointTrajectoryGoal()
    goal.trajectory.joint_names=['torso_lift_joint']
    
    goal.trajectory.points = [
        JointTrajectoryPoint(positions=[data.torso], velocities=[0]*6, time_from_start=rospy.Duration(data.time_to_finish))]


    client.send_goal(goal)
    client.wait_for_result()

def pr2_torsoSubscriber():
    rospy.init_node('scriptpr2_torso', anonymous=True)
    rospy.Subscriber("pr2_torso/Port", subscriber_torso, callback)

    rospy.spin()

if __name__ == '__main__':
    pr2_torsoSubscriber()
