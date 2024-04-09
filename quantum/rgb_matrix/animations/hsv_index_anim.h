#ifdef ENABLE_RGB_MATRIX_HSV_INDEX
RGB_MATRIX_EFFECT(HSV_INDEX)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include "hsv_table.h"

bool HSV_INDEX(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        uint8_t index = g_led_config.point[i].x / 15;
        HSV hsv = { hsvtable[index][0], hsvtable[index][1], hsvtable[index][2] };
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}


#    endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif     // DISABLE_RGB_HSV_INDEX
