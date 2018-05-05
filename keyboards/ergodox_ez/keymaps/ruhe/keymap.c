//#include QMK_KEYBOARD_H
#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define _QWERTY 0
#define _DVORAK 1
#define _GAMING 2
#define _NUMPAD 3
#define _LOWER 4
#define _RAISE 5
#define _MOVEMENT 6
#define _FUNCTION 7

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  GAMING,
  NUMPAD,
  LOWER,
  RAISE,
  MOVEMENT,
  FUNCTION
};

#define KC_ KC_TRNS
#define KC_FMOV LT(_MOVEMENT, KC_F)
#define KC_UMOV LT(_MOVEMENT, KC_U)
#define KC_NPAD MO(_NUMPAD)
#define KC_NPMO MO(_NUMPAD)
#define KC_DVTG TG(_DVORAK)
#define KC_NPTG TG(_NUMPAD)
#define KC_GMTG TG(_GAMING)
#define KC_LOWR MO(_LOWER)
#define KC_RASE MO(_RAISE)
#define KC_MOVE MO(_MOVEMENT)
#define KC_FUNC MO(_FUNCTION)
#define KC_CTLF LCTL(KC_LEFT)
#define KC_CTRT LCTL(KC_RGHT)
#define KC_ALLF LALT(KC_LEFT)
#define KC_ALRT LALT(KC_RGHT)

#define KC_CTLZ LCTL(KC_Z)
#define KC_CTLX LCTL(KC_X)
#define KC_CTLC LCTL(KC_C)
#define KC_CTLV LCTL(KC_V)

#define KC_RSET RESET

