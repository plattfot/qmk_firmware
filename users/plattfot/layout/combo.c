
#include "combo.h"
#ifdef PLT_ENABLE_CAPS_WORD
#  include "features/caps_word.h"
#endif

#ifdef PLT_ENABLE_CLOSE_TAP
#  include "features/close_tap.h"
#endif

#ifdef COMBO_ENABLE
// Contains combos to be able to use a 40% keyboard without homerow
// mods. Can kind of see this as homerow mod combos. Assumes the
// keyboard is using Colemak DH.
enum combo_events {
  C_ESC,
#ifdef PLT_ENABLE_CAPS_WORD
  C_CAPS, // caps word
#endif
  // Upper left hand
  C_CLEAR, // clear state
  C_LALTL,
  C_LCTRL,
  C_LGUI,
  C_RALTL,

  // Upper right hand
  C_RSHORT,
  C_LALTR,
  C_RCTRL,
  C_RGUI,
  C_RALTR,

  // Lower left hand
  C_TAB,
  C_LNAV, // to navigation

  // Lower right hand
  C_BSPC, // key will be del when on plt_left_symfunc_index layer
  C_RNAV, // to navigation

#ifdef PLT_ENABLE_COMBO_FULL
  // Lower left hand
  C_CPU, // Ctri + PgUp
  /* C_TAB, */
  /* C_LNAV*/
  C_MPLY,
  C_LSHIFT,

