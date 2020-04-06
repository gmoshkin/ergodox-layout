#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  HSV_146_208_210,
  HSV_48_255_153,
  HSV_0_200_220,
  HSV_237_189_211,
};

enum layers {
  BAS/*E*/,
  SYM/*BOLS*/,
  MED/*IA*/,
  NIL,
};

#define ___        KC_TRANSPARENT
#define T_MED(KEY) LT(MED, KEY)
#define CT(KEY)    LCTL_T(KEY)
#define AT(KEY)    LALT_T(KEY)
#define W_USB_P    WEBUSB_PAIR

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BAS] = LAYOUT_ergodox(
    // Left hand
    KC_EQL      , KC_1     , KC_2    , KC_3   , KC_4    , KC_5 , KC_ESC  ,
    KC_TAB      , KC_Q     , KC_W    , KC_E   , KC_R    , KC_T , TG(SYM) ,
    CT(KC_BSPC) , KC_A     , KC_S    , KC_D   , KC_F    , KC_G ,
    KC_LSFT     , CT(KC_Z) , KC_X    , KC_C   , KC_V    , KC_B , KC_LBRC ,
    MO(SYM)     , KC_GRV   , KC_QUOT , KC_LEFT, KC_RGHT ,

               AT(KC_APP) , KC_LGUI ,
                            KC_END  ,
    KC_SPACE , AT(KC_ESC) , KC_HOME ,

    // Right hand
    KC_DEL  , KC_6 , KC_7  , KC_8    , KC_9    , KC_0           , KC_MINS         ,
    KC_BSPC , KC_Y , KC_U  , KC_I    , KC_O    , KC_P           , KC_BSLS         ,
              KC_H , KC_J  , KC_K    , KC_L    , T_MED(KC_SCLN) , RGUI_T(KC_QUOT) ,
    KC_RBRC , KC_N , KC_M  , KC_COMM , KC_DOT  , CT(KC_SLSH)    , KC_RSFT         ,
                     KC_UP , KC_DOWN , KC_LBRC , KC_RBRC        , MO(SYM)         ,

    KC_DEL  , CT(KC_ESC) ,
    KC_PGUP ,
    KC_PGDN , KC_TAB         , KC_ENT
  ),

  [SYM] = LAYOUT_ergodox(
    // Left hand
    KC_ESC , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , ___ ,
    ___    , KC_EXLM , KC_AT   , KC_LCBR , KC_RCBR , KC_PIPE , ___ ,
    ___    , KC_HASH , KC_DLR  , KC_LPRN , KC_RPRN , KC_GRV  ,
    ___    , KC_PERC , KC_CIRC , KC_LBRC , KC_RBRC , KC_TILD , ___ ,
    ___    , W_USB_P , TG(NIL) , ___     , ___     ,

              RGB_MOD , HSV_146_208_210 ,
                        HSV_48_255_153  ,
    RGB_VAD , RGB_VAI , HSV_0_200_220   ,

    // Right hand
    ___ , KC_F6   , KC_F7 , KC_F8  , KC_F9 , KC_F10  , KC_F11 ,
    ___ , KC_UP   , KC_7  , KC_8   , KC_9  , KC_ASTR , KC_F12 ,
          KC_DOWN , KC_4  , KC_5   , KC_6  , KC_PLUS , ___    ,
    ___ , KC_AMPR , KC_1  , KC_2   , KC_3  , KC_BSLS , ___    ,
                    ___   , KC_DOT , KC_0  , KC_EQL  , ___    ,

    RGB_TOG            , RGB_SLD ,
    TOGGLE_LAYER_COLOR ,
    HSV_237_189_211    , RGB_HUD , RGB_HUI
  ),

  [MED] = LAYOUT_ergodox(
    // Left hand
    KC_SLEP , ___ , ___     , ___     , ___     , ___ , ___ ,
    ___     , ___ , KC_WH_L , KC_MS_U , KC_WH_R , ___ , ___ ,
    ___     , ___ , KC_MS_L , KC_MS_D , KC_MS_R , ___ ,
    ___     , ___ , ___     , ___     , ___     , ___ , ___ ,
    ___     , ___ , ___     , KC_BTN2 , KC_BTN1 ,

           ___  , ___  ,
                  ___  ,
    ___  , ___  , ___  ,

    // Right hand
    ___ , ___     , ___     , ___     , ___     , ___           , RESET      ,
    ___ , KC_WH_U , KC_VOLU , KC_VOLD , KC_MUTE , C(S(KC_PSCR)) , S(KC_PSCR) ,
          KC_WH_D , KC_ACL0 , KC_ACL1 , KC_ACL2 , ___           , KC_MPLY    ,
    ___ , KC_BTN3 , KC_MPLY , KC_MPRV , KC_MNXT , ___           , ___        ,
          KC_BTN1 , KC_BTN2 , KC_MUTE , ___     , ___           ,

    ___  , ___     ,
    ___  ,
    ___  , KC_WBAK , KC_WFWD
  ),

  [NIL] = LAYOUT_ergodox(
    // Left hand
    ___ , ___ , ___ , ___ , ___ , ___ , ___ ,
    ___ , ___ , ___ , ___ , ___ , ___ , ___ ,
    ___ , ___ , ___ , ___ , ___ , ___ ,
    ___ , ___ , ___ , ___ , ___ , ___ , ___ ,
    ___ , ___ , ___ , ___ , ___ ,

          ___ , ___ ,
                ___ ,
    ___ , ___ , ___ ,

    // Right hand
    ___ , ___ , ___ , ___ , ___ , ___ , ___ ,
    ___ , ___ , ___ , ___ , ___ , ___ , ___ ,
          ___ , ___ , ___ , ___ , ___ , ___ ,
    ___ , ___ , ___ , ___ , ___ , ___ , ___ ,
                ___ , ___ , ___ , ___ , ___ ,

    ___ , ___ ,
    ___ ,
    ___ , ___ , ___
  ),

};


extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

#undef G
#undef M

#define R   0,230,255
#define O  12,230,255
#define Y  32,255,255
#define G  85,240,255
#define B 146,255,255
#define V 168,255,200
#define M 235,255,255

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [BAS] = {
      // Right hand: left -> right
      {B}, {B}, {B}, {B}, {B},
      {B}, {B}, {B}, {B}, {B},
      {B}, {B}, {B}, {B}, {R},
      {B}, {B}, {B}, {B}, {G},
           {B}, {B}, {B}, {B},

      // Left hand: right -> left
      {B}, {B}, {B}, {B}, {B},
      {B}, {B}, {B}, {B}, {B},
      {B}, {B}, {B}, {B}, {B},
      {B}, {B}, {B}, {B}, {G},
           {B}, {B}, {B}, {B}
    },

    [SYM] = {
      // Right hand: left -> right
      {V}, {V}, {V}, {V}, {V},
      {B}, {Y}, {Y}, {Y}, {G},
      {B}, {Y}, {Y}, {Y}, {G},
      {G}, {Y}, {Y}, {Y}, {G},
           {B}, {G}, {Y}, {G},

      // Left hand: right -> left
      {V}, {V}, {V}, {V}, {V},
      {G}, {M}, {M}, {G}, {G},
      {G}, {M}, {M}, {G}, {G},
      {G}, {M}, {M}, {G}, {G},
           {B}, {B}, {O}, {R}
    },

    [MED] = {
      // Right hand: left -> right
      {R}, {R}, {R}, {R}, {R},
      {V}, {M}, {M}, {M}, {R},
      {V}, {R}, {R}, {R}, {R},
      {R}, {M}, {M}, {M}, {R},
           {G}, {Y}, {R}, {R},

      // Left hand: right -> left
      {R}, {R}, {R}, {R}, {R},
      {R}, {V}, {B}, {V}, {R},
      {R}, {B}, {B}, {B}, {R},
      {R}, {R}, {R}, {R}, {R},
           {G}, {Y}, {R}, {R}
    },

    [NIL] = {
      // Right hand: left -> right
      {R}, {R}, {R}, {R}, {R},
      {G}, {G}, {G}, {G}, {G},
      {B}, {B}, {B}, {B}, {B},
      {Y}, {Y}, {Y}, {Y}, {Y},
           {M}, {M}, {M}, {M},

      // Left hand: right -> left
      {R}, {R}, {R}, {R}, {R},
      {G}, {G}, {G}, {G}, {G},
      {B}, {B}, {B}, {B}, {B},
      {Y}, {Y}, {Y}, {Y}, {Y},
           {M}, {M}, {M}, {M},
    },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) {
    return;
  }
  switch (biton32(layer_state)) {
#define CASE_LAYER(LAYER) case LAYER: set_layer_color(LAYER); break;
    CASE_LAYER(BAS)
    CASE_LAYER(SYM)
    CASE_LAYER(MED)
    CASE_LAYER(NIL)
    default:
      if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
        rgb_matrix_set_color_all(0, 0, 0);
      }
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_146_208_210:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(146,208,210);
      }
      return false;
    case HSV_48_255_153:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(48,255,153);
      }
      return false;
    case HSV_0_200_220:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,200,220);
      }
      return false;
    case HSV_237_189_211:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(237,189,211);
      }
      return false;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
