/* Copyright 2019 altnometer
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "keycode_functions.h"

// Define the tap-hold delay here, otherwise it defaults to 200 ms
#define TAP_HOLD_DELAY 170
#include "process_tap_hold.h"

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define _______ KC_TRNS
#define XXXXXXX KC_NO
// Layers Declarations.
enum layers {
     _QWERTY = 0
    ,_BEAKL
    ,SYMBL
    ,NUMER
    ,FLAYER
    ,BAREBKL
    ,BARESBL
    ,NAVIG
    ,I3WM
    ,TMUX
    ,MOUSE
};

enum planck_keycodes {
   QWERTY = SAFE_RANGE
  ,BEAKL
  ,MY_COMM
  ,MY_MINS
  ,MY_DOT
  ,MY_QUOT
  ,BACKLT
  ,HOMELPN
  ,HOMERPN
  ,HOMEDLR
  ,I3_ESC
  ,TMX_INS
  /* ,HOME_AT */
  /* ,HOME_PR */
  ,_QK_TAP_HOLD // Has to be the last element
};

// Place this below the custom keycodes
uint16_t QK_TAP_HOLD = _QK_TAP_HOLD;
#define TH(n) (_QK_TAP_HOLD + n)

// This is where you place you tap-hold actions
// You can use the macros:
// ACTION_TAP_HOLD_SHIFT(KC_TAP, KC_HOLD, KC_TAP_SHIFT, KC_HOLD_SHIFT)
// and ACTION_TAP_HOLD(KC_TAP, KC_HOLD)
tap_hold_action_t tap_hold_actions[] = {
  [0] = ACTION_TAP_HOLD_SHIFT(KC_MENU, KC_HELP, KC_STOP, KC_FIND),
  [1] = ACTION_TAP_HOLD(KC_A, KC_1),
  [2] = ACTION_TAP_HOLD(KC_B, KC_2)
};

// Mouse Declarations.
#define MS_LEFT KC_MS_LEFT
#define MS_RGHT KC_MS_RIGHT
#define MS_UP KC_MS_UP
#define MS_DOWN KC_MS_DOWN
#define MS_BTN1 KC_MS_BTN1
#define MS_BTN2 KC_MS_BTN2
#define MS_ACCEL1 KC_MS_ACCEL1

// Layer Switching.
#define L_NAVSP LT(NAVIG, KC_SPC)
#define L_NAVBS LT(NAVIG, KC_BSPC)
#define L_NAVTB LT(NAVIG, KC_TAB)

#define L_SYM1 LT(SYMBL, KC_1)
#define L_SYM0 LT(SYMBL, KC_0)
#define L_SYMS LT(SYMBL, KC_S)
#define L_SYMA LT(SYMBL, KC_A)
#define L_SYMSP LT(SYMBL, KC_SPC)
#define L_BSMSP LT(BARESBL, KC_SPC)

#define L_NUMTB LT(NUMER, KC_TAB)
#define L_NUMEN LT(NUMER, KC_ENT)
#define L_NUM_Y LT(NUMER, KC_Y)
#define L_NUM_W LT(NUMER, KC_W)

#define L_FLRTB LT(FLAYER, KC_TAB)

#define  L_BKLBS  LT(BAREBKL, KC_BSPC)
#define  L_NUMSP  LT(NUMER, KC_SPC)

/* #define OS_NUM OSL(NUMER) */
#define T_MOUSE TT(MOUSE)

// Modifier Switching.
#define  MSFT_E MT(MOD_LSFT, KC_E)
#define  MSFT_R  MT(MOD_LSFT, KC_R)  // LSFT for keys implementing custom shift values.
#define  MSFT_EN  MT(MOD_LSFT, KC_ENT)  // LSFT for keys implementing custom shift values.
#define  MSFT_ES MT(MOD_LSFT, KC_ESC)  // LSFT for keys implementing custom shift values.
#define  MSFT_UP MT(MOD_LSFT, KC_UP)

