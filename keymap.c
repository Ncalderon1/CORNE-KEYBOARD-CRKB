/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2022 @toinux

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keycodes.h"
#ifdef OLED_ENABLE
#include "oled.h"
#endif
#include QMK_KEYBOARD_H

#include "sendstring_spanish_latin_america.h"

// TEMPLATE
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |        |        |        |        |        |        |                    |        |        |        |        |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |        |        |        |        |        |                    |        |        |        |        |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |        |        |        |        |        |                    |        |        |        |        |        |        |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |        |        |        |  |        |        |        |
//                                      `--------------------------'  `--------------------------'

enum {
    TD_SLSH,
    TD_BSLS,
    TD_MINS,
    TD_SCLN,
    TD_COMM,
    TD_DOT,
    TD_TAB,
    TD_EQL,
    TD_CAPLOCK,
    TD_QUOT,
    TD_ALT,
    TD_BACKF,
    TD_SPC,
    TD_ARR,
    TD_N_NTIL,
    TD_LPRN,
    TD_RPRN,
};

enum layers {
    _BASE,
    _LOWER,
    _RAISE,
    _CONF,
    _GAMING,
    _FUN,
    _MOUSE,
    _VSCODE
};

enum custom_keycodes {
    CUSTOM_MACRO = SAFE_RANGE,
    PY_IF,
    PY_IF_ELSE,
    PY_FOR,
    PY_WHILE,
    PY_DEF,
    PY_CLASS
};





const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// TEMPLATE
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |  tap   |    ;   |    ,   |    .   |    p   |    y   |                    |    f   |   g    |   c    |   h    |   l    |  bspc  |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |  sls   |   a    |    o   |    e   |    u   |    i   |                    |    d   |   r    |    t   |   n    |   s    |  del   |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |  ctr   |   '    |   q    |   j    |    k   |    x   |                    |    b   |   m    |    w   |   v    |   z    |  ctr   |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |  lower |  alt   |   spc  |  |  spc   |   alt  | raise  |
//                                      `--------------------------'  `--------------------------'


    [_BASE] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
TD(TD_TAB), TD(TD_QUOT), TD(TD_COMM), TD(TD_DOT), KC_P, KC_Y,                    KC_F,    KC_G,    KC_C,    KC_H,    KC_L,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
TD(TD_CAPLOCK), KC_A,   KC_O,    KC_E,    KC_U,    KC_I,                          KC_D,    KC_R,    KC_T,   TD(TD_N_NTIL),  KC_S,    KC_DEL,
  //---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LCTL, ES_SLSH, TD(TD_ARR), KC_J, KC_K,  KC_X,                          KC_B,    KC_M,    KC_W,   KC_V,    KC_Z,   KC_RCTL,
  //---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        MO(_LOWER),TD(TD_ALT),TD(TD_SPC),  TD(TD_SPC),KC_RALT, MO(_VSCODE)
                                      //|--------------------------|  |--------------------------|

    ),
// TEMPLATE
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |   7    |    8   |   9    |    '¨   |    [{  |    [(   |                    |    )]  |   }    |   +    |    =   |   /    |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |   4    |   5    |   6    |    $   |     &  |    @   |                    |   left |  down  |  up    |   rgth |    \   |    del |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |   1    |   2    |    3   |     0  |    `   |    ecp |                    |   cnf  |    *   |    ^   |    !   |    -   |    }    |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |        |    FUN  |      |  |        |        |        |
//                                    `--------------------------'  `--------------------------'ES_EXLM { ES_RCBR *{^}

[_LOWER] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
    KC_7,   KC_8,   KC_9, TD(TD_QUOT) ,  ES_LCBR,  TD(TD_LPRN),                     TD(TD_RPRN), ES_RCBR, KC_PPLS, TD(TD_EQL), TD(TD_SLSH), KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_4,   KC_5,   KC_6,    ES_DLR,   ES_AMPR,  ES_AT,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,   ES_BSLS, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_1,   KC_2,   KC_3,    KC_0,     ES_CIRC, KC_ESC,                  KC_APP,  ES_ASTR, ES_CIRC ,ES_EXLM, ES_MINS, KC_NUHS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS, MO(_FUN), TT(_GAMING),  TD(TD_SPC), KC_RALT, MO(_MOUSE)   

                                        //|--------------------------|  |--------------------------|!!!!!]\\\}]!!!!!!
  ),

