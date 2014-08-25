#!/usr/bin/env python

import roslib; roslib.load_manifest('control_msgs')
import rospy

#Brings in the SimpleActionClient
import actionlib

from control_msgs.msg import JointTrajectoryAction, JointTrajectoryGoal
from trajectory_msgs.msg import JointTrajectoryPoint
from pr2_head.msg import subscriber_head


def callback(data):
    rospy.loginfo("pan=%f tilt=%f time_to_finish=%f",data.pan,data.tilt, data.time_to_finish)
    client = actionlib.SimpleActionClient("/head_controller/joint_trajectory_action", JointTrajectoryAction)
    client.wait_for_server()

    goal = JointTrajectoryGoal()
    goal.trajectory.joint_names.append("head_pan_joint")
    goal.trajectory.joint_names.append("head_tilt_joint")
    
    goal.trajectory.points = [
        JointTrajectoryPoint(positions=[-data.pan, -data.tilt], velocities=[0]*6, time_from_start=rospy.Duration(data.time_to_finish))]


    client.send_goal(goal)
    client.wait_for_result()

def pr2_headSubscriber():
    rospy.init_node('scriptpr2_head', anonymous=True)
    rospy.Subscriber("pr2_head/Port", subscriber_head, callback)

    rospy.spin()

if __name__ == '__main__':
    pr2_headSubscriber()
