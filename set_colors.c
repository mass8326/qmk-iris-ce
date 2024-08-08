#include "quantum.h"

void set_colors(layer_state_t layer_state, led_t led_state) {
    const bool          caps_lock = led_state.caps_lock;
    const layer_state_t layer     = get_highest_layer(layer_state);

    if (caps_lock) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
        rgb_matrix_sethsv_noeeprom(HSV_RED);
        rgb_matrix_set_speed_noeeprom(255);
        return;
    }

    switch (layer) {
        case 5:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
            rgb_matrix_sethsv_noeeprom(5, 255, 255);
            rgb_matrix_set_speed_noeeprom(255);
            break;
        case 4:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
            rgb_matrix_sethsv_noeeprom(HSV_YELLOW);
            rgb_matrix_set_speed_noeeprom(255);
            break;
        case 3:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
            rgb_matrix_set_speed_noeeprom(255);
            break;
        case 2:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
            rgb_matrix_sethsv_noeeprom(HSV_CYAN);
            rgb_matrix_set_speed_noeeprom(255);
            break;
        case 1:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_PURPLE);
            break;
        case 0:
            rgb_matrix_reload_from_eeprom();
            break;
    }
}

uint32_t deferred_reset(uint32_t trigger_time, void *cb_arg) {
    set_colors(layer_state, host_keyboard_led_state());
    return 0;
}
