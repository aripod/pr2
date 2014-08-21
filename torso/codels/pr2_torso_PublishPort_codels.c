#include "acpr2_torso.h"

#include "pr2_torso_c_types.h"


/* --- Task PublishPort ------------------------------------------------- */


/** Codel InitModule of task PublishPort.
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


/* --- Activity Publish ------------------------------------------------- */

/** Codel mtMove of activity Publish.
 *
 * Triggered by pr2_torso_start.
 * Yields to pr2_torso_ether.
 * Throws pr2_torso_INVALID_TORSO.
 */
genom_event
mtMove(double torso, double time_to_finish, const pr2_torso_Port *Port,
       genom_context self)
{
    Port->data(self)->torso = torso;
    Port->data(self)->time_to_finish = time_to_finish;
    Port->write(self);

    return pr2_torso_ether;
}
