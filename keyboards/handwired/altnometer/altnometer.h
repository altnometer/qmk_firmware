/* Copyright 2019 REPLACE_WITH_YOUR_NAME
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

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
               L00, L01, L02, L03, L04,       R00, R01, R02, R03, R04, \
               L05, L06, L07, L08, L09,       R05, R06, R07, R08, R09, \
               L10, L11, L12, L13, L14,       R10, R11, R12, R13, R14, \
                         L15, L16, L17,       R15, R16, R17            \
) \
{ \
 {     L00,   L01,   L02,   L03,   L04, }, \
 {     L05,   L06,   L07,   L08,   L09, }, \
 {     L10,   L11,   L12,   L13,   L14, }, \
 {   KC_NO, KC_NO,   L15,   L16,   L17, },     \
  \
 {     R00,   R01,   R02,   R03,  R04,  }, \
 {     R05,   R06,   R07,   R08,  R09,  }, \
 {     R10,   R11,   R12,   R13,  R14,  }, \
 {     R15,   R16,   R17, KC_NO, KC_NO, }, \
}
