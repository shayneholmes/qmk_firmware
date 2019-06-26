#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include QMK_KEYBOARD_CONFIG_H

#undef MANUFACTURER
#undef PRODUCT
#undef DESCRIPTION
#define MANUFACTURER    Shayne Holmes
#define PRODUCT         Ergodox
#define DESCRIPTION     QMK firmware for Ergodox; layout by Shayne Holmes

#undef  TAPPING_TOGGLE
#define TAPPING_TOGGLE  2
#undef  TAPPING_TERM
#define TAPPING_TERM    230

#define DEBOUNCE 15

#undef  QMK_KEYS_PER_SCAN
#define QMK_KEYS_PER_SCAN 4

#define LEADER_TIMEOUT 300

#endif
