#include QMK_KEYBOARD_H

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

#define U_RDO KC_AGIN
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND KC_UNDO
#include "features/caps_word.h"
#include "features/adaptive_keys.h"

enum layers { BASE, CODE, MEDIA, NAV, MOUSE, SYM, NUM, FUN, QWERTY };

enum custom_keycodes {
  EQ2 = SAFE_RANGE,
  EQ3,
  NEQ,
  NEQ2,
  FAT_ARROW,
  GEQ,
  LEQ,
  BAND,
  EXP,
  BOR,
  COMMENT,
  DOTDOT,
  SEMINL,
  SELWORD,
  SELSENT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] =
        LAY(KC_ESC, KC_G, KC_M, KC_P, KC_V, KC_J, KC_DOT, KC_SLASH, KC_ENT, KC_QUOT,
            LGUI_T(KC_C), LALT_T(KC_S), LCTL_T(KC_N), LSFT_T(KC_T), KC_W, KC_COMM,
            RSFT_T(KC_A), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_H), KC_X,
            ALGR_T(KC_F), KC_L, LT(CODE, KC_D), KC_B, KC_MINS, LT(CODE, KC_U),
            KC_O, ALGR_T(KC_Y), KC_K, U_NP, U_NP, LT(MOUSE, KC_ESC),
            LT(NAV, KC_R), LT(MEDIA, KC_TAB), LT(SYM, KC_BSPC),
            LT(NUM, KC_SPC), LT(FUN, KC_DEL), U_NP, U_NP),
    /*[QWERTY] =
        LAY(KC_J, KC_G, KC_M, KC_P, KC_V, KC_J, KC_L, KC_COMM, KC_U, KC_NO,
            KC_C, KC_S, KC_N, KC_T, KC_W, KC_NO, KC_A, KC_E, KC_I, KC_H, KC_X,
            KC_F, KC_L, KC_D, KC_B, KC_NO, KC_U, KC_O, KC_Y, KC_K, U_NP, U_NP,
            KC_ESC, KC_R, KC_TAB, KC_BSPC, KC_SPC, KC_DEL, U_NP, U_NP),
    */ [QWERTY] = LAY(
       KC_Q,              KC_W,              KC_E,              KC_R, KC_T,
     KC_Y,              KC_U,              KC_I,              KC_O, KC_P, KC_A,
     KC_S,      KC_D,      KC_F,      KC_G,              KC_H, KC_J,      KC_K,
     KC_L,      KC_QUOT, KC_Z,  KC_X,      KC_C,              KC_V, KC_B, KC_N,
     KC_M,              KC_COMM,           KC_DOT,    KC_SLSH, U_NP, U_NP,
     KC_ESC, KC_SPC,   KC_TAB,  KC_ENT,   KC_BSPC,  KC_DEL,   U_NP, U_NP
     ),
    [NAV] = LAY(RESET, U_NA, U_NA, U_NA, U_NA, U_RDO, U_PST, U_CPY, U_CUT,
                U_UND, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA, KC_CAPS,
                KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, U_NA, KC_ALGR, U_NA, U_NA,
                U_NA, KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, U_NP, U_NP,
                U_NA, U_NA, U_NA, KC_BSPC, KC_BSPC, KC_DEL, U_NP, U_NP),
    [MOUSE] = LAY(RESET, U_NA, U_NA, U_NA, U_NA, U_RDO, U_PST, U_CPY, U_CUT,
                  U_UND, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA, U_NU,
                  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, U_NA, KC_ALGR, U_NA, U_NA,
                  U_NA, U_NU, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, U_NP, U_NP,
                  U_NA, U_NA, U_NA, KC_BTN1, KC_BTN3, KC_BTN2, U_NP, U_NP),
    [MEDIA] =
        LAY(RESET, U_NA, U_NA, U_NA, U_NA, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI,
            RGB_VAI, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA, U_NU, KC_LCBR,
            KC_RCBR, KC_LBRC, KC_RBRC, U_NA, KC_ALGR, U_NA, U_NA, U_NA,
            TG(QWERTY), KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, U_NP, U_NP, U_NA,
            U_NA, U_NA, KC_MSTP, KC_MPLY, KC_MUTE, U_NP, U_NP),
    [NUM] = LAY(KC_LBRC, KC_7, KC_8, KC_9, SELWORD, U_NA, U_NA, U_NA, U_NA,
                RESET, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL, U_NA, KC_LSFT,
                KC_LCTL, KC_LALT, KC_LGUI, KC_GRV, KC_1, KC_2, KC_3, KC_BSLS,
                U_NA, U_NA, U_NA, KC_ALGR, U_NA, U_NP, U_NP, KC_DOT, KC_0,
                KC_MINS, U_NA, U_NA, U_NA, U_NP, U_NP),
    [SYM] = LAY(KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, SELSENT, U_NA, U_NA, U_NA,
                U_NA, RESET, KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS, U_NA,
                KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_TILD, KC_EXLM, KC_AT,
                KC_HASH, KC_PIPE, U_NA, U_NA, U_NA, KC_ALGR, U_NA, U_NP, U_NP,
                KC_LPRN, KC_RPRN, KC_UNDS, U_NA, U_NA, U_NA, U_NP, U_NP),
    [FUN] = LAY(KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR, U_NA, U_NA, U_NA, U_NA,
                RESET, KC_F11, KC_F4, KC_F5, KC_F6, KC_SLCK, U_NA, KC_LSFT,
                KC_LCTL, KC_LALT, KC_LGUI, KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,
                U_NA, U_NA, U_NA, KC_ALGR, U_NA, U_NP, U_NP, KC_APP, KC_SPC,
                KC_TAB, U_NA, U_NA, U_NA, U_NP, U_NP),
    [CODE] = LAY(KC_TRNS, BAND, EXP, BOR, KC_TRNS, KC_TRNS, KC_TILD, KC_GRV,
                 FAT_ARROW, KC_TRNS, KC_TRNS, NEQ2, NEQ, KC_COLN, KC_TRNS,
                 KC_TRNS, SEMINL, EQ2, EQ3, KC_TRNS, KC_TRNS, GEQ, LEQ, U_NA,
                 KC_TRNS, KC_TRNS, U_NA, COMMENT, DOTDOT, KC_TRNS, U_NP, U_NP,
                 KC_BTN2, KC_SPC, KC_TAB, KC_ENT, KC_BSPC, KC_DEL, U_NP, U_NP)};

