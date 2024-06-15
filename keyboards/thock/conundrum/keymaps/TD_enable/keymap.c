#include QMK_KEYBOARD_H

#include "quantum.h"

enum layers {
  _COLEMAK,
  _QWERTY,
  _GAMER,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  GAMER
};

// Tap Dance declarations
enum {
    TD_1_TAB
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for 1, twice for Tab
    [TD_1_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_TAB),
};

#define LOWER TT(_LOWER)
#define RAISE TT(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_GRV, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |cp/pst| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, LT(0,KC_BSPC),
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    OSM(MOD_LSFT), KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    LT(0,KC_NO),  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Qwerty| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMER] = LAYOUT_grid(
    TD(TD_1_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LT(0,KC_2),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    LSFT_T(KC_3), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    LCTL_T(KC_4), KC_GRV, KC_LALT, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_grid(
KC_TRNS, KC_F12, KC_F7, KC_F8, KC_F9, KC_PLUS, KC_RPRN, KC_AMPR, KC_ASTR, KC_TILD, KC_RCBR, KC_TRNS, 
KC_NUMLOCK, KC_F11, KC_F4, KC_F5, KC_F6, KC_UNDS, KC_LPRN, KC_DLR, KC_PERC, KC_CIRC, KC_LCBR, KC_DEL, 
KC_TRNS, KC_F10, KC_F1, KC_F2, KC_F3, KC_TRNS, KC_PIPE, KC_EXLM, KC_AT, KC_HASH, KC_TRNS, KC_BSPC, 
KC_TRNS, KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_PGDN, KC_PGUP, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_grid(
KC_LNUM, KC_TRNS, KC_P7, KC_P8, KC_P9, KC_EQL, KC_RBRC, KC_F7, KC_F8, KC_F9, KC_F12, KC_TRNS, 
KC_CAPS, KC_DEL, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_LBRC, KC_F4, KC_F5, KC_F6, KC_F11, KC_GRV, 
KC_LSFT, KC_BSPC, KC_P1, KC_P2, KC_P3, KC_TRNS, KC_BSLS, KC_F1, KC_F2, KC_F3, KC_F10, KC_RSFT, 
KC_TRNS, KC_LCTL, KC_P0, KC_P0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_PGDN, KC_PGUP, KC_HOME
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |Colemk|QWERTY|GAMER|      |      |      |      |      |      |      | Reset|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_grid(
    _______, COLEMAK,  QWERTY,   GAMER,  _______, _______, _______, _______, _______,  _______, _______, RESET,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case GAMER:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAMER);
      }
      return false;
      break;
	//handle custom mod tap functions in the GAMER layer
	
	/* unused
	case LT(0,KC_1):
      if (!record->tap.count && record->event.pressed) {
          tap_code16(KC_TAB); // Intercept hold function to send TAB
          return false;
      }
      return true;             // Return true for normal processing of tap keycode
	*/
	
    case LT(0,KC_2):
      if (!record->tap.count && record->event.pressed) {
          tap_code16(KC_ESC); // Intercept hold function to send ESC
          return false;
      }
      return true;             // Return true for normal processing of tap keycode
	//tap backspace, hold is ctrl+bkspc
	case LT(0,KC_BSPC):
      if (!record->tap.count && record->event.pressed) {
          tap_code16(C(KC_BSPC)); // Intercept hold function to send CTRL-BKSPC
          return false;
      }
      return true;             // Return true for normal processing of tap keycode
	//handle copy and paste on a single key
	case LT(0,KC_NO):
      if (record->tap.count && record->event.pressed) {
          tap_code16(C(KC_C)); // Intercept tap function to send Ctrl-C
      } else if (record->event.pressed) {
          tap_code16(C(KC_V)); // Intercept hold function to send Ctrl-V
      }
      return false;
  }
  return true;
}
