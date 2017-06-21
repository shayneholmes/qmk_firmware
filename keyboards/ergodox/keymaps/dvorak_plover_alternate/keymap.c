#include "ergodox.h"
#include "keymap_dvorak.h"
#include "action_util.h"
#include "action_layer.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Default Layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   ~    |   1  |   2  |   3  |   4  |   5  |   \  |           |   '  |   6  |   7  |   8  |   9  |   0  |   =    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   E  |   R  |   T  | ~Fn1 |           | ~Fn3 |   Y  |   U  |   I  |   O  |   P  |   [    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | LShift |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | RShift |
     * |--------+------+------+------+------+------|  Fn0 |           | ~Fn4 |------+------+------+------+------+--------|
     * | LCtrl  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RCtrl  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | ~Fn1 | ~Fn2 | Caps | LAlt | LGui |                                       |  Lft |  Up  |  Dn  | Rght | ~Fn4 |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | +Fn2 | Home |       | PgUp | Del  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |  End |       | PgDn |      |      |
     *                                 | BkSp |  ESC |------|       |------| Enter| Space|
     *                                 |      |      |  Spc |       | Ins  |      |      |
     *                                 `--------------------'       `--------------------'
     */

    // BASE LAYERS

    #define LAYER_BASE 0
    KEYMAP(  // layer 0: customized qwerty with symbol row switched
        // left hand
        KC_FN6, KC_FN12,KC_FN12,KC_FN12,KC_FN12,KC_FN12,KC_F17,
        KC_TAB, KC_FN6, KC_W,   KC_E,   KC_R,   KC_T,   KC_FN2,
        KC_LSFT,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_LCTL,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_DEL,
        KC_FN3, KC_FN1, KC_LCTL,KC_LALT,KC_LGUI,
                                      KC_FN5, KC_F15,
                                           KC_F16,
                                 KC_BSPC,KC_LSFT,KC_LGUI,
        // right hand
             KC_F18, KC_FN12,KC_FN12,KC_FN12,KC_FN12,KC_FN12,KC_MPLY,
             KC_FN3, KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_FN6,
                  KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_RSFT,
             KC_DEL, KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RCTL,
                       KC_RGUI,KC_RALT,KC_RCTL,KC_FN6, KC_FN2,
        KC_F13, KC_MPLY,
        KC_F14,
        KC_ENT, KC_FN1, KC_SPC
    ),

    KEYMAP(  // layer 1: transparent because this gets triggered more than I'd like
        // left hand
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                      KC_TRNS,KC_TRNS,
                                           KC_TRNS,
                                 KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
             KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
             KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
             KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
    ),

    KEYMAP(  // layer 2: customized dvorak
        // left hand
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_BSLS,
        KC_TAB, KC_QUOT,KC_COMM,KC_DOT, KC_P,   KC_Y,   KC_FN2,
        KC_LSFT,KC_A,   KC_O,   KC_E,   KC_U,   KC_I,
        KC_LCTL,KC_SCLN,KC_Q,   KC_J,   KC_K,   KC_X,   KC_DEL,
        KC_FN3, KC_FN1, KC_LCTL,KC_LALT,KC_LGUI,
                                      KC_FN5, KC_HOME,
                                           KC_END,
                                 KC_BSPC,KC_LSFT,KC_LGUI,
        // right hand
             KC_MINS,KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_EQL,
             KC_FN3, KC_F,   KC_G,   KC_C,   KC_R,   KC_L,   KC_SLSH,
                  KC_D,   KC_H,   KC_T,   KC_N,   KC_S,   KC_RSFT,
             KC_DEL, KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,   KC_RCTL,
                       KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_FN2,
        KC_PGUP,KC_MPLY,
        KC_PGDN,
        KC_ENT, KC_FN1, KC_SPC
    ),

    KEYMAP(  // layer 3 : qwerty
        // left hand
        KC_TRNS,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_TRNS,
        KC_TRNS,KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_TRNS,
        KC_TRNS,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_TRNS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                      KC_TRNS,KC_TRNS,
                                           KC_TRNS,
                                 KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
             KC_TRNS,KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,
             KC_TRNS,KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_RBRC,
                  KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_RSFT,
             KC_TRNS,KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,
                       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
    ),

    // PLOVER (SPECIAL CASE)

    #define LAYER_PLOVER 4
    KEYMAP(  // layer 4: Steno for Plover
        // left hand
        KC_FN5, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  
        KC_NO,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_NO,  
        KC_TRNS,KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,  
        KC_NO,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  
                                      KC_FN5, KC_NO,  
                                           KC_NO,  
                                 KC_C,   KC_V,   KC_NO,  
        // right hand
             KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_TRNS,
             KC_NO,  KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_TRNS,
                  KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,
             KC_NO,  KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
                       KC_TRNS,KC_TRNS,KC_NO,  KC_NO,  KC_NO,  
        KC_TRNS,KC_TRNS,  
        KC_TRNS,  
        KC_NO,  KC_N,   KC_M   
    ),

    // MODIFIERS THAT MIGHT BE STICKY

    #define LAYER_NUMPAD 5
    KEYMAP(  // layer 5: mouse + numpad
        // left hand
        KC_FN0, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_PAUS,KC_PSCR,
        KC_TRNS,KC_NO,  KC_WH_U,KC_MS_U,KC_WH_D,KC_BTN2,KC_TRNS,
        KC_TRNS,KC_NO,  KC_MS_L,KC_MS_D,KC_MS_R,KC_BTN1,
        KC_TRNS,KC_FN7, KC_NO,  KC_NO,  KC_NO,  KC_BTN3,KC_TRNS,
        KC_TRNS,KC_FN13,KC_TRNS,KC_TRNS,KC_TRNS,
                                      KC_TRNS,KC_TRNS,
                                           KC_TRNS,
                                 KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
             KC_SLCK,KC_NLCK,KC_EQL, KC_PSLS,KC_PAST,KC_PMNS,KC_TRNS,
             KC_TRNS,KC_BSPC,KC_P7,  KC_P8,  KC_P9,  KC_PMNS,KC_BSPC,
                      KC_BSPC,KC_P4,  KC_P5,  KC_P6,  KC_PMNS,KC_PENT,
             KC_BSPC,KC_BSPC,KC_P1,  KC_P2,  KC_P3,  KC_PPLS,KC_PENT,
                       KC_P0,  KC_PDOT,KC_PDOT,KC_PENT,KC_PENT,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_ENT, KC_TRNS,KC_TRNS
    ),

    #define LAYER_MOVEMENT 6
    KEYMAP(  // layer 6: F-keys + cursor
        // left hand
        KC_FN0, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
        KC_FN4,KC_NO,  KC_PGUP,KC_UP,  KC_PGDN,KC_NO,  KC_TRNS,
        KC_TRNS,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END, 
        KC_TRNS,KC_NO,  KC_NO,  KC_END, KC_HOME,KC_NO,  KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_FN10,KC_FN11,
                                      KC_TRNS,KC_TRNS,
                                           KC_TRNS,
                                 KC_LCTL,KC_LSFT,KC_TRNS,
        // right hand
             KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_MINS,
             KC_TRNS,KC_NO,  KC_PGUP,KC_UP,  KC_PGDN, KC_NO, KC_FN4,
                  KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END, KC_TRNS,
             KC_TRNS,KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_TRNS,
                       KC_RGUI,KC_RALT,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,
        KC_TRNS, KC_TRNS,KC_RSFT,KC_RCTL
    ),

    #define LAYER_BLUESHIFT 7
    KEYMAP(  // layer 7: "BlueShift"
        // left hand
        KC_FN0, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
        KC_TRNS,KC_FN12,KC_FN12,KC_FN12,KC_PSCR,KC_BSLS,KC_TRNS,  // the FN12 entries are for tilde and inverted brace/bracket keys
        KC_TRNS,KC_APP, KC_TAB, KC_RBRC,KC_QUOT,KC_INS,
        KC_TRNS,KC_TRNS,KC_FN8, KC_TRNS,KC_CAPS,KC_TRNS,KC_TRNS,  // quit (alt+f4)
        KC_FN13,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                      KC_TRNS,KC_TRNS,
                                           KC_TRNS,
                                 KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
             KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_TRNS,
             KC_TRNS,KC_PGUP,KC_FN8, KC_UP,  KC_FN8, KC_LBRC,KC_TRNS, // Home and End mapped to Cmd-L/KC_R
                  KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,KC_QUOT,KC_TRNS,
             KC_TRNS,KC_TRNS,KC_NO,  KC_UP,  KC_NO,  KC_TRNS,KC_TRNS,
                       KC_LEFT,KC_DOWN,KC_RGHT,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
    ),

    // MODIFIERS THAT WON'T BE STICKY

    #define LAYER_FKEYS 8
    KEYMAP(  // layer 8: F-keys only
        // left hand
        KC_FN0, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  
        KC_TRNS,KC_F13, KC_F14, KC_F15, KC_F16, KC_NO,  KC_TRNS,
        KC_TRNS,KC_F17, KC_F18, KC_F19, KC_F20, KC_NO,  
        KC_TRNS,KC_F21, KC_F22, KC_F23, KC_F24, KC_NO,  KC_TRNS,
        KC_FN13,KC_FN13,KC_TRNS,KC_LALT,KC_LGUI,
                                      KC_TRNS,KC_TRNS,
                                           KC_TRNS,
                                 KC_LCTL,KC_LSFT,KC_TRNS,
        // right hand
             KC_NO,  KC_NO,  KC_F10, KC_F11, KC_F12, KC_NO,  KC_TRNS,
             KC_TRNS,KC_NO,  KC_F7,  KC_F8,  KC_F9,  KC_NO,  KC_TRNS,
                  KC_NO,  KC_F4,  KC_F5,  KC_F6,  KC_NO,  KC_TRNS,
             KC_TRNS,KC_NO,  KC_F1,  KC_F2,  KC_F3,  KC_NO,  KC_TRNS,
                       KC_RGUI,KC_RALT,KC_RCTL,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_RSFT,KC_RCTL
    ),
};

