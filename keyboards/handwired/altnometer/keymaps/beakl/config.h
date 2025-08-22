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
// tap-or-hold decision modes
// see https://docs.qmk.fm/tap_hold#tap-or-hold-decision-modes
// 1. default
// 2. PERMISSIVE_HOLD
// 3. HOLD_ON_OTHER_KEY_PRESS
#define PERMISSIVE_HOLD

// https://docs.qmk.fm/tap_hold#hold-on-other-key-press
// rather than defining HOLD_ON_OTHER_KEY_PRESS for all keys
// define HOLD_ON_OTHER_KEY_PRESS just for specific keycodes.
// specify these keycodes in function
// get_hold_on_other_key_press defined in keymap.c
// this is useful for dual-role key that never is used it
// typing usual sequences, e.g., KC_TAB plus some mode key because
// KC_TAB is not used in typing any sequence of characters
// (in contrast to 'ing', 'tion', 'qui', etc)
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

/* https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#tapping-force-hold */
/* #define TAPPING_FORCE_HOLD */

/* https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#retro-tapping */
/* #define RETRO_TAPPING */

// debugging only: output the frequency of switch matrix scan
//#define DEBUG_MATRIX_SCAN_RATE
// currently about 1100 scans per second?
#endif
