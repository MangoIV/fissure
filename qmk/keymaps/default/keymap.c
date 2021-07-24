#include "fissure.h"
#include "action_layer.h"

// Layers
#define _BASE  0
#define _LOWER 1
#define _RAISE 2

#define KEYMAP( \
    L40, L10, L11, L12, L13, L14,                 R10, R11, R12, R13, R14, R44, \
    L41, L20, L21, L22, L23, L24,                 R20, R21, R22, R23, R24, R43, \
         L30, L31, L32, L33, L34,                 R30, R31, R32, R33, R34, \
                        L42, L43, L44,            R40, R41, R42 \
    ) \
    { \
        { L10, L11, L12, L13, L14 }, \
        { L20, L21, L22, L23, L24 }, \
        { L30, L31, L32, L33, L34 }, \
        { L40, L41, L42, L43, L44 }, \
        { R14, R13, R12, R11, R10 }, \
        { R24, R23, R22, R21, R20 }, \
        { R34, R33, R32, R31, R30 }, \
        { R44, R43, R42, R41, R40 } \
    }

void set_hsv(uint8_t a, uint8_t b, uint8_t c) {
    rgblight_sethsv(a, b, (uint8_t) c * 0.15);
}

void keyboard_pre_init_user(void) {
    set_hsv(HSV_TEAL);
}

void suspend_power_down_user() {
    set_hsv(0, 0, 0);
}

void suspend_wakeup_init_user() {
    set_hsv(0, 0, 0);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (biton32(state)) {
    case _LOWER: set_hsv(HSV_GREEN); break;
    case _RAISE: set_hsv(HSV_CYAN); break;
    default: set_hsv(0, 0, 0); break;
    }
    return state;
}

#define DEL MT(MOD_LGUI, KC_DEL)
#define TAB MT(MOD_LCTL, KC_TAB)
#define ESC LT(_RAISE, KC_ESC)
#define ENT LT(_LOWER, KC_ENT)
#define SPC MT(MOD_LSFT, KC_SPC)
#define BKSP MT(MOD_LALT, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = KEYMAP(
        XXXXXXX, KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,        KC_I,       KC_O,        KC_P, XXXXXXX,
        XXXXXXX, KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,        KC_K,       KC_L,     KC_SCLN, XXXXXXX,
                 KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,      KC_N,     KC_M,     KC_COMM,     KC_DOT,     KC_SLSH,
                  DEL,      TAB,      ESC,      ENT,      SPC,     BKSP),

    [_LOWER] = KEYMAP(
        XXXXXXX, G(KC_1),  G(KC_2),  G(KC_3),  G(KC_4),  G(KC_5),   G(KC_6),  G(KC_7),  G(KC_8),  KC_F11,  KC_F12, XXXXXXX,
        XXXXXXX,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,    KC_9,    KC_0, XXXXXXX,
                   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,   KC_F9,  KC_F10,
                 _______,  _______,  _______,  _______,  _______,  _______),

    [_RAISE] = KEYMAP(
        XXXXXXX, KC_BRID,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_BRIU,     KC_HOME,     KC_PGDN,   KC_PGUP,       KC_END,  KC_PSCR, XXXXXXX,
        XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     KC_LEFT,     KC_DOWN,     KC_UP,     KC_RIGHT,  XXXXXXX, XXXXXXX,
                 XXXXXXX,  KC_MPRV,  KC_MPLY,  KC_MNXT,  XXXXXXX,  C(KC_LEFT),  C(KC_DOWN),  C(KC_UP),  C(KC_RIGHT),  XXXXXXX,
                 _______,  _______,  _______,  _______,  _______,    _______),
};

const uint16_t PROGMEM combos[COMBO_COUNT][3] = {
    {KC_W, KC_E, COMBO_END},
    {KC_E, KC_R, COMBO_END},
    {KC_A, KC_S, COMBO_END},
    {KC_S, KC_D, COMBO_END},
    {KC_D, KC_F, COMBO_END},
    {KC_Z, KC_X, COMBO_END},
    {KC_X, KC_C, COMBO_END},
    {KC_C, KC_V, COMBO_END},
    {KC_W, KC_S, COMBO_END},
    {KC_S, KC_X, COMBO_END},
    {KC_E, KC_D, COMBO_END},
    {KC_D, KC_C, COMBO_END},
    {KC_R, KC_F, COMBO_END},
    {KC_F, KC_V, COMBO_END},
    {KC_U, KC_I, COMBO_END},
    {KC_I, KC_O, COMBO_END},
    {KC_J, KC_K, COMBO_END},
    {KC_K, KC_L, COMBO_END},
    {KC_L, KC_SCLN, COMBO_END},
    {KC_M, KC_COMM, COMBO_END},
    {KC_COMM, KC_DOT, COMBO_END},
    {KC_U, KC_J, COMBO_END},
    {KC_J, KC_M, COMBO_END},
    {KC_I, KC_K, COMBO_END},
    {KC_K, KC_COMM, COMBO_END},
    {KC_O, KC_L, COMBO_END},
    {KC_L, KC_DOT, COMBO_END},
    {KC_DOT, KC_SLSH, COMBO_END},
};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combos[0], KC_BSLS),
    COMBO(combos[1], KC_LBRC),
    COMBO(combos[2], KC_CIRC),
    COMBO(combos[3], KC_DLR),
    COMBO(combos[4], KC_LPRN),
    COMBO(combos[5], KC_EXLM),
    COMBO(combos[6], KC_AT),
    COMBO(combos[7], KC_LCBR),
    COMBO(combos[8], KC_GRV),
    COMBO(combos[9], KC_TILD),
    COMBO(combos[10], KC_AMPR),
    COMBO(combos[11], KC_PIPE),
    COMBO(combos[12], KC_ASTR),
    COMBO(combos[13], KC_HASH),
    COMBO(combos[14], KC_RBRC),
    COMBO(combos[15], KC_PLUS),
    COMBO(combos[16], KC_RPRN),
    COMBO(combos[17], KC_EQL),
    COMBO(combos[18], KC_COLN),
    COMBO(combos[19], KC_RCBR),
    COMBO(combos[20], KC_PERC),
    COMBO(combos[21], KC_UNDS),
    COMBO(combos[22], KC_MINS),
    COMBO(combos[23], KC_DQUO),
    COMBO(combos[24], KC_LT),
    COMBO(combos[25], KC_QUOT),
    COMBO(combos[26], KC_GT),
    COMBO(combos[27], KC_QUES),
};
