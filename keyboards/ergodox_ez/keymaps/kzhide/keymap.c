#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_japanese.h"

typedef union {
    uint32_t raw;
    struct {
        bool jis: 1;
    };
} user_config_t;
user_config_t user_config;

enum layers {
    BASE,  // default layer
    BASEQ, // Qwerty
    BASE_ONISHI, // Onishi
    BASE_NOACT, // Dvorak-like, without romaji modification
    SYMB,  // symbols
    MDIA,  // media keys
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be he
  ROT_BL,
  EPRM,
  VRSN,
  RGB_SLD,
  JIS_MODE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer (Dvorak)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  | JISM |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Grv    |   '  |   ,  |   .  |   P  |   Y  | BASE |           |  L1  |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------| SWCH |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   -    |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |   ;  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |    L1| LAlt |   /  |   [  |   ]  |                                       | Left | Down |  Up  | Rght |   \  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | PScr | Home |       | PgUp  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | Eisu |       | Kana |        |      |
 *                                 |      |      | Gui  |       | Gui  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   JIS_MODE,
        KC_GRV,        KC_QUOT,      KC_COMM,   KC_DOT,   KC_P,   KC_Y,   DF(BASEQ),
        KC_LCTL,        KC_A,         KC_O,   KC_E,   KC_U,   KC_I,
        KC_LSFT,        KC_SCLN,  KC_Q,   KC_J,   KC_K,   KC_X,   DF(BASE_NOACT),
        MO(SYMB),KC_LALT,      KC_SLSH,  KC_LBRC,KC_RBRC,
                                                   KC_PSCR,  KC_HOME,
                                                              KC_END,
                                               KC_SPC,KC_BSPC,LGUI_T(KC_LNG2),
        // right hand
             KC_RGHT,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_EQL,
             TG(SYMB),    KC_F,   KC_G,  KC_C,   KC_R,   KC_L,             KC_SLSH,
                          KC_D,   KC_H,  KC_T,   KC_N,   KC_S,          KC_MINS,
             TG(MDIA),     KC_B,   KC_M,  KC_W,KC_V, CTL_T(KC_Z),   KC_COLN,
                                  KC_LEFT, KC_DOWN,KC_UP,KC_RGHT,          LT(MDIA, KC_BSLS),
             KC_PGUP,        CTL_T(KC_ESC),
             KC_PGDN,
             RGUI_T(KC_LNG1),KC_TAB, KC_ENT
    ),
