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
                                        //  [0] = ACTION_TAP_HOLD_SHIFT(KC_MENU, KC_HELP, KC_STOP, KC_FIND),
                                        //  [0] = ACTION_TAP_HOLD_SHIFT(KC_TAB, KC_HELP, KC_STOP, KC_FIND),
  [0] = ACTION_TAP_HOLD(KC_TAB, KC_HELP),
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
#define L_NAVES LT(NAVIG, KC_ESC)
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

//#define L_FLRTB LT(FLAYER, KC_TAB)
#define L_FLRME LT(FLAYER, KC_MENU)

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
#define  MGUI_BS MT(MOD_LGUI, KC_BSPC)

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
 * `------+------+------+------+------+             +------+------+------+------+------'
 *               | Esc  | Spc  | BkSp |             |  Tab | Entr |  Esc |
 *               `--------------------'             `--------------------'
 *                   ^      ^      ^                    ^      ^      ^
 *                  I3     Symb   Nav                 Shft    Num    Shft
 */
 [_BEAKL] = LAYOUT(
  KC_Q   , KC_H   , KC_O   , KC_U   , KC_X   ,                   KC_G   , KC_D   , KC_N   , KC_M   , KC_V   ,
  KC_Y   , MALT_I , MSFT_E , MCTL_A , MY_DOT ,                   KC_C   , MCTL_S , MSFT_R , MALT_T , KC_W,
  KC_J   , KC_SLSH, MY_QUOT, MY_MINS, KC_Z   ,                   KC_B   , KC_P   , KC_L   , KC_F   , KC_K   ,
                    MGUI_BS, L_SYMSP, L_NAVES,                   L_FLRME, L_NUMEN, TH(0)
),

/* SYMBL
 * ,----------------------------------.             ,----------------------------------.
 * |      |  <   |  =   |  >   |   ~  |             |   ^  |   {  |   *  |   }  |      |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |  @   |  [   |  "   |  ]   | .  # |             |   ;  |   (  |   $  |   )  |   %  |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |  \   | /  ? | '  ` | ,  ! |   &  |             |   +  |   -  |   |  |   :  |   _  |
 * `------+------+------+------+------+             +------+------+------+------+------'
 *               |      |      |      |             | BkSp |  Spc |  Del |
 *               `--------------------'             `--------------------'
 *                                                      ^      ^
 *                                                     Bbkl   Num
 */
 [SYMBL] = LAYOUT(
  _______, KC_LT  , KC_EQL , KC_GT  , KC_TILD,                   KC_CIRC, KC_LCBR, KC_ASTR, KC_RCBR, _______,
  KC_AT  , HOME_LB, KC_DQT , HOME_RB, MY_DOT ,                   KC_SCLN, HOMELPN, HOMEDLR, HOMERPN, KC_PERC,
  KC_BSLS, KC_SLSH, MY_QUOT, MY_COMM, KC_AMPR,                   KC_PLUS, KC_MINS, KC_PIPE, KC_COLN, KC_UNDS,
                    _______, _______, _______,                   L_BKLBS, L_NUMSP, KC_DEL
),

/* NUMER
 * ,----------------------------------.             ,----------------------------------.
 * |  d   |  5   |  =   |  4   |  x   |             |      |   8  |   *  |   9  |   a  |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |  e   |  3   |  2   |  1   | .  # |             |   ;  |   0  |   6  |   7  |   b  |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |  f   | /  ? | '  ` | ,  ! |   &  |             |   +  |   -  |   |  |   :  |   c  |
 * `------+------+------+------+------+             +------+------+------+------+------'
 *               |      |      |      |             |      |      |      |
 *               `--------------------'             `--------------------'
 */
 [NUMER] = LAYOUT(
  KC_D   , KC_5   , KC_EQL , KC_4   , KC_X   ,                   _______, KC_8   , KC_ASTR, KC_9   , KC_A   ,
  KC_E   , MALT_3 , MSFT_2 , MCTL_1 , MY_DOT ,                   KC_SCLN, MCTL_0 , MSFT_6 , MALT_7 , KC_B   ,
  KC_F   , KC_SLSH, MY_QUOT, MY_COMM, KC_AMPR,                   KC_PLUS, KC_MINS, KC_PIPE, KC_COLN, KC_C   ,
                    _______, _______, L_BSMSP,                   _______, _______, _______
),

