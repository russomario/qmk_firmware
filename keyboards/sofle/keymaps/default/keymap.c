#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

#include "quantum.h"

enum {
    TD_SHIFT_CAPS
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_QUOT,
        KC_ESC, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    KC_BSPC,
        TD(TD_SHIFT_CAPS), KC_A, KC_S,  KC_D,   KC_F,   KC_G,             KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_RSFT,
        KC_TAB,  KC_Z,  KC_X,   KC_C,   KC_V,   KC_B, KC_NO,       KC_MUTE,KC_N,  KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_MINS,
                        KC_LCTL,KC_LALT,KC_LGUI,TT(1), KC_ENT,     KC_SPC, TT(2), KC_RGUI,KC_RALT,KC_RCTL
    ),

    [1] = LAYOUT(
        KC_TILD,KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,                  KC_CIRC,KC_AMPR,KC_ASTR,KC_NO,  KC_NO,   KC_NO,
        KC_TAB, KC_NO,  KC_NO,  KC_NO,  QK_MACRO_1, KC_UNDS,              KC_QUOT,KC_DQUO,KC_LPRN,KC_RPRN,KC_KB_VOLUME_UP, KC_BSPC,
        KC_CAPS,KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_PMNS,                  KC_PEQL,KC_PPLS,KC_LBRC,KC_RBRC,KC_KB_VOLUME_DOWN, KC_RSFT,
        KC_TAB, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,     QK_MACRO_2,KC_BSLS,KC_PIPE,KC_LCBR,KC_RCBR,KC_KB_MUTE,KC_MPLY,
                        KC_LCTL,KC_LALT,KC_LGUI,KC_NO, KC_NO,      QK_MACRO_0,KC_RGUI,KC_RALT,KC_RCTL,KC_NO
    ),

    [2] = LAYOUT(
        KC_NO,  KC_NO,  KC_F2,  KC_NO,  KC_NO,  KC_NO,                    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                    QK_MACRO_3,QK_MACRO_4,KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                    KC_LEFT,KC_DOWN,KC_UP, KC_RGHT,KC_NO,   KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,     KC_MUTE,KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,
                        KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,      KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO
    ),

};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case QK_MACRO_0:
                SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCMD)SS_TAP(X_SPC)SS_UP(X_LCMD)SS_UP(X_LSFT));
                return false;
            case QK_MACRO_1:
                SEND_STRING("->");
                return false;
            case QK_MACRO_2:
                SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LCMD)SS_TAP(X_C)SS_UP(X_LCMD)SS_UP(X_LALT)SS_UP(X_LCTL));
                return false;
            case QK_MACRO_3:
                SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LSFT)SS_TAP(X_EQL)SS_UP(X_LSFT)SS_UP(X_LALT));
                return false;
            case QK_MACRO_4:
                SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LSFT)SS_TAP(X_MINS)SS_UP(X_LSFT)SS_UP(X_LALT));
                return false;
        }
    }

    return true;
};


