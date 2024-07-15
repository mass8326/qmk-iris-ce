#include QMK_KEYBOARD_H
#include "set_colors.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {};

layer_state_t layer_state_set_user(layer_state_t layer_state) {
    set_colors(layer_state, host_keyboard_led_state());
    return layer_state;
}

bool led_update_user(led_t led_state) {
    set_colors(layer_state, led_state);
    return true;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(2, KC_SPACE):
        case LT(3, KC_SPACE):
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}