enum { STATE_NONE, STATE_SELECTED, STATE_WORD, STATE_FIRST_LINE, STATE_LINE };


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint8_t state = STATE_NONE;
  if (!process_adaptive_key(keycode, record)) {
    return false;
  }
  if (!process_caps_word(keycode, record)) {
    return false;
  }
  // Your macros ...
  if (record->event.pressed) {
    bool handled = true;
    switch (keycode) {
    case EQ2:
      SEND_STRING("==");
      break;
    case EQ3:
      SEND_STRING("===");
      break;
    case NEQ:
      SEND_STRING("!=");
      break;
    case NEQ2:
      SEND_STRING("!==");
      break;
    case FAT_ARROW:
      SEND_STRING("=>");
      break;
    case GEQ:
      SEND_STRING(">=");
      break;
    case LEQ:
      SEND_STRING("<=");
      break;
    case BAND:
      SEND_STRING("&&");
      break;
    case EXP:
      SEND_STRING("**");
      break;
    case BOR:
      SEND_STRING("||");
      break;
    case COMMENT:
      SEND_STRING("//");
      break;
    case DOTDOT:
      SEND_STRING("../");
      break;
    case SEMINL:
      SEND_STRING(";");
      tap_code(KC_ENT);
      break;
    case SELWORD:
      register_code(KC_LCTL);
      if (state == STATE_NONE) {
        SEND_STRING(SS_TAP(X_RGHT) SS_TAP(X_LEFT));
      }
      register_code(KC_LSFT);
      register_code(KC_RGHT);
      state = STATE_WORD;
      break;
    case SELSENT:
      if (state == STATE_NONE) {
        clear_mods();
        SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
        state = STATE_FIRST_LINE;
      } else {
        register_code(KC_LSFT);
        register_code(KC_DOWN);
        state = STATE_LINE;
      }
      break;
    default:
      handled = false;
    }
    if (handled)
      return false;
  }

  switch (state) {
  case STATE_WORD:
    unregister_code(KC_RGHT);
    unregister_code(KC_LSFT);
    unregister_code(KC_LCTL);
    state = STATE_SELECTED;
    break;

  case STATE_FIRST_LINE:
    state = STATE_SELECTED;
    break;

  case STATE_LINE:

    unregister_code(KC_DOWN);
    unregister_code(KC_LSFT);
    state = STATE_SELECTED;
    break;

  case STATE_SELECTED:
    if (keycode == KC_ESC) {
      tap_code(KC_RGHT);
      state = STATE_NONE;
      return false;
    }
    // Fallthrough.
  default:
    state = STATE_NONE;
  }

  return true;
}

#include "features/keymap_combo.h"