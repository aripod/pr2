#!/usr/bin/env python

import roslib; #roslib.load_manifest('pr2_with_supervisor')
import rospy

#Brings in the SimpleActionClient
import actionlib

from control_msgs.msg import JointTrajectoryAction, JointTrajectoryGoal
from trajectory_msgs.msg import JointTrajectoryPoint
from pr2_head.msg import subscriber_head
from pr2_l_arm.msg import subscriber_l_arm
from pr2_r_arm.msg import subscriber_r_arm
from pr2_torso.msg import subscriber_torso
from pr2_gotopos.msg import subscriber_position


def callback_head(data):
    client = actionlib.SimpleActionClient("/head_controller/joint_trajectory_action", JointTrajectoryAction)
    client.wait_for_server()
    goal = JointTrajectoryGoal()
    goal.trajectory.joint_names.append("head_pan_joint")
    goal.trajectory.joint_names.append("head_tilt_joint")
    
    goal.trajectory.points = [
        JointTrajectoryPoint(positions=[data.pan, data.tilt], velocities=[0]*6, time_from_start=rospy.Duration(data.time_to_finish))]

    client.send_goal(goal)
    client.wait_for_result()

def callback_l_arm(data):
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

def callback_r_arm(data):
    client = actionlib.SimpleActionClient("/r_arm_controller/joint_trajectory_action", JointTrajectoryAction)
    client.wait_for_server()

    goal = JointTrajectoryGoal()
    goal.trajectory.joint_names.append("r_shoulder_pan_joint")
    goal.trajectory.joint_names.append("r_shoulder_lift_joint")
    goal.trajectory.joint_names.append("r_upper_arm_roll_joint")
    goal.trajectory.joint_names.append("r_elbow_flex_joint")
    goal.trajectory.joint_names.append("r_forearm_roll_joint")
    goal.trajectory.joint_names.append("r_wrist_flex_joint")
    goal.trajectory.joint_names.append("r_wrist_roll_joint")
    
    goal.trajectory.points = [
        JointTrajectoryPoint(positions=[data.r_shoulder_pan_joint,data.r_shoulder_lift_joint, data.r_upper_arm_roll_joint, data.r_elbow_flex_joint, data.r_forearm_roll_joint, data.r_wrist_flex_joint, data.r_wrist_roll_joint], velocities=[0]*7, time_from_start=rospy.Duration(data.time_to_finish))]


    client.send_goal(goal)
    client.wait_for_result()

def callback_torso(data):
    client = actionlib.SimpleActionClient("/torso_lift_controller/joint_trajectory_action", JointTrajectoryAction)
    client.wait_for_server()

    goal = JointTrajectoryGoal()
    goal.trajectory.joint_names=['torso_lift_joint']
    
    goal.trajectory.points = [
        JointTrajectoryPoint(positions=[data.torso], velocities=[0]*6, time_from_start=rospy.Duration(data.time_to_finish))]


    client.send_goal(goal)
    client.wait_for_result()


if __name__ == '__main__':
    rospy.init_node('scriptpr2_head', anonymous=True)
    rospy.Subscriber("pr2_full/Port_head", subscriber_head, callback_head)
    rospy.Subscriber("pr2_full/Port_l_arm", subscriber_l_arm, callback_l_arm)
    rospy.Subscriber("pr2_full/Port_r_arm", subscriber_r_arm, callback_r_arm)
    rospy.Subscriber("pr2_full/Port_torso", subscriber_torso, callback_torso)

    rospy.spin()
