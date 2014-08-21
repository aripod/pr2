#include "acpr2_head.h"

#include "pr2_head_c_types.h"


/* --- Task PublishPort ------------------------------------------------- */


/** Codel InitModule of task PublishPort.
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


/* --- Activity Publish ------------------------------------------------- */

/** Codel pPublish of activity Publish.
 *
 * Triggered by pr2_head_start.
 * Yields to pr2_head_display.
 */
genom_event
pPublish(double pan, double tilt, double time_to_finish,
         const pr2_head_Port *Port, genom_context self)
{
    Port->data(self)->pan = pan;
    Port->data(self)->tilt = tilt;
    Port->data(self)->time_to_finish = time_to_finish;
    Port->write(self);

    return pr2_head_display;
}

/** Codel pDisplay of activity Publish.
 *
 * Triggered by pr2_head_display.
 * Yields to pr2_head_display, pr2_head_ether.
 */
genom_event
pDisplay(const pr2_head_result_pr2_head *result_pr2_head,
         genom_context self)
{
  /* skeleton sample: insert your code */
  /* skeleton sample */ return pr2_head_ether;
}
