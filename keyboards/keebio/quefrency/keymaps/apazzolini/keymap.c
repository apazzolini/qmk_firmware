#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum layer_names {
  _QWERTY,
  _WINDOWS,
  _GAMING,
  _META,
  _RAISE,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  WINDOWS,
  GAMING,
  META,
  RAISE,
};

#define KC_QWER QWERTY
#define KC_GAME GAMING
#define KC_WIND WINDOWS
#define KC_RASE MO(_RAISE)
/* #define KC_META LT(_META, KC_BSPC) */
#define KC_META MO(_META)

#define KC_ KC_TRNS
#define KC_RST RESET
#define KC_CTES LCTL_T(KC_ESC)
#define KC_PCBR LGUI(KC_LCBR)
#define KC_NCBR LGUI(KC_RCBR)
#define KC_PBRC LGUI(KC_LBRC)
#define KC_NBRC LGUI(KC_RBRC)
#define KC_NOTE LALT(KC_I)
#define KC_MSPC LGUI(KC_SPC)
#define KC_TERM LCTL(LSFT(KC_A))
#define KC_WVDP LGUI(LCTL(KC_LEFT))
#define KC_WVDN LGUI(LCTL(KC_RGHT))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Default layer: http://www.keyboard-layout-editor.com/#/gists/60a262432bb340b37d364a4424f3037b */
  [_QWERTY] = LAYOUT_65(
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  KC_ESC,   KC_MPLY,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,            KC_DEL,
    KC_CTES,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_PGUP,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,                      KC_UP,    KC_PGDN,
    KC_RASE,  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_META,                      _______,  KC_SPC,   KC_RASE,  KC_RALT,  KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [_WINDOWS] = LAYOUT_65(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,           _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,           _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                     _______,  _______,
    KC_LCTL,  KC_RASE,  KC_LGUI,  KC_LALT,  _______,                      _______,  _______,  _______,  _______,  _______,            _______, _______,  _______
  ),

  [_GAMING] = LAYOUT_65(
    KC_ESC,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,           _______,
    KC_LCTL,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,           _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                     _______,  _______,
    _______,  _______,  KC_RASE,  _______,  KC_SPC,                       _______,  _______,  _______,  _______,  KC_RGUI,            _______, _______,  _______
  ),

  [_META] = LAYOUT_65(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,
    _______,  _______,  _______,  KC_BSLS,  KC_PIPE,  KC_AMPR,  KC_WVDP,  KC_WVDN,  KC_PCBR,  KC_NCBR,  KC_NOTE,  KC_PBRC,  KC_NBRC,  _______,           _______,
    _______,  KC_TERM,  _______,  KC_PLUS,  KC_EQL,   KC_UNDS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,            _______,           KC_HOME,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                     _______,  KC_END,
    _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,            _______, _______,  _______
  ),

  [_RAISE] = LAYOUT_65(
    KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,   RESET,    RGB_TOG,
    _______,  _______,  KC_MPLY,  KC_VOLU,  _______,  _______,  _______,  _______,  KC_PSCR,  KC_SLCK,  KC_PAUS,  _______,  _______,  _______,            RGB_SAI,
    _______,  _______,  KC_MPRV,  KC_VOLD,  KC_MNXT,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,            _______,            RGB_SAD,
    _______,  KC_QWER,  KC_WIND,  KC_GAME,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_HUD,                      RGB_VAI,  RGB_HUI,
    _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,            RGB_RMOD, RGB_VAD,  RGB_MOD
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        layer_off(_GAMING);
        layer_off(_WINDOWS);
      }
      return false;
    case WINDOWS:
      if (record->event.pressed) {
        layer_on(_WINDOWS);
        layer_off(_GAMING);
      }
      return false;
    case GAMING:
      if (record->event.pressed) {
        layer_on(_WINDOWS);
        layer_on(_GAMING);
      }
      return false;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    tap_code(KC_VOLU);
  } else {
    tap_code(KC_VOLD);
  }
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
