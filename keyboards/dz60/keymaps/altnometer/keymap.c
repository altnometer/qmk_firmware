#include "dz60.h"

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define _______ KC_TRNS
#define XXXXXXX KC_NO
// Layers Declarations.
enum layers {
     _QWERTY = 0
    ,_BEAKL
    ,NUMER
    ,SYMBL
    ,NAVIG
    ,MOUSE
};
enum planck_keycodes {
   QWERTY = SAFE_RANGE
  ,BEAKL
  ,MY_COMM
  ,MY_DOT
  ,MY_QUOT
  ,BACKLT
  ,HOME_RP   // pseudo CTL_T(S(KC_0))
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

#define L_SYM1 LT(SYMBL, KC_1)
#define L_SYM0 LT(SYMBL, KC_0)
#define L_SYMF LT(SYMBL, KC_F)
#define L_SYMJ LT(SYMBL, KC_J)
#define L_SYMS LT(SYMBL, KC_S)
#define L_SYMA LT(SYMBL, KC_A)

/* #define OS_NUM OSL(NUMER) */
#define T_NUMER TT(NUMER)
#define T_MOUSE TT(MOUSE)

// Modifier Switching.
#define  MSFT_D MT(MOD_LSFT, KC_D)
#define  MSFT_K MT(MOD_RSFT, KC_K)
#define  MSFT_E MT(MOD_LSFT, KC_E)
#define  MSFT_R  MT(MOD_LSFT, KC_R)  // LSFT as MY_QUOT is scripted to use it.

#define  MALT_A MT(MOD_LALT, KC_A)
#define  MALT_Y MT(MOD_LALT, KC_Y)
#define  MALT_SC MT(MOD_RALT, KC_SCLN)
#define  MALT_W MT(MOD_RALT, KC_W)


#define  MCTL_L MT(MOD_RCTL, KC_L)
#define  MCTL_T MT(MOD_RCTL, KC_T)
#define  MCTL_I MT(MOD_RCTL, KC_I)
#define  MCTL_S MT(MOD_LCTL, KC_S)
#define  HOME_LB MT(MOD_LCTL, KC_LBRC)

#define  MCTL_7 MT(MOD_RCTL, KC_7)
#define  MCTL_3 MT(MOD_RCTL, KC_3)

// One shot modifiers.
#define OS_LGUI OSM(MOD_LGUI)

// Key code abbreviations.
#define  KC_RGHT KC_RIGHT
#define  KC_PGDN KC_PGDOWN

#include "keycode_functions.h"
/* #include "tapdance.h" */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

        /* _QWERTY
        * ,-----------------------------------------------------------------------------------------.
        * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bspc    |
        * |-----------------------------------------------------------------------------------------+
        * | Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \    |
        * |-----------------------------------------------------------------------------------------+
        * |  FN2    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
        * |-----------------------------------------------------------------------------------------+
        * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |     Shift       |
        * |-----------------------------------------------------------------------------------------+
        * |  Alt  | Ctrl |  GUI |             Space                 | Ctrl | Alt  | FN3 |     |     |
        * `-----------------------------------------------------------------------------------------'
        */
	[_QWERTY] = LAYOUT(
		KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , XXXXXXX, KC_BSPC,
		KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
		T_NUMER, MALT_A , MCTL_S , MSFT_D , L_SYMF , KC_G   , KC_H   , L_SYMJ , MSFT_K , MCTL_L , MALT_SC, T_NUMER, T_NUMER,
		KC_LSFT, XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, XXXXXXX,
		KC_LALT, KC_LCTL, OS_LGUI, L_NAVSP, L_NAVSP, L_NAVSP, OS_LGUI, T_MOUSE, XXXXXXX, T_MOUSE, XXXXXXX),
        /* BEAKL10
        * custom shift symbols:
        * / -> ?
        * ' -> `
        * , -> !
        * ,-----------------------------------------------------------------------------------------.
        * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bspc    |
        * |-----------------------------------------------------------------------------------------+
        * | Tab   |  Q  |  H  |  O  |  U  |  X  |  G  |  D  |  N  |  M  |  V  |  [  |  ]  |    \    |
        * |-----------------------------------------------------------------------------------------+
        * |  FN2    |  Y  |  I  |  E  |  A  |  .  |  C  |  S  |  R  |  T  |  W  | NUM |    Enter    |
        * |-----------------------------------------------------------------------------------------+
        * | Shift     |  J  | / ? | ' ` | , ! |  Z  |  B  |  P  |  L  |  F  |  K  |     Shift       |
        * |-----------------------------------------------------------------------------------------+
        * |  Alt  | Ctrl |  GUI |             Space                 | Ctrl | Alt  | FN3 |     |     |
        * `-----------------------------------------------------------------------------------------'
        */
	[_BEAKL] = LAYOUT(
		KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , XXXXXXX, KC_BSPC,
		KC_TAB , KC_Q   , KC_H   , KC_O   , KC_U   , KC_X   , KC_G   , KC_D   , KC_N   , KC_M   , KC_V   , KC_LBRC, KC_RBRC, KC_BSLS,
		T_NUMER, MALT_Y , MCTL_I , MSFT_E , L_SYMA , MY_DOT , KC_C   , L_SYMS , MSFT_R , MCTL_T , MALT_W , T_NUMER, KC_ENT ,
		KC_LSFT, XXXXXXX, KC_J   , KC_SLSH, MY_QUOT, MY_COMM, KC_Z   , KC_B   , KC_P   , KC_L   , KC_F   , KC_K   , KC_RSFT, XXXXXXX,
		KC_LALT, KC_LCTL, OS_LGUI, L_NAVSP, L_NAVSP, L_NAVSP, OS_LGUI, T_MOUSE, XXXXXXX, T_MOUSE, XXXXXXX),

