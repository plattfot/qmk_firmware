
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
  C_OE, // ö
  C_AE, // ä
  C_AO, // å
  C_EE, // é
  C_ESC, // escape
#ifdef PLT_ENABLE_COMBO40
  C_QUOTE, // '
  C_BS, // backspace
  C_DEL, // backspace
  C_CTRL,
  C_ALT,
  C_ALTGR,
  C_GUI,
  C_SHIFT,
  C_TAB,
  C_NAV, // to navigation
  C_BASE, // to base
#endif
#ifdef PLT_ENABLE_CAPS_WORD
  C_CAPS, // caps word
#endif
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM oe_combo[] = {KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM ae_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM ao_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM ee_combo[] = {KC_G, KC_S, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_SPACE, KC_ENT, COMBO_END};

#ifdef PLT_ENABLE_COMBO40
const uint16_t PROGMEM nav_combo[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM alt_combo[] = {KC_P, KC_T, COMBO_END};
const uint16_t PROGMEM ctrl_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM shift_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_Q, KC_A, COMBO_END};

const uint16_t PROGMEM base_combo[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM bs_combo[] = {KC_N, KC_L, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_N, KC_H, COMBO_END};
const uint16_t PROGMEM gui_combo[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM altgr_combo[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM quote_combo[] = {KC_SCLN, KC_O, COMBO_END};
#endif

#ifdef PLT_ENABLE_CAPS_WORD
const uint16_t PROGMEM caps_combo[] = {KC_G, KC_M, COMBO_END};
#endif

combo_t key_combos[] = {
 [C_OE] = COMBO_ACTION(oe_combo),
 [C_AE] = COMBO_ACTION(ae_combo),
 [C_AO] = COMBO_ACTION(ao_combo),
 [C_EE] = COMBO_ACTION(ee_combo),
 [C_ESC] = COMBO_ACTION(esc_combo),

#ifdef PLT_ENABLE_COMBO40
 [C_NAV] = COMBO_ACTION(nav_combo),
 [C_CTRL] = COMBO_ACTION(ctrl_combo),
 [C_ALT] = COMBO_ACTION(alt_combo),
 [C_GUI] = COMBO_ACTION(gui_combo),
 [C_TAB] = COMBO_ACTION(tab_combo),

 [C_BASE] = COMBO_ACTION(base_combo),
 [C_BS] = COMBO_ACTION(bs_combo),
 [C_DEL] = COMBO_ACTION(del_combo),
 [C_SHIFT] = COMBO_ACTION(shift_combo),
 [C_ALTGR] = COMBO_ACTION(altgr_combo),
 [C_QUOTE] = COMBO_ACTION(quote_combo),
#endif
#ifdef PLT_ENABLE_CAPS_WORD
 [C_CAPS] = COMBO_ACTION(caps_combo),
#endif
};

__attribute__((weak)) void process_combo_event(uint16_t combo_index, bool pressed)
{
  switch(combo_index) {
  case C_OE:
    if (pressed) {
      tap_code16(RALT(KC_O));
    }
    break;
  case C_AE:
    if (pressed) {
      tap_code16(RALT(KC_A));
    }
    break;
  case C_AO:
    if (pressed) {
      tap_code16(RALT(KC_W));
    }
    break;
  case C_EE:
    if (pressed) {
      tap_code16(RALT(KC_G));
    }
    break;
  case C_ESC:
    if (pressed) {
      tap_code16(KC_ESC);
      caps_word_set(false);
    }
    break;
#ifdef PLT_ENABLE_COMBO40
  case C_NAV:
    if (pressed) {
      layer_move(plt_nav_index());
    }
    break;
  case C_BASE:
    if (pressed) {
      layer_move(plt_base_index());
#ifdef PLT_ENABLE_CAPS_WORD
      caps_word_set(false);
#endif
#ifdef PLT_ENABLE_CLOSE_TAP
      cancel_close_tap();
#endif
    }
    break;
  case C_CTRL:
    if (pressed) {
      add_oneshot_mods(MOD_BIT(KC_LCTL));
    }
    break;
  case C_ALT:
    if (pressed) {
      add_oneshot_mods(MOD_BIT(KC_LALT));
    }
    break;
  case C_GUI:
    if (pressed) {
      add_oneshot_mods(MOD_BIT(KC_LGUI));
    }
    break;
  case C_TAB:
    if (pressed) {
      tap_code16(KC_TAB);
    }
    break;
  case C_BS:
    if (pressed) {
      tap_code16(KC_BSPC);
    }
    break;
  case C_DEL:
    if (pressed) {
      tap_code16(KC_DEL);
    }
    break;
  case C_SHIFT:
    if (pressed) {
      add_oneshot_mods(MOD_BIT(KC_LSFT));
    }
    break;
  case C_ALTGR:
    if (pressed) {
      add_oneshot_mods(MOD_BIT(KC_RALT));
    }
    break;
  case C_QUOTE:
    if (pressed) {
      tap_code16(KC_QUOT);
    }
    break;
#endif
#ifdef PLT_ENABLE_CAPS_WORD
  case C_CAPS:
    if (pressed) {
      caps_word_set(!caps_word_get());
    }
    break;
  }
#endif
}
#endif
