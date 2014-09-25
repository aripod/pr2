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
        printf("Timestamp:\n\tsecs: %d\n\tnsecs: %d\n", Image->data(self)->header.stamp.secs, Image->data(self)->header.stamp.nsecs);
        printf("Height: %d\nWidth: %d\nData: ", Image->data(self)->height,Image->data(self)->width);
        printf("Encoding: %s\n", Image->data(self)->encoding);
        printf("Is bigendian: %d\n", Image->data(self)->is_bigendian);
        printf("Step: %d\n", Image->data(self)->step);
        printf("Data: [ ");
        for(i=0; i<Image->data(self)->data._length;i++)
        {
            printf("%d, ", *(Image->data(self)->data._buffer+i));
        }
        printf("]\n\n");
    }
    else    
        printf("No data available.\n");

    return pr2_rgba_start;
}