// Functions and keypad
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |        |   F1   |   F2   |   F2   |   F4   |        |                    |        |   7    |   8    |   9    |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |   F5   |   F6   |   F7   |   F8   |        |                    |        |   4    |   5    |   6    |   -    |   /    |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |   F9   |   F10  |   F11  |   F12  |        |                    |        |   1    |   2    |   3    |   +    |   *    |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |        |        |        |  |   =    |   0    |   .    |
//     
  [_FUN] = LAYOUT_split_3x6_3(
      _______,   KC_F1,    KC_F2,  KC_F3,   KC_F4, XXXXXXX,                      XXXXXXX,   KC_P7,   KC_P8,   KC_P9, XXXXXXX, _______,
      _______,   KC_F5,    KC_F6,  KC_F7,   KC_F8, XXXXXXX,                      XXXXXXX,   KC_P4,   KC_P5,   KC_P6, KC_PMNS, KC_PSLS,
      KC_LCTL,   KC_F9,   KC_F10, KC_F11,  KC_F12, XXXXXXX,                      XXXXXXX,   KC_P1,   KC_P2,   KC_P3, KC_PPLS, KC_PAST,
                                          KC_RALT, _______, _______,   KC_PENT,    KC_P0, KC_PDOT

  ),

// TEMPLATE
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |        |        |        |        |        |        |                    |        |        |        |        |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |        |        |        |        |        |                    |        |        |        |        |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |        |        |        |        |        |                    |        |        |        |        |        |        |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |        |        |        |  |        |        |        |
//                                      `--------------------------'  `--------------------------'


    [_RAISE] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
    KC_F1,    KC_F2,     KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_END, KC_PGDN, KC_PGUP, KC_HOME, KC_UNDO, KC_AGAIN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                       KC_LEFT , KC_DOWN, KC_UP, KC_RGHT , KC_BRID, KC_BRIU,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_ESC,  KC_SLEP ,  KC_PWR,  KC_CALC, KC_MYCM, KC_PSCR,                      KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU , KC_MPRV, KC_MNXT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LALT, MO(_LOWER),  TD(TD_SPC),    MO(_CONF),MO(_RAISE) ,KC_8
                                      //|--------------------------|  |--------------------------|
    ),

// Mouse
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |        |        | Wh up  | Ms up  | Wh dn  |        |                    |        |        |        |        |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |        | Ms lft | Ms dn  | Ms rgt |        |                    |        |  btn1  |  btn3  |  btn2  |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |        | Wh lft |        | Wh rgt |        |                    |        |        |        |        |        |        |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |        |        |        |  |        |        |        |
//                                      `--------------------------'  `--------------------------'
  [_MOUSE] = LAYOUT_split_3x6_3(
      _______, _______, KC_WH_U, KC_MS_U, KC_WH_D, _______,                      _______, _______, _______, _______, _______, _______,
      _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                      _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______,
      _______, _______, KC_WH_L, _______, KC_WH_R, _______,                      _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______,    _______, _______, _______
\
  ),



// CONF
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |  Reset |        |        |        |        | Print  |                    | Num    | Caps   | Scroll |        |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  | On/Off | Hue ↑  | Sat ↑  | Brght ↑|        |        |                    |        |        |        |        |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  | Cycle  | Hue ↓  | Sat ↓  | Brght ↓|        |        |                    |        |        |        |        |        |        |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |        |        |        |  |        |        |        |
//                                      `--------------------------'  `--------------------------'
[_CONF] = LAYOUT_split_3x6_3(
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,                       KC_NUM, KC_CAPS, KC_SCRL, XXXXXXX, XXXXXXX, XXXXXXX,
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, RGB_M OD,                      RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, RGB_RMOD,                      RGB_SPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                          _______, _______, _______,    _______, _______, _______
  ),           



// TEMPLATE
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |        |        |        |        |        |        |                    |        |        |        |        |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |        |        |        |        |        |                    |        |        |        |        |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |        |        |        |        |        |                    |        |        |        |        |        |        |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |        |        |        |  |        |        |        |
//                                      `--------------------------'  `--------------------------'


    [_GAMING] = LAYOUT_split_3x6_3(
   //  .-----------------------------------------------------.                    .-------------------------------------    ----------------.
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_1,    KC_2,    KC_3,    KC_4,   KC_5,  KC_6,
  //  |--------+--------+--------+--------+--------+--------|    /* _WIN10 */    |--------+--------+--------+--------+--------+--------|
  KC_LEFT_SHIFT, KC_A,    KC_S,   KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,  KC_MINUS, KC_QUOT,
  //  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_Z, SFTENT,
  //  '--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                  KC_ESC, KC_LALT, KC_SPC,                 KC_ESC, TT(_GAMING), RALT_T(KC_CAPS)
                                        //'--------------------------'  '--------------------------------'.
  ),
    
