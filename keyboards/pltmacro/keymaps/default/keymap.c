// Copyright 2026 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
// SPDX-FileCopyrightText: 2026 Fredrik Salomonsson <plattfot@posteo.net>

#include QMK_KEYBOARD_H
#include "version.h"

enum combo_events {
  C_VERSION,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM version_combo[] = {KC_P, KC_T, COMBO_END};

combo_t key_combos[] = {
    [C_VERSION] = COMBO_ACTION(version_combo),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ P │ L │ T │
     * └───┴───┴───┘
     */
    [0] = LAYOUT_ortho_1x3(
        KC_P,    KC_L,    KC_T
    )
};

__attribute__((weak)) void process_combo_event(uint16_t combo_index, bool pressed)
{
    switch(combo_index) {
    case C_VERSION:
        if (pressed) {
            SEND_STRING("Keyboard: pltmacro\nKeymap: default\nVersion: "QMK_VERSION"\n");
        }
        break;
    }
}
