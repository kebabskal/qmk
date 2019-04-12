#include "kb.h"

#define _QWERTY 0
#define _RAISE 1
#define _LOWER 2
#define _ARROWS 3
#define _FN 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FN,
  ADJUST,
  ATAB1,
  ATAB2,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KEYMAP(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, 
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, 
    KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                   KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                   KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, 
    ADJUST,  KC_LGUI, KC_LALT, KC_LALT, KC_LCTL, KC_SPC, LOWER, KC_LCTL, RAISE, KC_BSPC, KC_RALT, KC_NUHS, KC_NUBS, FN
  ),

  [_RAISE] = KEYMAP(
    _______, _______, _______, _______, _______, _______,                   _______,    _______,    _______, _______, _______,    KC_EQL, 
    _______, _______, _______, _______, _______, _______,                   ALTG(KC_8), KC_HOME,    KC_UP,   KC_END,  ALTG(KC_9), KC_SLSH, 
    KC_DEL,  _______, _______, _______, _______, _______,                   ALTG(KC_7), KC_LEFT,    KC_DOWN, KC_RGHT, ALTG(KC_0), KC_NUHS, 
    _______, _______, _______, _______, _______, _______,                   LSFT(KC_8), LSFT(KC_0), KC_NUBS, KC_NUHS, LSFT(KC_9), _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______,    _______
  ),

  [_LOWER] = KEYMAP(
    _______, _______, _______, _______, _______, _______,                   _______,    _______,       _______, _______, _______, _______, 
    _______, _______, KC_UP,   _______, _______, _______,                   LSFT(KC_2), RALT(KC_NUBS), KC_7,    KC_8,    KC_9,    _______, 
    KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, ATAB1,   ATAB2  ,                   KC_NUHS,    RALT(KC_NUBS), KC_4,    KC_5,    KC_6,    KC_BSLS, 
    _______, _______, _______, _______, _______, _______,                   LSFT(KC_0), KC_NUBS,       KC_1,    KC_2,    KC_3,    _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_DEL,        KC_0,    _______, _______, _______
  ), 

  [_ARROWS] = KEYMAP(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, 
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, 
    KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                   KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                   KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_ENT, 
    ADJUST,  KC_LGUI, KC_LALT, KC_LALT, KC_LCTL, KC_SPC, LOWER, KC_LCTL, RAISE, KC_BSPC, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_FN] = KEYMAP(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, 
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_ADJUST] = KEYMAP(
    RESET,   DF(_QWERTY),   DF(_ARROWS),  _______, _______, _______,                   _______, _______, _______, _______, _______, _______, 
    _______, _______,       _______,      _______, _______, _______,                   _______, _______, _______, _______, _______, _______, 
    _______, _______,       _______,      _______, _______, _______,                   _______, _______, _______, _______, _______, _______, 
    _______, _______,       _______,      _______, _______, _______,                   _______, _______, _______, _______, _______, _______, 
    _______, _______,       _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  keyevent_t event = record->event;
  switch (id) { }
  return MACRO_NONE;
}

void matrix_init_user(void) { } 
void matrix_scan_user(void) { }

bool alt_tabbing = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      
        if (alt_tabbing) {
          alt_tabbing = false;
          unregister_code(KC_LALT);
        }
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      
        if (alt_tabbing) {
          alt_tabbing = false;
          unregister_code(KC_LALT);
        }
      }
      return false;
      break;

    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      return false;
      break;

    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;

    case ATAB1:
      if (record->event.pressed) {
        alt_tabbing = true;
        register_code(KC_LALT);
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      return false; // Skip all further processing of this key
    
    case ATAB2:
      if (record->event.pressed) {
        alt_tabbing = true;
        register_code(KC_LALT);
        register_code(KC_LSFT);
        register_code(KC_TAB);
        unregister_code(KC_LSFT);
      } else {
        unregister_code(KC_TAB);
      }
      return false; // Skip all further processing of this key
    
    default:
      return true; // Process all other keycodes normally
  }
}