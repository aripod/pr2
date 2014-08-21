#include "acpr2_torso.h"

#include "pr2_torso_c_types.h"


/* --- Activity move_torso ---------------------------------------------- */

/** Validation codel controlTorso of activity move_torso.
 *
 * Returns genom_ok.
 * Throws pr2_torso_INVALID_TORSO.
 */
genom_event
controlTorso(double torso, genom_context self)
{
    if(torso<0 || torso>0.4)
        return pr2_torso_INVALID_TORSO(self);
    else 
        return genom_ok;
}
