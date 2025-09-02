#include QMK_KEYBOARD_H
#include "keycodes.h"

__attribute__((weak)) void keyboard_post_init_user(void) {
    // Activamos el efecto arcoíris y brillo máximo al iniciar
    rgb_matrix_mode(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
    rgb_matrix_sethsv_noeeprom(HSV_WHITE); // Puedes cambiar HSV si quieres otro tono
    rgb_matrix_set_speed(128); // Velocidad media (0-255)
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Solo añadimos indicador de Caps Lock (rojo)
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(25, RGB_RED);  // Ajusta el índice según tu teclado
    }
    return false; // Mantener efecto activo
}
