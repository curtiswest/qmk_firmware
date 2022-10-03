/* Copyright 2021 TweetyDaBird
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

#include "lotus58.h"

 led_config_t g_led_config = {
  {
        // left hand switch matrix to led map
        {  5,  4,  3,  2,   1,   0 },
        {  6,  7,  8,  9,  10,  11 },
        {  17, 16, 15, 14,  13, 12 },
        {  18, 19, 20, 21, 22,  23 },
        {  NO_LED, 28, 27, 26, 25, 24 },

        // right hand switch matrix to led map
        {  40, 39, 38, 37,  36,  35 },
        {  41, 42, 43, 44,  45,  46 },
        {  52, 51, 50, 49,  48,  47 },
        {  53, 54, 55, 56,  57,  58 },
        {  NO_LED, 63, 62, 61, 60, 59 }
    },
    {
        // Left Hand switch led positions
        {86,0},   {69,0},   {52,0},   {34,0},   {17,0},   {0,0},
        {0,16},   {17,16},  {34,16},  {52,16},  {69,16},  {86,16},
        {86,32},  {69,32},  {52,32},  {34,32},  {17,32},  {0,32},
        {0,48},   {17,48},  {34,48},  {52,48},  {69,48},  {86,48},
        {103,40}, {103,64}, {78,64},  {60,64},  {43,64},

        // Left Underglow led positions
        {52,64},  {86,48},  {9,48},
        {9,0},    {43,0},   {78,0},

        // Right Hand switch led positions
        {138,0},  {155,0},  {172,0},  {190,0},  {207,0},  {224,0},
        {224,0},  {207,16}, {190,16}, {172,16}, {155,16}, {138,16},
        {138,32}, {155,32}, {172,32}, {190,32}, {207,32}, {224,32},
        {224,48}, {207,48}, {190,48}, {172,48}, {155,48}, {138,48},
        {121,40}, {121,64}, {146,64}, {164,64}, {181,64},

        // Right Underglow led positions
        {172,64}, {129,48}, {215,48},
        {215,0},  {181,0},  {146,0}
    },
    // led flags
    {
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,

        LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
        LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,

        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,

        LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
        LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW
    }
 };