/* FLAYER
 * ,----------------------------------.             ,----------------------------------.
 * |      | F5   | F15  | F4   | F14  |             |  F18 |  F8  |  F19 |  F9  |      |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |      | F3   | F2   | F1   | F21  |             |  F23 |  F10 |  F6  |  F7  |      |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |      | F13  | F12  | F11  | F22  |             |  F24 |  F20 |  F16 |  F17 |      |
 * `------+------+------+------+------+             +------+------+------+------+------'
 *               |      |      |      |             |      |      |      |
 *               `--------------------'             `--------------------'
 */
 [FLAYER] = LAYOUT(
  _______, KC_F5  , KC_F15 , KC_F4  , KC_F14 ,                   KC_F18 , KC_F8  , KC_F19 , KC_F9  , _______,
  _______, KC_F3  , KC_F2  , KC_F1  , KC_F21 ,                   KC_F23 , KC_F10 , KC_F6  , KC_F7  , _______,
  _______, KC_F13 , KC_F12 , KC_F11 , KC_F22 ,                   KC_F24 , KC_F20 , KC_F16 , KC_F17 , _______,
                    _______, _______, _______,                   _______, _______, _______
),

 [BAREBKL] = LAYOUT(
  KC_Q   , KC_H   , KC_O   , KC_U   , KC_X   ,                   KC_G   , KC_D   , KC_N   , KC_M   , KC_V   ,
  KC_Y   , KC_I   , MSFT_E , KC_A   , KC_HASH,                   KC_C   , KC_S   , MSFT_R , KC_T   , KC_W   ,
  KC_J   , KC_QUES, KC_GRV , KC_EXLM, KC_Z   ,                   KC_B   , KC_P   , KC_L   , KC_F   , KC_K   ,
                    XXXXXXX, XXXXXXX, _______,                   _______, XXXXXXX, XXXXXXX
),

 [BARESBL] = LAYOUT(
  XXXXXXX, KC_LT  , KC_EQL , KC_GT  , KC_TILD,                   KC_CIRC, KC_LCBR, KC_ASTR, KC_RCBR, XXXXXXX,
  KC_AT  , KC_LBRC, KC_DQT , KC_RBRC, MY_DOT ,                   KC_SCLN, KC_LPRN, KC_DLR , KC_RPRN, KC_PERC,
  KC_BSLS, KC_QUES, MY_QUOT, MY_COMM, KC_AMPR,                   KC_PLUS, KC_MINS, KC_PIPE, KC_COLN, KC_UNDS,
                    XXXXXXX, XXXXXXX, _______,                   _______, XXXXXXX, XXXXXXX
),
/* NAVIG
 * ,----------------------------------.             ,----------------------------------.
 * |      |QWERTY| BEAKL|      |      |             |      |      | Home |  End |      |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |      | Alt  | Shft | Ctrl |      |             | Left | Down |  Up  | Rght |      |
 * |------+------+------+------+------+             +------+------+------+------+------|
 * |      |      |      | Caps |      |             |      |      | PGUP | PGDN |      |
 * `------+------+------+------+------+             +------+------+------+------+------'
 *               |      |      |      |             |      |      |      |
 *               `--------------------'             `--------------------'
 */
 [NAVIG] = LAYOUT(
  XXXXXXX, QWERTY , BEAKL  , XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_HOME, KC_END, XXXXXXX,
  XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_PGUP, KC_PGDN, XXXXXXX,
                    XXXXXXX, XXXXXXX, _______,                   MSFT_EN, XXXXXXX, XXXXXXX
),

};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}

bool has_layer_changed = true;

void matrix_scan_user(void) {
  matrix_scan_tap_hold(); // Place this function call here
}

#define SHIFT_MODS  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
static uint8_t shift_on;  // shift and comma pressed

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false; // skip all further processing of this key
      break;
    case BEAKL:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BEAKL);
      }
      return false; // skip all further processing of this key
      break;

  case MY_QUOT:
      if (record->event.pressed) {
        shift_on = get_mods()&SHIFT_MODS;
        if (shift_on) {
          unregister_mods(MOD_BIT(KC_LSFT));
          register_code(KC_GRV);
          register_mods(MOD_BIT(KC_LSFT));
        } else {
          register_code(KC_QUOT);
        }
      } else {
        if (shift_on) {
          unregister_code(KC_GRV);
        } else {
          unregister_code(KC_QUOT);
        }
      }
      break;

  case MY_DOT:
      if (record->event.pressed) {
        shift_on = get_mods()&SHIFT_MODS;
        if (shift_on) {
          register_code(KC_3);
        } else {
          register_code(KC_DOT);  // for shifted KC_HASH
        }
      } else {
        if (shift_on) {
          unregister_code(KC_3);  // for shifted KC_HASH
        } else {
          unregister_code(KC_DOT);
        }
      }
      break;

  case MY_COMM:
      if (record->event.pressed) {
        shift_on = get_mods()&SHIFT_MODS;
        if (shift_on) {
          register_code(KC_1);  // for shifted KC_EXLM
        } else {
          register_code(KC_COMM);
        }
      } else {
        if (shift_on) {
          unregister_code(KC_1);  // for shifted KC_EXLM
        } else {
          unregister_code(KC_COMM);
        }
      }
      break;

  case MY_MINS:
      if (record->event.pressed) {
        shift_on = get_mods()&SHIFT_MODS;
        if (shift_on) {
          register_code(KC_1);  // for shifted KC_EXLM
        } else {
          register_code(KC_MINS);
        }
      } else {
        if (shift_on) {
          unregister_code(KC_1);  // for shifted KC_EXLM
        } else {
          unregister_code(KC_MINS);
        }
      }
      break;

  case HOMELPN:
      // on press, send KC_LPRN (shifted KC_9)
      // on hold, send KC_RCTL
      mt_shift(record, KC_RCTL, 0, KC_9);
      break;

  case HOMERPN:
      // on press, send KC_RPRN (shifted KC_0)
      // on hold, send KC_RALT
      mt_shift(record, KC_RALT, 0, KC_0);
      break;

  case HOMEDLR:
      // on press, send KC_DLR (shifted KC_4)
      // on hold, send KC_RSHIFT
      mt_shift(record, KC_RSHIFT, 0, KC_4);
      break;

    /* case HOME_AT: */
    /*   // on hold raise NUMER layer, on tap send KC_AT */
    /*   lt_shift(record, KC_2, NUMER); */
    /*   break; */
    /* case HOME_PR: */
    /*   // on hold raise NUMER layer, on tap send KC_PERC */
    /*   lt_shift(record, KC_5, NUMER); */
    /*   break; */

  }
  process_record_tap_hold(keycode, record); // Place this function call here
  return true;  // let QMK send press/release events for the key
}
