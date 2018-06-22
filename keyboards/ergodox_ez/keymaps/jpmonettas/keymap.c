#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum{
  TD_E_LIS=0,
  TD_W_VEC,
  TD_R_MAP,
  TD_I_PIPE,
  TD_RET_DQ
};

enum custom_keycodes {
  EMAIL=SAFE_RANGE,
  PASSWORD
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_W_VEC] = ACTION_TAP_DANCE_DOUBLE(KC_W,KC_LBRC),
  [TD_E_LIS] = ACTION_TAP_DANCE_DOUBLE(KC_E,KC_LPRN),
  [TD_R_MAP] = ACTION_TAP_DANCE_DOUBLE(KC_R,KC_LCBR),
  [TD_I_PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_I,KC_PIPE),
  [TD_RET_DQ] = ACTION_TAP_DANCE_DOUBLE(KC_ENT,KC_DOUBLE_QUOTE)
};

enum macros {
  WIN_C = 0,
  WIN_T,
  WIN_X,
  CTRL_US,
  ALT_US
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4  |   5  | MC   |           |  MR  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W/[|   E/( |  R/{|   T  | MT   |           |  MU  |   Y  |   U  |   I/||   O  |   P  |   Back |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / : | Ret/"  |
 * |--------+------+------+------+------+------| ME   |           | '    |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  | /    | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Win   |      |      | Win | Alt  |                                       |  ~L1  |      |      |      | _    |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  Home| End  |       |   *  |   +    |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       |   /  |        |      |
 *                                 | Space| ~L1  |------|       |------|  -     |Back  |
 *                                 |      |      | PgDwn|       |   =  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
                        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   M(WIN_C),
                        KC_TAB,         KC_Q,         TD(TD_W_VEC),  TD(TD_E_LIS),   TD(TD_R_MAP),   KC_T,   M(WIN_T),
                        KC_LCTRL,       KC_A,         KC_S,  KC_D,   KC_F,   KC_G,
                        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B, M(WIN_X),
                        KC_LWIN ,       KC_TRNS,      KC_TRNS,  KC_LWIN,KC_LALT,
                                              KC_HOME,  KC_END,
                                                              KC_PGUP,
                                               KC_SPC,MO(1),KC_PGDN,
        // right hand
                        M(ALT_US),     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
                        M(CTRL_US),    KC_Y,   KC_U,  TD(TD_I_PIPE),   KC_O,   KC_P,             KC_BSPACE,
                        KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN ,TD(TD_RET_DQ),
                        KC_QUOT,KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH ,   KC_RSFT,
                        MO(1) ,         KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,
             KC_ASTERISK,        KC_PLUS,
             KC_SLASH,
             KC_EQL,KC_MINS, KC_BSPACE
                          ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Email    |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |Pass     |      |      |      |      |      |      |           |      |      |      |   U  |      |      |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |   L  |   D  |  R   |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       EMAIL,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       PASSWORD,KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               RGB_VAD,RGB_VAI,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_TRNS,  KC_TRNS,  KC_UP,   KC_TRNS,   KC_TRNS, KC_F12,
       KC_TRNS, KC_LEFT,  KC_DOWN,   KC_RIGHT,   KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_DOWN,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
                         KC_TRNS,KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
  case WIN_C:
    if (record->event.pressed)
      {
        register_code(KC_LWIN);
        register_code(KC_C);
        unregister_code(KC_C);
        unregister_code(KC_LWIN);
      }
    break;
  case WIN_T:
    if (record->event.pressed)
      {
        register_code(KC_LWIN);
        register_code(KC_T);
        unregister_code(KC_T);
        unregister_code(KC_LWIN);
      }
    break;
  case WIN_X:
    if (record->event.pressed)
      {
        register_code(KC_LWIN);
        register_code(KC_X);
        unregister_code(KC_X);
        unregister_code(KC_LWIN);
      }
    break;
  case CTRL_US:
    if (record->event.pressed)
      {
        register_code(KC_LCTL);
        register_mods(MOD_LSFT);
        register_code(KC_MINUS);
        unregister_code(KC_MINUS);
        unregister_mods(MOD_LSFT);
        unregister_code(KC_LCTL);
      }
    break;
  case ALT_US:
    if (record->event.pressed)
      {
        register_code(KC_LALT);
        register_mods(MOD_LSFT);
        register_code(KC_MINUS);
        unregister_code(KC_MINUS);
        unregister_mods(MOD_LSFT);
        unregister_code(KC_LALT);
      }
    break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  
  case EMAIL:
    if (record->event.pressed) {
      SEND_STRING ("jpmonettas@gmail.com");
    }
    return false;
    break;
  case PASSWORD:
    if (record->event.pressed) {
      SEND_STRING ("Tw|$7ed7");
    }
    return false;
    break;
  
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
