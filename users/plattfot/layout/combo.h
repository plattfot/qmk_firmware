/* Copyright 2022 Fredrik Salomonsson <plattfot@posteo.net>
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

#pragma once

#include QMK_KEYBOARD_H

// Function that return the index to the base layer. Needs to be
// defined in the keymap.c file!
int plt_base_index(void);

// Function that return the index to the navigation layer. Needs to be
// defined in the keymap.c file!
int plt_nav_index(void);

// Function that return the index to the shortcut layer. Needs to be
// defined in the keymap.c file!
int plt_shortcut_index(void);

// Function that return the index to the left symbol/function
// layer. Needs to be defined in the keymap.c file!
int plt_left_symfunc_index(void);

