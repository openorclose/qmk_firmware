#define DP(A, B) \
if (pressed) { \
    if (caps_word_get()) { \
        register_code(KC_LSFT); \
        tap_code(A); \
        tap_code(B); \
        unregister_code(KC_LSFT); \
    } else { \
        tap_code(A); \
        if (get_mods() & MOD_MASK_SHIFT) { \
            del_mods(MOD_MASK_SHIFT); \
        } \
        tap_code(B); \
    }     \
    break; \
}

switch(combo_index) {
case C_ENDSENT:
    if (pressed) {
        SEND_STRING(". ");
        add_oneshot_mods(MOD_BIT(KC_LSFT));
        break;
    }
case C_QU:
    DP(KC_Q, KC_U);
case C_YOU:
    DP(KC_Y, KC_O);
    DP(KC_U, KC_NO);
}