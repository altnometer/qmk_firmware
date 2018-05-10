/* credit to http://thedarnedestthing.com/colophon */

// Tap Dance Declarations.
enum tap_dance {
     _EIGHT = 0
    ,_TILD
};
#define TD_EIGH TD(_EIGHT)
#define TD_TILD TD(_TILD)


// Tap Dance Definitions: ~ to ~/
void tilde(qk_tap_dance_state_t *state, void *user_data)
{
  // double tap plus down: repeating keycode
  if (state->count > 2) {
    register_code(KC_LSFT);
    register_code(KC_GRV);
  }
  // tap: keycode
  else {
    shift_key(KC_GRV);
    // double tap: unix home directory
    if (state->count > 1) {
      tap_key(KC_SLSH);
    }
  }
}

void tilde_reset(qk_tap_dance_state_t *state, void *user_data)
{
  unregister_code(KC_GRV);
  unregister_code(KC_LSFT);
}

// Tap Dance Definitions.
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for 8, twice for *
     [_EIGHT]  = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_ASTR)
    ,[_TILD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tilde, tilde_reset)
};