#undef TAPPING_TERM
#define TAPPING_TERM 400

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = KC_KEYMAP2(
  //,--------------------------------------------------.      ,--------------------------------------------------.
       ESC   ,   1  ,   2  ,   3  ,   4  ,   5  , GRV  ,        EQL  ,   6  ,   7  ,   8  ,   9  ,   0  ,  MINS  ,
  //|--------+------+------+------+------+-------------|      |------+------+------+------+------+------+--------|
       TAB   ,   Q  ,   W  ,   E  ,   R  ,   T  , ENT  ,         NO  ,   Y  ,   U  ,   I  ,   O  ,   P  ,  BSLS  ,
  //|--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
       CAPS  ,   A  ,   S  ,   D  , FMOV ,   G  ,                        H  ,   J  ,   K  ,   L  , SCLN ,  QUOT  ,
  //|--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
       LSFT  ,   Z  ,   X  ,   C  ,   V  ,   B  , SPC  ,        MOVE ,   N  ,   M  , COMM ,  DOT , SLSH ,  RSFT  ,
  //`--------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
       LCTL  , NPMO , LGUI , LALT , FUNC ,                                    FUNC , RALT , RGUI , APP  , RCTL ,
  //  `----------------------------------'                                  `----------------------------------'
  //                                     ,-------------.      ,-------------.
                                           LCTL , LALT ,        RALT , RCTL ,
  //                              ,------|------|------|      |------+------+------.
                                                  LSFT ,        RSFT ,
  //                              |------|------|------|      |------|------|------|
                                    DEL  , BSPC , LOWR ,        RASE , SPC  , ENT
  //                              `--------------------'      `--------------------'
),
[_DVORAK] = KC_KEYMAP2(
  //,--------------------------------------------------.      ,--------------------------------------------------.
             ,      ,      ,      ,      ,      ,      ,             ,      ,      ,      ,      ,      ,  BSLS  ,
  //|--------+------+------+------+------+-------------|      |------+------+------+------+------+------+--------|
             , SCLN , COMM , DOT  ,   P  ,   Y  ,      ,             ,   F  ,   G  ,   C  ,   R  ,   L  ,  SLSH  ,
  //|--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
             ,   A  ,   O  ,   E  , UMOV ,   I  ,                        D  ,   H  ,   T  ,   N  ,   S  ,  MINS  ,
  //|--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
             , QUOT ,   Q  ,   J  ,   K  ,   X  ,      ,             ,   B  ,   M  ,   W ,    V  ,   Z  ,        ,
  //`--------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
             ,      ,      ,      ,      ,                                         ,      ,      ,      ,      ,
  //  `----------------------------------'                                  `----------------------------------'
  //                                     ,-------------.      ,-------------.
                                                ,      ,             ,      ,
  //                              ,------|------|------|      |------+------+------.
                                                       ,             ,
  //                              |------|------|------|      |------|------|------|
                                         ,      ,      ,             ,      ,
  //                              `--------------------'      `--------------------'
),
[_GAMING] = KC_KEYMAP2(
  //,--------------------------------------------------.      ,--------------------------------------------------.
             ,      ,      ,      ,      ,      ,      ,             ,      ,      ,      ,      ,      ,        ,
  //|--------+------+------+------+------+-------------|      |------+------+------+------+------+------+--------|
             ,      ,      ,      ,      ,      , MOVE ,             ,      ,      ,      ,      ,      ,        ,
  //|--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
             ,      ,      ,      ,   F  ,      ,                           ,      ,      ,      ,      ,        ,
  //|--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
             ,      ,      ,      ,      ,      , MOVE ,             ,      ,      ,      ,      ,      ,        ,
  //`--------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
             ,      ,      ,      ,      ,                                         ,      ,      ,      ,      ,
  //  `----------------------------------'                                  `----------------------------------'
  //                                     ,-------------.      ,-------------.
                                                ,      ,             ,      ,
  //                              ,------|------|------|      |------+------+------.
                                                       ,             ,
  //                              |------|------|------|      |------|------|------|
                                    ENT  , SPC  ,      ,             , BSPC , DEL
  //                              `--------------------'      `--------------------'
),
[_NUMPAD] = KC_KEYMAP2(
  //,--------------------------------------------------.      ,--------------------------------------------------.
             ,      ,      ,      ,      ,      ,      ,             ,  NO  , NLCK , PSLS , PAST , PMNS ,        ,
  //|--------+------+------+------+------+-------------|      |------+------+------+------+------+------+--------|
             ,      ,      ,      ,      ,      ,      ,             , EQL  ,  P7  ,  P8  ,  P9  , PPLS ,        ,
  //|--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
             ,      ,      ,      ,      ,      ,                       NO  ,  P4  ,  P5  ,  P6  , PPLS ,        ,
  //|--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
             ,      ,      ,      ,      ,      ,      ,             ,  NO  ,  P1  ,  P2  ,  P3  , PENT ,        ,
  //`--------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
             ,      ,      ,      ,      ,                                     P0  ,  P0  , PDOT , PENT ,      ,
  //  `----------------------------------'                                  `----------------------------------'
  //                                     ,-------------.      ,-------------.
                                                ,      ,             ,      ,
  //                              ,------|------|------|      |------+------+------.
                                                       ,             ,
  //                              |------|------|------|      |------|------|------|
                                         ,      ,      ,             ,      ,
  //                              `--------------------'      `--------------------'
),
[_LOWER] = KC_KEYMAP2(
  //,--------------------------------------------------.      ,--------------------------------------------------.
             ,      ,      ,      ,      ,      ,      ,             ,      ,      ,      ,      ,      ,        ,
  //|--------+------+------+------+------+-------------|      |------+------+------+------+------+------+--------|
             , CIRC ,  AT  , HASH , DLR  , PERC ,      ,             , GRV  , PLUS , LPRN , RPRN , SLSH ,  SLSH ,
  //|--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
             , EXLM , AMPR , ASTR , LABK , RABK ,                      TILD , EQL  , LBRC , RBRC , PIPE ,        ,
  //|--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
             , CTLZ , CTLX , CTLC , CTLV ,      ,      ,             , UNDS , MINS , LCBR , RCBR , BSLS ,        ,
  //`--------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
             ,      ,      ,      ,      ,                                         ,      ,      ,      ,      ,
  //  `----------------------------------'                                  `----------------------------------'
  //                                     ,-------------.      ,-------------.
                                                ,      ,             ,      ,
  //                              ,------|------|------|      |------+------+------.
                                                       ,             ,
  //                              |------|------|------|      |------|------|------|
                                         ,      ,      ,             ,      ,
  //                              `--------------------'      `--------------------'
),
[_RAISE] = KC_KEYMAP2(
  //,--------------------------------------------------.      ,--------------------------------------------------.
             ,      ,      ,      ,      ,      , DVTG ,        GMTG ,      ,      ,      ,      ,      ,        ,
  //|--------+------+------+------+------+-------------|      |------+------+------+------+------+------+--------|
             , EXLM ,  AT  , HASH , DLR  , PERC ,      ,             , CIRC , AMPR , ASTR , LABK , RABK ,        ,
  //|--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
             ,   1  ,   2  ,   3  ,   4  ,   5  ,                        6  ,   7  ,   8  ,   9  ,   0  ,        ,
  //|--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
             , CTLZ , CTLX , CTLC , CTLV ,      ,      ,             ,      ,      ,      ,      ,      ,        ,
  //`--------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
             ,      ,      ,      ,      ,                                         ,      ,      ,      ,      ,
  //  `----------------------------------'                                  `----------------------------------'
  //                                     ,-------------.      ,-------------.
                                                ,      ,             ,      ,
  //                              ,------|------|------|      |------+------+------.
                                                       ,             ,
  //                              |------|------|------|      |------|------|------|
                                         ,      ,      ,             ,      ,
  //                              `--------------------'      `--------------------'
),
[_MOVEMENT] = KC_KEYMAP2(
  //,--------------------------------------------------.      ,--------------------------------------------------.
             ,      ,      ,      ,      ,      ,      ,             ,      ,      ,      ,      ,      ,        ,
  //|--------+------+------+------+------+-------------|      |------+------+------+------+------+------+--------|
             ,      ,      ,      ,      ,      ,      ,             , HOME , PGDN , PGUP , END  ,  NO  ,        ,
  //|--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
       LGUI  , LSFT , LCTL , LALT ,      ,      ,                      LEFT , DOWN ,  UP  , RGHT ,  NO  ,        ,
  //|--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
             ,      ,      ,      ,      ,      ,      ,             , CTLF , ALLF , ALRT , CTRT ,  NO  ,        ,
  //`--------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
             ,      ,      ,      ,      ,                                         ,      ,      ,      ,      ,
  //  `----------------------------------'                                  `----------------------------------'
  //                                     ,-------------.      ,-------------.
                                                ,      ,             ,      ,
  //                              ,------|------|------|      |------+------+------.
                                                       ,             ,
  //                              |------|------|------|      |------|------|------|
                                         ,      ,      ,             ,      ,
  //                              `--------------------'      `--------------------'
),
[_FUNCTION] = KC_KEYMAP2(
  //,--------------------------------------------------.      ,--------------------------------------------------.
             ,  F1  ,  F2  ,  F3  ,  F4  ,  F5  ,      ,             ,  F6  ,  F7  ,  F8  ,  F9  , F10  ,  F11   ,
  //|--------+------+------+------+------+-------------|      |------+------+------+------+------+------+--------|
             ,      ,      ,      ,      ,      ,      ,             ,      ,      ,      ,      ,      ,  F12   ,
  //|--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
             ,      ,      ,      ,      ,      ,                           ,      ,      ,      ,      ,        ,
  //|--------+------+------+------+------+------|      |      |      |------+------+------+------+------+--------|
             ,      ,      ,      ,      ,      , NPTG ,             ,      ,      ,      ,      ,      ,        ,
  //`--------+------+------+------+------+-------------'      `-------------+------+------+------+------+--------'
             , NPTG ,      ,      ,      ,                                         ,      ,      ,      ,      ,
  //  `----------------------------------'                                  `----------------------------------'
  //                                     ,-------------.      ,-------------.
                                           INS  , PSCR ,        SLCK , PAUS ,
  //                              ,------|------|------|      |------+------+------.
                                                       ,             ,
  //                              |------|------|------|      |------|------|------|
                                         ,      , RSET ,        RSET ,      ,
  //                              `--------------------'      `--------------------'
),
};

// const uint16_t PROGMEM fn_actions[] = {
//     [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
// };

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     // dynamically generate these.
//     case EPRM:
//       if (record->event.pressed) {
//         eeconfig_init();
//       }
//       return false;
//       break;
//     case VRSN:
//       if (record->event.pressed) {
//         SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
//       }
//       return false;
//       break;
//     case RGB_SLD:
//       if (record->event.pressed) {
//         #ifdef RGBLIGHT_ENABLE
//           rgblight_mode(1);
//         #endif
//       }
//       return false;
//       break;
//   }
//   return true;
// }

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
          rgblight_init();
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
