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
  YEGO_RGB_FREQ_UP,       YF_UP  = YEGO_RGB_FREQ_UP,
  YEGO_RGB_FREQ_DOWN,     YF_DWN = YEGO_RGB_FREQ_DOWN,
  YEGO_RGB_FREQ_DEFAULT,  YF_DEF = YEGO_RGB_FREQ_DEFAULT,
  YEGO_RGB_FREQ_SAVE,     YF_SAV = YEGO_RGB_FREQ_SAVE,
  YEGO_RGB_FREQ_RESTORE,  YF_RES = YEGO_RGB_FREQ_RESTORE,
};

enum layers {
  BASE,    BAS = BASE,
  SYMBOLS, SYM = SYMBOLS,
  MEDIA,   MED = MEDIA,
  GAMING,  GAM = GAMING,
  SWAP,    SWP = SWAP,
  NIL,
};

#define T_M(KEY)   LT(MED, KEY)
#define CT(KEY)    LCTL_T(KEY)
#define AT(KEY)    LALT_T(KEY)
#define WT(KEY)    LGUI_T(KEY)
#define W_USB_P    WEBUSB_PAIR

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ergodox(
    // Left hand
    KC_EQL      , KC_1    , KC_2    , KC_3   , KC_4    , KC_5 , KC_ESC  ,
    KC_TAB      , KC_Q    , KC_W    , KC_E   , KC_R    , KC_T , KC_DEL  ,
    CT(KC_BSPC) , KC_A    , KC_S    , KC_D   , KC_F    , KC_G ,
    KC_LSFT     , KC_Z    , KC_X    , KC_C   , KC_V    , KC_B , KC_LBRC ,
    MO(SYM)     , KC_GRV  , KC_QUOT , KC_LEFT, KC_RGHT ,

               KC_APP     , KC_END  ,
                            KC_HOME ,
    KC_SPACE , AT(KC_ESC) , KC_LGUI ,

    // Right hand
    KC_ESC  , KC_6 , KC_7  , KC_8    , KC_9    , KC_0         , KC_MINS     ,
    KC_BSPC , KC_Y , KC_U  , KC_I    , KC_O    , KC_P         , KC_BSLS     ,
              KC_H , KC_J  , KC_K    , KC_L    , T_M(KC_SCLN) , WT(KC_QUOT) ,
    KC_RBRC , KC_N , KC_M  , KC_COMM , KC_DOT  , KC_SLSH      , KC_RSFT     ,
                     KC_UP , KC_DOWN , KC_LBRC , KC_RBRC      , MO(SYM)     ,

    KC_PGUP , KC_LCTL ,
    KC_PGDN ,
    KC_DEL  , KC_RCTL , KC_ENT
  ),

  [SYMBOLS] = LAYOUT_ergodox(
    // Left hand
    KC_ESC , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , _______ ,
    _______, KC_EXLM , KC_AT   , KC_LCBR , KC_RCBR , KC_PIPE , _______ ,
    _______, KC_HASH , KC_DLR  , KC_LPRN , KC_RPRN , KC_GRV  ,
    _______, KC_PERC , KC_CIRC , KC_LBRC , KC_RBRC , KC_TILD , _______ ,
    _______, W_USB_P , TG(NIL) , _______ , TG(SWP) ,

              RGB_MOD , _______ ,
                        _______ ,
    RGB_VAD , RGB_VAI , _______ ,

    // Right hand
    _______ , KC_F6   , KC_F7   , KC_F8  , KC_F9 , KC_F10  , KC_F11  ,
    _______ , KC_UP   , KC_7    , KC_8   , KC_9  , KC_ASTR , KC_F12  ,
              KC_DOWN , KC_4    , KC_5   , KC_6  , KC_PLUS , _______ ,
    _______ , KC_AMPR , KC_1    , KC_2   , KC_3  , KC_BSLS , _______ ,
                        TG(SWP) , KC_DOT , KC_0  , KC_EQL  , _______ ,

    RGB_TOG            , RGB_SLD ,
    TOGGLE_LAYER_COLOR ,
    _______            , RGB_HUD , RGB_HUI
  ),

  [MEDIA] = LAYOUT_ergodox(
    // Left hand
    KC_SLEP , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , KC_WH_L , KC_MS_U , KC_WH_R , _______ , _______ ,
    _______ , _______ , KC_MS_L , KC_MS_D , KC_MS_R , TG(GAM) ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , KC_BTN2 , KC_BTN1 ,

              YF_SAV  , YF_UP   ,
                        YF_DWN  ,
    _______ , YF_RES  , YF_DEF  ,

    // Right hand
    _______ , _______ , _______ , _______ , _______ , _______ , RESET      ,
    _______ , KC_WH_U , KC_VOLU , KC_VOLD , KC_MUTE , KC_PSCR , S(KC_PSCR) ,
              KC_WH_D , KC_ACL0 , KC_ACL1 , KC_ACL2 , _______ , KC_MPLY    ,
    _______ , KC_BTN3 , KC_MPLY , KC_MPRV , KC_MNXT , _______ , _______    ,
                        KC_BTN1 , KC_BTN2 , KC_MUTE , _______ , _______    ,

    _______ , _______ ,
    _______ ,
    _______ , KC_WBAK , KC_WFWD
  ),

  [GAMING] = LAYOUT_ergodox(
    // Left hand
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    KC_LCTL , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,

              _______ , _______ ,
                        _______ ,
    _______ , KC_LALT , KC_ESC  ,

    // Right hand
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
              _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                        _______ , _______ , _______ , _______ , _______ ,

    _______ , _______ ,
    _______ ,
    _______ , _______ , _______
  ),

  [SWAP] = LAYOUT_ergodox(
    // Left hand
    KC_MINS     , KC_6      , KC_7    , KC_8    , KC_9    , KC_0    , KC_ESC  ,
    KC_BSLS     , KC_Y      , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC ,
    WT(KC_QUOT) , T_M(KC_H) , KC_J    , KC_K    , KC_L    , KC_SCLN ,
    KC_RSFT     , KC_N      , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RBRC ,
    TG(SWP)     , KC_LBRC   , KC_RBRC , KC_DOWN , KC_UP   ,

              KC_LCTL , KC_PGUP ,
                        KC_PGDN ,
    KC_ENT  , KC_RCTL , KC_DEL  ,

    // Right hand
    KC_ESC  , KC_1 , KC_2    , KC_3    , KC_4   , KC_5    , KC_EQL      ,
    KC_DEL  , KC_Q , KC_W    , KC_E    , KC_R   , KC_T    , KC_TAB      ,
              KC_A , KC_S    , KC_D    , KC_F   , KC_G    , CT(KC_BSPC) ,
    KC_LBRC , KC_Z , KC_X    , KC_C    , KC_V   , KC_B    , KC_LSFT     ,
                     KC_LEFT , KC_RGHT , KC_GRV , KC_QUOT , TG(SWP)     ,

    KC_END  , KC_APP     ,
    KC_HOME ,
    KC_LGUI , AT(KC_ESC) , KC_SPACE
  ),

  [NIL] = LAYOUT_ergodox(
    // Left hand
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,

              _______ , _______ ,
                        _______ ,
    _______ , _______ , _______ ,

    // Right hand
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
              _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                        _______ , _______ , _______ , _______ , _______ ,

    _______ , _______ ,
    _______ ,
    _______ , _______ , _______
  ),

};


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

