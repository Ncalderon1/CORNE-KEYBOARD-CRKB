#include QMK_KEYBOARD_H
#include <stdio.h> 
#include "layers.h"

// Logo CRKBD (en el master)
static void render_crkbd_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        // Datos del logo (los que ya tienes)
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(crkbd_logo, false);
}

// Mensajes motivacionales para el esclavo
const char* messages[] = {
    "Ctrl + Alt + Succes",
    "Error 404: Motivacion no encontrada",
    "Push y sigue!",
    "Compila tus sueños!",
    "Segunda taza de cafe, activada",
    "Tu bug no te define",
    "Debuguea la vida!",
    "Casi lo logras!",
    "Git commit y a seguir",
    "No procrastines... mucho",
    "Sigue tipeando!",
    "Café, teclado y gloria",
};


#define NUM_MESSAGES (sizeof(messages)/sizeof(messages[0]))
static uint8_t message_index = 0;
static uint32_t last_update = 0;
#define MESSAGE_DELAY 5000 // 5 segundos

// Mostrar layer en una sola línea + mensaje motivacional
// Mostrar layer en una línea y mensaje motivacional en la línea siguiente
static void render_layer_state(void) {
    oled_clear(); // limpia todo antes de escribir

    // Mostrar la capa actual en la primera línea
    oled_set_cursor(0, 0); 
    oled_write_P(PSTR("Layer: "), false); 
    switch (get_highest_layer(layer_state)) {
        case _BASE: oled_write_P(PSTR("Base"), false); break;
        case _LOWER: oled_write_P(PSTR("Lower"), false); break;
        case _RAISE: oled_write_P(PSTR("Raise"), false); break;
        case _CONF: oled_write_P(PSTR("CONF"), false); break;
        case _GAMING: oled_write_P(PSTR("Gaming"), false); break;
        case _FUN: oled_write_P(PSTR("Fun"), false); break;
        case _MOUSE: oled_write_P(PSTR("Mouse"), false); break;
        case _VSCODE: oled_write_P(PSTR("VSCode"), false); break;
        default: oled_write_P(PSTR("Undefined"), false); break;
    }

    // Actualizar mensaje motivacional cada MESSAGE_DELAY
    if (timer_elapsed32(last_update) > MESSAGE_DELAY) {
        message_index++;
        if (message_index >= NUM_MESSAGES) message_index = 0;
        last_update = timer_read32();
    }

    // Mostrar mensaje en la segunda línea con un corazón
    oled_set_cursor(0, 1); // segunda línea
    char buf[32];
    snprintf(buf, sizeof(buf), " %s", messages[message_index]);
    oled_write(buf, false);
}


bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_crkbd_logo();
    } else {
        render_layer_state();
    }
    return false;
}
