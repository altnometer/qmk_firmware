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
    ,QWERTY
    ,NAVIG
    ,MOUSE
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
#define L_BS2 LT(QWERTY, KC_2)
#define L_BS6 LT(QWERTY, KC_6)
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
#define  MSFT_E MT(MOD_LSFT, KC_E)
#define  MSFT_K MT(MOD_RSFT, KC_K)
#define  MSFT_R MT(MOD_RSFT, KC_R)

#define  MALT_A MT(MOD_LALT, KC_A)
#define  MALT_Y MT(MOD_LALT, KC_Y)
#define  MALT_SC MT(MOD_RALT, KC_SCLN)
#define  MALT_W MT(MOD_RALT, KC_W)

#define  MCTL_L MT(MOD_RCTL, KC_L)
#define  MCTL_T MT(MOD_RCTL, KC_T)
#define  MCTL_I MT(MOD_RCTL, KC_I)
#define  MCTL_S MT(MOD_LCTL, KC_S)
#define  MCTL_BR MT(MOD_LCTL, KC_LBRC)

#define  MCTL_7 MT(MOD_RCTL, KC_7)
#define  MCTL_3 MT(MOD_RCTL, KC_3)

// One shot modifiers.
#define OS_LGUI OSM(MOD_LGUI)

// Key code abbreviations.
#define  KC_RGHT KC_RIGHT
#define  KC_PGDN KC_PGDOWN

