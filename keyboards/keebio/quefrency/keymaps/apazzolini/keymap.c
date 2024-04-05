#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum layer_names {
    _QWERTY,
    _GAMING,
    _META,
    _RAISE,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    GAMING,
    META,
    RAISE,
    KC_USB1,
    KC_USB2,
};

/* #define KC_QWER QWERTY */
/* #define KC_GAME TG(_GAMING) */
#define KC_GAME GAMING
#define KC_RASE MO(_RAISE)
#define KC_META MO(_META)

#define KC_ KC_TRNS
#define KC_RST QK_BOOT
#define KC_CTES LCTL_T(KC_ESC)
#define KC_CMD9 LALT(KC_9)
#define KC_CMD0 LALT(KC_0)
#define KC_PCBR LALT(KC_LCBR)
#define KC_NCBR LALT(KC_RCBR)
#define KC_PBRC LALT(KC_LBRC)
#define KC_NBRC LALT(KC_RBRC)
#define KC_MSPC LALT(KC_SPC)
#define KC_WVDP LALT(LCTL(KC_LEFT))
#define KC_WVDN LALT(LCTL(KC_RGHT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default layer: http://www.keyboard-layout-editor.com/#/gists/60a262432bb340b37d364a4424f3037b */
    [_QWERTY] = LAYOUT_65(
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  _______,  KC_MPLY,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,            KC_DEL,
        KC_CTES,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_PGUP,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,                      KC_UP,    KC_PGDN,
        KC_LCTL,  KC_RASE,  KC_LGUI,  KC_LALT,  KC_META,                      _______,  KC_SPC,   KC_RASE,  KC_RALT,  KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

    [_GAMING] = LAYOUT_65(
        KC_ESC,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,           _______,
        KC_LCTL,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,           _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                     _______,  _______,
        _______,  _______,  _______,  _______,  KC_SPC,                       _______,  _______,  _______,  KC_META,  _______,            _______, _______,  _______
    ),

    [_META] = LAYOUT_65(
        _______,  KC_USB1,  KC_USB2,  _______,  _______,  _______,  _______,  _______,  _______,  KC_CMD9,  KC_CMD0,  _______,  _______,  _______, _______,  _______,
        _______,  _______,  _______,  KC_BSLS,  KC_PIPE,  KC_AMPR,  KC_WVDP,  KC_WVDN,  KC_PCBR,  KC_NCBR,  _______,  KC_PBRC,  KC_NBRC,  _______,           _______,
        _______,  _______,  _______,  KC_PLUS,  KC_EQL,   KC_UNDS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,            _______,           KC_HOME,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                     _______,  KC_END,
        _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,            _______, _______,  _______
    ),

    [_RAISE] = LAYOUT_65(
        KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   DB_TOGG,  KC_RST,   RGB_TOG,
        _______,  _______,  KC_MPLY,  KC_VOLU,  _______,  _______,  _______,  _______,  KC_PSCR,  KC_SCRL,  KC_PAUS,  _______,  _______,  KC_SCRL,            RGB_SAI,
        _______,  _______,  KC_MPRV,  KC_VOLD,  KC_MNXT,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,            _______,            RGB_SAD,
        _______,  KC_GAME,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_HUD,                      RGB_VAI,  RGB_HUI,
        _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,            RGB_RMOD, RGB_VAD,  RGB_MOD
    ),
};

typedef union {
    uint32_t raw;
    struct {
        bool is_gaming :1;
    };
} user_config_t;

user_config_t user_config;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GAMING:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_GAMING)) {
                    layer_off(_GAMING);
                    user_config.is_gaming = 0;
                    eeconfig_update_user(user_config.raw);
                } else {
                    layer_on(_GAMING);
                    user_config.is_gaming = 1;
                    eeconfig_update_user(user_config.raw);
                }
            }
            return false;
        case KC_USB1:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_RCTL) SS_DELAY(10) SS_TAP(X_RCTL) SS_DELAY(10) SS_TAP(X_1) SS_DELAY(10) SS_TAP(X_ENT));
            }
            return false;
        case KC_USB2:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_RCTL) SS_DELAY(10) SS_TAP(X_RCTL) SS_DELAY(10) SS_TAP(X_2) SS_DELAY(10) SS_TAP(X_ENT));
            }
            return false;
    }

    return true;
}

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
    if (user_config.is_gaming) {
        layer_on(_GAMING);
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return false;
}

/*
[BLANK] = LAYOUT_65(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,           _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,           _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                     _______,  _______,
    _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,            _______, _______,  _______
),
*/
