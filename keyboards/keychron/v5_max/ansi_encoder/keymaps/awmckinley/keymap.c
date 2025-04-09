#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum custom_keycodes {
    PD_0 = SAFE_RANGE,
    PD_1,
    PD_2,
    PD_3,
    PD_4,
    PD_5,
    PD_6,
    PD_7,
    PD_8,
    PD_9,
    PD_BSLS,
    PD_EQL,
    PD_GRV,
    PD_MINS,
    PD_RBRC,
};

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
};

// macOS supports F1 to F19
#define MT_19RC RCMD_T(KC_F19)
#define MT_ESCA LCA_T(KC_ESC)
#define MT_ESOC LAG_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_98(
        KC_CAPS,            KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,            KC_DEL,   KC_HOME,  KC_END,     KC_MUTE,
        PD_GRV,   PD_1,     PD_2,     PD_3,     PD_4,     PD_5,     PD_6,     PD_7,     PD_8,     PD_9,     PD_0,     PD_MINS,  PD_EQL,     KC_BSPC,            KC_NUM,   KC_PSLS,  KC_PAST,    KC_PMNS,
        KC_TAB,   KC_SCLN,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_SLSH,  PD_RBRC,    PD_BSLS,            KC_P7,    KC_P8,    KC_P9,      KC_PPLS,
        MT_ESOC,  KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,              KC_ENT,             KC_P4,    KC_P5,    KC_P6,
        KC_LSFT,            KC_QUOT,  KC_Q,     KC_J,     KC_K,     KC_X,     KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,                 KC_RSFT,  KC_UP,    KC_P1,    KC_P2,    KC_P3,      KC_PENT,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 MT_19RC,  KC_ROPTN, MO(MAC_FN), KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT            ),
    [MAC_FN] = LAYOUT_ansi_98(
        _______,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,             _______,  _______,  _______,    RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,            _______,  _______,  _______,    _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,            _______,  _______,  _______,    _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,  _______,  _______,  _______,    _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______            ),
    [WIN_BASE] = LAYOUT_ansi_98(
        KC_CAPS,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,   KC_F12,             KC_DEL,   KC_HOME,  KC_END,     KC_MUTE,
        PD_GRV,   PD_1,     PD_2,     PD_3,     PD_4,     PD_5,     PD_6,     PD_7,     PD_8,     PD_9,     PD_0,     PD_MINS,    PD_EQL,   KC_BSPC,            KC_NUM,   KC_PSLS,  KC_PAST,    KC_PMNS,
        KC_TAB,   KC_SCLN,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_SLSH,    PD_RBRC,  PD_BSLS,            KC_P7,    KC_P8,    KC_P9,      KC_PPLS,
        MT_ESCA,  KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,              KC_ENT,             KC_P4,    KC_P5,    KC_P6,
        KC_LSFT,            KC_QUOT,  KC_Q,     KC_J,     KC_K,     KC_X,     KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,                 KC_RSFT,  KC_UP,    KC_P1,    KC_P2,    KC_P3,      KC_PENT,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT            ),
    [WIN_FN] = LAYOUT_ansi_98(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,    KC_VOLD,  KC_VOLU,            _______,  _______,  _______,    RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,  _______,  _______,    _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,  _______,  _______,    _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,  _______,  _______,  _______,    _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______            ),
 };

#if defined(ENCODER_MAP_ENABLE)

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
};

#endif // ENCODER_MAP_ENABLE

#if defined(KEY_OVERRIDE_ENABLE)

#define ko_make_user_base(trigger_key, replacement_key) \
	ko_make_with_layers_and_negmods(0, trigger_key, replacement_key, ~0, MOD_MASK_SHIFT)

#define ko_make_user_shft(trigger_key, replacement_key) \
	ko_make_basic(MOD_MASK_SHIFT, trigger_key, replacement_key)

const key_override_t base_0 = ko_make_user_base(PD_0, LSFT(KC_8));
const key_override_t shft_0 = ko_make_user_shft(PD_0, KC_0);

const key_override_t base_1 = ko_make_user_base(PD_1, LSFT(KC_EQL));
const key_override_t shft_1 = ko_make_user_shft(PD_1, KC_1);

const key_override_t base_2 = ko_make_user_base(PD_2, KC_LBRC);
const key_override_t shft_2 = ko_make_user_shft(PD_2, KC_2);

const key_override_t base_3 = ko_make_user_base(PD_3, LSFT(KC_LBRC));
const key_override_t shft_3 = ko_make_user_shft(PD_3, KC_3);

const key_override_t base_4 = ko_make_user_base(PD_4, LSFT(KC_9));
const key_override_t shft_4 = ko_make_user_shft(PD_4, KC_4);

const key_override_t base_5 = ko_make_user_base(PD_5, LSFT(KC_7));
const key_override_t shft_5 = ko_make_user_shft(PD_5, KC_5);

const key_override_t base_6 = ko_make_user_base(PD_6, KC_EQL);
const key_override_t shft_6 = ko_make_user_shft(PD_6, KC_6);

const key_override_t base_7 = ko_make_user_base(PD_7, LSFT(KC_0));
const key_override_t shft_7 = ko_make_user_shft(PD_7, KC_7);

const key_override_t base_8 = ko_make_user_base(PD_8, LSFT(KC_RBRC));
const key_override_t shft_8 = ko_make_user_shft(PD_8, KC_8);

const key_override_t base_9 = ko_make_user_base(PD_9, KC_RBRC);
const key_override_t shft_9 = ko_make_user_shft(PD_9, KC_9);

const key_override_t base_bsls = ko_make_user_base(PD_BSLS, KC_BSLS);
const key_override_t shft_bsls = ko_make_user_shft(PD_BSLS, LSFT(KC_3));

const key_override_t base_eql = ko_make_user_base(PD_EQL, LSFT(KC_BSLS));
const key_override_t shft_eql = ko_make_user_shft(PD_EQL, KC_GRAVE);

const key_override_t base_grv = ko_make_user_base(PD_GRV, LSFT(KC_4));
const key_override_t shft_grv = ko_make_user_shft(PD_GRV, LSFT(KC_6));

const key_override_t base_mins = ko_make_user_base(PD_MINS, LSFT(KC_1));
const key_override_t shft_mins = ko_make_user_shft(PD_MINS, LSFT(KC_5));

const key_override_t base_rbrc = ko_make_user_base(PD_RBRC, LSFT(KC_2));
const key_override_t shft_rbrc = ko_make_user_shft(PD_RBRC, LSFT(KC_GRAVE));

const key_override_t **key_overrides = (const key_override_t *[]){
    &base_0,
    &shft_0,
    &base_1,
    &shft_1,
    &base_2,
    &shft_2,
    &base_3,
    &shft_3,
    &base_4,
    &shft_4,
    &base_5,
    &shft_5,
    &base_6,
    &shft_6,
    &base_7,
    &shft_7,
    &base_8,
    &shft_8,
    &base_9,
    &shft_9,
    &base_bsls,
    &shft_bsls,
    &base_eql,
    &shft_eql,
    &base_grv,
    &shft_grv,
    &base_mins,
    &shft_mins,
    &base_rbrc,
    &shft_rbrc,
    NULL,
};

#endif // KEY_OVERRIDE_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}