/* id for user defined functions */
enum function_id {
    ANY_KEY,
    PLOVER_SWITCH,
    SHIFT_SWITCH,
    TEENSY_BUTTON,
    FKEY_SWITCH,
    UNUSED,
};

enum macro_id {
    PASSWORD1,
    PASSWORD2,
    PASSWORD3,
};

/*
 * Fn action definition (limited to 32)
 */
const uint16_t PROGMEM fn_actions[] = {
    ACTION_LAYER_SET(0, ON_PRESS),                  // FN0 - reset layer to just 0
    ACTION_LAYER_TAP_TOGGLE(LAYER_BLUESHIFT),       // FN1 - switch to BlueShift
    ACTION_LAYER_TAP_KEY(LAYER_MOVEMENT, KC_F21),   // FN2 - movement layer, also desktop switcher
    ACTION_LAYER_TAP_TOGGLE(LAYER_NUMPAD),          // FN3 - numpad
    ACTION_FUNCTION(TEENSY_BUTTON),                 // FN4 - teensy reset button
    ACTION_FUNCTION(PLOVER_SWITCH),                 // FN5 - toggle Plover
    ACTION_FUNCTION_OPT(ANY_KEY, LAYER_BASE),       // FN6 - AnyKey on Base
    ACTION_FUNCTION_OPT(ANY_KEY, LAYER_NUMPAD),     // FN7 - AnyKey on Numpad
    ACTION_FUNCTION_OPT(ANY_KEY, LAYER_BLUESHIFT),  // FN8 - AnyKey on Blueshift
    ACTION_FUNCTION(UNUSED),                        // ** FN9 - unused
    ACTION_MACRO(PASSWORD1),                        // FN10 - password1
    ACTION_MACRO(PASSWORD2),                        // FN11 - password2
    ACTION_FUNCTION(SHIFT_SWITCH),                  // FN12 - symbolized number row
    ACTION_FUNCTION(FKEY_SWITCH),                   // FN13 - Two-button Fkey layer requires special logic to get rid of it appropriately
};

