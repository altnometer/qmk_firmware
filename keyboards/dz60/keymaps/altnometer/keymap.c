#include "dz60.h"

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define _______ KC_TRNS
#define XXXXXXX KC_NO
// Layers Declarations.
enum layers {
    _BASE = 0,
    NUMER,
    NAVIG,
    MOUSE,
    BRACE
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
#define L_NUMSP LT(NUMER, KC_SPC)
#define T_NUMER TT(NUMER)

// Modifier Switching.
#define  MLSFT_D MT(MOD_LSFT, KC_D)
#define  MRSFT_K MT(MOD_RSFT, KC_K)

#define  MLALT_F MT(MOD_LALT, KC_F)
#define  MRALT_J MT(MOD_RALT, KC_J)
#define  MLALT_1 MT(MOD_LALT, KC_1)
#define  MRALT_0 MT(MOD_RALT, KC_0)

#define  MRCTL_L MT(MOD_RCTL, KC_L)
#define  MRCTL_S MT(MOD_LCTL, KC_S)

#define  MRCTL_7 MT(MOD_RCTL, KC_7)

// One shot modifiers.
#define OS_LGUI OSM(MOD_LGUI)

// Key code abbreviations.
#define  KC_RGHT KC_RIGHT
#define  KC_PGDN KC_PGDOWN

// Tap Dance Declarations.
enum {
    TD_8_AST = 0
};
#define TD_8AST TD(TD_8_AST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

        /* Layer 0
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
	[_BASE] = LAYOUT(
		F(0)   , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , XXXXXXX, KC_BSPC,
		KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
		OS_LGUI, KC_A   , MRCTL_S, MLSFT_D, MLALT_F, KC_G   , KC_H   , MRALT_J, MRSFT_K, MRCTL_L, KC_SCLN, KC_QUOT, KC_ENT ,
		KC_LSFT, XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, XXXXXXX,
		KC_LALT, OS_LGUI, OSL(2) , L_NUMSP, L_NUMSP, L_NUMSP, T_NUMER, KC_RALT, XXXXXXX, MO(3)  , XXXXXXX),

        /* NUMER SHIFT
        * ,-----------------------------------------------------------------------------------------.
        * |       |     |     |     |     |     |     |     |  8  |  9  |     |     |     |         |
        * |-----------------------------------------------------------------------------------------+
        * |         |     |     |     |     |  #  |     |  0  |     |     |     |     |             |
        * |-----------------------------------------------------------------------------------------+
        * |           |     |  ?  |  ~  |  !  |     |     |     |     |     |     |                 |
        * |-----------------------------------------------------------------------------------------+
        * |       |      |      |              Spc                  |      |      |     |     |     |
        * `-----------------------------------------------------------------------------------------'
        */
        /* NUMER
        * ,-----------------------------------------------------------------------------------------.
        * |       |     |  5  |  4  |  =  |     |     |  *  |  8  |  9  |     |     |     |         |
        * |-----------------------------------------------------------------------------------------+
        * |         |     |  3  |  2  |  1  |  .  |  ;  |  0  |  6  |  7  |     |     |             |
        * |-----------------------------------------------------------------------------------------+
        * |           |     |  /  |  '  |  ,  |     |  +  |  -  |  \  |  :  |     |                 |
        * |-----------------------------------------------------------------------------------------+
        * |       |      |      |              Spc                  |      |      |     |     |     |
        * `-----------------------------------------------------------------------------------------'
        */
	/* [NUMER] = LAYOUT( */
	/* 	KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, KC_DEL, */
	/* 	KC_GRV , KC_LBRC, KC_UNDS, KC_MINS, KC_EQL , KC_PLUS, _______, KC_7   , TD_8AST, KC_9   , KC_DOT , _______, _______, _______, */
	/* 	_______, KC_RBRC, KC_LPRN, KC_RPRN, KC_LPRN, KC_RCBR, _______, KC_1   , KC_2   , MRCTL_3, KC_0   , _______, _______, */
	/* 	_______, XXXXXXX, KC_CIRC, KC_HASH, KC_DLR , KC_ASTR, _______, KC_ENT , KC_4   , KC_5   , KC_6   , KC_COMM, _______, _______, */
	/* 	_______, _______, KC_BSPC, _______, _______, _______, KC_BSPC, _______, _______, _______, _______), */
	[NUMER] = LAYOUT(
		KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, KC_DEL,
		KC_GRV , _______, KC_5   , KC_4   , KC_EQL , _______, _______, KC_ASTR, KC_8   , KC_9   , _______, _______, _______, _______,
		_______, _______, KC_3   , KC_2   , MLALT_1, KC_DOT , KC_SCLN, MRALT_0, KC_6   , MRCTL_7, _______, _______, _______,
		_______, XXXXXXX, _______, KC_SLSH, KC_QUOT, KC_COMM, _______, KC_PLUS, KC_MINS, KC_BSLS, KC_COLN, _______, _______, _______,
		_______, _______, KC_BSPC, KC_SPC , KC_SPC , KC_SPC , _______, _______, _______, _______, _______),
	[NAVIG] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, KC_END , KC_HOME, KC_PGUP, KC_PGDN, _______, _______, _______,
		_______, _______, KC_LCTL, KC_LSFT, KC_LALT, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, _______, _______, _______, _______, _______,
		_______, _______, _______, KC_ENT , KC_ENT , KC_ENT , _______, _______, _______, _______, _______),

	[MOUSE] = LAYOUT(
		_______, M(1)   , M(2)   , M(3)   , M(4)   , M(5)   , M(6)   , M(7)   , M(8)   , M(9)   , M(10)   , M(11) , M(12)  , _______, _______,
		_______, MS_BTN1, MS_UP  , MS_BTN2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, MS_LEFT, MS_DOWN, MS_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______, _______, _______, _______, _______, _______,
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
}

// Tap Dance Definitions.
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for 8, twice for *
  [TD_8_AST]  = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_ASTR)
// Other declarations would go here, separated by commas, if you have them
};

