#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define KC_ KC_TRNS
#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_S_ES LSFT_T(KC_ESC) //ESC(tap) or Shift
#define KC_S_BS LSFT_T(KC_BSPC) //BSPC(tap) or Shift
#define KC_CDSP LGUI(KC_SPC) //CMD + SPACE
#define KC_C_BS RCTL_T(KC_BSPC) // Backspace(tap) or CTRL
#define KC_G_SP RGUI_T(KC_SPC) // space(tap) or GUI
#define KC_A_EN LALT_T(KC_ENT) // Enter(tap) or LALT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
   //,----+----+----+--+-+----+----.              ,----+----+-+--+----+----+----.
     GRV , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LALT, Z  , X  , C  , V  , B  , DEL,      ENT, N  , M  ,COMM,DOT ,SLSH,A_EN,
  //`----+----+----+--+-+----+----+----/    \----+----+----+-+--+----+----+----'
                      LOWR, LSFT, SPC,         ENT ,C_BS,RASE
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+--+-+----+----.              ,----+----+-+--+----+----+----.
     ESC ,    ,    ,    ,    ,    ,               CAPS, INS, P9 ,PMNS,EQL ,NLCK,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LGUI,    ,    ,    ,    ,    ,                P7 , P8 , P9 ,PPLS,LBRC,RBRC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL,VOLD,VOLU,MUTE,FIND,    ,                P4 , P5 , P6 ,PCMM,MINS,PSCR,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LGUI,    ,    ,    ,    ,    ,    ,      ENT, P1 , P2 , P3 ,PDOT,    ,RALT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+-+--+----+----+----'
                          ,TRNS,SPC ,         ENT , P0 ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+--+-+----+----.              ,----+----+-+--+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,PLUS,LCBR,RCBR,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,LEFT, UP ,DOWN,RGHT,    ,               LEFT,DOWN, UP ,RGHT,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+-+--+----+----+----'
                       RCTL,ENT ,CDSP,             ,TRNS, P0
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
