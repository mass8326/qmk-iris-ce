#include QMK_KEYBOARD_H
#include "set_colors.h"
#include "seeded_rand.h"

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

static uint16_t leader_time_user;

void leader_start_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_WHITE);
    leader_time_user = timer_read();
}

void leader_end_user(void) {
    bool success = true;
    // d2
    if (leader_sequence_one_key(KC_2)) {
        print_roll(2, timer_elapsed(leader_time_user));
    } else if (leader_sequence_two_keys(KC_R, KC_2)) {
        SEND_STRING("/r 1d2");
    } else
    // d4
    if (leader_sequence_one_key(KC_4)) {
        print_roll(4, timer_elapsed(leader_time_user));
    } else if (leader_sequence_two_keys(KC_R, KC_4)) {
        SEND_STRING("/r 1d4");
    } else
    // d6
    if (leader_sequence_one_key(KC_6)) {
        print_roll(6, timer_elapsed(leader_time_user));
    } else if (leader_sequence_two_keys(KC_R, KC_6)) {
        SEND_STRING("/r 1d6");
    } else
    // d8
    if (leader_sequence_one_key(KC_8)) {
        print_roll(8, timer_elapsed(leader_time_user));
    } else if (leader_sequence_two_keys(KC_R, KC_8)) {
        SEND_STRING("/r 1d8");
    } else
    // d10
    if (leader_sequence_two_keys(KC_1, KC_0)) {
        print_roll(10, timer_elapsed(leader_time_user));
    } else if (leader_sequence_three_keys(KC_R, KC_1, KC_0)) {
        SEND_STRING("/r 1d10");
    } else
    // d12
    if (leader_sequence_two_keys(KC_1, KC_2)) {
        print_roll(12, timer_elapsed(leader_time_user));
    } else if (leader_sequence_three_keys(KC_R, KC_1, KC_2)) {
        SEND_STRING("/r 1d12");
    } else
    // d20
    if (leader_sequence_two_keys(KC_2, KC_0)) {
        print_roll(20, timer_elapsed(leader_time_user));
    } else if (leader_sequence_three_keys(KC_R, KC_2, KC_0)) {
        SEND_STRING("/r 1d20");
    } else
    // d100
    if (leader_sequence_three_keys(KC_1, KC_0, KC_0)) {
        print_roll(100, timer_elapsed(leader_time_user));
    } else if (leader_sequence_four_keys(KC_R, KC_1, KC_0, KC_0)) {
        SEND_STRING("/r 1d100");
    } else
    // Rest
    {
        success = false;
    }

    if (success) {
        rgb_matrix_sethsv_noeeprom(HSV_GREEN);
    } else {
        rgb_matrix_sethsv_noeeprom(HSV_RED);
    }
    defer_exec(300, deferred_reset, NULL);
}
