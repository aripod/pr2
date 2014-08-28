#include "acpr2_rgba.h"

#include "pr2_rgba_c_types.h"

#include <string.h>


/* --- Task ReceiveImage ------------------------------------------------ */


/** Codel InitPublishPort of task ReceiveImage.
 *
 * Triggered by pr2_rgba_start.
 * Yields to pr2_rgba_ether.
 */
genom_event
InitPublishPort(genom_context self)
{
  /* skeleton sample: insert your code */
  /* skeleton sample */ return pr2_rgba_ether;
}


/* --- Activity Receive ------------------------------------------------- */

/** Codel rReceive of activity Receive.
 *
 * Triggered by pr2_rgba_start.
 * Yields to pr2_rgba_start.
 */
genom_event
rReceive(const pr2_rgba_Image *Image, genom_context self)
{
    int i, len;
    Image->read(self);
    if(Image->data(self)!=NULL)
    {
        len = strlen(Image->data(self)->data);
        for(i=0; i<len; i++)    
            printf("%c", Image->data(self)->data[i]);
        printf("\n");
    }
    else    
        printf("No data available.\n");

    return pr2_rgba_start;
}
