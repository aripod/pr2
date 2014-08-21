#include "acpr2_r_arm.h"

#include "pr2_r_arm_c_types.h"


/* --- Task display ----------------------------------------------------- */


/** Codel InitModule of task display.
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


/* --- Activity DispData ------------------------------------------------ */

/** Codel dpStart of activity DispData.
 *
 * Triggered by pr2_r_arm_start.
 * Yields to pr2_r_arm_start.
 */
genom_event
dpStart(const pr2_r_arm_State *State, pr2_r_arm_ids *ids,
        genom_context self)
{
    int i;

    State->read(self);
    if(State->data(self)!=NULL)
    {
        ids->currentTime._secs = State->data(self)->header.stamp._secs;
        ids->currentTime._nsecs = State->data(self)->header.stamp._nsecs;
        //printf("State: secs: %lu\tnsecs: %lu\n", ids->currentTime._secs, ids->currentTime._nsecs);
    }
    else
        //printf("State: No data available\n");

    return pr2_r_arm_start;
}
