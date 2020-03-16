#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // Default layer
#define GAME 1 // Experimental layer
#define SYMB 2 // Symbols
#define MDIA 3 // Media keys
#define MOUS 4 // Mouse/backlight keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
/* // Macros */
  M_LRBRC, // []
  M_LRCBR, // {}
  M_LRPRN, // ()
  M_LRABR, // <>
  M_DQOUT, // ""
};

// Fillers to make layering more clear, from the default preonic keymap
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ~    |   1  |   2  |   3  |   4  |   5  | ECS  |           | ESC  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   \    |   Q  |   W  |   E  |   R  |   T  | ^L2  |           |  =   |   Y  |   U  |   I  |   O  |   P  |   [    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|  (   |           |  )   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           '-------------+------+------+------+------+--------'
 *   | ~L4  |   ]  |  </> | LGUI | LCTL |                                       |  L3  | C-M  | RGUI | ~L1  | ~L4  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Del  |ScLock|       | PgUp |  PgDn  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | End  |        |      |
 *                                 | Space| LALT |------|       |------| Enter  | Back |
 *                                 |      |      | L2   |       | RALT |        | Space|
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_ESC,
        KC_BSLS, KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    OSL(SYMB),
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_LPRN,
        TG(MOUS),KC_RBRC, KC_NUBS, KC_LGUI, KC_LCTL,
                                                    KC_DEL,  KC_SLCK,
                                                             KC_HOME,
                                            KC_SPC, KC_LALT, MO(SYMB),
        // right hand
        KC_ESC,      KC_6,   KC_7,      KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_EQL,      KC_Y,   KC_U,      KC_I,    KC_O,    KC_P,    KC_LBRC,
                     KC_H,   KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_RPRN,     KC_N,   KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                             MO(MDIA),  LALT(KC_RCTL), KC_RGUI, TG(GAME),TG(MOUS),
        KC_PGUP,     KC_PGDN,
        KC_END,
        KC_RALT,     KC_ENT, KC_BSPC
    ),
/* Keymap 1: Game keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           '-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Game layout
[GAME] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

/* Keymap 2: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           | F12  |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |  []  |  ()  |  {}  |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  (   |  )   |  \   |  -   |  <>  |------|           |------|  ""  |  {   |  }   |  [   |  ]   |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           '-------------+------+------+------+------+--------'
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
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
       _______, _______, M_LRBRC, M_LRPRN, M_LRCBR, _______, _______,
       _______, KC_LPRN, KC_RPRN, KC_BSLS, KC_MINS, M_LRABR,
       _______, _______, M_LRBRC, M_LRPRN, M_LRCBR, _______, _______,
       _______, _______, _______, _______, _______,
                                                    _______, KC_INS,
                                                             _______,
                                           _______, _______, _______,
       // right hand
       KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
       _______, _______, _______, _______, _______, _______, _______,
                M_DQOUT, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______,
       _______, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, KC_DEL
),
/* Keymap 3: Media  keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | Mute | Vol- | Vol+ |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Play | Left |  Up  | Down | Right|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           '-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA
[MDIA] = LAYOUT_ergodox(
       VRSN,    _______, _______, _______, _______, _______, _______,
       KC_PSCR, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
                KC_MPLY, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, _______,
       _______, _______, _______, KC_MPRV, KC_MNXT, _______, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, KC_WBAK
),
/* Keymap 4: Mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      | EPRM |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           '-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 | Lclk | Rclk |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MOUSE
[MOUS] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, EPRM,
       _______, _______, _______, KC_MS_U, _______, _______, _______,
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
       _______, _______, BL_INC,  BL_DEC,  BL_TOGG,  _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  KC_BTN1, KC_BTN2, _______,
    // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, BL_TOGG, BL_DEC,  BL_INC,  _______, _______,
                _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      // dynamically generate these.
    case EPRM:
      eeconfig_init();
      break;
    case VRSN:
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      return false;
    case RGB_SLD:
#ifdef RGBLIGHT_ENABLE
      rgblight_mode(1);
#endif
      return false;
    case M_LRPRN:
      SEND_STRING("()"SS_TAP(X_LEFT));
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      return false;
    case M_LRCBR:
      SEND_STRING("{}"SS_TAP(X_LEFT));
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      return false;
    case M_LRBRC:
      SEND_STRING("[]"SS_TAP(X_LEFT));
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      return false;
    case M_LRABR:
      SEND_STRING("<>"SS_TAP(X_LEFT));
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      return false;
    case M_DQOUT:
      SEND_STRING("\"\""SS_TAP(X_LEFT));
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      return false;
    }
  }
  return true;
}

/* // Runs just one time when the keyboard initializes. */
/* void matrix_init_user(void) { */

/* }; */
#ifdef KEYBOARD_ergodox_ez
// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
};
#endif
