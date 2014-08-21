#include "acpr2_r_arm.h"

#include "pr2_r_arm_c_types.h"

#include <stdio.h>
#include <stdlib.h>

#include <ros/ros.h>
#include <tf/transform_datatypes.h>
#include <actionlib/client/simple_action_client.h>
#include <control_msgs/JointTrajectoryAction.h>

static ros::NodeHandle *node;
typedef actionlib::SimpleActionClient< control_msgs::JointTrajectoryAction > TrajClient;
TrajClient* traj_client_=NULL;

/* --- Task move -------------------------------------------------------- */


/** Codel InitModule of task move.
 *
 * Triggered by pr2_r_arm_start.
 * Yields to pr2_r_arm_ether.
 */
genom_event
InitModule(genom_context self)
{
  /* skeleton sample: insert your code */
  /* skeleton sample */ return pr2_r_arm_ether;
}


/* --- Activity Move_r_arm ---------------------------------------------- */

/** Codel mraMove of activity Move_r_arm.
 *
 * Triggered by pr2_r_arm_start.
 * Yields to pr2_r_arm_ether.
 */
genom_event
mraMove(double r_shoulder_pan_joint, double r_shoulder_lift_joint,
        double r_upper_arm_roll_joint, double r_elbow_flex_joint,
        double r_forearm_roll_joint, double r_wrist_flex_joint,
        double r_wrist_roll_joint, genom_context self)
{
    int i, j;
    
    // tell the action client that we want to spin a thread by default
    traj_client_ = new TrajClient("r_arm_controller/joint_trajectory_action", true);

    // wait for action server to come up
    while(!traj_client_->waitForServer(ros::Duration(5.0))){
      ROS_INFO("Waiting for the joint_trajectory_action server");
    }

    control_msgs::JointTrajectoryGoal goal;

    // First, the joint names, which apply to all waypoints
    goal.trajectory.joint_names.push_back("r_shoulder_pan_joint");
    goal.trajectory.joint_names.push_back("r_shoulder_lift_joint");
    goal.trajectory.joint_names.push_back("r_upper_arm_roll_joint");
    goal.trajectory.joint_names.push_back("r_elbow_flex_joint");
    goal.trajectory.joint_names.push_back("r_forearm_roll_joint");
    goal.trajectory.joint_names.push_back("r_wrist_flex_joint");
    goal.trajectory.joint_names.push_back("r_wrist_roll_joint");

    // We will have one waypoints in this goal trajectory
    goal.trajectory.points.resize(1);

    // First trajectory point
    // Positions
    int ind = 0;
    goal.trajectory.points[ind].positions.resize(7);
    goal.trajectory.points[ind].positions[0] = r_shoulder_pan_joint;
    goal.trajectory.points[ind].positions[1] = r_shoulder_lift_joint;
    goal.trajectory.points[ind].positions[2] = r_upper_arm_roll_joint;
    goal.trajectory.points[ind].positions[3] = r_elbow_flex_joint;
    goal.trajectory.points[ind].positions[4] = r_forearm_roll_joint;
    goal.trajectory.points[ind].positions[5] = r_wrist_flex_joint;
    goal.trajectory.points[ind].positions[6] = r_wrist_roll_joint;
    // Velocities
    goal.trajectory.points[ind].velocities.resize(7);
    for (size_t j = 0; j < 7; ++j)
    {
      goal.trajectory.points[ind].velocities[j] = 0.0;
    }
    // To be reached 1 second after starting along the trajectory
    goal.trajectory.points[ind].time_from_start = ros::Duration(1.0);

    goal.trajectory.header.stamp = ros::Time::now() + ros::Duration(1.0);
    traj_client_->sendGoal(goal);

    return pr2_r_arm_ether;
}
