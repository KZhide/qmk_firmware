RGB_MATRIX_EFFECT(my_media_effect)
RGB_MATRIX_EFFECT(my_symbol_effect)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
    static bool my_media_effect(effect_params_t* params) {
        RGB_MATRIX_USE_LIMITS(led_min, led_max);

        HSV hsv = rgb_matrix_config.hsv;
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);

        rgb_matrix_set_color_all(0, 0, 0);

        rgb_matrix_set_color(8, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(12, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(13, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(14, rgb.r, rgb.g, rgb.b);
        return rgb_matrix_check_finished_leds(led_max);
    }

    static bool my_symbol_effect(effect_params_t* params) {
        RGB_MATRIX_USE_LIMITS(led_min, led_max);

        HSV hsv = rgb_matrix_config.hsv;
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);

        for(uint8_t i = led_min; i < led_max; i++) {
            if ((i >= 6 && i < 9) || (i >= 11 && i < 14) || (i >= 16 && i < 19) || i == 22) {
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            } else if ((i >= 30 && i < 32) || (i >= 35 && i < 37) || (i >= 40 && i < 42)) {
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            } else {
                rgb_matrix_set_color(i, 0, 0, 0);
            }
        }
        return rgb_matrix_check_finished_leds(led_max);
    }
#endif