        /* NUMER
        * ,-----------------------------------------------------------------------------------------.
        * |       |     |  5  |  =  |  4  |     |     |  *  |  8  |  9  |     |     |     |         |
        * |-----------------------------------------------------------------------------------------+
        * |         |     |  3  |  2  |  1  |  .  |  ;  |  0  |  6  |  7  |     |     |             |
        * |-----------------------------------------------------------------------------------------+
        * |           |     |  /  |  '  |  ,  |     |  +  |  -  |  \  |  :  |     |                 |
        * |-----------------------------------------------------------------------------------------+
        * |       |      |      |              Spc                  |      |      |     |     |     |
        * `-----------------------------------------------------------------------------------------'
        */
	[NUMER] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, KC_5   , KC_EQL , KC_4   , _______, _______, KC_ASTR, KC_8   , KC_9   , _______, _______, _______, _______,
		_______, KC_LALT, MCTL_3 , KC_2   , L_SYM1 , KC_DOT , KC_SCLN, L_SYM0 , KC_6   , MCTL_7 , KC_LALT, _______, _______,
		_______, XXXXXXX, _______, KC_SLSH, KC_QUOT, KC_COMM, _______, KC_PLUS, KC_MINS, KC_BSLS, KC_COLN, _______, _______, _______,
		_______, _______, _______, L_NAVSP, L_NAVSP, L_NAVSP, _______, _______, _______, _______, _______),
        /* SYMBL
        * ,-----------------------------------------------------------------------------------------.
        * |       |     |  <  |  =  |  >  |  ~  |     |  {  |  ^  |  }  |     |     |     |         |
        * |-----------------------------------------------------------------------------------------+
        * |         |  @  |  [  |  "  |  ]  |  #  |  ;  |  (  |  $  |  )  |  %  |     |             |
        * |-----------------------------------------------------------------------------------------+
        * |           |     |  ?  |  `  |  !  |  &  |  +  |  _  |  |  |  :  |     |                 |
        * |-----------------------------------------------------------------------------------------+
        * |       |      |      |              Spc                  |      |      |     |     |     |
        * `-----------------------------------------------------------------------------------------'
        */
	[SYMBL] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, KC_LT  , KC_EQL , KC_GT  , KC_TILD, _______, KC_LCBR, KC_CIRC, KC_RCBR, _______, _______, _______, _______,
		_______, KC_AT  , HOME_LB, KC_DQT , KC_RBRC, KC_HASH, KC_SCLN, KC_LPRN, KC_DLR , HOME_RP, KC_PERC, _______, _______,
		_______, XXXXXXX, _______, KC_QUES, KC_GRV , KC_EXLM, KC_AMPR, KC_PLUS, KC_UNDS, KC_PIPE, KC_COLN, _______, _______, _______,
		_______, _______, _______, L_NAVSP, L_NAVSP, L_NAVSP, _______, _______, _______, _______, _______),
	[NAVIG] = LAYOUT(
		_______, _______, _______, _______, RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, QWERTY , BEAKL  , _______, _______, _______, _______, KC_HOME, KC_END , _______, _______, RGB_M_P, RGB_TOG,
		_______, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______, _______,
		_______, XXXXXXX, _______, _______, KC_CAPS, KC_ENT , KC_BSPC, KC_BSPC, KC_ENT , KC_PGUP, KC_PGDN, _______, _______, _______,
		_______, _______, _______, KC_SPC , KC_SPC , KC_SPC , _______, _______, _______, _______, _______),

	[MOUSE] = LAYOUT(
		_______, M(1)   , M(2)   , M(3)   , M(4)   , M(5)   , M(6)   , M(7)   , M(8)   , M(9)   , M(10)   , M(11) , M(12)  , _______, _______,
		_______, _______, MS_UP  , MS_BTN1, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, MS_LEFT, MS_DOWN, MS_RGHT, MS_BTN2, _______, _______, KC_ACL2, KC_ACL1, KC_ACL0, _______, _______, _______,
		_______, XXXXXXX, _______, _______, T_MOUSE, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
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

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        DDRB |= (1 << 2); PORTB &= ~(1 << 2);
    } else {
        DDRB &= ~(1 << 2); PORTB &= ~(1 << 2);
    }
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        rgblight_enable();
        rgblight_setrgb (0xFF,  0x00, 0x00);
    } else {
        /* rgblight_disable(); */
    }
}

