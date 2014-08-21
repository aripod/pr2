#include "acpr2_torso.h"

#include "pr2_torso_c_types.h"


/* --- Activity Publish ------------------------------------------------- */

/** Validation codel controlTorso of activity Publish.
 *
 * Returns genom_ok.
 * Throws pr2_torso_INVALID_TORSO.
 */
genom_event
controlTorso(double torso, genom_context self)
{
    if(torso<0 || torso>0.45)
        return pr2_torso_INVALID_TORSO(self);
    else
        return genom_ok;
}
