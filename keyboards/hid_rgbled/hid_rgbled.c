#include "hid_rgbled.h"

#include <raw_hid.h>
#include <rgblight.h>

void keyboard_post_init_kb(void) {
    rgblight_enable();
    rgblight_sethsv_noeeprom(0, 0, 0);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    keyboard_post_init_user();
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
    switch (data[0]) {
        case HID_PING:
            data[0] = 1;
            data[1] = 'R';
            data[2] = 'G';
            data[3] = 'B';
            break;
        case HID_SET_HSV:
            rgblight_sethsv_noeeprom(data[1], data[2], data[3]);
            data[0] = 1;
            break;
        case HID_SET_RGB:
            rgblight_setrgb(data[1], data[2], data[3]);
            data[0] = 1;
            break;
        default:
            data[1] = data[0];
            data[0] = 0;
            break;
    }
    raw_hid_send(data, length);
}
