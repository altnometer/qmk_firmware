#ifndef PROCESS_TAP_HOLD_H
#define PROCESS_TAP_HOLD_H

#define shiftActive() \
  (keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)))

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

// QK_TAP_HOLD and QK_TAP_HOLD_MAX should be defined in the enum
// quantum_keycodes at qmk_firmware/quantum/quantum_keycodes.h
extern uint16_t QK_TAP_HOLD;
#define QK_TAP_HOLD_MAX QK_TAP_HOLD + 10

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
void selectAndSendKey(tap_hold_action_t *t, bool pressed, bool register_kc, bool unregister_code) {
  if (shiftActive()) {
    tap(pressed ? t->KC_hold_shift : t->KC_tap_shift, register_kc, unregister_code);
  } else {
    tap(pressed ? t->KC_hold : t->KC_tap, register_kc, unregister_code);
  }
  t->timer_active = false;
}
void process_record_tap_hold(uint16_t keycode, keyrecord_t *record) {
  if (QK_TAP_HOLD <= keycode && keycode <= QK_TAP_HOLD_MAX) {
    uint16_t idx = keycode - QK_TAP_HOLD;
    if ((int16_t)idx > highest_th) {
      highest_th = idx;
    }
    tap_hold_action_t *t = &tap_hold_actions[idx];
    if (record->event.pressed) {
      prev_mods = get_mods();
      t->timer = timer_read();
      t->timer_active = true;
    } else {
      if (timer_elapsed(t->timer) < TAP_HOLD_DELAY) {
        selectAndSendKey(t, false, true, true);
      } else {
        selectAndSendKey(t, true, false, true);
      }
    }
  }
}

#endif