// TEMPLATE
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |        |  DEF   | BUSC   |BUSCall |        | cursor↓   |                    | Redo   |        |  IF    | IF-ELSE|        | RUN    |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        | Com    |Mov↓    |        |        | Cursor↑   |                    | Replace|        | FOR    | WHILE  |        | CONSOLA|
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        | Block  |Mov↑  |        |        |SIMILAR |                    | REPLACE| DEF    |          | CLASS  |        |TERMINAL|
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |  Salt  |   MO   | CLOSE  |  |        |        |        |
//                                      `--------------------------'  `--------------------------'
    [_VSCODE] = LAYOUT_split_3x6_3(
   //  .-----------------------------------------------------.                                         .-------------------------------------    ----------------.
       XXXXXXX, KC_F12,  LCTL(KC_P), LCTL(LSFT(KC_F)),XXXXXXX,LCTL(LALT(KC_UP)),                        LCTL(KC_Y),XXXXXXX,PY_IF,PY_IF_ELSE,XXXXXXX,  LCTL(LSFT(KC_D)),
  //  |--------+--------+--------+--------+--------+--------|                                          |--------+--------+--------+--------+--------+--------|
       XXXXXXX,LCTL(ES_RCBR),LALT(KC_UP),XXXXXXX,XXXXXXX,LCTL(LALT(KC_DOWN)),                           LCTL(KC_H),XXXXXXX,PY_FOR,PY_WHILE,XXXXXXX, LCTL(LSFT(KC_Y)),
  //  |--------+--------+--------+--------+--------+--------|                                          |--------+--------+--------+--------+--------+--------|
        XXXXXXX,LSFT(LALT(KC_A)),LALT(KC_DOWN),XXXXXXX,XXXXXXX, LCTL(KC_D),                             LCTL(LSFT(KC_H)), XXXXXXX,PY_DEF,PY_CLASS,XXXXXXX, LCTL(ES_NTIL),
  //  '--------+--------+--------+--------+--------+--------+--------|                       |--------+--------+--------+--------+--------+--------+--------'
                                  LCTL(KC_G), MO(_RAISE), LCTL(KC_B),                         KC_ESC, MO(_RAISE), MO(_VSCODE)
                                        //'--------------------------'                       '--------------------------------'.
  )


};




// /* 
// Tap Dance definitions
// Tap Dance definitions adaptadas a Español */
tap_dance_action_t tap_dance_actions[] = {  
    // Tap once for /, twice for ?
    [TD_SLSH]    = ACTION_TAP_DANCE_DOUBLE(ES_SLSH, ES_QUES),
    // Tap once for ', twice for "
    [TD_QUOT]    = ACTION_TAP_DANCE_DOUBLE(ES_QUOT, ES_DQUO),
    // Tap once for =, twice for +
    [TD_EQL]     = ACTION_TAP_DANCE_DOUBLE(ES_EQL, ES_PLUS),
    // Tap once for \, twice for |
    [TD_BSLS]    = ACTION_TAP_DANCE_DOUBLE(ES_BSLS, ES_PIPE),
    // Tap once for -, twice for _
    [TD_SCLN]    = ACTION_TAP_DANCE_DOUBLE(ES_SCLN, ES_COLN),
    // Tap once for ,, twice for ;
    [TD_COMM]    = ACTION_TAP_DANCE_DOUBLE(ES_COMM, ES_SCLN),
    // Tap once for ., twice for :
    [TD_DOT]     = ACTION_TAP_DANCE_DOUBLE(ES_DOT, ES_COLN),
    // Tap once for `, twice for ~
    [TD_BACKF]   = ACTION_TAP_DANCE_DOUBLE(ES_GRV, ES_TILD),
    // Tap once for Tab, twice for Esc
    [TD_TAB]     = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
    // Tap once for Shift, twice for Caps Lock
    [TD_CAPLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    // Tap once for Alt, twice for GUI
    [TD_ALT]     = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_LGUI),
    // Tap once for q, twice for @
    [TD_ARR]     = ACTION_TAP_DANCE_DOUBLE(KC_Q, ES_AT),
    // Tap once for Space, twice for Enter
    [TD_SPC]     = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT), 
    // Tap once for n, twice for ñ
    [TD_N_NTIL]  = ACTION_TAP_DANCE_DOUBLE(KC_N, ES_NTIL),   
    //tap para } y ] ES_LCBR
    [TD_LPRN]  = ACTION_TAP_DANCE_DOUBLE(ES_LPRN, ES_LBRC),  
    [TD_RPRN]  = ACTION_TAP_DANCE_DOUBLE(ES_RPRN, ES_RBRC),  


};


