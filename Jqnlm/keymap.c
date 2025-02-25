#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
};


typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;
tap_dance_action_t *action;

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    TO(8),          KC_MEDIA_STOP,  KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_CAPS,                                        KC_PSCR,        KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,
    KC_NO,          CW_TOGG,        KC_W,           KC_F,           KC_P,           KC_G,                                           KC_J,           KC_L,           KC_U,           KC_Y,           KC_DELETE,      RGB_TOG,        
    KC_Q,           KC_A,           KC_R,           KC_S,           KC_T,           KC_D,                                           KC_H,           KC_N,           KC_E,           KC_I,           KC_O,           KC_QUOTE,       
    TG(1),          KC_Z,           MEH_T(KC_X),    ALL_T(KC_C),    KC_V,           KC_B,                                           KC_K,           KC_M,           ALL_T(KC_COMMA),MEH_T(KC_DOT),  KC_SLASH,       KC_RIGHT_ALT,   
                                                    LT(2,KC_ENTER), LT(3,KC_ESCAPE),                                LT(5,KC_BSPC),  LT(4,KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_NO,          KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_NO,          KC_NO,          
    KC_Q,           KC_A,           KC_S,           MT(MOD_LCTL, KC_D),MT(MOD_LSFT, KC_F),KC_G,                                           KC_H,           MT(MOD_RSFT, KC_J),MT(MOD_RCTL, KC_K),KC_L,           KC_P,           KC_QUOTE,       
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
                                                    LT(2,KC_ENTER), LT(3,KC_ESCAPE),                                LT(5,KC_BSPC),  LT(4,KC_SPACE)
  ),
  [2] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          RGB_VAD,        RGB_VAI,        
    KC_NO,          KC_NO,          KC_NO,          LGUI(KC_TAB),   LCTL(KC_TAB),   KC_NO,                                          ST_MACRO_0,     ST_MACRO_1,     ST_MACRO_2,     ST_MACRO_3,     ST_MACRO_4,     KC_NO,          
    KC_NO,          OSM(MOD_LGUI),  OSM(MOD_LALT),  OSM(MOD_LCTL),  OSM(MOD_LSFT),  KC_NO,                                          ST_MACRO_5,     KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,          
    KC_TRANSPARENT, KC_NO,          KC_NO,          LALT(LCTL(KC_LEFT_GUI)),QK_LLCK,        KC_NO,                                          KC_NO,          KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          LSFT(KC_G),     KC_K,                                           KC_NO,          KC_7,           KC_8,           KC_9,           KC_NO,          KC_NO,          
    KC_NO,          OSM(MOD_LGUI),  OSM(MOD_LALT),  OSM(MOD_LCTL),  OSM(MOD_LSFT),  KC_J,                                           KC_ASTR,        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_NO,          
    KC_NO,          KC_NO,          KC_MEH,         KC_HYPR,        QK_LLCK,        KC_TRANSPARENT,                                 KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_MINUS,       KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_DELETE,      KC_0
  ),
  [4] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_EXLM,        KC_EQUAL,       KC_PERC,        KC_ASTR,                                        KC_HASH,        KC_GRAVE,       KC_MINUS,       KC_BSLS,        KC_NO,          KC_NO,          
    KC_CIRC,        KC_LBRC,        KC_LCBR,        KC_LPRN,        KC_COLN,        KC_AMPR,                                        KC_DLR,         OSM(MOD_LSFT),  OSM(MOD_LCTL),  OSM(MOD_LALT),  OSM(MOD_LGUI),  KC_AT,          
    KC_NO,          KC_RBRC,        KC_RCBR,        KC_RPRN,        KC_SCLN,        KC_NO,                                          KC_NO,          KC_TILD,        KC_UNDS,        KC_PIPE,        KC_NO,          KC_NO,          
                                                    KC_SPACE,       KC_NO,                                          KC_NO,          KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_UP,       KC_MS_WH_UP,    KC_MS_WH_RIGHT,                                 KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          LGUI(KC_LEFT),  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    LGUI(KC_RIGHT),                                 KC_NO,          OSM(MOD_LSFT),  OSM(MOD_RCTL),  OSM(MOD_RALT),  OSM(MOD_RGUI),  KC_NO,          
    KC_NO,          TD(DANCE_0),    LGUI(KC_X),     LGUI(KC_C),     TD(DANCE_1),    KC_MS_BTN3,                                     KC_NO,          QK_LLCK,        LGUI(LCTL(LSFT(KC_4))),KC_NO,          KC_NO,          KC_NO,          
                                                    KC_MS_BTN1,     KC_MS_BTN2,                                     KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_SYSTEM_SLEEP,                                KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          QK_BOOT,        KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_NO,          
    KC_NO,          OSM(MOD_LGUI),  OSM(MOD_LALT),  OSM(MOD_LCTL),  OSM(MOD_LSFT),  KC_NO,                                          KC_NO,          KC_F4,          KC_F5,          KC_F6,          KC_F11,         KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F12,         KC_NO,          
                                                    KC_NO,          KC_NO,                                          KC_NO,          KC_NO
  ),
  [7] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_6,                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    ST_MACRO_7,     ST_MACRO_8,     ST_MACRO_9,     KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_B),                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_10,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_voyager(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          
    KC_T,           KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_G,           KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_B,           KC_LEFT_CTRL,   KC_Z,           KC_X,           KC_C,           KC_V,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_SPACE,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const uint16_t PROGMEM combo0[] = { KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_Z, MEH_T(KC_X), COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_Z, ALL_T(KC_C), COMBO_END};
const uint16_t PROGMEM combo3[] = { MEH_T(KC_X), ALL_T(KC_C), COMBO_END};
const uint16_t PROGMEM combo4[] = { ALL_T(KC_C), KC_V, COMBO_END};
const uint16_t PROGMEM combo5[] = { LT(3,KC_ESCAPE), LT(5,KC_BSPC), COMBO_END};
const uint16_t PROGMEM combo6[] = { LT(3,KC_ESCAPE), LT(5,KC_BSPC), COMBO_END};
const uint16_t PROGMEM combo7[] = { LT(2,KC_ENTER), LT(4,KC_SPACE), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_TAB),
    COMBO(combo1, LCTL(KC_Z)),
    COMBO(combo2, LCTL(KC_X)),
    COMBO(combo3, LCTL(KC_C)),
    COMBO(combo4, LCTL(KC_V)),
    COMBO(combo5, OSL(6)),
    COMBO(combo6, OSL(6)),
    COMBO(combo7, OSL(7)),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_T:
            return TAPPING_TERM -50;
        case LT(2,KC_ENTER):
            return TAPPING_TERM -80;
        case LT(3,KC_ESCAPE):
            return TAPPING_TERM -80;
        case KC_N:
            return TAPPING_TERM -50;
        case LT(5,KC_BSPC):
            return TAPPING_TERM -80;
        case LT(4,KC_SPACE):
            return TAPPING_TERM -80;
        case MT(MOD_LSFT, KC_F):
            return TAPPING_TERM -50;
        case MT(MOD_RSFT, KC_J):
            return TAPPING_TERM -50;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {25,195,255}, {25,195,255}, {0,0,0}, {0,0,0}, {245,195,249}, {25,195,255}, {135,151,220}, {191,125,231}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {175,22,244}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {25,195,255}, {25,195,255}, {25,195,255}, {25,195,255}, {25,195,255}, {0,0,0}, {25,195,255}, {25,195,255}, {25,195,255}, {25,195,255}, {25,195,255}, {0,0,0}, {0,0,0}, {25,195,255}, {25,195,255}, {25,195,255}, {25,195,255}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {245,195,249}, {245,195,249}, {0,0,0}, {245,195,249}, {25,195,255}, {135,151,220}, {191,125,231}, {245,195,249}, {0,0,0}, {0,0,0}, {175,22,244}, {175,22,244}, {175,22,244}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {245,195,249}, {245,195,249}, {245,195,249}, {245,195,249}, {0,0,0}, {0,0,0}, {245,195,249}, {245,195,249}, {245,195,249}, {245,195,249}, {245,195,249}, {245,195,249}, {245,195,249}, {245,195,249}, {245,195,249}, {245,195,249}, {245,195,249}, {0,0,0}, {245,195,249}, {245,195,249} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {135,151,220}, {135,151,220}, {135,151,220}, {135,151,220}, {135,151,220}, {0,0,0}, {135,151,220}, {135,151,220}, {135,151,220}, {135,151,220}, {135,151,220}, {0,0,0}, {135,151,220}, {135,151,220}, {135,151,220}, {135,151,220}, {135,151,220}, {135,151,220}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {135,151,220}, {135,151,220}, {135,151,220}, {135,151,220}, {135,151,220}, {0,0,0}, {135,151,220}, {245,195,249}, {25,195,255}, {135,151,220}, {191,125,231}, {0,0,0}, {0,0,0}, {135,151,220}, {135,151,220}, {135,151,220}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {191,125,231}, {191,125,231}, {191,125,231}, {191,125,231}, {191,125,231}, {0,0,0}, {191,125,231}, {191,125,231}, {191,125,231}, {191,125,231}, {191,125,231}, {0,0,0}, {191,125,231}, {191,125,231}, {191,125,231}, {191,125,231}, {191,125,231}, {191,125,231}, {191,125,231}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {245,195,249}, {25,195,255}, {135,151,220}, {191,125,231}, {0,0,0}, {0,0,0}, {175,22,244}, {191,125,231}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,218,204}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {191,125,231}, {135,151,220}, {25,195,255}, {245,195,249}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {245,195,249}, {25,195,255}, {135,151,220}, {191,125,231}, {0,0,0}, {0,0,0}, {245,195,249}, {25,195,255}, {135,151,220}, {191,125,231}, {0,0,0}, {0,0,0}, {245,195,249}, {25,195,255}, {135,151,220}, {191,125,231}, {0,0,0}, {0,0,0}, {0,0,0} },

    [7] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {10,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {84,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [8] = { {189,255,238}, {189,255,238}, {189,255,238}, {189,255,238}, {189,255,238}, {189,255,238}, {189,255,238}, {189,255,238}, {128,222,183}, {128,222,183}, {128,222,183}, {128,222,183}, {189,255,238}, {189,255,238}, {128,222,183}, {128,222,183}, {128,222,183}, {189,255,238}, {189,255,238}, {189,255,238}, {189,255,238}, {189,255,238}, {189,255,238}, {189,255,238}, {189,255,238}, {189,255,238}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,240}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
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

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
    case 8:
      set_layer_color(8);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_W)) SS_DELAY(100) SS_TAP(X_Q));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_W)) SS_DELAY(100) SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_W)) SS_DELAY(100) SS_TAP(X_DOWN));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_W)) SS_DELAY(100) SS_TAP(X_UP));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_W)) SS_DELAY(100) SS_TAP(X_RIGHT));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(100) SS_TAP(X_V) SS_DELAY(100) SS_TAP(X_S) SS_DELAY(100) SS_TAP(X_P)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(100) SS_LSFT(SS_TAP(X_G)));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(100) SS_TAP(X_W) SS_DELAY(100) SS_TAP(X_Q)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(100) SS_TAP(X_Q)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(100) SS_TAP(X_W)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_LBRC));
    }
    break;

    case TD(DANCE_0):
    case TD(DANCE_1):
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }
        break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }


tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_TAP_HOLD(LGUI(KC_Z), LGUI(LSFT(KC_Z))),
        [DANCE_1] = ACTION_TAP_DANCE_TAP_HOLD(LGUI(KC_V), LGUI(LSFT(KC_V))),
};
