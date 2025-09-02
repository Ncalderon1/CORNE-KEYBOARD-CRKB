MOUSEKEY_ENABLE   = yes    # Mouse keys
RGBLIGHT_ENABLE   = no
OLED_ENABLE       = yes
LTO_ENABLE        = yes
OLED_DRIVER_ENABLE = yes


SRC += ./oled.c ./rgb.c


# Habilitar la matriz RGB
RGB_MATRIX_ENABLE = yes

# Efectos RGB habilitados
RGB_MATRIX_EFFECT_BREATHING = yes
RGB_MATRIX_EFFECT_RAINBOW_SWIRL = yes
RGB_MATRIX_EFFECT_RAINBOW_MOVING_CHEVRON = yes
RGB_MATRIX_EFFECT_SOLID_COLOR = yes
RGB_MATRIX_EFFECT_SPLASH = yes

# Otras configuraciones que ya tenías
NKRO_ENABLE = yes


#tap dance habilitado
TAP_DANCE_ENABLE = yes
