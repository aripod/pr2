#include "acpr2_full.h"

#include "pr2_full_c_types.h"


/* --- Task VideoCamera_RGBA -------------------------------------------- */


/** Codel InitModule of task VideoCamera_RGBA.
 *
 * Triggered by pr2_full_start.
 * Yields to pr2_full_ether.
 */
/* already defined in task PublishPort */



/* --- Activity receive_image ------------------------------------------- */

/** Codel vcRGBAReceive of activity receive_image.
 *
 * Triggered by pr2_full_start.
 * Yields to pr2_full_start.
 */
genom_event
vcRGBAReceive(const pr2_full_Image *Image, genom_context self)
{
    int i;
    unsigned long len;
    Image->read(self);
    if(Image->data(self)!=NULL)
    {
        len = Image->data(self)->data[0] + Image->data(self)->data[1]*256 + Image->data(self)->data[2]*256*256 + Image->data(self)->data[3]*256*256*256;
        /*printf("data[%d]: ", len);
        for(i=4; i< len+4; i++)
            printf("%lu ", Image->data(self)->data[i]);
        printf("\n---\n\n");*/
        printf("Lenght: %lu\n", len);
    }
    else
        printf("No data available.\n");
    return pr2_full_start;
}