void simon_hotkey(keyevent_t event, action_t action)
{
    switch (action.kind.id) {
        /* Key and Mods */
        case ACT_LMODS:
        case ACT_RMODS:
            {
                uint8_t mods = (action.kind.id == ACT_LMODS) ?  action.key.mods : action.key.mods<<4;
                if (event.pressed) {
                    if (mods) {
                        add_weak_mods(mods);
                        send_keyboard_report();
                    }
                    register_code(action.key.code);
                } else {
                    unregister_code(action.key.code);
                    if (mods) {
                        del_weak_mods(mods);
                        send_keyboard_report();
                    }
                }
            }
            break;
        default:
            print("not supported.\n");
            break;
    }
}

void action_plover_key(keyevent_t event) {
    if (event.pressed) return;

    uint8_t savedmods = get_mods();
    uint8_t shift_pressed = (savedmods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)));
    if (shift_pressed) {
        layer_off(LAYER_PLOVER); // shift+plover is a signal to AHK to restart Plover, so don't toggle the plover layer
        return;
    }

    bool turning_on = !(layer_state & 1<<LAYER_PLOVER);
    layer_invert(LAYER_PLOVER);
    if (turning_on) {
        // PHROPB
        action_macro_play(MACRO(D(E), D(R), D(F), D(V), D(I), D(K), U(E), U(R), U(F), U(V), U(I), U(K), END));
    } else {
        // PHRO*F
        action_macro_play(MACRO(D(E), D(R), D(F), D(V), D(Y), D(U), U(E), U(R), U(F), U(V), U(Y), U(U), END));
    }
}

uint16_t key_depending_on_mods(keyevent_t event, uint8_t default_key, uint8_t modified_key, uint8_t dependent_mods) {
    static bool mod_pressed;
    if (event.pressed) {
        // save mod state that will persist until the unpress
        mod_pressed = (get_mods() & dependent_mods);
    }
    return ACTION_MODS_KEY(0, mod_pressed ? modified_key : default_key);
}

