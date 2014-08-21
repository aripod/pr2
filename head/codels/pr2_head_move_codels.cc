#include "acpr2_head.h"

#include "pr2_head_c_types.h"

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
 * Triggered by pr2_head_start.
 * Yields to pr2_head_ether.
 */
genom_event
InitModule(genom_context self)
{
  /* skeleton sample: insert your code */
  /* skeleton sample */ return pr2_head_ether;
}


/* --- Activity move_head ----------------------------------------------- */

/** Codel mraMove of activity move_head.
 *
 * Triggered by pr2_head_start.
 * Yields to pr2_head_ether.
 */
genom_event
mraMove(double pan, double tilt, genom_context self)
{
    int j;

    // tell the action client that we want to spin a thread by default
    traj_client_ = new TrajClient("head_controller/joint_trajectory_action", true);    

    // wait for action server to come up
    while(!traj_client_->waitForServer(ros::Duration(5.0))){
      ROS_INFO("Waiting for the joint_trajectory_action server");
    }

    control_msgs::JointTrajectoryGoal goal;

    // First, the joint names, which apply to all waypoints
    goal.trajectory.joint_names.push_back("head_pan_joint");
    goal.trajectory.joint_names.push_back("head_tilt_joint");

    // We will have one waypoints in this goal trajectory
    goal.trajectory.points.resize(1);

    // Positions
    int ind = 0;
    goal.trajectory.points[ind].positions.resize(2);
    goal.trajectory.points[ind].positions[0] = -pan;    //negative values -> pans left
    goal.trajectory.points[ind].positions[1] = -tilt;   //negative values -> titls down

    // Velocities
    goal.trajectory.points[ind].velocities.resize(2);
    for (size_t j = 0; j < 2; ++j)
    {
      goal.trajectory.points[ind].velocities[j] = 0.0;
    }
    // To be reached 1 second after starting along the trajectory
    goal.trajectory.points[ind].time_from_start = ros::Duration(1.0);


    goal.trajectory.header.stamp = ros::Time::now() + ros::Duration(1.0);
    traj_client_->sendGoal(goal);

    return pr2_head_ether;
}
