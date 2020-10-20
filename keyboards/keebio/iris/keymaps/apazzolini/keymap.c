#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum layer_names {
    _QWERTY,
    _WINDOWS,
    _GAMING,
    _LOWER,
    _RAISE,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  WINDOWS,
  GAMING,
  RAISE,
  LOWER,
};

#define KC_QWER QWERTY
#define KC_GAME GAMING
#define KC_WIND WINDOWS
#define KC_RASE MO(_RAISE)
#define KC_LOWR MO(_LOWER)

#define KC_ KC_TRNS
#define KC_RST RESET
#define KC_CTES LCTL_T(KC_ESC)
#define KC_PCBR LGUI(KC_LCBR)
#define KC_NCBR LGUI(KC_RCBR)
#define KC_PBRC LGUI(KC_LBRC)
#define KC_NBRC LGUI(KC_RBRC)
#define KC_CTLA LCTL(KC_A)
#define KC_CTLZ LCTL(KC_Z)
#define KC_LSBR MT(MOD_LSFT, KC_LBRC)
#define KC_RSBR MT(MOD_RSFT, KC_RBRC)

#define KC_RTOG RGB_TOG
#define KC_RVAI RGB_VAI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GRV , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CTES, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSBR, Z  , X  , C  , V  , B  ,LGUI,     DEL , N  , M  ,COMM,DOT ,SLSH,RSBR,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LGUI,LOWR, ENT ,        SPC ,RASE,LALT
  //                  `----+----+----'        `----+----+----'
  ),

  [_WINDOWS] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LALT,    ,     ,            ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_GAMING] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,ENT ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LALT,    , SPC ,            ,    ,LGUI
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,BSLS,PIPE,    ,                   , 7  , 8  , 9  ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,PLUS,EQL ,    ,                   , 4  , 5  , 6  ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    , 1  , 2  , 3  ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,               , 0  , DOT
  //                  `----+----+----'          `----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
          ,QWER,WIND,GAME,    ,    ,                   ,    ,    ,    ,    , RST,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
          ,    ,MPRV,VOLU,MNXT,    ,                   ,    ,PBRC,NBRC,    ,    ,
   //|----+----+----+----+----+----|              |----+----+----+----+----+----|
          ,CTLA,MPLY,VOLD,    ,    ,               LEFT,DOWN, UP,RIGHT,    ,    ,
   //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
          ,CTLZ,    ,MUTE,    ,    ,    ,         ,    ,    ,PCBR,NCBR,    ,    ,
   //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                            ,    ,    ,             ,    ,
   //                  `----+----+----'        `----+----+----'
  ),
};

void keyboard_post_init_user(void) {
  rgblight_disable_noeeprom();
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        layer_off(_GAMING);
        layer_off(_WINDOWS);
        rgblight_enable_noeeprom();
        rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
        wait_ms(500);
        rgblight_disable_noeeprom();
      }
      return false;
    case WINDOWS:
      if (record->event.pressed) {
        layer_on(_WINDOWS);
        layer_off(_GAMING);
        rgblight_enable_noeeprom();
        rgblight_sethsv_noeeprom(HSV_PURPLE);
        wait_ms(500);
        rgblight_disable_noeeprom();
      }
      return false;
    case GAMING:
      if (record->event.pressed) {
        layer_on(_GAMING);
        rgblight_enable_noeeprom();
        rgblight_sethsv_noeeprom(HSV_AZURE);
        wait_ms(500);
        rgblight_disable_noeeprom();
      }
      return false;
  }
  return true;
}
