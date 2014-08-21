#include "acpr2_gotopos.h"

#include "pr2_gotopos_c_types.h"


/* --- Task PublishPort ------------------------------------------------- */


/** Codel InitPublishPort of task PublishPort.
 *
 * Triggered by pr2_gotopos_start.
 * Yields to pr2_gotopos_ether.
 */
genom_event
InitPublishPort(genom_context self)
{
  /* skeleton sample: insert your code */
  /* skeleton sample */ return pr2_gotopos_ether;
}


/* --- Activity Publish ------------------------------------------------- */

/** Codel pPublish of activity Publish.
 *
 * Triggered by pr2_gotopos_start.
 * Yields to pr2_gotopos_display.
 */
genom_event
pPublish(double x, double y, double w, const pr2_gotopos_Port *Port,
         genom_context self)
{
    Port->data(self)->x = x;
    Port->data(self)->y = y;
    Port->data(self)->w = w;
    Port->write(self);

    return pr2_gotopos_display;
}

/** Codel pDisplay of activity Publish.
 *
 * Triggered by pr2_gotopos_display.
 * Yields to pr2_gotopos_display, pr2_gotopos_ether.
 */
genom_event
pDisplay(const pr2_gotopos_result_pr2_gotopos *result_pr2_gotopos,
         genom_context self)
{
    result_pr2_gotopos->read(self);
    if(result_pr2_gotopos->data(self)!=NULL)
    {
        if(strcmp(result_pr2_gotopos->data(self)->data,"Goal reached.") != 0)
        {
            printf("%s\n", result_pr2_gotopos->data(self)->data);   
            return pr2_gotopos_display;
        }
        else
        {
            printf("%s\n", result_pr2_gotopos->data(self)->data);
            return pr2_gotopos_ether;
        }
    }
    else
    {
        printf("result_pr2_gotopos: No data available\n");
        return pr2_gotopos_ether;
    }
}