  // Lower right hand
  C_CPD, // Ctri + PgDn
  /* C_BSPC, */
  /* C_RNAV*/
  C_F20, // mic mute
  C_RSHIFT,
#endif

  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM esc_combo[] = {KC_SPACE, KC_ENT, COMBO_END};
#ifdef PLT_ENABLE_CAPS_WORD
const uint16_t PROGMEM caps_combo[] = {KC_G, KC_M, COMBO_END};
#endif

const uint16_t PROGMEM clear_combo[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM laltl_combo[] = {KC_P, KC_T, COMBO_END};
const uint16_t PROGMEM lctrl_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM lgui_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM raltl_combo[] = {KC_Q, KC_A, COMBO_END};

const uint16_t PROGMEM rshort_combo[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM laltr_combo[] = {KC_L, KC_N, COMBO_END};
const uint16_t PROGMEM rctrl_combo[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM rgui_combo[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM raltr_combo[] ={KC_SCLN, KC_O, COMBO_END};

const uint16_t PROGMEM tab_combo[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM lnav_combo[] = {KC_S, KC_C, COMBO_END};

const uint16_t PROGMEM bspc_combo[] = {KC_N, KC_H, COMBO_END};
const uint16_t PROGMEM rnav_combo[] = {KC_E, KC_COMM, COMBO_END};

#ifdef PLT_ENABLE_COMBO_FULL
const uint16_t PROGMEM cpu_combo[] = {KC_G, KC_V, COMBO_END};
// <- tab placement ->
// <- nav placement ->
const uint16_t PROGMEM mply_combo[] = {KC_R, KC_X, COMBO_END};
const uint16_t PROGMEM lshift_combo[] = {KC_A, KC_Z, COMBO_END};

const uint16_t PROGMEM cpd_combo[] = {KC_M, KC_K, COMBO_END};
// <- backspace placement ->
// <- nav placement ->
const uint16_t PROGMEM micmute_combo[] = {KC_I, KC_DOT, COMBO_END};
const uint16_t PROGMEM rshift_combo[] = {KC_O, KC_SLSH, COMBO_END};
#endif

combo_t key_combos[] = {
 [C_ESC] = COMBO_ACTION(esc_combo),
#ifdef PLT_ENABLE_CAPS_WORD
 [C_CAPS] = COMBO_ACTION(caps_combo),
#endif

 [C_CLEAR] = COMBO_ACTION(clear_combo),
 [C_LALTL] = COMBO_ACTION(laltl_combo),
 [C_LCTRL] = COMBO_ACTION(lctrl_combo),
 [C_LGUI] = COMBO_ACTION(lgui_combo),
 [C_RALTL] = COMBO_ACTION(raltl_combo),

 [C_RSHORT] = COMBO_ACTION(rshort_combo),
 [C_LALTR] = COMBO_ACTION(laltr_combo),
 [C_RCTRL] = COMBO_ACTION(rctrl_combo),
 [C_RGUI] = COMBO_ACTION(rgui_combo),
 [C_RALTR] = COMBO_ACTION(raltr_combo),

 [C_TAB] = COMBO(tab_combo, KC_TAB),
 [C_LNAV] = COMBO_ACTION(lnav_combo),

 [C_BSPC] = COMBO_ACTION(bspc_combo),
 [C_RNAV] = COMBO_ACTION(rnav_combo),

#ifdef PLT_ENABLE_COMBO_FULL
 [C_CPU] = COMBO(cpu_combo, LCTL(KC_PGUP)),
 // <- tab ->
 // <- nav ->
 [C_MPLY] = COMBO(mply_combo, KC_MPLY),
 [C_LSHIFT] = COMBO_ACTION(lshift_combo),

 [C_CPD] = COMBO(cpd_combo, RCTL(KC_PGDN)),
 // <- backspace ->
 // <- nav ->
 [C_F20] = COMBO(micmute_combo, KC_F20),
 [C_RSHIFT] = COMBO_ACTION(rshift_combo),
#endif
};

__attribute__((weak)) void process_combo_event(uint16_t combo_index, bool pressed)
{
    switch(combo_index) {
    case C_LNAV:
    case C_RNAV:
        if (pressed) {
            set_oneshot_layer(plt_nav_index(), ONESHOT_START);
        } else {
            clear_oneshot_layer_state(ONESHOT_PRESSED);
        }
        break;
#ifdef PLT_ENABLE_COMBO_FULL
    case C_LSHIFT:
        if (pressed) {
            register_code(KC_LSFT);
            add_oneshot_mods(MOD_BIT(KC_LSFT));
        } else {
            unregister_code(KC_LSFT);
        }
        break;
    case C_RSHIFT:
        if (pressed) {
            register_code(KC_RSFT);
            add_oneshot_mods(MOD_BIT(KC_RSFT));
        } else {
            unregister_code(KC_RSFT);
        }
        break;
#endif
    case C_BSPC:
        const uint8_t key = get_highest_layer(layer_state) == plt_left_symfunc_index()?
            KC_DEL:
            KC_BSPC;
        if (pressed) {
            register_code(key);
        } else {
            unregister_code(key);
            clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        }
        break;
    case C_LCTRL:
        if (pressed) {
            register_code(KC_LCTL);
            add_oneshot_mods(MOD_BIT(KC_LCTL));
        } else {
            unregister_code(KC_LCTL);
        }
        break;
    case C_RCTRL:
        if (pressed) {
            register_code(KC_RCTL);
            add_oneshot_mods(MOD_BIT(KC_RCTL));
        } else {
            unregister_code(KC_RCTL);
        }
        break;
    case C_RALTR:
    case C_RALTL:
        if (pressed) {
            register_code(KC_RALT);
            add_oneshot_mods(MOD_BIT(KC_RALT));
        } else {
            unregister_code(KC_RALT);
        }
        break;
    case C_LALTR:
    case C_LALTL:
        if (pressed) {
            register_code(KC_LALT);
            add_oneshot_mods(MOD_BIT(KC_LALT));
        } else {
            unregister_code(KC_LALT);
        }
        break;
    case C_LGUI:
        if (pressed) {
            register_code(KC_LGUI);
            add_oneshot_mods(MOD_BIT(KC_LGUI));
        } else {
            unregister_code(KC_LGUI);
        }
        break;
    case C_RGUI:
        if (pressed) {
            register_code(KC_RGUI);
            add_oneshot_mods(MOD_BIT(KC_RGUI));
        } else {
            unregister_code(KC_RGUI);
        }
        break;
    case C_RSHORT:
        if (pressed) {
            set_oneshot_layer(plt_shortcut_index(), ONESHOT_START);
        } else {
            clear_oneshot_layer_state(ONESHOT_PRESSED);
        }
        break;
    case C_ESC:
        if (pressed) {
            tap_code16(KC_ESC);
            caps_word_set(false);
            cancel_close_tap();
        }
        break;
    case C_CLEAR:
        if (pressed) {
            clear_oneshot_mods();
            layer_move(plt_base_index());
#ifdef PLT_ENABLE_CAPS_WORD
            caps_word_set(false);
#endif
#ifdef PLT_ENABLE_CLOSE_TAP
            cancel_close_tap();
#endif
        }
        break;
#ifdef PLT_ENABLE_CAPS_WORD
    case C_CAPS:
        if (pressed) {
            caps_word_set(!caps_word_get());
        }
        break;
#endif
    }
}

#endif
