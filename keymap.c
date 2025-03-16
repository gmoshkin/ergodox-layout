#include QMK_KEYBOARD_H
#include "version.h"

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
#define ST(KEY)    LSFT_T(KEY)
#define W_USB_P    WEBUSB_PAIR
#define KC_SPC     KC_SPACE
#define BOOTLOADER QK_BOOTLOADER

#define STATIC_ASSERT(c, name) static uint8_t name[(c) ? 1 : -1];

void static_asserts(void) {
  STATIC_ASSERT(QK_BOOTLOADER == 0x00005c00, assert_QK_BOOTLOADER); (void) assert_QK_BOOTLOADER;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ergodox(
    // Left hand
    KC_EQL      , KC_1    , KC_2    , KC_3   , KC_4    , KC_5 , KC_ESC  ,
    KC_TAB      , KC_Q    , KC_W    , KC_E   , KC_R    , KC_T , KC_DEL  ,
    CT(KC_BSPC) , KC_A    , KC_S    , KC_D   , KC_F    , KC_G ,
    KC_LSFT     , KC_Z    , KC_X    , KC_C   , KC_V    , KC_B , MO(SYM) ,
    MO(SYM)     , KC_GRV  , KC_QUOT , KC_LEFT, KC_RGHT ,

               KC_APP     , KC_END  ,
                            KC_HOME ,
    KC_LCTL, KC_SPC, AT(KC_ESC),

    // Right hand
    KC_ESC  , KC_6 , KC_7  , KC_8    , KC_9    , KC_0         , KC_MINS     ,
    KC_BSPC , KC_Y , KC_U  , KC_I    , KC_O    , KC_P         , KC_BSLS     ,
              KC_H , KC_J  , KC_K    , KC_L    , T_M(KC_SCLN) , WT(KC_QUOT) ,
    MO(SYM) , KC_N , KC_M  , KC_COMM , KC_DOT  , KC_SLSH      , KC_RSFT     ,
                     KC_UP , KC_DOWN , KC_LBRC , KC_RBRC      , KC_LALT     ,

    KC_PGUP , KC_LCTL ,
    KC_PGDN ,
    KC_DEL  , KC_ENT, KC_RSFT
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
              KC_DOWN , KC_4    , KC_5   , KC_6  , KC_PLUS , KC_LGUI ,
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
    _______ , _______ , _______ , _______ , _______ , _______ , BOOTLOADER ,
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
    KC_SPC  , KC_LALT , KC_ESC  ,

    // Right hand
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
              _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                        _______ , _______ , _______ , _______ , _______ ,

    _______ , _______ ,
    _______ ,
    _______ , _______ , KC_ENT
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

#define YEGO_LED_INDEX_KEY_1       28
#define YEGO_LED_INDEX_KEY_2       27
#define YEGO_LED_INDEX_KEY_3       26
#define YEGO_LED_INDEX_KEY_4       25
#define YEGO_LED_INDEX_KEY_5       24
#define YEGO_LED_INDEX_KEY_6        0
#define YEGO_LED_INDEX_KEY_7        1
#define YEGO_LED_INDEX_KEY_8        2
#define YEGO_LED_INDEX_KEY_9        3
#define YEGO_LED_INDEX_KEY_0        4
#define YEGO_LED_INDEX_KEY_Q       33
#define YEGO_LED_INDEX_KEY_W       32
#define YEGO_LED_INDEX_KEY_E       31
#define YEGO_LED_INDEX_KEY_R       30
#define YEGO_LED_INDEX_KEY_T       29
#define YEGO_LED_INDEX_KEY_Y        5
#define YEGO_LED_INDEX_KEY_U        6
#define YEGO_LED_INDEX_KEY_I        7
#define YEGO_LED_INDEX_KEY_O        8
#define YEGO_LED_INDEX_KEY_P        9
#define YEGO_LED_INDEX_KEY_A       38
#define YEGO_LED_INDEX_KEY_S       37
#define YEGO_LED_INDEX_KEY_D       36
#define YEGO_LED_INDEX_KEY_F       35
#define YEGO_LED_INDEX_KEY_G       34
#define YEGO_LED_INDEX_KEY_H       10
#define YEGO_LED_INDEX_KEY_J       11
#define YEGO_LED_INDEX_KEY_K       12
#define YEGO_LED_INDEX_KEY_L       13
#define YEGO_LED_INDEX_KEY_colon   14
#define YEGO_LED_INDEX_KEY_Z       43
#define YEGO_LED_INDEX_KEY_X       42
#define YEGO_LED_INDEX_KEY_C       41
#define YEGO_LED_INDEX_KEY_V       40
#define YEGO_LED_INDEX_KEY_B       39
#define YEGO_LED_INDEX_KEY_N       15
#define YEGO_LED_INDEX_KEY_M       16
#define YEGO_LED_INDEX_KEY_lt      17
#define YEGO_LED_INDEX_KEY_gt      18
#define YEGO_LED_INDEX_KEY_qmark   19
#define YEGO_LED_INDEX_KEY_tilde   47
#define YEGO_LED_INDEX_KEY_dquote  46
#define YEGO_LED_INDEX_KEY_left    45
#define YEGO_LED_INDEX_KEY_right   44
#define YEGO_LED_INDEX_KEY_up      20
#define YEGO_LED_INDEX_KEY_down    21
#define YEGO_LED_INDEX_KEY_lb      22
#define YEGO_LED_INDEX_KEY_rb      23

static inline uint8_t yego_led_index_world_to_internal(uint8_t index) {
  switch (index) {
    case  0: return YEGO_LED_INDEX_KEY_1;
    case  1: return YEGO_LED_INDEX_KEY_2;
    case  2: return YEGO_LED_INDEX_KEY_3;
    case  3: return YEGO_LED_INDEX_KEY_4;
    case  4: return YEGO_LED_INDEX_KEY_5;
    case  5: return YEGO_LED_INDEX_KEY_6;
    case  6: return YEGO_LED_INDEX_KEY_7;
    case  7: return YEGO_LED_INDEX_KEY_8;
    case  8: return YEGO_LED_INDEX_KEY_9;
    case  9: return YEGO_LED_INDEX_KEY_0;
    case 10: return YEGO_LED_INDEX_KEY_Q;
    case 11: return YEGO_LED_INDEX_KEY_W;
    case 12: return YEGO_LED_INDEX_KEY_E;
    case 13: return YEGO_LED_INDEX_KEY_R;
    case 14: return YEGO_LED_INDEX_KEY_T;
    case 15: return YEGO_LED_INDEX_KEY_Y;
    case 16: return YEGO_LED_INDEX_KEY_U;
    case 17: return YEGO_LED_INDEX_KEY_I;
    case 18: return YEGO_LED_INDEX_KEY_O;
    case 19: return YEGO_LED_INDEX_KEY_P;
    case 20: return YEGO_LED_INDEX_KEY_A;
    case 21: return YEGO_LED_INDEX_KEY_S;
    case 22: return YEGO_LED_INDEX_KEY_D;
    case 23: return YEGO_LED_INDEX_KEY_F;
    case 24: return YEGO_LED_INDEX_KEY_G;
    case 25: return YEGO_LED_INDEX_KEY_H;
    case 26: return YEGO_LED_INDEX_KEY_J;
    case 27: return YEGO_LED_INDEX_KEY_K;
    case 28: return YEGO_LED_INDEX_KEY_L;
    case 29: return YEGO_LED_INDEX_KEY_colon;
    case 30: return YEGO_LED_INDEX_KEY_Z;
    case 31: return YEGO_LED_INDEX_KEY_X;
    case 32: return YEGO_LED_INDEX_KEY_C;
    case 33: return YEGO_LED_INDEX_KEY_V;
    case 34: return YEGO_LED_INDEX_KEY_B;
    case 35: return YEGO_LED_INDEX_KEY_N;
    case 36: return YEGO_LED_INDEX_KEY_M;
    case 37: return YEGO_LED_INDEX_KEY_lt;
    case 38: return YEGO_LED_INDEX_KEY_gt;
    case 39: return YEGO_LED_INDEX_KEY_qmark;
    case 40: return YEGO_LED_INDEX_KEY_tilde;
    case 41: return YEGO_LED_INDEX_KEY_dquote;
    case 42: return YEGO_LED_INDEX_KEY_left;
    case 43: return YEGO_LED_INDEX_KEY_right;
    case 44: return YEGO_LED_INDEX_KEY_up;
    case 45: return YEGO_LED_INDEX_KEY_down;
    case 46: return YEGO_LED_INDEX_KEY_lb;
    case 47: return YEGO_LED_INDEX_KEY_rb;
    default: return 0xff;
  }
}

static inline uint8_t yego_row_column_to_led_index_internal(uint8_t row, uint8_t col) {
  switch (row) {
    case 0:
      switch (col) {
        case  1: return YEGO_LED_INDEX_KEY_1;
        case  2: return YEGO_LED_INDEX_KEY_2;
        case  3: return YEGO_LED_INDEX_KEY_3;
        case  4: return YEGO_LED_INDEX_KEY_4;
        case  5: return YEGO_LED_INDEX_KEY_5;
        case  8: return YEGO_LED_INDEX_KEY_6;
        case  9: return YEGO_LED_INDEX_KEY_7;
        case 10: return YEGO_LED_INDEX_KEY_8;
        case 11: return YEGO_LED_INDEX_KEY_9;
        case 12: return YEGO_LED_INDEX_KEY_0;
        default: return 0xff;
      }
    case 1:
      switch (col) {
        case  1: return YEGO_LED_INDEX_KEY_Q;
        case  2: return YEGO_LED_INDEX_KEY_W;
        case  3: return YEGO_LED_INDEX_KEY_E;
        case  4: return YEGO_LED_INDEX_KEY_R;
        case  5: return YEGO_LED_INDEX_KEY_T;
        case  8: return YEGO_LED_INDEX_KEY_Y;
        case  9: return YEGO_LED_INDEX_KEY_U;
        case 10: return YEGO_LED_INDEX_KEY_I;
        case 11: return YEGO_LED_INDEX_KEY_O;
        case 12: return YEGO_LED_INDEX_KEY_P;
        default: return 0xff;
      }
    case 2:
      switch (col) {
        case  1: return YEGO_LED_INDEX_KEY_A;
        case  2: return YEGO_LED_INDEX_KEY_S;
        case  3: return YEGO_LED_INDEX_KEY_D;
        case  4: return YEGO_LED_INDEX_KEY_F;
        case  5: return YEGO_LED_INDEX_KEY_G;
        case  8: return YEGO_LED_INDEX_KEY_H;
        case  9: return YEGO_LED_INDEX_KEY_J;
        case 10: return YEGO_LED_INDEX_KEY_K;
        case 11: return YEGO_LED_INDEX_KEY_L;
        case 12: return YEGO_LED_INDEX_KEY_colon;
        default: return 0xff;
      }
    case 3:
      switch (col) {
        case  1: return YEGO_LED_INDEX_KEY_Z;
        case  2: return YEGO_LED_INDEX_KEY_X;
        case  3: return YEGO_LED_INDEX_KEY_C;
        case  4: return YEGO_LED_INDEX_KEY_V;
        case  5: return YEGO_LED_INDEX_KEY_B;
        case  8: return YEGO_LED_INDEX_KEY_N;
        case  9: return YEGO_LED_INDEX_KEY_M;
        case 10: return YEGO_LED_INDEX_KEY_lt;
        case 11: return YEGO_LED_INDEX_KEY_gt;
        case 12: return YEGO_LED_INDEX_KEY_qmark;
        default: return 0xff;
      }
    case 4:
      switch (col) {
        case  1: return YEGO_LED_INDEX_KEY_tilde;
        case  2: return YEGO_LED_INDEX_KEY_dquote;
        case  3: return YEGO_LED_INDEX_KEY_left;
        case  4: return YEGO_LED_INDEX_KEY_right;
        case  9: return YEGO_LED_INDEX_KEY_up;
        case 10: return YEGO_LED_INDEX_KEY_down;
        case 11: return YEGO_LED_INDEX_KEY_lb;
        case 12: return YEGO_LED_INDEX_KEY_rb;
        default: return 0xff;
      }
    default: return 0xff;
  }
}

#define YEGO_FREQ_DEFAULT 4
static uint8_t yego_freq_saved = YEGO_FREQ_DEFAULT;
static uint8_t yego_freq = YEGO_FREQ_DEFAULT;
static uint8_t do_override_digit_rbg = 0;
static uint32_t override_digit_rbg_value = 0;

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) return;

  static int current_tick = 0;
  static uint8_t current_led_hue = 0;
  static uint8_t led_hue_offset_buffer[48] = {0};

  current_tick += 1;
  if (current_tick % yego_freq == 0) ++current_led_hue;

  uint8_t hue_delta_this_tick = 0;
  if (current_tick % (yego_freq / 2) == 0) hue_delta_this_tick = 1;

  HSV hsv = (HSV) { .h = current_led_hue, .s = 255, .v = 255 };
  RGB rgb;

  for (uint8_t row = 0; row < 5; row++) {
    for (uint8_t col = 1; col < 13; col++) {
      if (col == 6 || col == 7) continue;
      int i = yego_row_column_to_led_index_internal(row, col);
      if (i == 0xff) continue;

      uint8_t *hue_offset = &led_hue_offset_buffer[i];
      if (*hue_offset > 0) *hue_offset -= hue_delta_this_tick;
      /*
       * I don't know who called these rows & cols,
       * I can see that on my ergodox these are definitely inverted
       */
      if (matrix_is_on(col, row)) *hue_offset = 128;

      hsv.h = current_led_hue - *hue_offset;
      rgb = hsv_to_rgb(hsv);
      rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }

  if (do_override_digit_rbg) {
      RGB rgb_on  = (RGB) { .r = 0xff, .g = 0xff, .b = 0xff, };
      RGB rgb_off = (RGB) { .r = 0xff, .g = 0x00, .b = 0x00, };

      rgb = (override_digit_rbg_value & 0x00000001) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_9, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00000002) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_8, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00000004) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_7, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00000008) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_6, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00000010) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_4, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00000020) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_3, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00000040) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_2, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00000080) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_1, rgb.r, rgb.g, rgb.b);

      rgb = (override_digit_rbg_value & 0x00000100) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_O, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00000200) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_I, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00000400) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_U, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00000800) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_Y, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00001000) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_R, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00002000) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_E, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00004000) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_W, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00008000) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_Q, rgb.r, rgb.g, rgb.b);

      rgb = (override_digit_rbg_value & 0x00010000) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_L, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00020000) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_K, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00040000) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_J, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00080000) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_H, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00100000) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_F, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00200000) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_D, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00400000) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_S, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x00800000) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_A, rgb.r, rgb.g, rgb.b);

      rgb = (override_digit_rbg_value & 0x01000000) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_gt, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x02000000) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_lt, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x04000000) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_M, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x08000000) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_N, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x10000000) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_V, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x20000000) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_C, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x40000000) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_X, rgb.r, rgb.g, rgb.b);
      rgb = (override_digit_rbg_value & 0x80000000) ? rgb_on : rgb_off; rgb_matrix_set_color(YEGO_LED_INDEX_KEY_Z, rgb.r, rgb.g, rgb.b);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case RGB_MOD:
      if (record->event.pressed) do_override_digit_rbg = 1 - do_override_digit_rbg;
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
  }
  return true;
}

uint16_t layer_state_set_user(uint16_t state) {

  override_digit_rbg_value = state;
  override_digit_rbg_value |= ((uint32_t) SYMBOLS << 0x08);
  override_digit_rbg_value |= ((uint32_t) MEDIA   << 0x10);
  override_digit_rbg_value |= ((uint32_t) GAMING  << 0x18);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  if (state & (1 << SYMBOLS)) ergodox_right_led_1_on();
  if (state & (1 << MEDIA))   ergodox_right_led_2_on();
  if (state & (1 << GAMING))  ergodox_right_led_3_on();
  return state;
};

// vi: sw=2
