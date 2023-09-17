/* Copyright021 TweetyDaBird
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
#include "quantum.h"

bool autoshift;

enum layers {
    _QWERTY,
    _NUM,
    _FN,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_NUMERIC,
    KC_FUNCTION,
};

/* Legend											     _____        _____
 * .---------.-------.-------.-------.-------.-------.  /     \      /     \  .-------.-------.-------.-------.-------.---------.
 * |  Esc    |   1   |   2   |   3   |   4   |   5   | ( Media )    ( Media ) |   6   |   7   |   8   |   9   |   0   |    -    |
 * |---------+-------+-------+-------+-------+-------|  \_____/      \_____/  |-------+-------+-------+-------+-------+---------|
 * |  Tab    |   Q   |   W   |   E   |   R   |   T   |                        |   Y   |   U   |   I   |   O   |   P   |  [ (Å)  |
 * |---------+-------+-------+-------+-------+-------|                        |-------+-------+-------+-------+-------+---------|
 * | Capslk  |   A   |   S   |   D   |   F   |   G   |                        |   H   |   J   |   K   |   L   | ; (Ö) |  ' (Ä)  |
 * |---------+-------+-------+-------+-------+-------+----------.  .----------+-------+-------+-------+-------+-------+---------|
 * | <- Ctrl |   Z   |   X   |   C   |   V   |   B   |   Down   |  |    Up    |   N   |   M   |   ,   |   .   |   /   | Ctrl -> |
 * '---------'-------'-------+-------+-------+-------+-.--------'  '--------.-+-------+-------+-------+-------'-------'---------'
 *                           |  Win  | Lower |  Alt  |/ Space  /    \  Enter \| AltGr | Raise | Bksp  |
							 |		 |		 |	     | Shift  /      \  Shift |       |       |       |
 *                           '-------'-------'-------'-------'        '-------'-------'-------'-------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
    QK_GESC, 	KC_1, 	KC_2,   KC_3,	KC_4,    KC_5,	KC_MPLY,     	KC_MPLY, 	KC_6, 	KC_7,	KC_8,    KC_9,   KC_0,    KC_MINS,
    KC_TAB, 	KC_Q, 	KC_W,   KC_E,   KC_R,    KC_T,                             	KC_Y, 	KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC,
	KC_CAPS, 	KC_A, 	KC_S,   KC_D,   KC_F,    KC_G,                             	KC_H, 	KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,
	LCTL_T(KC_LEFT), 	KC_Z, 	KC_X,   KC_C,   KC_V,    KC_B, 	RGB_MODE_FORWARD,     	RGB_TOG,  KC_N,	KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
							MO(_FN), KC_LGUI,  KC_LALT,    LSFT_T(KC_SPC),      KC_BSPC, RSFT_T(KC_ENT),KC_ESC, KC_DOT
	),

[_NUM] = LAYOUT(
  _______,   KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,  _______,      _______, KC_CIRC,    KC_KP_7,    KC_KP_8,    KC_KP_9, KC_PMNS, KC_EQL,
  _______, XXXXXXX,   KC_UP,  XXXXXXX, XXXXXXX, XXXXXXX,                         KC_HASH,    KC_KP_4,    KC_KP_5,    KC_KP_6, KC_PPLS, XXXXXXX,
  XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, KC_LBRC, KC_RBRC,                         KC_AMPR,    KC_KP_1,    KC_KP_2,    KC_KP_3, KC_PENT, XXXXXXX,
  _______, XXXXXXX, KC_PAST,  KC_PPLS, KC_PSLS,  KC_EQL, _______,       _______,  KC_DLR,    KC_KP_0, KC_KP_0, KC_KP_DOT, KC_PENT, _______,
							  _______, _______, _______, _______,       _______, _______, _______, _______
),

[_FN] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______,        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_PIPE,
  _______, _______, _______, _______, KC_LPRN, KC_RPRN,                          KC_LPRN, KC_RPRN, KC_PPLS, KC_ASTR, _______, _______,
  _______, _______, _______, _______, KC_LBRC, KC_RBRC,                          KC_LBRC, KC_RBRC, KC_EQL,  KC_EQL , _______, _______,
  _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______,        _______, KC_LCBR, KC_RCBR, KC_PMNS, KC_SLSH, _______, _______,
							 _______, _______, _______, _______,        _______, _______, _______, _______
),

};

#ifdef OLED_ENABLE


static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}


static void print_status_narrow(void) {
    // Print header
    oled_write_P(PSTR("\n"), false);
  oled_write_P(PSTR(""), false);
    oled_write_P(PSTR("Lotus -58-"), false);
  oled_write_P(PSTR("\n"), false);


    // Print current layer
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("-Base\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("-Func\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("-Num \n"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }

}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_90;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
	return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
   return state;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
    } else if (index == 1) {
        if (clockwise) {
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_UP);
            }
        }
    return true;
}

#endif


void rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case _FN:
            rgb_matrix_set_color_all(0,30,0);
            break;
        case _NUM:
            rgb_matrix_set_color_all(0,0,10);
            //WASD as arrow keys
            rgb_matrix_set_color(8, RGB_SPRINGGREEN);
            rgb_matrix_set_color(16, RGB_SPRINGGREEN);
            rgb_matrix_set_color(15, RGB_SPRINGGREEN);
            rgb_matrix_set_color(14, RGB_SPRINGGREEN);
            //Num pad

            rgb_matrix_set_color(38, RGB_WHITE); // 7
            rgb_matrix_set_color(37, RGB_WHITE); // 8
            rgb_matrix_set_color(36, RGB_WHITE); // 9

            rgb_matrix_set_color(43, RGB_WHITE); // 4/U
            rgb_matrix_set_color(44, RGB_WHITE); // 5/I
            rgb_matrix_set_color(45, RGB_WHITE); // 6/O

            rgb_matrix_set_color(50, RGB_WHITE); // 1/J
            rgb_matrix_set_color(49, RGB_WHITE); // 2/K
            rgb_matrix_set_color(48, RGB_WHITE); // 3/L

            rgb_matrix_set_color(57, RGB_WHITE); // M/0
            rgb_matrix_set_color(56, RGB_WHITE); // ,/0
            rgb_matrix_set_color(55, RGB_PURPLE); // ./.

            rgb_matrix_set_color(39, RGB_RED); // 0/-
            rgb_matrix_set_color(42, RGB_GREEN); // P/+

            rgb_matrix_set_color(51, RGB_BLUE); // M/ENTER
            rgb_matrix_set_color(54, RGB_BLUE); // ,/ENTER

            break;
        default:
            break;
    }

    if (host_keyboard_led_state().caps_lock) {
        // LHS to red
        for (uint8_t i = 0; i <= 5; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, RGB_RED);
            }
        }
        // RHS to red
        for (uint8_t i = 35; i <= 40; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, RGB_RED);
            }
        }
        // And caps key
        rgb_matrix_set_color(17, RGB_RED);
    }

}