// =======================
// Control de capas y RGB
// =======================

// Variable para detectar si el usuario cambió manualmente los efectos (opcional)
static bool user_changed_effect = false;

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTRLSC:
            return true;
        default:
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (record->event.pressed) {
        switch (keycode) {
            case _FUN:
                if (!host_keyboard_led_state().num_lock) {
                    tap_code(KC_NUM_LOCK);
                }
                break;

            // Detecta si el usuario cambia RGB manualmente
            case RGB_MOD:
            case RGB_RMOD:
            case RGB_TOG:
            case RGB_HUI:
            case RGB_HUD:
            case RGB_SAI:
            case RGB_SAD:
            case RGB_VAI:
            case RGB_VAD:
                user_changed_effect = true;
                break;

            // ===================== SNIPPETS PYTHON =====================
            case PY_IF:
                SEND_STRING("if : " SS_TAP(X_LEFT) SS_TAP(X_TAB));
                return false;

            case PY_IF_ELSE:
                SEND_STRING("if : " SS_TAP(X_LEFT)  SS_TAP(X_TAB) 
                            SS_TAP(X_ENTER) "else:" SS_TAP(X_ENTER) SS_TAP(X_TAB));
                return false;

            case PY_FOR:
                SEND_STRING("for i in range():" SS_TAP(X_LEFT) SS_TAP(X_LEFT)
                             SS_TAP(X_TAB));
                return false;

            case PY_WHILE:
                SEND_STRING("while :" SS_TAP(X_LEFT) SS_TAP(X_TAB));
                return false;

            case PY_DEF:
                SEND_STRING("def function_name():" SS_TAP(X_LEFT) SS_TAP(X_LEFT)
                             SS_TAP(X_TAB));
                return false;

            case PY_CLASS:
                SEND_STRING("class ClassName:"  SS_TAP(X_TAB));
                return false;



            // ===================== ATAJOS VSCODE =====================

        }
    }
    return true;
}


layer_state_t layer_state_set_user(layer_state_t state) {
    if (!user_changed_effect) {
        switch (get_highest_layer(state)) {
            case _BASE:
                rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
                rgb_matrix_sethsv_noeeprom(0, 255, 200); // Púrpura 
                break;
            case _LOWER:
                rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS);
                rgb_matrix_sethsv_noeeprom(85, 255, 200); // Verde
                break;
            case _RAISE:
                rgb_matrix_mode_noeeprom(RGB_MATRIX_MULTISPLASH);
                rgb_matrix_sethsv_noeeprom(0, 255, 200); // Rojo
                break;
            case _GAMING:
                rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS);
                rgb_matrix_sethsv_noeeprom(300, 255, 200); // Púrpura
                break;
            case _CONF:
                rgb_matrix_mode_noeeprom(RGB_MATRIX_BAND_VAL);
                rgb_matrix_sethsv_noeeprom(43, 255, 200); // Amarillo
                break;
            default:
                //rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
                rgb_matrix_mode_noeeprom(RGB_MATRIX_MULTISPLASH);
                rgb_matrix_sethsv_noeeprom(300, 255, 200); // Púrpura
                break;
        }
    }
    return state;
}

void keyboard_post_init_user(void) {
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    rgb_matrix_enable_noeeprom();                          // Activa el RGB al inicio
    rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);   // Efecto inicial para BASE
    rgb_matrix_sethsv_noeeprom(85, 255, 200); // Verde           // HUE:180 (azul), SAT:255, VAL:200 (brillo)
    rgb_matrix_set_speed_noeeprom(32);                    // Velocidad media
#endif
}

bool rgb_matrix_indicators_user(void) {
    if (!rgb_matrix_is_enabled()) return true;

    HSV base_hsv = rgb_matrix_get_hsv(); // Obtiene el HSV actual del efecto
    for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        // Respeta LEDs que son parte del efecto reactivo
        if (HAS_ANY_FLAGS(g_led_config.flags[i], (LED_FLAG_MODIFIER | LED_FLAG_KEYLIGHT))) {
            continue;
        }

        // Calcula arco iris dinámico en base al hue actual + desplazamiento
        uint16_t hue = (base_hsv.h + (i * 360 / RGB_MATRIX_LED_COUNT)) % 360;
        HSV hsv = { hue, 255, 40 }; // Brillo bajo para no competir
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

    return true;
}