/* Keymap 3: Basic layer (Qwerty)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Grv    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   -    |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   '  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       | Left | Down |  Up  | Rght |   \  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | PScr | Home |       | PgUp |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | Eisu |       | Kana |        |      |
 *                                 |      |      | Gui  |       | Gui  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASEQ] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   JIS_MODE,
        KC_GRV,        KC_Q,      KC_W,   KC_E,   KC_R,   KC_T,   DF(BASE_NOACT),
        KC_LCTL,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,   DF(BASE),
        MO(SYMB),KC_LALT,      KC_SLSH,  KC_LBRC,KC_RBRC,
                                              KC_PSCR,  KC_HOME,
                                                              KC_END,
                                               KC_SPC,KC_BSPC,LGUI_T(KC_LNG2),
        // right hand
             KC_RGHT,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_EQL,
             TG(SYMB),    KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_SLSH,
                          KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,          KC_MINS,
             TG(MDIA),     KC_N,   KC_M,  KC_COMM,KC_DOT, CTL_T(KC_QUOT),   KC_COLN,
                                  KC_LEFT, KC_DOWN,KC_UP,KC_RGHT,          LT(MDIA, KC_BSLS),
             KC_PGUP,        CTL_T(KC_ESC),
             KC_PGDN,
             RGUI_T(KC_LNG1),KC_TAB, KC_ENT
    ),
/* Keymap 6: Basic layer (Onishi)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Grv    |   Q  |   L  |   U  |   ,  |   .  |  L3  |           |  L1  |   F  |   W  |   R  |   Y  |   P  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   E  |   I  |   A  |   O  |   -  |------|           |------|   K  |   T  |   N  |   S  |   H  |   -    |
 * |--------+------+------+------+------+------| TRNS |           |  xx  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   ;  |      |           |      |   G  |   D  |   M  |   J  |   B  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1| Alt  |   /  |  { [ | ] }  |                                       | Left | Down |  Up  | Rght | \L2  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | PScr | Home |       | PgUp |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | Eisu |       | Kana |        |      |
 *                                 |      |      | Gui  |       | Gui  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE_ONISHI] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   JIS_MODE,
        KC_GRV,        KC_Q,      KC_L,   KC_U,   KC_COMM,   KC_DOT,   DF(BASE_NOACT),
        KC_LCTL,        KC_E,         KC_I,   KC_A,   KC_O,   KC_MINS,
        KC_LSFT,        KC_Z,  KC_X,   KC_C,   KC_V,   KC_SCLN,   DF(BASEQ),
        MO(SYMB),KC_LALT,      KC_SLSH,  KC_LBRC,KC_RBRC,
                                              KC_PSCR,  KC_HOME,
                                                              KC_END,
                                               KC_SPC,KC_BSPC,LGUI_T(KC_LNG2),
        // right hand
             KC_RGHT,     KC_6,   KC_7,  KC_8,  KC_9,   KC_0,             KC_EQL,
             TG(SYMB),    KC_F,   KC_W,  KC_R,   KC_Y,   KC_P,             KC_SLSH,
                          KC_K,   KC_T,  KC_N,  KC_S,   KC_H,          KC_MINS,
             TG(MDIA),     KC_G,   KC_D,  KC_M,  KC_J,   KC_B,   KC_COLN,
                                  KC_LEFT, KC_DOWN,KC_UP,KC_RGHT,          LT(MDIA, KC_BSLS),
             KC_PGUP,        CTL_T(KC_ESC),
             KC_PGDN,
             RGUI_T(KC_LNG1),KC_TAB, KC_ENT
    ),
/* Keymap -: Basic layer (No-Act Dvorak)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Grv    |   '  |   ,  |   .  |   P  |   L  |  L3  |           |  L1  |   F  |   G  |   K  |   R  |   Y  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   -    |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |   ;  |   Q  |   J  |   C  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1| LAlt |   /  |   [  |   ]  |                                       | Left | Down |  Up  | Rght |   \  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | PScr | Home |       | PgUp  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | Eisu |       | Kana |        |      |
 *                                 |      |      | Gui  |       | Gui  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE_NOACT] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   JIS_MODE,
        KC_GRV,        KC_QUOT,      KC_COMM,   KC_DOT,   KC_P,   KC_L,   DF(BASE),
        KC_LCTL,        KC_A,         KC_O,   KC_E,   KC_U,   KC_I,
        KC_LSFT,        CTL_T(KC_SCLN),  KC_Q,   KC_J,   KC_C,   KC_X,   DF(BASEQ),
        MO(SYMB),KC_LALT,      KC_SLSH,  KC_LBRC,KC_RBRC,
                                                   KC_PSCR,  KC_HOME,
                                                              KC_END,
                                               KC_SPC,KC_BSPC,LGUI_T(KC_LNG2),
        // right hand
             KC_RGHT,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_EQL,
             TG(SYMB),    KC_F,   KC_G,  KC_K,   KC_R,   KC_Y,             KC_SLSH,
                          KC_D,   KC_H,  KC_T,   KC_N,   KC_S,          KC_MINS,
             TG(MDIA),     KC_B,   KC_M,  KC_W,KC_V, CTL_T(KC_Z),   KC_COLN,
                                  KC_LEFT, KC_DOWN,KC_UP,KC_RGHT,          LT(MDIA, KC_BSLS),
             KC_PGUP,        CTL_T(KC_ESC),
             KC_PGDN,
             RGUI_T(KC_LNG1),KC_TAB, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
         QK_BOOT,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |  Up  |      |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      | Left | Down | Rght |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolDn |VolUp | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_F12,
                 KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM layercolors[][2] = {
  [BASE] = {0, 255},
  [BASEQ] = {170, 255},
  [BASE_ONISHI] = {30, 255},
  [BASE_NOACT] = {120, 255},
  [SYMB] = {0, 255},
  [MDIA] = {85, 255},
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

// US/JIS切り替え用
const uint16_t us2jis[][2] = {
  {KC_LPRN, JP_LPRN},
  {KC_RPRN, JP_RPRN},
  {KC_AT,   JP_AT},
  {KC_LBRC, JP_LBRC},
  {KC_RBRC, JP_RBRC},
  {KC_LCBR, JP_LCBR},
  {KC_RCBR, JP_RCBR},
  {KC_MINS, JP_MINS},
  {KC_EQL,  JP_EQL},
  {KC_BSLS, JP_BSLS},
  {KC_SCLN, JP_SCLN},
  {KC_QUOT, JP_QUOT},
  {KC_GRV,  JP_GRV},
  {KC_PLUS, JP_PLUS},
  {KC_COLN, JP_COLN},
  {KC_UNDS, JP_UNDS},
  {KC_PIPE, JP_PIPE},
  {KC_DQT,  JP_DQUO},
  {KC_ASTR, JP_ASTR},
  {KC_TILD, JP_TILD},
  {KC_AMPR, JP_AMPR},
  {KC_CIRC, JP_CIRC},
};

bool twpair_on_jis(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) return true;

  uint16_t skeycode; // シフトビットを反映したキーコード
  bool lshifted = keyboard_report->mods & MOD_BIT(KC_LSFT); // シフトキーの状態
  bool rshifted = keyboard_report->mods & MOD_BIT(KC_RSFT);
  bool shifted = lshifted | rshifted;

  if (shifted) {
    skeycode = QK_LSFT | keycode;
  } else {
    skeycode = keycode;
  }

  for (int i = 0; i < sizeof(us2jis) / sizeof(us2jis[0]); i++) {
    if (us2jis[i][0] == skeycode) {
      unregister_code(KC_LSFT);
      unregister_code(KC_RSFT);
      if ((us2jis[i][1] & QK_LSFT) == QK_LSFT || (us2jis[i][1] & QK_RSFT) == QK_RSFT) {
        register_code(KC_LSFT);
        tap_code(us2jis[i][1]);
        unregister_code(KC_LSFT);
      } else {
        tap_code(us2jis[i][1]);
      }
      if (lshifted) register_code(KC_LSFT);
      if (rshifted) register_code(KC_RSFT);
      return false;
    }
  }

  return true;
}

void set_jis_mode_led(void) {
    if (user_config.jis) {
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_off();
    }
}

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
    set_jis_mode_led();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
    case JIS_MODE:
      if (record->event.pressed) {
          if (user_config.jis == 1) {
              user_config.jis = 0;
          } else {
              user_config.jis = 1;
          }
          set_jis_mode_led();
          eeconfig_update_user(user_config.raw);
      }
      return false;
      break;
  }

  if (user_config.jis) {
      return twpair_on_jis(keycode, record);
  } else {
      return true;
  }
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
#ifdef RGB_MATRIX_ENABLE
  rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
  rgb_matrix_sethsv(0, 0, 255);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

#ifdef RGB_MATRIX_ENABLE
void set_layer_color(uint8_t layer) {
  HSV hsv = { .h = pgm_read_byte(&layercolors[layer][0]), .s = pgm_read_byte(&layercolors[layer][1]), .v = 200 };
  //RGB rgb = hsv_to_rgb( hsv );

  //for (int i = 0; i < 10; ++i) {
  //  rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
  //}
  rgb_matrix_sethsv(hsv.h, hsv.s, hsv.v);
}

bool rgb_matrix_indicators_user(void) {
  if(rgb_matrix_config.enable == 1) {
    uint8_t layer = biton32(default_layer_state);

    HSV hsv = { .h = pgm_read_byte(&layercolors[layer][0]), .s = pgm_read_byte(&layercolors[layer][1]), .v = 200 };
    RGB rgb = hsv_to_rgb( hsv );

    for (int i = 0; i < 5; ++i) {
      rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    for (int i = 24; i < 29; ++i) {
      rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
  return true;
}
#endif

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        rgb_matrix_sethsv(0, 0, 255);
        rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
        break;
      case SYMB:
        ergodox_right_led_1_on();
        rgb_matrix_sethsv(pgm_read_byte(&layercolors[SYMB][0]), pgm_read_byte(&layercolors[SYMB][1]), 255);
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_symbol_effect);
        break;
      case MDIA:
        ergodox_right_led_2_on();
        rgb_matrix_sethsv(pgm_read_byte(&layercolors[MDIA][0]), pgm_read_byte(&layercolors[MDIA][1]), 255);
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_media_effect);
        break;
      default:
        break;
    }
  return state;
};
