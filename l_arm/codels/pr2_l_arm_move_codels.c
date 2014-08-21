#include "acpr2_l_arm.h"

#include "pr2_l_arm_c_types.h"


/* --- Task move -------------------------------------------------------- */


/** Codel InitModule of task move.
 *
 * Triggered by pr2_l_arm_start.
 * Yields to pr2_l_arm_ether.
 */
genom_event
InitModule(genom_context self)
{
  /* skeleton sample: insert your code */
  /* skeleton sample */ return pr2_l_arm_ether;
}


/* --- Activity Publish ------------------------------------------------- */

/** Codel mraMove of activity Publish.
 *
 * Triggered by pr2_l_arm_start.
 * Yields to pr2_l_arm_ether.
 */
genom_event
mraMove(double l_shoulder_pan_joint, double l_shoulder_lift_joint,
        double l_upper_arm_roll_joint, double l_elbow_flex_joint,
        double l_forearm_roll_joint, double l_wrist_flex_joint,
        double l_wrist_roll_joint, double time_to_finish,
        const pr2_l_arm_Port *Port, genom_context self)
{
    Port->data(self)->l_shoulder_pan_joint = l_shoulder_pan_joint;
    Port->data(self)->l_shoulder_lift_joint = l_shoulder_lift_joint;
    Port->data(self)->l_upper_arm_roll_joint = l_upper_arm_roll_joint;
    Port->data(self)->l_elbow_flex_joint = l_elbow_flex_joint;
    Port->data(self)->l_forearm_roll_joint = l_forearm_roll_joint;
    Port->data(self)->l_wrist_flex_joint = l_wrist_flex_joint;
    Port->data(self)->l_wrist_roll_joint = l_wrist_roll_joint;
    Port->data(self)->time_to_finish = time_to_finish;
    Port->write(self);

    Port->write(self);return pr2_l_arm_ether;
}
