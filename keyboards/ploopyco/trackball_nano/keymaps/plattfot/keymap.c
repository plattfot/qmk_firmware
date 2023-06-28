/* Copyright 2021 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2019 Hiroyuki Okada
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// safe range starts at `PLOOPY_SAFE_RANGE` instead.

// toggle numlock based on defaint00 keymap[0]

// [0] https://github.com/defiant00/qmk_firmware/blob/ba467206f1/keyboards/ploopyco/trackball_nano/keymaps/defiant00/keymap.c

#define MOVEMENT_TIMEOUT 1000

void pointing_device_init_user(void)
{
    pointing_device_set_cpi(600);
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    static uint16_t movement_timer;
    // Need to track the state internally.  Relying only on the
    // num_lock state is unstable and causes it to start spamming
    // KC_NUM_LOCK when it tries to turn it off.
    static bool moving = false;
    led_t leds = host_keyboard_led_state();

    if (mouse_report.x || mouse_report.y) {
        movement_timer = timer_read();
        moving = true;
        if (!leds.num_lock) {
            tap_code(KC_NUM_LOCK);
        }
    } else if (moving && leds.num_lock && timer_elapsed(movement_timer) > MOVEMENT_TIMEOUT) {
        moving = false;
        tap_code(KC_NUM_LOCK);
    }

    const int8_t x = mouse_report.x;
    const int8_t y = mouse_report.y;

    // Rotating 90° CCW and inverting axis here as the main config
    // defines a rotation.
    mouse_report.x = -y;
    mouse_report.y = x;


    return mouse_report;
}
