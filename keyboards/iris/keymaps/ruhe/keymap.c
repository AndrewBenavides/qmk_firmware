#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _MOVEMENT 3
#define _ADJUST 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  MOVEMENT,
  ADJUST
};

#define TAPPING_TERM 200 // tap toggle timeout (ms)
#define TAPPING_TOGGLE 1// tap toggle count

#define KC_ KC_TRNS
#define _______ KC_TRNS
#define KC_AJST ADJUST
#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_MOVE MOVEMENT
#define KC_RST RESET
#define KC_BL_S BL_STEP

#define QUO_RSF MT(MOD_RSFT, KC_QUOT)
#define KC_QURS QUO_RSF
#define F_MOVE LT(3, KC_F)
#define KC_FMOV F_MOVE
#define MIN_ADJ LT(4, KC_MINS)
#define KC_MIAD MIN_ADJ
#define Z_GUI MT(MOD_LGUI, KC_Z)
#define KC_ZGUI Z_GUI
#define X_ALT MT(MOD_LALT, KC_X)
#define KC_XALT X_ALT
#define SLH_GUI MT(MOD_RGUI, KC_SLSH)
#define KC_SLGU SLH_GUI
#define DOT_ALT MT(MOD_RALT, KC_DOT)
#define KC_DALT DOT_ALT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,MIAD,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,EQL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT, A  , S  , D  ,FMOV, G  ,                H  , J  , K  , L  ,SCLN,QURS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LCTL,ZGUI,XALT, C  , V  , B  ,LOWR ,    RASE, N  , M  ,COMM,DALT,SLGU,RCTL,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                       DEL ,BSPC,LOWR,        RASE, SPC, ENT
  //                  `----+----+----'        `----+----+----'
  ),

  // [_QWERTY] = KEYMAP(
  // //,-------+-------+-------+-------+-------+-------.                    .-------+-------+-------+-------+-------+-------.
  //    KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                      KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,MIN_ADJ,
  // //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //    KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                      KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_EQL ,
  // //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //    KC_LSFT, KC_A  , KC_S  , KC_D  ,F_MOVE , KC_G  ,                      KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,QUO_RSF,
  // //|-------+-------+-------+-------+-------+-------+-------.    ,-------|-------+-------+-------+-------+-------+-------|
  //    KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,KC_LOWR ,    KC_RASE, KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_RCTL,
  // //`-------+-------+-------+-------+-------+-------+-------/    \-------+-------+-------+-------+-------+-------+-------'
  //                                   KC_DEL ,KC_BSPC,KC_LCTL,       KC_LALT, KC_SPC, KC_ENT
  // //                              `-------+-------+-------'        `-------+-------+-------'
  // ),


  [_LOWER] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TILD,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,LBRC,               RBRC,    ,    ,    ,    ,PIPE,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,LCBR,               RCBR,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,LPRN,    ,         ,RPRN,    ,    ,    ,BSLS,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                            ,    ,    ,           ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CAPS,    ,    ,    ,    ,    ,                   , P7 , P8 , P9 ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   , P4 , P5 , P6 ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    , P1 , P2 , P3,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             , P0 , P0
  //                  `----+----+----'        `----+----+----'
  ),

    [_MOVEMENT] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               HOME,PGDN,PGUP,END ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,LCTL,LSFT,LALT,    ,    ,               LEFT,DOWN, UP ,RGHT,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      BL_STEP, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, _______,                  _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  )

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
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
