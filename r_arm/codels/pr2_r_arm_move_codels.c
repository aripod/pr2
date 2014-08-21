#include "acpr2_r_arm.h"

#include "pr2_r_arm_c_types.h"


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


/* --- Activity Publish ------------------------------------------------- */

/** Codel mraMove of activity Publish.
 *
 * Triggered by pr2_r_arm_start.
 * Yields to pr2_r_arm_ether.
 */
genom_event
mraMove(double r_shoulder_pan_joint, double r_shoulder_lift_joint,
        double r_upper_arm_roll_joint, double r_elbow_flex_joint,
        double r_forearm_roll_joint, double r_wrist_flex_joint,
        double r_wrist_roll_joint, double time_to_finish,
        const pr2_r_arm_Port *Port, genom_context self)
{
    Port->data(self)->r_shoulder_pan_joint = r_shoulder_pan_joint;
    Port->data(self)->r_shoulder_lift_joint = r_shoulder_lift_joint;
    Port->data(self)->r_upper_arm_roll_joint = r_upper_arm_roll_joint;
    Port->data(self)->r_elbow_flex_joint = r_elbow_flex_joint;
    Port->data(self)->r_forearm_roll_joint = r_forearm_roll_joint;
    Port->data(self)->r_wrist_flex_joint = r_wrist_flex_joint;
    Port->data(self)->r_wrist_roll_joint = r_wrist_roll_joint;
    Port->data(self)->time_to_finish = time_to_finish;
    Port->write(self);

    return pr2_r_arm_ether;
}
