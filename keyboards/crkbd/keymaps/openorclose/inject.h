switch(combo_index) {
    case C_ENDSENT:
    if (pressed) {
        SEND_STRING(". ");
        add_oneshot_mods(MOD_BIT(KC_LSFT));
        break;
    }
}