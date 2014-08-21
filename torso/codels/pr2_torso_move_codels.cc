#include "acpr2_torso.h"

#include "pr2_torso_c_types.h"

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
 * Triggered by pr2_torso_start.
 * Yields to pr2_torso_ether.
 */
genom_event
InitModule(genom_context self)
{
  /* skeleton sample: insert your code */
  /* skeleton sample */ return pr2_torso_ether;
}


/* --- Activity move_torso ---------------------------------------------- */

/** Codel mtMove of activity move_torso.
 *
 * Triggered by pr2_torso_start.
 * Yields to pr2_torso_ether.
 * Throws pr2_torso_INVALID_TORSO.
 */
genom_event
mtMove(double torso, genom_context self)
{
    int i, j;
    
    // tell the action client that we want to spin a thread by default
    traj_client_ = new TrajClient("torso_lift_controller/joint_trajectory_action", true);

    // wait for action server to come up
    while(!traj_client_->waitForServer(ros::Duration(5.0))){
      ROS_INFO("Waiting for the joint_trajectory_action server");
    }

    control_msgs::JointTrajectoryGoal goal;

    // First, the joint names, which apply to all waypoints
    goal.trajectory.joint_names.push_back("torso_lift_joint");

    // We will have one waypoints in this goal trajectory
    goal.trajectory.points.resize(1);

    // First trajectory point
    // Positions
    int ind = 0;
    goal.trajectory.points[ind].positions.resize(1);
    goal.trajectory.points[ind].positions[0] = torso;

    // Velocities
    goal.trajectory.points[ind].velocities.resize(1);
    goal.trajectory.points[ind].velocities[0] = 0.0;

    // To be reached 1 second after starting along the trajectory
    goal.trajectory.points[ind].time_from_start = ros::Duration(1.0);

    goal.trajectory.header.stamp = ros::Time::now() + ros::Duration(1.0);
    traj_client_->sendGoal(goal);         

    return pr2_torso_ether;
}