typedef struct {
  uint8_t row, col;
} yego_pos_t;

static yego_pos_t yego_black_pos = { .row = 0, .col = 0 };

static inline void yego_black_move_row(int8_t ofs) {
  int8_t new = yego_black_pos.row + ofs;
  yego_black_pos.row = (new < 0) ? 4 : (new > 4) ? 0 : new;
}

static inline void yego_black_move_col(int8_t ofs) {
  int8_t new = yego_black_pos.col + ofs;
  yego_black_pos.col = (new < 0) ? 9 : (new > 9) ? 0 : new;
}

static inline uint8_t yego_pos_to_led_index(yego_pos_t pos) {
  uint8_t res = 0;
  if (pos.row == 4 && (pos.col == 4 || pos.col == 5)) return -1;
  if (pos.col < 5) { // left hand
    res = 24;
    res += pos.row * 5;
    res += 4 - pos.col;
    if (pos.row == 4) res -= 1;
  } else { // right hand
    res += pos.row * 5;
    res += pos.col - 5;
    if (pos.row == 4) res -= 1;
  }

  return res;
}

static uint8_t yego_hue = 0;
#define YEGO_FREQ_DEFAULT 4
static uint8_t yego_freq_saved = YEGO_FREQ_DEFAULT;
static uint8_t yego_freq = YEGO_FREQ_DEFAULT;

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) return;

  static int yego_tick = 0;

  if (++yego_tick % yego_freq == 0) ++yego_hue;

  RGB rgb = hsv_to_rgb((HSV) { .h = yego_hue, .s = 255, .v = 255 });
  rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);

  uint8_t idx = yego_pos_to_led_index(yego_black_pos);
  if (idx == (uint8_t) -1) return;
  rgb_matrix_set_color(idx, 0, 0, 0);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case YEGO_RGB_FREQ_UP:
      if (record->event.pressed) ++yego_freq;
      return false;
    case YEGO_RGB_FREQ_DOWN:
      if (record->event.pressed) --yego_freq;
      return false;
    case YEGO_RGB_FREQ_DEFAULT:
      if (record->event.pressed) yego_freq = YEGO_FREQ_DEFAULT;
      return false;
    case YEGO_RGB_FREQ_SAVE:
      if (record->event.pressed) yego_freq_saved = yego_freq;
      return false;
    case YEGO_RGB_FREQ_RESTORE:
      if (record->event.pressed) yego_freq = yego_freq_saved;
      return false;
    case KC_UP:
      if (record->event.pressed) yego_black_move_row(-1);
      return true;
    case KC_DOWN:
      if (record->event.pressed) yego_black_move_row(+1);
      return true;
    case KC_LEFT:
      if (record->event.pressed) yego_black_move_col(-1);
      return true;
    case KC_RIGHT:
      if (record->event.pressed) yego_black_move_col(+1);
      return true;
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
