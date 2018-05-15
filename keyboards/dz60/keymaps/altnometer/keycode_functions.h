/* credit to http://thedarnedestthing.com/colophon */
// .......................................................... Keycode Primitives

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
