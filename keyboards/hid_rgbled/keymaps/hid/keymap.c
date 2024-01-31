// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <raw_hid.h>

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_ortho_1x1(KC_A)
};
// clang-format on

void keyboard_post_init_user(void) {
    rgblight_enable();
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
    // `data` is a pointer to the buffer containing the received HID report
    // `length` is the length of the report - always `RAW_EPSIZE`
    uint8_t response[length];
    memset(response, 0, length);
    response[0] = 'B';
    if (data[0] == 'A') {
        raw_hid_send(response, length);
    }
}