uint16_t get_any_key_action(keyevent_t event, uint8_t layer) {
    uint8_t col = event.key.col;
    uint8_t row = event.key.row;

    switch (layer) {
        case LAYER_BLUESHIFT:
            if (col == 1) {
                switch (row) {
                    case 9:  return ACTION_MODS_KEY(MOD_LGUI, KC_LEFT); // Home
                    case 11: return ACTION_MODS_KEY(MOD_LGUI, KC_RGHT); // End
                }
            }
            break;
        case LAYER_NUMPAD:
            if (col == 3 && row == 1) {
                return ACTION_MODS_KEY(MOD_LSFT, KC_Z);  // :
            }
            break;
        case LAYER_BASE:
            if (col == 4 && row == 12) {
                return ACTION_MODS_KEY(MOD_LGUI, KC_TAB); // Alt+tab
            } else if (col == 1 && row == 1) { // apostrophe / CMD+`
                return key_depending_on_mods(event, KC_Q, KC_GRV, MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI));
            } else if (col == 1 && row == 13) { // media forward/back
                return key_depending_on_mods(event, KC_MEDIA_NEXT_TRACK, KC_MEDIA_PREV_TRACK, MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
            } else if (col == 0 && row == 0) { // ESC / CMD+`
                return key_depending_on_mods(event, KC_ESC, KC_GRV, MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI));
            }
            break;
        default:
            break;
    }
    if (!event.pressed) {
        print("Unknown anykey press:\n");
        print("col = "); pdec(col); print("\n");
        print("row = "); pdec(row); print("\n");
    }
    return ACTION_NO;
}

void action_any_key(keyevent_t event, uint8_t layer) {
    action_t action;
    action.code = get_any_key_action(event, layer);
    if (action.code != ACTION_NO) {
        simon_hotkey(event, action);
    }
}

uint8_t get_shiftswitch_key(keyevent_t event) {
    uint8_t col = event.key.col;
    uint8_t row = event.key.row;

    if (col == 0) { // Number row
        switch (row) {
            case 1:  return KC_1;
            case 2:  return KC_2;
            case 3:  return KC_3;
            case 4:  return KC_4;
            case 5:  return KC_5;
            case 8:  return KC_6;
            case 9:  return KC_7;
            case 10: return KC_8;
            case 11: return KC_9;
            case 12: return KC_0;
        }
    }
    else if (col == 1) { // next row
        switch (row) {
            case 1: return KC_GRV;
            case 2: return KC_MINS; // Left brace in Dvorak
            case 3: return KC_EQL; // Right brace in Dvorak
        }
    }
    return KC_NO;
}

void action_shiftswitch(keyevent_t event) {
    uint8_t keycode = get_shiftswitch_key(event);
    if (keycode == KC_NO) return;

    uint8_t savedmods = get_mods();

    action_t action;
    action.code = ACTION_MODS_KEY(savedmods ? 0 : MOD_LSFT, keycode);

    bool shift_pressed = savedmods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));

    if (shift_pressed) {
        del_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
        send_keyboard_report();
        simon_hotkey(event, action);
        set_mods(savedmods);
        send_keyboard_report();
    } else {
        simon_hotkey(event, action);
        del_weak_mods(MOD_BIT(KC_LSFT));
    }
}

bool is_out_of_order_fkey_release(keyevent_t event, uint32_t layer_state) {
    if (!event.pressed) return false;

    uint8_t row = event.key.row;
    return
        ((row == 0) && (layer_state & 1<<LAYER_NUMPAD)) ||
        ((row == 1) && (layer_state & 1<<LAYER_BLUESHIFT));
}

void action_fkey(keyevent_t event) {
    layer_invert(LAYER_FKEYS);
    if (is_out_of_order_fkey_release(event, layer_state)) { 
        layer_invert(LAYER_NUMPAD);
        layer_invert(LAYER_BLUESHIFT);
    }
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    keyevent_t event = record->event;

    switch (id) {
        case PLOVER_SWITCH:
            return action_plover_key(event);
        case ANY_KEY:
            return action_any_key(event, opt);
        case SHIFT_SWITCH:
            return action_shiftswitch(event);
        case TEENSY_BUTTON:
            clear_keyboard();
            wait_ms(50);
            bootloader_jump(); // not return
            break;
        case FKEY_SWITCH:
            return action_fkey(event);
        default:
            print("Unknown action_function called\n");
            print("id  = "); phex(id); print("\n");
            print("opt = "); phex(opt); print("\n");
            break;
    }
}

/*
 * Macro definition
 */
#include "passwords.h"

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    keyevent_t event = record->event;

    if (event.pressed) {
        switch (id) {
            case PASSWORD1: return MACRO_PASSWORD1;
            case PASSWORD2: return MACRO_PASSWORD2;
            case PASSWORD3: return MACRO_PASSWORD3;
        }
    }
    return MACRO_NONE;
}

// vim:shiftwidth=4:cindent:expandtab:tabstop=4
