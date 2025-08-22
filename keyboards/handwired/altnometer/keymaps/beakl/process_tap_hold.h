/*
  Copyright 2025 The KeyGlove originator.

  You may use the content of this file as you wish.
 */

/**

   it seems that this file has no use anymore.
   it is left here just as an example of
   - custom switch matrix scan
   - custom tap-or-hold processing
     + although tap-or-hold
       did not produce desired results:
       - it unregisters the mods that
         were pressed before.

  CONSIDER REMOVING THIS FILE.
 */

#include "print.h"

#ifndef PROCESS_TAP_HOLD_H
#define PROCESS_TAP_HOLD_H

#define ctrActive() \
  (keyboard_report->mods & (MOD_BIT(KC_LEFT_CTRL) | MOD_BIT(KC_RIGHT_CTRL)))
#define shiftActive() \
  (keyboard_report->mods & (MOD_BIT(KC_LEFT_SHIFT) | MOD_BIT(KC_RIGHT_SHIFT)))
#define altActive() \
  (keyboard_report->mods & (MOD_BIT(KC_LEFT_ALT) | MOD_BIT(KC_RIGHT_ALT)))
// GUI is Super key
#define guiActive() \
  (keyboard_report->mods & (MOD_BIT(KC_LEFT_GUI) | MOD_BIT(KC_RIGHT_GUI)))

#define ACTION_TAP_HOLD_SHIFT(kc_tap, kc_tap_shift, kc_hold, kc_hold_shift) \
  { kc_tap, kc_tap_shift, kc_hold, kc_hold_shift, 0, false }
#define ACTION_TAP_HOLD(kc_tap, kc_hold) \
  ACTION_TAP_HOLD_SHIFT(kc_tap, LSFT(kc_tap), kc_hold, LSFT(kc_hold))

#ifndef TAP_HOLD_DELAY
  #define TAP_HOLD_DELAY 200
#endif

typedef struct tap_hold_action_t {
  uint16_t KC_tap;
  uint16_t KC_tap_shift;
  uint16_t KC_hold;
  uint16_t KC_hold_shift;
  uint16_t timer;
  bool timer_active;
} tap_hold_action_t;

extern tap_hold_action_t tap_hold_actions[];

// MY_TAP_HOLD_KEYCODE and MY_TAP_HOLD_KEYCODE_MAX
// are the custom kecodes used to catch keycode for processing
// tap-hold action
// they are defined in keyglove_keycodes in ./keymap.c
extern uint16_t MY_TAP_HOLD_KEYCODE;
// allow only limited (e.g., 100) such keycodes
// this is only relevant if there will be other
// keycodes defined after.
// but since I define _MY_CATCH_TAP_HOLD_KEYCODES
// as the last keycode, the limit is not really relevant
#define MY_TAP_HOLD_KEYCODE_MAX MY_TAP_HOLD_KEYCODE + 100

void process_record_tap_hold(uint16_t keycode, keyrecord_t *record);
void matrix_scan_tap_hold(void);

//=============================================//
// TODO: Put code under this line in a .c file //
//=============================================//

void selectAndSendKey(tap_hold_action_t *t, bool pressed, bool register_kc, bool unregister_kc);
void tap(uint16_t keycode, bool register_kc, bool unregister_kc);

static int8_t highest_th = -1;

void matrix_scan_tap_hold(void) {
  if (highest_th == -1) {
    return;
  }

  for (uint8_t i = 0; i <= highest_th; i++) {
    if (tap_hold_actions[i].timer_active &&
        timer_elapsed(tap_hold_actions[i].timer) >= TAP_HOLD_DELAY) {
      selectAndSendKey(&tap_hold_actions[i], true, true, false);
    }
  }
}
static uint8_t prev_mods = 0;

void tap(uint16_t keycode, bool register_kc, bool unregister_kc) {
  if (keycode == KC_NO) {
    return;
  }

  uint8_t mods = 0;

  if ((keycode & QK_RSFT) == QK_RSFT) {
    mods |= MOD_BIT(KC_RSFT);
  } else if ((keycode & QK_LSFT) == QK_LSFT) {
    mods |= MOD_BIT(KC_LSFT);
  }
  if ((keycode & QK_RCTL) == QK_RCTL) {
    mods |= MOD_BIT(KC_RCTL);
  } else if ((keycode & QK_LCTL) == QK_LCTL) {
    mods |= MOD_BIT(KC_LCTL);
  }
  if ((keycode & QK_RGUI) == QK_RGUI) {
    mods |= MOD_BIT(KC_RGUI);
  } else if ((keycode & QK_LGUI) == QK_LGUI) {
    mods |= MOD_BIT(KC_LGUI);
  }
  if ((keycode & QK_RALT) == QK_RALT) {
    mods |= MOD_BIT(KC_RALT);
  } else if ((keycode & QK_LALT) == QK_LALT) {
    mods |= MOD_BIT(KC_LALT);
  }

  if (register_kc) {

    set_mods(mods);
    send_keyboard_report();

    register_code(keycode);
  }

  if (unregister_kc) {
    unregister_code(keycode);

    set_mods(prev_mods);
    send_keyboard_report();
  }
}

void selectAndSendKey(tap_hold_action_t *t, bool key_hold, bool register_kc, bool unregister_code) {
  if (shiftActive()) {
    tap(key_hold ? t->KC_hold_shift : t->KC_tap_shift, register_kc, unregister_code);
  } else {
    tap(key_hold ? t->KC_hold : t->KC_tap, register_kc, unregister_code);
  }
  t->timer_active = false;
}

void process_record_tap_hold(uint16_t keycode, keyrecord_t *record) {

  if (MY_TAP_HOLD_KEYCODE <= keycode && keycode <= MY_TAP_HOLD_KEYCODE_MAX) {
    //uprintf(">>>>> inside process_record_tap_hold %s\n", "<<<<<<<");
    uint16_t idx = keycode - MY_TAP_HOLD_KEYCODE;
    if ((int16_t)idx > highest_th) {
      highest_th = idx;
    }
    tap_hold_action_t *t = &tap_hold_actions[idx];
    if (record->event.pressed) {
      prev_mods = get_mods();
      print("\n");
      //uprintf(">>>>>> press shift mods: %d\n", get_mods() & MOD_MASK_SHIFT);
      //uprintf(">>>>>> press ctrl mods: %d\n", get_mods() & MOD_MASK_CTRL);
      //uprintf(">>>>>> press alt mods: %d\n", get_mods() & MOD_MASK_ALT);
      //uprintf(">>>>>> press qui mods: %d\n", get_mods() & MOD_MASK_GUI);

      t->timer = timer_read();
      t->timer_active = true;
    } else {
      //uprintf(">>>>>> release shift mods: %d\n", get_mods() & MOD_MASK_SHIFT);
      //uprintf(">>>>>> release ctrl mods: %d\n", get_mods() & MOD_MASK_CTRL);
      //uprintf(">>>>>> release alt mods: %d\n", get_mods() & MOD_MASK_ALT);
      //uprintf(">>>>>> release gui mods: %d\n", get_mods() & MOD_MASK_GUI);

      if (timer_elapsed(t->timer) < TAP_HOLD_DELAY) {
        selectAndSendKey(t, false, true, true);
      } else {
        selectAndSendKey(t, true, false, true);
      }
    }
  }
}

#endif
