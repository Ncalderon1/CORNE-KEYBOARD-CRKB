#include QMK_KEYBOARD_H
#include <stdio.h>

// Incluir el bitmap generado
static const char PROGMEM logo_bitmap[] = {
    #include "logo_bitmap.c"  // Este archivo contiene el array del logo
};

bool oled_task_user(void) {
    // Limpia la pantalla
    oled_clear();

    // Muestra el logo centrado en la OLED
    oled_write_raw_P(logo_bitmap, sizeof(logo_bitmap));

    return false;  // No se necesitan más actualizaciones
}
