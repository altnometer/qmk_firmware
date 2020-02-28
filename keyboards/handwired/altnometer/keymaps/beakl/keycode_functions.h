/* credit to http://thedarnedestthing.com/colophon */
// .......................................................... Keycode Primitives
 /* #include <print.h> */

// register simple key press
void tap_key(uint16_t keycode)
{
  register_code  (keycode);
  unregister_code(keycode);
}

void shift_key(uint16_t keycode)
{
  register_code  (KC_LSFT);
  tap_key        (keycode);
  unregister_code(KC_LSFT);
}

#define SHIFT   1
#define NOSHIFT 0

static uint16_t key_timer = 0;

bool key_press(uint8_t shift, uint16_t keycode)
{
  if(keycode) {
     if (timer_elapsed(key_timer) < TAPPING_TERM) {
        if (shift) {
          shift_key(keycode);
        }
        else {
          tap_key(keycode);
        }
        return false;
     }
  }
  return false;
}

// ALT_T, CTL_T, GUI_T, SFT_T for shifted keycodes
void mt_shift(keyrecord_t *record, uint16_t modifier, uint16_t modifier2, uint16_t keycode)
{
  if (record->event.pressed) {
    key_timer = timer_read();
    register_mods(MOD_BIT(modifier));
    if (modifier2) {
      register_mods(MOD_BIT(modifier2));
    }
  }
  else {
    unregister_mods(MOD_BIT(modifier));
    if (modifier2) {
      unregister_mods(MOD_BIT(modifier2));
    }
    if (timer_elapsed(key_timer) < TAPPING_TERM) {
      shift_key(keycode);
    }
    key_timer = 0;
  }
}

// LT for S(keycode)
void lt_shift(keyrecord_t *record, uint16_t keycode, uint8_t layer)
{
  if (record->event.pressed) {
    key_timer = timer_read();
    layer_on(layer);
  }
  else {
    layer_off(layer);
    // for shifted keycodes, hence, LT_SHIFT
    key_press(SHIFT, keycode);
    clear_mods();
    key_timer = 0;
  }
}

// activate L-ayer, activafe M-ode, send keycode if within T-APPING_TERM
void lmt(keyrecord_t *record, uint8_t layer, uint16_t modifier, uint16_t keycode)
{
  if (record->event.pressed) {
    key_timer = timer_read();
    register_code(modifier);
    layer_on(layer);
  }
  else {
    unregister_code(modifier);
    layer_off(layer);
    if (timer_elapsed(key_timer) < TAPPING_TERM) {
        tap_key(keycode);
    }
    key_timer = 0;
  }
}
