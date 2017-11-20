#include "viterbi.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
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

// Fillers to make layering more clear
#define KC_ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_AJST ADJUST
#define KC_LOWR LOWER
#define KC_RASE RAISE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |  Ins |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  | Bksp | Del  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   -  | Tab  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   =  | Esc  |   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   ;  |   "  |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Pg Up| Shift|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  | Home | End  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Pg Dn|Adjust| Ctrl | Alt  | GUI  |Lower |Space |      |Space |Raise | Left | Down |  Up  | Right|   \  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,GRV ,     BSLS, 6  , 7  , 8  , 9  , 0  ,PGUP,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,LBRC,     RBRC, Y  , U  , I  , O  , P  ,PGDN,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
     CAPS, A  , S  , D  , F  , G  ,LPRN,     RPRN, H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,MINS,     EQL , N  , M  ,COMM,DOT ,SLSH,RSFT,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
     LCTL,AJST,LGUI,LALT,LOWR,BSPC,DEL ,     ENT ,SPC ,RASE,RALT,APP ,AJST,RCTL
  //`----+----+----+----+----+----+----'    `----+----+----+----+----+----+----'
  ),

/* Lower
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |   ~  |  F1  |  F3  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   _  |      |   !  |   @  |   #  |   $  |   %  |      |   ^  |   &  |   *  |   (  |   )  |   {  |   }  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   +  |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   _  |   +  |   {  |   }  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_LOWER] = KC_KEYMAP(
  //,----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----.
         , F1 , F2 , F3 , F4 , F5 , F6 ,      F7 , F8 , F9 ,F10 ,F11 ,F12 ,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
     TILD,EXLM, AT ,HASH,DLR ,PERC,    ,         ,CIRC,AMPR,ASTR,LPRN,RPRN,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,     LBRC,RBRC,LPRN,RPRN,LCBR,RCBR,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,UNDS,PLUS,MINS,EQL ,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,
  //`----+----+----+----+----+----+----'    `----+----+----+----+----+----+----'
  ),

/* Raise
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |   ~  |  F1  |  F3  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   _  |      |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   {  |   }  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   +  |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   -  |   =  |   [  |   ]  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 |ISO # |ISO / |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_RAISE] = KC_KEYMAP(
  //,----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,    ,         ,    , P7 , P8 , P9 ,PSLS,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         , 1  , 2  , 3  , 4  , 5  ,    ,         ,    , P4 , P5 , P6 ,PAST,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         , 6  , 7  , 8  , 9  , 0  ,    ,         ,    , P1 , P2 , P3 ,PMNS,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    , P0 , P0 ,PDOT,PPLS,    ,
  //|----+----+----+----+----+----+----|    |----+----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,     PENT,    ,    ,    ,    ,    ,
  //`----+----+----+----+----+----+----'    `----+----+----+----+----+----+----'
  ),

  [_ADJUST] = KEYMAP(
  //_______, _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_DEL,  _______,
  //_______, _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______, _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,  KC_END,  \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
    KC_LGUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_LALT, _______, KC_LCTL, KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
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
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
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