bool has_layer_changed = true;

/* void matrix_scan_user(void) { */
/*   uint8_t layer = biton32(layer_state); */
/*   static uint8_t old_layer = 0; */

/*   if (old_layer != layer) { */
/*     has_layer_changed = true; */
/*     old_layer = layer; */
/*   } */

/*   if (has_layer_changed) { */
/*     has_layer_changed = false; */

/*     switch (layer) { */
/*       case NUMER: */
/*         rgblight_enable(); */
/*         rgblight_sethsv (120,255,255); // green */
/*       break; */
/*       case MOUSE: */
/*         rgblight_enable(); */
/*         rgblight_sethsv (0,255,255); // red */
/*       break; */
/*       default: */
/*         rgblight_disable(); */
/*       break; */
/*     } */
/*   } */
/*   if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) { */
/*     rgblight_enable(); */
/*     rgblight_sethsv (240,255,255); // blue */
/*   } */
/* }; */

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    /* case _QWERTY: */
    /*     rgblight_enable(); */
    /*     rgblight_setrgb (0x00,  0x00, 0xFF); */
    /*     break; */
    case _BEAKL:
        rgblight_enable();
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    case NUMER:
        rgblight_enable();
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    case MOUSE:
        rgblight_enable();
        rgblight_setrgb (0x7A,  0x00, 0xFF);
        break;
    default: //  for any other layers, or the default layer
        rgblight_disable();
        /* rgblight_setrgb (0x00,  0xFF, 0xFF); */
        break;
    }
  return state;
}

/* uint32_t layer_state_set_user(uint32_t state) { */
/*   return update_tri_layer_state(state, NUMER, SYMBL, _ADJUST); */
/* } */
#define SHIFT_MODS  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
static uint8_t shift_on;  // shift and comma pressed
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BEAKL:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BEAKL);
      }
      return false;
      break;
    case BACKLT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        PORTE &= ~(1<<6);
      } else {
        unregister_code(KC_RSFT);
        PORTE |= (1<<6);
      }
      return false;
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
          register_code(KC_1);  // for shifted KC_EXCL
        } else {
          register_code(KC_COMM);
        }
      } else {
        if (shift_on) {
          unregister_code(KC_1);  // for shifted KC_EXCL
        } else {
          unregister_code(KC_COMM);
        }
      }
      break;
    case HOME_RP:
      // CTL_T(S(KC_0))
      mt_shift(record, KC_LCTL, 0, KC_0);
      break;
  }
  return true;
}
