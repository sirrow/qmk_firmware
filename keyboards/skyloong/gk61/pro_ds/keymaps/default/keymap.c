// Copyright 2021 JZ-Skyloong (@JZ-Skyloong)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _WIN,
    _MAC,
    _WIN_INDEX,
    _MAC_INDEX,
    _HHKB
};

enum tap_hold_keys {
    _DN_MU   //Tap--KC_DOWN  and  Hold--KC_APP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Bsp│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Tab│ Q │ W │ E | R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ \ │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Cap│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │   |Ent│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │   |Sft|   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Ctl│GUI│Alt│   │Spc│Mut│   │   |Spc|Alt│App│Ctl│   │Mo1|
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [_WIN] = LAYOUT_all(
         KC_ESC,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,        KC_6,     KC_7,        KC_8,      KC_9,                    KC_0,      KC_MINS,        KC_EQL,           KC_BSPC,
         KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,        KC_Y,     KC_U,        KC_I,      KC_O,                     KC_P,     KC_LBRC,       KC_RBRC,           KC_BSLS,
        KC_LCTL,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,        KC_H,     KC_J,        KC_K,      KC_L,                  KC_SCLN,     KC_QUOT,                           KC_ENT,
        KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,        KC_N,     KC_M,     KC_COMM,    KC_DOT,                  KC_SLSH,              LT(_HHKB, KC_UP),
        KC_LCTL,  KC_LGUI,  KC_LALT,             KC_SPC,   KC_SPC,                             KC_SPC,   KC_RALT,  LT(_WIN_INDEX, KC_LEFT),    TD(_DN_MU),                  RCTL_T(KC_RIGHT)
    ),

     [_MAC] = LAYOUT_all(
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,     _______,   _______,                    _______,     _______,      _______,           _______,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,     _______,   _______,                    _______,     _______,      _______,           _______,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,     _______,   _______,                    _______,     _______,                         _______,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,     _______,   _______,                    _______,             LT(_HHKB, KC_UP),
        _______,  KC_LALT,  KC_LGUI,            _______,  _______,                            _______,   KC_RGUI,    LT(_MAC_INDEX, KC_LEFT),   RALT_T(KC_DOWN),           RCTL_T(KC_RIGHT)
    ),

    [_WIN_INDEX] =  LAYOUT_all(
        KC_GRV ,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,
        _______,  _______,    TO(0),    TO(1),  _______,  _______,     _______,  _______,  _______,  _______,  RGB_M_P,  RGB_RMOD, RGB_RMOD, RGB_TOG,
        KC_CAPS,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,  _______,  RGB_SPD,  RGB_SPI,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  RGB_VAD,  RGB_VAI,  KC_UP,              _______,
        _______,  _______,  _______,            _______,  _______,                         _______,  KC_LEFT,  _______,  KC_DOWN,            KC_RIGHT
    ),

    [_MAC_INDEX] = LAYOUT_all(
        KC_GRV ,   KC_F14,   KC_F15,  C(KC_UP),  G(KC_D),  G(KC_SPC),   LAG(KC_EJCT),  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,   KC_VOLD,  KC_VOLU,  KC_DEL,
        _______,  _______,    TO(0),     TO(1),  _______,    _______,     _______,  _______,  _______,  _______,  RGB_M_P,  RGB_RMOD, RGB_RMOD, RGB_TOG,
        KC_CAPS,  _______,  _______,   _______,  _______,    _______,     _______,  _______,  _______,  _______,  RGB_SPD,   RGB_SPI,           _______,
        _______,  _______,  _______,   _______,  _______,    _______,     _______,  _______,  RGB_VAD,  RGB_VAI,  KC_UP,              _______,
        _______,  _______,  _______,             _______,    _______,                         _______,  KC_LEFT,  _______,   KC_DOWN,           KC_RIGHT
    ),

     [_HHKB] = LAYOUT_all(
        KC_GRV ,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,    KC_F7,     KC_F8,     KC_F9,                      KC_F10,      KC_F11,      KC_F12,             KC_DEL,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,     _______,   _______,                    _______,     KC_UP,      _______,           _______,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,     KC_HOME,   KC_PGUP,                    KC_LEFT,     KC_RIGHT,                         _______,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,     KC_END ,   KC_PGDN,                    KC_DOWN,              _______,
        _______,  _______,  _______,            _______,  _______,                            _______,   _______,    _______,   _______,           _______
    )

};