#include "keycode_functions.h"
#include "tapdance.h"
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
		T_NUMER, MALT_A , MCTL_S , MSFT_D , L_SYMF , KC_G   , KC_H   , L_SYMJ , MSFT_K , MCTL_L , MALT_SC, T_NUMER, KC_ENT ,
		KC_LSFT, XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, XXXXXXX,
		KC_LALT, KC_LCTL, OS_LGUI, L_NAVSP, L_NAVSP, L_NAVSP, OS_LGUI, T_MOUSE, XXXXXXX, T_MOUSE, XXXXXXX),
        /* BEAKL10
        * ,-----------------------------------------------------------------------------------------.
        * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bspc    |
        * |-----------------------------------------------------------------------------------------+
        * | Tab   |  Q  |  H  |  O  |  U  |  X  |  G  |  D  |  N  |  M  |  V  |  [  |  ]  |    \    |
        * |-----------------------------------------------------------------------------------------+
        * |  FN2    |  Y  |  I  |  E  |  A  |  .  |  C  |  S  |  R  |  T  |  W  | NUM |    Enter    |
        * |-----------------------------------------------------------------------------------------+
        * | Shift     |  J  |  /  |  '  |  ,  |  Z  |  B  |  P  |  L  |  F  |  K  |     Shift       |
        * |-----------------------------------------------------------------------------------------+
        * |  Alt  | Ctrl |  GUI |             Space                 | Ctrl | Alt  | FN3 |     |     |
        * `-----------------------------------------------------------------------------------------'
        */
	[_BEAKL] = LAYOUT(
		KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , XXXXXXX, KC_BSPC,
		KC_TAB , KC_Q   , KC_H   , KC_O   , KC_U   , KC_X   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
		T_NUMER, MALT_Y , MCTL_I , MSFT_E , L_SYMA , KC_DOT , KC_H   , L_SYMS , MSFT_R , MCTL_T , MALT_W , T_NUMER, KC_ENT ,
		KC_LSFT, XXXXXXX, KC_J   , KC_SLSH, KC_QUOT, KC_COMM, KC_Z   , KC_B   , KC_P   , KC_L, KC_F , KC_K, KC_RSFT, XXXXXXX,
		KC_LALT, KC_LCTL, OS_LGUI, L_NAVSP, L_NAVSP, L_NAVSP, OS_LGUI, T_MOUSE, XXXXXXX, T_MOUSE, XXXXXXX),
        /* BEAKLSH, custom SHIFT layer.
        * ,-----------------------------------------------------------------------------------------.
        * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bspc    |
        * |-----------------------------------------------------------------------------------------+
        * | Tab   |  Q  |  H  |  O  |  U  |  X  |  G  |  D  |  N  |  M  |  V  |  [  |  ]  |    \    |
        * |-----------------------------------------------------------------------------------------+
        * |  FN2    |  Y  |  I  |  E  |  A  |  .  |  C  |  S  |  R  |  T  |  W  | NUM |    Enter    |
        * |-----------------------------------------------------------------------------------------+
        * | Shift     |  J  |  ?  |  `  |  !  |  Z  |  B  |  P  |  L  |  F  |  K  |     Shift       |
        * |-----------------------------------------------------------------------------------------+
        * |  Alt  | Ctrl |  GUI |             Space                 | Ctrl | Alt  | FN3 |     |     |
        * `-----------------------------------------------------------------------------------------'
        */
	[_BEAKLSH] = LAYOUT(
		KC_ESC , S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_UNDS, KC_PLUS, XXXXXXX, KC_BSPC,
		KC_TAB , S(KC_Q), S(KC_H), S(KC_O), S(KC_U), S(KC_X), S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), KC_LCBR, KC_RCBR, KC_PIPE,
		T_NUMER, KC_Y   , KC_I   , KC_E   , KC_A   , KC_G   , KC_H   , L_SYMJ , MSFT_K , MCTL_L , MALT_SC, T_NUMER, KC_ENT ,
		KC_LSFT, XXXXXXX, KC_J   , KC_GRV , KC_EXLM, KC_Z   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, XXXXXXX,
		KC_LALT, KC_LCTL, OS_LGUI, L_NAVSP, L_NAVSP, L_NAVSP, OS_LGUI, T_MOUSE, XXXXXXX, T_MOUSE, XXXXXXX),

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
	[NUMER] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, KC_5   , KC_4   , TD_EQL , _______, _______, KC_ASTR, KC_8   , KC_9   , _______, _______, _______, _______,
		_______, KC_LALT, MCTL_3 , L_BS2  , L_SYM1 , KC_DOT , KC_SCLN, L_SYM0 , L_BS6  , MCTL_7 , KC_LALT, _______, _______,
		_______, XXXXXXX, _______, KC_SLSH, KC_QUOT, KC_COMM, _______, KC_PLUS, KC_MINS, KC_BSLS, KC_COLN, _______, _______, _______,
		_______, _______, _______, L_NAVSP, L_NAVSP, L_NAVSP, _______, _______, _______, _______, _______),
        /* SYMBL
        * ,-----------------------------------------------------------------------------------------.
        * |       |     |  <  |  >  |  ~  |     |     |  ^  |  {  |  }  |     |     |     |         |
        * |-----------------------------------------------------------------------------------------+
        * |         |  @  |  [  |  $  |  ]  |  #  |     |  (  |  "  |  )  |  %  |     |             |
        * |-----------------------------------------------------------------------------------------+
        * |           |     |  ?  |  `  |  !  |     |     |  _  |  |  |  &  |     |                 |
        * |-----------------------------------------------------------------------------------------+
        * |       |      |      |              Spc                  |      |      |     |     |     |
        * `-----------------------------------------------------------------------------------------'
        */
	[SYMBL] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, KC_LT  , KC_GT  , TD_TILD, _______, _______, KC_CIRC, KC_LCBR, KC_RCBR, _______, _______, _______, _______,
		_______, KC_AT  , MCTL_BR, KC_DLR , KC_RBRC, KC_HASH, KC_SCLN, KC_LPRN, KC_DQT , KC_RPRN, KC_PERC, _______, _______,
		_______, XXXXXXX, _______, KC_QUES, KC_GRV , KC_EXLM, _______, KC_PLUS, KC_UNDS, KC_PIPE, KC_COLN, _______, _______, _______,
		_______, _______, _______, L_NAVSP, L_NAVSP, L_NAVSP, _______, _______, _______, _______, _______),
    // the layer is raised from numeric layer, it mimics the default _QWERTY.
	[QWERTY] = LAYOUT(
		_______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , XXXXXXX, KC_BSPC,
		_______, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
		_______, MALT_A , MCTL_S , MSFT_D , L_SYMF , KC_G   , KC_H   , L_SYMJ , MSFT_K , MCTL_L , MALT_SC, KC_QUOT, KC_ENT ,
		_______, XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, XXXXXXX,
		_______, _______, _______, KC_ENT , KC_ENT , KC_ENT , _______, _______, XXXXXXX, _______, XXXXXXX),
	[NAVIG] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET ,
		_______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END , _______, _______, RGB_M_P, RGB_TOG,
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
}

bool has_layer_changed = true;

void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);
  static uint8_t old_layer = 0;

  if (old_layer != layer) {
    has_layer_changed = true;
    old_layer = layer;
  }

  if (has_layer_changed) {
    has_layer_changed = false;

    switch (layer) {
      case NUMER:
        rgblight_enable();
        rgblight_sethsv (120,255,255); // green
      break;
      case MOUSE:
        rgblight_enable();
        rgblight_sethsv (0,255,255); // red
      break;
      default:
        rgblight_disable();
      break;
    }
  }
  if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
    rgblight_enable();
    rgblight_sethsv (240,255,255); // blue
  }
};
