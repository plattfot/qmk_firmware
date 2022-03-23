OLED_ENABLE = yes
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
LEADER_ENABLE = no         # Disable the Leader Key feature
MOUSEKEY_ENABLE = no       # Disable mouse, need to save space.
COMBO_ENABLE = yes

SRC += features/caps_word.c
SRC += features/close_tap.c
