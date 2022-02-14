# Copyright 2019 Manna Harbour
# https://github.com/manna-harbour/miryoku
# generated -*- buffer-read-only: t -*-

MOUSEKEY_ENABLE = yes # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control
AUTO_SHIFT_ENABLE = yes # Auto Shift
COMMAND_ENABLE   = no # Commands for debug and configuration
UNICODE_ENABLE   = no# Unicode
NKRO_ENABLE =    yes
EXTRAFLAGS        += -flto

COMBO_ENABLE = yes

SRC += features/caps_word.c

# alternative layouts:
