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

#define KC_CTLF LCTL(KC_LEFT)
#define KC_CTRT LCTL(KC_RGHT)
#define KC_ALLF LALT(KC_LEFT)
#define KC_ALRT LALT(KC_RGHT)
#define KC_CTLZ LCTL(KC_Z)
#define KC_CTLX LCTL(KC_X)
#define KC_CTLC LCTL(KC_C)
#define KC_CTLV LCTL(KC_V)

#define F_MOVE LT(3, KC_F)
#define KC_FMOV F_MOVE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CAPS, A  , S  , D  ,FMOV, G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,LCTL,     RALT, N  , M  ,COMM, DOT,SLSH,RSFT,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                        DEL ,BSPC,LOWR,       RASE, SPC, ENT
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     LGUI,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LALT,    ,    ,    ,    ,    ,               GRV ,PLUS,LPRN,RPRN,SLSH,SLSH,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL,    ,    ,    ,    ,    ,               TILD,EQL ,LBRC,RBRC,PIPE,RALT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT,    ,    ,    ,    ,    ,LGUI,     APP ,UNDS,MINS,LCBR,RCBR,BSLS,RCTL,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                            ,    ,    ,           ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     LGUI, F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LALT,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,F12 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,RALT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT,CTLZ,CTLX,CTLC,CTLV,    ,AJST,     RGUI,    ,    ,    ,    ,    ,RCTL,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                        INS ,PSCR,    ,           ,SLCK,PAUS
  //                  `----+----+----'        `----+----+----'
  ),

    [_MOVEMENT] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               HOME,PGDN,PGUP,END , NO ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LGUI,LSFT,LCTL,LALT,    ,    ,               LEFT,DOWN, UP ,RGHT, NO ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,CTLF,ALLF,ALRT,CTRT, NO ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                            ,    ,    ,           ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      _______, _______, _______, _______, _______, RESET  ,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      BL_STEP, RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
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
