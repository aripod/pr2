#!/usr/bin/env python

import roslib; roslib.load_manifest('control_msgs')
import rospy

#Brings in the SimpleActionClient
import actionlib

from control_msgs.msg import JointTrajectoryAction, JointTrajectoryGoal
from trajectory_msgs.msg import JointTrajectoryPoint
from pr2_l_arm.msg import subscriber_l_arm


def callback(data):
    #rospy.loginfo("l_shoulder_pan_joint=%f l_shoulder_lift_joint=%f l_shoulder_lift_joint=%f l_shoulder_lift_joint=%f l_shoulder_lift_joint=%f l_shoulder_lift_joint=%f l_shoulder_lift_joint=%f l_shoulder_lift_joint=%f time_to_finish=%f",data.l_shoulder_pan_joint,data.l_shoulder_lift_joint, data.l_upper_arm_roll_joint, data.l_elbow_flex_joint, data.l_forearm_roll_joint, data.l_wrist_flex_joint, data.l_wrist_roll_joint, data.time_to_finish)
    client = actionlib.SimpleActionClient("/l_arm_controller/joint_trajectory_action", JointTrajectoryAction)
    client.wait_for_server()

    goal = JointTrajectoryGoal()
    goal.trajectory.joint_names.append("l_shoulder_pan_joint")
    goal.trajectory.joint_names.append("l_shoulder_lift_joint")
    goal.trajectory.joint_names.append("l_upper_arm_roll_joint")
    goal.trajectory.joint_names.append("l_elbow_flex_joint")
    goal.trajectory.joint_names.append("l_forearm_roll_joint")
    goal.trajectory.joint_names.append("l_wrist_flex_joint")
    goal.trajectory.joint_names.append("l_wrist_roll_joint")
    
    goal.trajectory.points = [
        JointTrajectoryPoint(positions=[data.l_shoulder_pan_joint,data.l_shoulder_lift_joint, data.l_upper_arm_roll_joint, data.l_elbow_flex_joint, data.l_forearm_roll_joint, data.l_wrist_flex_joint, data.l_wrist_roll_joint], velocities=[0]*7, time_from_start=rospy.Duration(data.time_to_finish))]


    client.send_goal(goal)
    client.wait_for_result()

def pr2_l_armSubscriber():
    rospy.init_node('scriptpr2_l_arm', anonymous=True)
    rospy.Subscriber("pr2_l_arm/Port", subscriber_l_arm, callback)

    rospy.spin()

if __name__ == '__main__':
    pr2_l_armSubscriber()
