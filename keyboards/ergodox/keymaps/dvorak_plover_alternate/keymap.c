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
        FN6, FN12,FN12,FN12,FN12,FN12,F17,
        TAB, FN6, W,   E,   R,   T,   FN2,
        LSFT,A,   S,   D,   F,   G,
        LCTL,Z,   X,   C,   V,   B,   DEL,
        FN3, FN1, LCTL,LALT,LGUI,
                                      FN5, F15,
                                           F16,
                                 BSPC,LSFT,LGUI,
        // right hand
             F18, FN12,FN12,FN12,FN12,FN12,MPLY,
             FN3, Y,   U,   I,   O,   P,   FN6,
                  H,   J,   K,   L,   SCLN,RSFT,
             DEL, N,   M,   COMM,DOT, SLSH,RCTL,
                       RGUI,RALT,RCTL,FN6, FN2,
        F13, MPLY,
        F14,
        ENT, FN1, SPC
    ),

    KEYMAP(  // layer 1: transparent because this gets triggered more than I'd like
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // layer 2: customized dvorak
        // left hand
        ESC, 1,   2,   3,   4,   5,   BSLS,
        TAB, QUOT,COMM,DOT, P,   Y,   FN2,
        LSFT,A,   O,   E,   U,   I,
        LCTL,SCLN,Q,   J,   K,   X,   DEL,
        FN3, FN1, LCTL,LALT,LGUI,
                                      FN5, HOME,
                                           END,
                                 BSPC,LSFT,LGUI,
        // right hand
             MINS,6,   7,   8,   9,   0,   EQL,
             FN3, F,   G,   C,   R,   L,   SLSH,
                  D,   H,   T,   N,   S,   RSFT,
             DEL, B,   M,   W,   V,   Z,   RCTL,
                       LEFT,DOWN,UP,  RGHT,FN2,
        PGUP,MPLY,
        PGDN,
        ENT, FN1, SPC
    ),

    KEYMAP(  // layer 3 : qwerty
        // left hand
        TRNS,1,   2,   3,   4,   5,   TRNS,
        TRNS,Q,   W,   E,   R,   T,   TRNS,
        TRNS,A,   S,   D,   F,   G,
        TRNS,Z,   X,   C,   V,   B,   TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,6,   7,   8,   9,   0,   MINS,
             TRNS,Y,   U,   I,   O,   P,   RBRC,
                  H,   J,   K,   L,   SCLN,RSFT,
             TRNS,N,   M,   COMM,DOT, SLSH,RSFT,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    // PLOVER (SPECIAL CASE)

    #define LAYER_PLOVER 4
    KEYMAP(  // layer 4: Steno for Plover
        // left hand
        FN5, NO,  NO,  NO,  NO,  NO,  NO,  
        NO,  1,   2,   3,   4,   5,   NO,  
        TRNS,Q,   W,   E,   R,   T,  
        NO,  A,   S,   D,   F,   G,   NO,
        NO,  NO,  NO,  NO,  NO,  
                                      FN5, NO,  
                                           NO,  
                                 C,   V,   NO,  
        // right hand
             NO,  NO,  NO,  NO,  NO,  NO,  TRNS,
             NO,  6,   7,   8,   9,   0,   TRNS,
                  Y,   U,   I,   O,   P,   LBRC,
             NO,  H,   J,   K,   L,   SCLN,QUOT,
                       TRNS,TRNS,NO,  NO,  NO,  
        TRNS,TRNS,  
        TRNS,  
        NO,  N,   M   
    ),

    // MODIFIERS THAT MIGHT BE STICKY

    #define LAYER_NUMPAD 5
    KEYMAP(  // layer 5: mouse + numpad
        // left hand
        FN0, NO,  NO,  NO,  NO,  PAUS,PSCR,
        TRNS,NO,  WH_U,MS_U,WH_D,BTN2,TRNS,
        TRNS,NO,  MS_L,MS_D,MS_R,BTN1,
        TRNS,FN7, NO,  NO,  NO,  BTN3,TRNS,
        TRNS,FN13,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             SLCK,NLCK,EQL, PSLS,PAST,PMNS,TRNS,
             TRNS,BSPC,P7,  P8,  P9,  PMNS,BSPC,
                  BSPC,P4,  P5,  P6,  PMNS,PENT,
             BSPC,BSPC,P1,  P2,  P3,  PPLS,PENT,
                       P0,  PDOT,PDOT,PENT,PENT,
        TRNS,TRNS,
        TRNS,
        ENT, TRNS,TRNS
    ),

    #define LAYER_MOVEMENT 6
    KEYMAP(  // layer 6: F-keys + cursor
        // left hand
        FN0, F1,  F2,  F3,  F4,  F5,  F6,
        BTLD,NO,  PGUP,UP,  PGDN,NO,  TRNS,
        TRNS,HOME,LEFT,DOWN,RGHT,END, 
        TRNS,NO,  NO,  END, HOME,NO,  TRNS,
        TRNS,TRNS,TRNS,FN10,FN11,
                                      TRNS,TRNS,
                                           TRNS,
                                 LCTL,LSFT,TRNS,
        // right hand
             F7,  F8,  F9,  F10, F11, F12, MINS,
             TRNS,NO,  PGUP,UP,  PGDN, NO, BTLD,
                  HOME,LEFT,DOWN,RGHT,END, TRNS,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                       RGUI,RALT,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS, TRNS,RSFT,RCTL
    ),

    #define LAYER_BLUESHIFT 7
    KEYMAP(  // layer 7: "BlueShift"
        // left hand
        FN0, F1,  F2,  F3,  F4,  F5,  F6,
        TRNS,FN12,FN12,FN12,PSCR,BSLS,TRNS,  // the FN12 entries are for tilde and inverted brace/bracket keys
        TRNS,APP, TAB, RBRC,QUOT,INS,
        TRNS,TRNS,FN8, TRNS,CAPS,TRNS,TRNS,  // quit (alt+f4)
        FN13,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F7,  F8,  F9,  F10, F11, F12, TRNS,
             TRNS,PGUP,FN8, UP,  FN8, LBRC,TRNS, // Home and End mapped to Cmd-L/R
                  PGDN,LEFT,DOWN,RGHT,QUOT,TRNS,
             TRNS,TRNS,NO,  UP,  NO,  TRNS,TRNS,
                       LEFT,DOWN,RGHT,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    // MODIFIERS THAT WON'T BE STICKY

    #define LAYER_FKEYS 8
    KEYMAP(  // layer 8: F-keys only
        // left hand
        FN0, NO,  NO,  NO,  NO,  NO,  NO,  
        TRNS,F13, F14, F15, F16, NO,  TRNS,
        TRNS,F17, F18, F19, F20, NO,  
        TRNS,F21, F22, F23, F24, NO,  TRNS,
        FN13,FN13,TRNS,LALT,LGUI,
                                      TRNS,TRNS,
                                           TRNS,
                                 LCTL,LSFT,TRNS,
        // right hand
             NO,  NO,  F10, F11, F12, NO,  TRNS,
             TRNS,NO,  F7,  F8,  F9,  NO,  TRNS,
                  NO,  F4,  F5,  F6,  NO,  TRNS,
             TRNS,NO,  F1,  F2,  F3,  NO,  TRNS,
                       RGUI,RALT,RCTL,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,RSFT,RCTL
    ),
};

/* id for user defined functions */
enum function_id {
    ANY_KEY,
    PLOVER_SWITCH,
    SHIFT_SWITCH,
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
static const action_t PROGMEM fn_actions[] = {
    ACTION_LAYER_SET(0, ON_PRESS),                  // FN0 - reset layer to just 0
    ACTION_LAYER_TAP_TOGGLE(LAYER_BLUESHIFT),       // FN1 - switch to BlueShift
    ACTION_LAYER_TAP_KEY(LAYER_MOVEMENT, KC_F21),   // FN2 - movement layer, also desktop switcher
    ACTION_LAYER_TAP_TOGGLE(LAYER_NUMPAD),          // FN3 - numpad
    ACTION_FUNCTION(UNUSED),                        // ** FN4 - unused
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

action_t key_depending_on_mods(keyevent_t event, uint8_t default_key, uint8_t modified_key, uint8_t dependent_mods) {
    static bool mod_pressed;
    if (event.pressed) {
        // save mod state that will persist until the unpress
        mod_pressed = (get_mods() & dependent_mods);
    }
    return (action_t) ACTION_MODS_KEY(MOD_NONE, mod_pressed ? modified_key : default_key);
}

action_t get_any_key_action(keyevent_t event, uint8_t layer) {
    uint8_t col = event.key.col;
    uint8_t row = event.key.row;

    switch (layer) {
        case LAYER_BLUESHIFT:
            if (col == 1) {
                switch (row) {
                    case 9:  return (action_t)ACTION_MODS_KEY(MOD_LGUI, KC_LEFT); // Home
                    case 11: return (action_t)ACTION_MODS_KEY(MOD_LGUI, KC_RGHT); // End
                }
            }
            break;
        case LAYER_NUMPAD:
            if (col == 3 && row == 1) {
                return (action_t)ACTION_MODS_KEY(MOD_LSFT, KC_Z);  // :
            }
            break;
        case LAYER_BASE:
            if (col == 4 && row == 12) {
                return (action_t)ACTION_MODS_KEY(MOD_LGUI, KC_TAB); // Alt+tab
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
    return (action_t)ACTION_NO;
}

void action_any_key(keyevent_t event, uint8_t layer) {
    action_t action = get_any_key_action(event, layer);
    if (action.code != (action_t)ACTION_NO.code) {
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

    action_t action = (action_t)ACTION_MODS_KEY(savedmods ? MOD_NONE : MOD_LSFT, keycode);

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
#include "keymap_passwords.h"

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
