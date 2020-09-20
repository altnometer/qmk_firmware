/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
*/

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 1
/* #define TAPPING_TERM 200 */
#define TAPPING_TERM 170
/* #define ONESHOT_TAP_TOGGLE 3 */
/* #define ONESHOT_LAYER_TOGGLE 3 */
/* #define ONESHOT_TIMEOUT 800 */

#define PREVENT_STUCK_MODIFIERS
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD

/* https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#tapping-force-hold */
#define TAPPING_FORCE_HOLD

/* https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#retro-tapping */
#define RETRO_TAPPING

#endif
