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

#define KC_MAC_UNDO  LGUI(KC_Z)
#define KC_MAC_CUT   LGUI(KC_X)
#define KC_MAC_COPY  LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO   LCTL(KC_Z)
#define KC_PC_CUT    LCTL(KC_X)
#define KC_PC_COPY   LCTL(KC_C)
#define KC_PC_PASTE  LCTL(KC_V)
#define ES_LESS_MAC  KC_GRAVE
#define ES_GRTR_MAC  LSFT(KC_GRAVE)
#define ES_BSLS_MAC  ALGR(KC_6)
#define NO_PIPE_ALT  KC_GRAVE
#define NO_BSLS_ALT  KC_EQUAL

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  HSV_146_208_210,
  HSV_48_255_153,
  HSV_0_200_220,
  HSV_237_189_211,
};

enum layers {
  BASE,
  SYMB/*OLS*/,
  MEDI/*A*/,
  SMTH,
};

#define KC__ KC_TRANSPARENT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ergodox(
    // Left hand
    KC_EQUAL,          KC_1,           KC_2,     KC_3,    KC_4,     KC_5, KC_ESCAPE,
    KC_TAB,            KC_Q,           KC_W,     KC_E,    KC_R,     KC_T, TG(SYMB),
    LCTL_T(KC_BSPACE), KC_A,           KC_S,     KC_D,    KC_F,     KC_G,
    KC_LSHIFT,         LCTL_T(KC_Z),   KC_X,     KC_C,    KC_V,     KC_B, KC_LBRACKET,
    MO(SYMB),          KC_GRAVE,       KC_QUOTE, KC_LEFT, KC_RIGHT,

              LALT_T(KC_APPLICATION),  KC_LGUI,
                                       KC_HOME,
    KC_SPACE, LALT_T(KC_ESCAPE),       KC_END,

    // Right hand
    KC_DELETE,    KC_6,  KC_7,  KC_8,     KC_9,        KC_0,                KC_MINUS,
    KC_BSPACE,    KC_Y,  KC_U,  KC_I,     KC_O,        KC_P,                KC_BSLASH,
                  KC_H,  KC_J,  KC_K,     KC_L,        LT(MEDI, KC_SCOLON), RGUI_T(KC_QUOTE),
    KC_RBRACKET,  KC_N,  KC_M,  KC_COMMA, KC_DOT,      RCTL_T(KC_SLASH),    KC_RSHIFT,
                         KC_UP, KC_DOWN,  KC_LBRACKET, KC_RBRACKET,         MO(SYMB),

    KC_DELETE, LCTL_T(KC_ESCAPE),
    KC_PGUP,
    KC_PGDOWN, KC_TAB,            KC_ENTER
  ),

  [SYMB] = LAYOUT_ergodox(
    // Left hand
    KC_ESCAPE, KC_F1,       KC_F2,    KC_F3,       KC_F4,       KC_F5,    KC__,
    KC__,      KC_EXLM,     KC_AT,    KC_LCBR,     KC_RCBR,     KC_PIPE,  KC__,
    KC__,      KC_HASH,     KC_DLR,   KC_LPRN,     KC_RPRN,     KC_GRAVE,
    KC__,      KC_PERC,     KC_CIRC,  KC_LBRACKET, KC_RBRACKET, KC_TILD,  KC__,
    KC__,      WEBUSB_PAIR, TG(SMTH), KC__,        KC__,

              RGB_MOD , HSV_146_208_210 ,
                        HSV_48_255_153  ,
    RGB_VAD , RGB_VAI , HSV_0_200_220   ,

    // Right hand
    KC__, KC_F6,   KC_F7,  KC_F8,  KC_F9, KC_F10,    KC_F11,
    KC__, KC_UP,   KC_7,   KC_8,   KC_9,  KC_ASTR,   KC_F12,
          KC_DOWN, KC_4,   KC_5,   KC_6,  KC_PLUS,   KC__,
    KC__, KC_AMPR, KC_1,   KC_2,   KC_3,  KC_BSLASH, KC__,
                   KC__,   KC_DOT, KC_0,  KC_EQUAL,  KC__,

    RGB_TOG            , RGB_SLD ,
    TOGGLE_LAYER_COLOR ,
    HSV_237_189_211    , RGB_HUD , RGB_HUI
  ),

  [MEDI] = LAYOUT_ergodox(
    // Left hand
    KC_SYSTEM_SLEEP, KC__, KC__,          KC__,       KC__,           KC__, KC__,
    KC__,            KC__, KC_MS_WH_LEFT, KC_MS_UP,   KC_MS_WH_RIGHT, KC__, KC__,
    KC__,            KC__, KC_MS_LEFT,    KC_MS_DOWN, KC_MS_RIGHT,    KC__,
    KC__,            KC__, KC__,          KC__,       KC__,           KC__, KC__,
    KC__,            KC__, KC__,          KC_MS_BTN2, KC_MS_BTN1,

          KC__, KC__,
                KC__,
    KC__, KC__, KC__,

    // Right hand
    KC__, KC__,          KC__,                KC__,                KC__,                KC__,                   RESET,
    KC__, KC_MS_WH_UP,   KC_AUDIO_VOL_UP,     KC_AUDIO_VOL_DOWN,   KC_AUDIO_MUTE,       LCTL(LSFT(KC_PSCREEN)), LSFT(KC_PSCREEN),
          KC_MS_WH_DOWN, KC_MS_ACCEL0,        KC_MS_ACCEL1,        KC_MS_ACCEL2,        KC__,                   KC_MEDIA_PLAY_PAUSE,
    KC__, KC_MS_BTN3,    KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC__,                   KC__,
          KC_MS_BTN1,    KC_MS_BTN2,          KC_AUDIO_MUTE,       KC__,                KC__,

    KC__, KC__,
    KC__,
    KC__, KC_WWW_BACK, KC_WWW_FORWARD
  ),

  [SMTH] = LAYOUT_ergodox(
    // Left hand
    KC__, KC__, KC__, KC__, KC__, KC__, KC__,
    KC__, KC__, KC__, KC__, KC__, KC__, KC__,
    KC__, KC__, KC__, KC__, KC__, KC__,
    KC__, KC__, KC__, KC__, KC__, KC__, KC__,
    KC__, KC__, KC__, KC__, KC__,

          KC__, KC__,
                KC__,
    KC__, KC__, KC__,

    // Right hand
    KC__, KC__, KC__, KC__, KC__, KC__, KC__,
    KC__, KC__, KC__, KC__, KC__, KC__, KC__,
          KC__, KC__, KC__, KC__, KC__, KC__,
    KC__, KC__, KC__, KC__, KC__, KC__, KC__,
                KC__, KC__, KC__, KC__, KC__,

    KC__, KC__,
    KC__,
    KC__, KC__, KC__
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

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][4] = {
    [BASE] = {
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

    [SYMB] = {
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

    [MEDI] = {
      // Right hand: left -> right
      {R}, {R}, {R}, {R}, {R},
      {B}, {M}, {M}, {M}, {R},
      {B}, {R}, {R}, {R}, {R},
      {R}, {M}, {M}, {M}, {R},
           {G}, {Y}, {R}, {R},

      // Left hand: right -> left
      {R}, {R}, {R}, {R}, {R},
      {R}, {R}, {B}, {R}, {R},
      {R}, {B}, {B}, {B}, {R},
      {R}, {R}, {R}, {R}, {R},
           {G}, {Y}, {R}, {R}
    },

    [SMTH] = {
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
    CASE_LAYER(BASE)
    CASE_LAYER(SYMB)
    CASE_LAYER(MEDI)
    CASE_LAYER(SMTH)
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