#define  MALT_A MT(MOD_LALT, KC_A)
#define  MALT_Y MT(MOD_LALT, KC_Y)
#define  MALT_I MT(MOD_LALT, KC_I)
#define  MALT_SC MT(MOD_RALT, KC_SCLN)
#define  MALT_W MT(MOD_RALT, KC_W)
#define  MALT_T MT(MOD_RALT, KC_T)


#define  MCTL_L MT(MOD_RCTL, KC_L)
#define  MCTL_T MT(MOD_RCTL, KC_T)
#define  MCTL_I MT(MOD_RCTL, KC_I)
#define  MCTL_A MT(MOD_RCTL, KC_A)
#define  MCTL_S MT(MOD_LCTL, KC_S)
// TODO: investigate why HOME_RB and } produse '}', should be nothing?
#define  HOME_LB MT(MOD_LALT, KC_LBRC)
#define  HOME_RB MT(MOD_LCTL, KC_RBRC)

#define  MCTL_0 MT(MOD_RCTL, KC_0)
#define  MSFT_6 MT(MOD_RSFT, KC_6)
#define  MALT_7 MT(MOD_RALT, KC_7)
#define  MCTL_1 MT(MOD_LCTL, KC_1)
#define  MSFT_2 MT(MOD_LSFT, KC_2)
#define  MALT_3 MT(MOD_LALT, KC_3)

#define  MGUI_ES MT(MOD_LGUI, KC_ESC)

// One shot modifiers.
#define OS_LGUI OSM(MOD_LGUI)
#define LM_I3WM LM(I3WM, MOD_LGUI)

// Key code abbreviations.
#define  KC_RGHT KC_RIGHT
#define  KC_PGDN KC_PGDOWN


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* _QWERTY
 * ,----------------------------------.             ,----------------------------------.
 * |  Q   |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |  A   |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |  Z   |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |
 * `------+------+------+------+------+             +------+------+------+------+------'
 *               | GUI  | Spc  | Tab  |             | BkSp |  Entr | Esc |
 *               `--------------------'             `--------------------'
 *                         ^      ^                     ^      ^      ^
 *                        Symb   Nav                   Shft   Num    Shft
 */
[_QWERTY] = LAYOUT(
  KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                      KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,
  MALT_A , MCTL_S , KC_D   , KC_F   , KC_G   ,                      KC_H   , KC_J   , KC_K   , MCTL_L , MALT_SC,
  KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                      KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,
                    OS_LGUI, L_SYMSP, L_NAVBS,                      L_NUMTB, MSFT_EN, MSFT_ES
),

/* _BEAKL (beakl10)
 * ,----------------------------------.             ,----------------------------------.
 * |  Q   |  H   |  O   |  U   |  X   |             |   G  |   D  |   N  |   M  |   V  |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |  Y   |  I   |  E   |  A   | .  # |             |   C  |   S  |   R  |   T  |   W  |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |  J   | /  ? | '  ` | ,  ! |  Z   |             |   B  |   P  |   L  |   F  |   K  |
 * |------+------+------+------+------+             +------+------+------+------+------'
 *               | Esc  | Spc  | BkSp |             |  Tab | Entr |  Esc |
 *               `--------------------'             `--------------------'
 *                   ^      ^      ^                    ^      ^      ^
 *                  I3     Symb   Nav                 Shft    Num    Shft
 */
 [_BEAKL] = LAYOUT(
  KC_Q   , KC_H   , KC_O   , KC_U   , KC_X   ,                   KC_G   , KC_D   , KC_N   , KC_M   , KC_V   ,
  L_NUM_Y, MALT_I , MSFT_E , MCTL_A , MY_DOT ,                   KC_C   , MCTL_S , MSFT_R , MALT_T , L_NUM_W,
  KC_J   , KC_SLSH, MY_QUOT, MY_MINS, KC_Z   ,                   KC_B   , KC_P   , KC_L   , KC_F   , KC_K   ,
                    MGUI_ES, L_SYMSP, L_NAVBS,                   L_FLRTB, L_NUMEN, TH(0)
),

};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
