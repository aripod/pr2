#include "acpr2_move_base.h"

#include "pr2_move_base_c_types.h"


/* --- Task display ----------------------------------------------------- */


/** Codel InitModule of task display.
 *
 * Triggered by pr2_move_base_start.
 * Yields to pr2_move_base_ether.
 */
genom_event
InitModule(genom_context self)
{
  /* skeleton sample: insert your code */
  /* skeleton sample */ return pr2_move_base_ether;
}


/* --- Activity DispData ------------------------------------------------ */

/** Codel dpStart of activity DispData.
 *
 * Triggered by pr2_move_base_start.
 * Yields to pr2_move_base_start.
 */
genom_event
dpStart(const pr2_move_base_Odometry *Odometry, genom_context self)
{
  /* skeleton sample: insert your code */
  /* skeleton sample */ return pr2_move_base_start;
}


/* --- Activity Position ------------------------------------------------ */

/** Codel pStart of activity Position.
 *
 * Triggered by pr2_move_base_start.
 * Yields to pr2_move_base_ether.
 */
genom_event
pStart(double x, double y, double z,
       const pr2_move_base_Teleport *Teleport, genom_context self)
{
    Teleport->data(self)->linear.x = x;
    Teleport->data(self)->linear.y = y;
    Teleport->data(self)->angular.z = z;
    Teleport->write(self);    
    return pr2_move_base_ether;
}
