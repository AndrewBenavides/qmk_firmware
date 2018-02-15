#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _NUMPAD 1
#define _ADJUST 2
#define _LOWER 3
#define _RAISE 4
#define _MOVEMENT 5
#define _FUNCTION 6

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUMPAD,
  ADJUST,
  LOWER,
  RAISE,
  MOVEMENT,
  FUNCTION
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_NPAD NUMPAD
#define KC_AJST ADJUST
#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_MOVE MOVEMENT
#define KC_FUNC FUNCTION

#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD

#define KC_FMOV LT(_MOVEMENT, KC_F)
#define KC_CTLF LCTL(KC_LEFT)
#define KC_CTRT LCTL(KC_RGHT)
#define KC_ALLF LALT(KC_LEFT)
#define KC_ALRT LALT(KC_RGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  , NO ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CAPS, A  , S  , D  ,FMOV, G  ,                H  , J  , K  , L  ,SCLN, NO ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,                N  , M  ,COMM,DOT ,SLSH,RSFT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LCTL,NPAD,LGUI,LALT,FUNC, LCTL,LALT    ,RALT,RCTL,FUNC,RALT,RGUI,APP ,RCTL,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                        DEL ,BSPC,LOWR       ,RASE,SPC ,ENT
  //                  `----+----+----'        `----+----+----'
  ),

  [_NUMPAD] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                NO , P7 , P8 , P9 ,PSLS,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               EQL , P4 , P5 , P6 ,PAST,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                NO , P1 , P2 , P3 ,PMNS,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    , NO , P0 , P0 ,PDOT,PPLS,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                            ,    ,           ,    ,    ,PENT
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,    ,    ,    ,    ,    ,               GRV ,PLUS,LPRN,RPRN, NO ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               TILD,EQL ,LBRC,RBRC,PIPE,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               UNDS,MINS,LCBR,RCBR,BSLS,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                            ,    ,           ,    ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                            ,    ,           ,    ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_FUNCTION] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,F12 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,AJST     ,AJST,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                            ,    ,           ,    ,    ,
  //                  `----+----+----'        `----+----+----'
  ),
    [_MOVEMENT] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,               HOME,PGDN,PGUP,END , NO ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LGUI,LSFT,LCTL,LALT,    ,    ,               LEFT,DOWN, UP ,RGHT, NO ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               CTLF,ALLF,ALRT,CTRT, NO ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                            ,    ,           ,    ,    ,
  //                  `----+----+----'        `----+----+----'
  ),


    [_ADJUST] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RTOG,RMOD,RHUI,RSAI,RVAI,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     BL_S,    ,RHUD,RSAD,RVAD,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,DBUG,RST ,    ,    ,    ,         ,    ,    ,    ,    ,RST ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                            ,    ,           ,    ,    ,
  //                  `----+----+----'        `----+----+----'
  ),
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
