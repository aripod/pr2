#include "acpr2_full.h"

#include "pr2_full_c_types.h"


/* --- Task PublishPort ------------------------------------------------- */


/** Codel InitModule of task PublishPort.
 *
 * Triggered by pr2_full_start.
 * Yields to pr2_full_ether.
 */
genom_event
InitModule(genom_context self)
{
  /* skeleton sample: insert your code */
  /* skeleton sample */ return pr2_full_ether;
}


/* --- Activity move_head ----------------------------------------------- */

/** Codel cMove_Head of activity move_head.
 *
 * Triggered by pr2_full_start.
 * Yields to pr2_full_ether.
 */
genom_event
cMove_Head(double pan, double tilt, double time_to_finish,
           const pr2_full_Port_head *Port_head, genom_context self)
{
    Port_head->data(self)->pan = pan;
    Port_head->data(self)->tilt = tilt;
    Port_head->data(self)->time_to_finish = time_to_finish;
    Port_head->write(self);    

    return pr2_full_ether;
}


/* --- Activity go_to_position ------------------------------------------ */

/** Codel cGo_To_Position of activity go_to_position.
 *
 * Triggered by pr2_full_start.
 * Yields to pr2_full_ether.
 */
genom_event
cGo_To_Position(double x, double y, double w,
                const pr2_full_Port_gotoposition *Port_gotoposition,
                genom_context self)
{
    Port_gotoposition->data(self)->x = x;
    Port_gotoposition->data(self)->y = y;
    Port_gotoposition->data(self)->w = w;
    Port_gotoposition->write(self);    
    
    return pr2_full_ether;
}


/* --- Activity move_l_arm ---------------------------------------------- */

/** Codel c_Move_Left_Arm of activity move_l_arm.
 *
 * Triggered by pr2_full_start.
 * Yields to pr2_full_ether.
 */
genom_event
c_Move_Left_Arm(double l_shoulder_pan_joint,
                double l_shoulder_lift_joint,
                double l_upper_arm_roll_joint,
                double l_elbow_flex_joint, double l_forearm_roll_joint,
                double l_wrist_flex_joint, double l_wrist_roll_joint,
                double time_to_finish,
                const pr2_full_Port_l_arm *Port_l_arm,
                genom_context self)
{
    Port_l_arm->data(self)->l_shoulder_pan_joint = l_shoulder_pan_joint;
    Port_l_arm->data(self)->l_shoulder_lift_joint = l_shoulder_lift_joint;
    Port_l_arm->data(self)->l_upper_arm_roll_joint = l_upper_arm_roll_joint;
    Port_l_arm->data(self)->l_elbow_flex_joint = l_elbow_flex_joint;
    Port_l_arm->data(self)->l_forearm_roll_joint = l_forearm_roll_joint;
    Port_l_arm->data(self)->l_wrist_flex_joint = l_wrist_flex_joint;
    Port_l_arm->data(self)->l_wrist_roll_joint = l_wrist_roll_joint;
    Port_l_arm->data(self)->time_to_finish = time_to_finish;
    Port_l_arm->write(self);    
        
    return pr2_full_ether;
}


/* --- Activity move_r_arm ---------------------------------------------- */

/** Codel c_Move_Right_Arm of activity move_r_arm.
 *
 * Triggered by pr2_full_start.
 * Yields to pr2_full_ether.
 */
genom_event
c_Move_Right_Arm(double r_shoulder_pan_joint,
                 double r_shoulder_lift_joint,
                 double r_upper_arm_roll_joint,
                 double r_elbow_flex_joint,
                 double r_forearm_roll_joint,
                 double r_wrist_flex_joint, double r_wrist_roll_joint,
                 double time_to_finish,
                 const pr2_full_Port_r_arm *Port_r_arm,
                 genom_context self)
{
    Port_r_arm->data(self)->r_shoulder_pan_joint = r_shoulder_pan_joint;
    Port_r_arm->data(self)->r_shoulder_lift_joint = r_shoulder_lift_joint;
    Port_r_arm->data(self)->r_upper_arm_roll_joint = r_upper_arm_roll_joint;
    Port_r_arm->data(self)->r_elbow_flex_joint = r_elbow_flex_joint;
    Port_r_arm->data(self)->r_forearm_roll_joint = r_forearm_roll_joint;
    Port_r_arm->data(self)->r_wrist_flex_joint = r_wrist_flex_joint;
    Port_r_arm->data(self)->r_wrist_roll_joint = r_wrist_roll_joint;
    Port_r_arm->data(self)->time_to_finish = time_to_finish;
    Port_r_arm->write(self);    

    return pr2_full_ether;
}


/* --- Activity move_torso ---------------------------------------------- */

/** Codel c_Move_Torso of activity move_torso.
 *
 * Triggered by pr2_full_start.
 * Yields to pr2_full_ether.
 * Throws pr2_full_INVALID_TORSO.
 */
genom_event
c_Move_Torso(double torso, double time_to_finish,
             const pr2_full_Port_torso *Port_torso,
             genom_context self)
{
    Port_torso->data(self)->torso = torso;
    Port_torso->data(self)->time_to_finish = time_to_finish;
    Port_torso->write(self);    
    
    return pr2_full_ether;
}
