#include QMK_KEYBOARD_H
#include "keymap_dvorak.h"
#include "keymap_plover.h"

#include "sendstring_dvorak.h"

#ifdef SHAYNEH_PASSWORDS_H
#include "passwords.h"
#else
#include "passwords_example.h"
#endif

/* id for user defined functions */
enum function_id {
    ANY_KEY,
    PLOVER_SWITCH,
    SHIFT_SWITCH,
    FKEY_SWITCH,
    UNUSED,
};

/*
 * Macro definition
 */
enum macro_id {
    PASSWORD1,
    PASSWORD2,
    PASSWORD3,
};

// Tap Dance Definitions
enum tap_dance_custom_keys {
  TD_SEMICOLON_COLON,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SEMICOLON_COLON] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLON)
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define LAYER_BASE 0
#define LAYER_PLOVER 4
#define LAYER_NUMPAD 5
#define LAYER_MOVEMENT 6
#define LAYER_BLUESHIFT 7
#define LAYER_FKEYS 8

#define FOPT(FN,OPT) FUNC((ACTION_FUNCTION_OPT(FN, OPT) & 0xFFF))

#define ANYKEY FOPT(ANY_KEY, CURRENT_LAYER)
#define PLOVER F(PLOVER_SWITCH)
#define SHIFTED F(SHIFT_SWITCH)
#define FN_KEYS F(FKEY_SWITCH)

#define TO_BASE TO(LAYER_BASE)
#define TT_BLUE TT(LAYER_BLUESHIFT)
#define TT_NUM TT(LAYER_NUMPAD)
#define LT_MOVE LT(LAYER_MOVEMENT, KC_F21)
#define PASSWD1 M(PASSWORD1)
#define PASSWD2 M(PASSWORD2)
#define PASSWD3 M(PASSWORD3)

#define SCRNSVR LSFT(LCTL(LALT(DV_R)))

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

    #define CURRENT_LAYER LAYER_BASE
    #define ALTTAB LGUI(KC_TAB)
    [LAYER_BASE] = KEYMAP(  // customized qwerty with symbol row switched
        // left hand
        ANYKEY, SHIFTED,SHIFTED,SHIFTED,SHIFTED,SHIFTED,KC_F17,
        KC_TAB, ANYKEY, KC_W,   KC_E,   KC_R,   KC_T,   LT_MOVE,
        KC_LSFT,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_LCTL,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_DEL,
        TT_NUM, TT_BLUE,KC_LCTL,KC_LALT,KC_LGUI,
                                                PLOVER, KC_LEAD,
                                                        KC_F16,
                                       KC_BSPC,KC_LSFT,KC_LGUI,
        // right hand
                KC_F18, SHIFTED,SHIFTED,SHIFTED,SHIFTED,SHIFTED,KC_MPLY,
                TT_NUM, KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   ANYKEY,
                        KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_RSFT,
                KC_DEL, KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RCTL,
                                KC_RGUI,KC_RALT,KC_RCTL,ALTTAB, LT_MOVE,
        SCRNSVR,KC_MPLY,
        KC_F14,
        KC_ENT, TT_BLUE,KC_SPC
    ),
    #undef CURRENT_LAYER

    KEYMAP(  // transparent because this gets triggered more than I'd like
        // left hand
        _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,
                                                _______,_______,
                                                        _______,
                                        _______,_______,_______,
        // right hand
                _______,_______,_______,_______,_______,_______,_______,
                _______,_______,_______,_______,_______,_______,_______,
                        _______,_______,_______,_______,_______,_______,
                _______,_______,_______,_______,_______,_______,_______,
                                _______,_______,_______,_______,_______,
        _______,_______,
        _______,
        _______,_______,_______
    ),

    KEYMAP(  // customized dvorak
        // left hand
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_BSLS,
        KC_TAB, KC_QUOT,KC_COMM,KC_DOT, KC_P,   KC_Y,   LT_MOVE,
        KC_LSFT,KC_A,   KC_O,   KC_E,   KC_U,   KC_I,
        KC_LCTL,KC_SCLN,KC_Q,   KC_J,   KC_K,   KC_X,   KC_DEL,
        TT_NUM, TT_BLUE,KC_LCTL,KC_LALT,KC_LGUI,
                                                PLOVER, KC_HOME,
                                                        KC_END,
                                        KC_BSPC,KC_LSFT,KC_LGUI,
        // right hand
                KC_MINS,KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_EQL,
                TT_NUM, KC_F,   KC_G,   KC_C,   KC_R,   KC_L,   KC_SLSH,
                        KC_D,   KC_H,   KC_T,   KC_N,   KC_S,   KC_RSFT,
                KC_DEL, KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,   KC_RCTL,
                                KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,LT_MOVE,
        KC_PGUP,KC_MPLY,
        KC_PGDN,
        KC_ENT, TT_BLUE,KC_SPC
    ),

    KEYMAP(  // qwerty
        // left hand
        _______,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   _______,
        _______,KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   _______,
        _______,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        _______,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   _______,
        _______,_______,_______,_______,_______,
                                                _______,_______,
                                                        _______,
                                        _______,_______,_______,
        // right hand
                _______,KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,
                _______,KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_RBRC,
                        KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_RSFT,
                _______,KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,
                                _______,_______,_______,_______,_______,
        _______,_______,
        _______,
        _______,_______,_______
    ),

    // PLOVER (SPECIAL CASE)

    [LAYER_PLOVER] = KEYMAP(  // Steno for Plover
        // transparencies are for media keys

        // left hand
        PLOVER, XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,PV_NUM, PV_NUM, PV_NUM, PV_NUM, PV_NUM, XXXXXXX,
        _______,PV_LS,  PV_LT,  PV_LP,  PV_LH,  PV_STAR,
        XXXXXXX,PV_LS,  PV_LK,  PV_LW,  PV_LR,  PV_STAR,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                                                PLOVER, XXXXXXX,
                                                        XXXXXXX,
                                        PV_A,   PV_O,   XXXXXXX,
        // right hand
                XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
                XXXXXXX,PV_NUM, PV_NUM, PV_NUM, PV_NUM, PV_NUM, _______,
                        PV_STAR,PV_RF,  PV_RP,  PV_RL,  PV_RT,  PV_RD,
                XXXXXXX,PV_STAR,PV_RR,  PV_RB,  PV_RG,  PV_RS,  PV_RZ,
                                _______,_______,XXXXXXX,XXXXXXX,XXXXXXX,
        _______,_______,
        _______,
        XXXXXXX,PV_E,   PV_U
    ),

    // MODIFIERS THAT MIGHT BE STICKY

    #define CURRENT_LAYER LAYER_NUMPAD
    [LAYER_NUMPAD] = KEYMAP(  // mouse + numpad
        #define NUM_CLN LSFT(DV_SCLN)
        // left hand
        TO_BASE,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_PAUS,KC_PSCR,
        _______,XXXXXXX,KC_WH_U,KC_MS_U,KC_WH_D,KC_BTN2,_______,
        _______,XXXXXXX,KC_MS_L,KC_MS_D,KC_MS_R,KC_BTN1,
        _______,NUM_CLN,XXXXXXX,XXXXXXX,XXXXXXX,KC_BTN3,_______,
        _______,FN_KEYS,_______,_______,_______,
                                                _______,_______,
                                                        _______,
                                        _______,_______,_______,
        // right hand
                KC_SLCK,KC_NLCK,KC_EQL, KC_PSLS,KC_PAST,KC_PMNS,_______,
                _______,KC_BSPC,KC_P7,  KC_P8,  KC_P9,  KC_PMNS,KC_BSPC,
                        KC_BSPC,KC_P4,  KC_P5,  KC_P6,  KC_PMNS,KC_PENT,
                KC_BSPC,KC_BSPC,KC_P1,  KC_P2,  KC_P3,  KC_PPLS,KC_PENT,
                                KC_P0,  DV_COMM,KC_PDOT,KC_PENT,KC_PENT,
        _______,_______,
        _______,
        KC_ENT, _______,_______
    ),
    #undef CURRENT_LAYER

    [LAYER_MOVEMENT] = KEYMAP(  // F-keys + cursor
        // left hand
        TO_BASE,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
        RESET,  XXXXXXX,KC_PGUP,KC_UP,  KC_PGDN,XXXXXXX,_______,
        _______,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END,
        _______,XXXXXXX,XXXXXXX,KC_END, KC_HOME,XXXXXXX,_______,
        _______,_______,_______,PASSWD1,PASSWD2,
                                                _______,_______,
                                                        _______,
                                        KC_LCTL,KC_LSFT,_______,
        // right hand
                KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_MINS,
                _______,XXXXXXX,KC_PGUP,KC_UP,  KC_PGDN,XXXXXXX,RESET,
                        KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END, _______,
                _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
                                KC_RGUI,KC_RALT,_______,_______,_______,
        _______,_______,
        _______, _______,KC_RSFT,KC_RCTL
    ),

    #define CURRENT_LAYER LAYER_BLUESHIFT
    [LAYER_BLUESHIFT] = KEYMAP(  // "BlueShift"
        // left hand
        TO_BASE,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
        _______,SHIFTED,SHIFTED,SHIFTED,KC_PSCR,KC_BSLS,_______,  // the SHIFTED entries are for tilde and inverted brace/bracket keys
        _______,KC_APP, KC_TAB, DV_EQL, DV_MINS,KC_INS,
        _______,_______,_______,_______,KC_CAPS,_______,_______,
        FN_KEYS,_______,_______,_______,_______,
                                                _______,_______,
                                                        _______,
                                        _______,_______,_______,
        // right hand
                KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______,
                _______,KC_PGUP,KC_HOME,KC_UP,  KC_END, DV_SLSH,_______,
                        KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,DV_MINS,_______,
                _______,_______,XXXXXXX,KC_UP,  XXXXXXX,_______,_______,
                                KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,
        _______,_______,
        _______,
        _______,_______,_______
    ),
    #undef CURRENT_LAYER

    // MODIFIERS THAT WON'T BE STICKY

    [LAYER_FKEYS] = KEYMAP(  // F-keys only
        // left hand
        TO_BASE,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        _______,KC_F13, KC_F14, KC_F15, KC_F16, XXXXXXX,_______,
        _______,KC_F17, KC_F18, KC_F19, KC_F20, XXXXXXX,
        _______,KC_F21, KC_F22, KC_F23, KC_F24, XXXXXXX,_______,
        FN_KEYS,FN_KEYS,_______,KC_LALT,KC_LGUI,
                                                _______,_______,
                                                        _______,
                                        KC_LCTL,KC_LSFT,_______,
        // right hand
                XXXXXXX,XXXXXXX,KC_F10, KC_F11, KC_F12, XXXXXXX,_______,
                _______,XXXXXXX,KC_F7,  KC_F8,  KC_F9,  XXXXXXX,_______,
                        XXXXXXX,KC_F4,  KC_F5,  KC_F6,  XXXXXXX,_______,
                _______,XXXXXXX,KC_F1,  KC_F2,  KC_F3,  XXXXXXX,_______,
                                KC_RGUI,KC_RALT,KC_RCTL,_______,_______,
        _______,_______,
        _______,
        _______,KC_RSFT,KC_RCTL
    ),
};

/*
 * Fn action definition (limited to 32)
 *
 * Unused; everything is defined inline in the keymap.
 */
const uint16_t PROGMEM fn_actions[] = {
};

void action_plover_key(keyrecord_t *record) {
    if (record->event.pressed) return;

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
        action_macro_play(MACRO(
                    DOWN(PV_LP), DOWN(PV_LH), DOWN(PV_LR),
                    DOWN(PV_O), DOWN(PV_RP), DOWN(PV_RB),
                    UP(PV_LP), UP(PV_LH), UP(PV_LR),
                    UP(PV_O), UP(PV_RP), UP(PV_RB),
                    END));
    } else {
        // PHRO*F
        action_macro_play(MACRO(
                    DOWN(PV_LP), DOWN(PV_LH), DOWN(PV_LR),
                    DOWN(PV_O), DOWN(PV_STAR), DOWN(PV_RF),
                    UP(PV_LP), UP(PV_LH), UP(PV_LR),
                    UP(PV_O), UP(PV_STAR), UP(PV_RF),
                    END));
    }
}

uint16_t key_depending_on_mods(keyrecord_t *record, uint8_t default_key, uint8_t modified_key, uint8_t dependent_mods) {
    static bool mod_pressed;
    if (record->event.pressed) {
        // save mod state that will persist until the unpress
        mod_pressed = (get_mods() & dependent_mods);
    }
    return ACTION_MODS_KEY(0, mod_pressed ? modified_key : default_key);
}

uint16_t get_any_key_action(keyrecord_t *record, uint8_t layer) {
    uint8_t col = record->event.key.col;
    uint8_t row = record->event.key.row;

    switch (layer) {
        case LAYER_BASE:
            if (col == 1 && row == 1) { // apostrophe / CMD+`
                return key_depending_on_mods(record, DV_QUOT, KC_GRV, MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI));
            } else if (col == 1 && row == 13) { // media forward/back
                return key_depending_on_mods(record, KC_MEDIA_NEXT_TRACK, KC_MEDIA_PREV_TRACK, MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
            } else if (col == 0 && row == 0) { // ESC / CMD+`
                return key_depending_on_mods(record, KC_ESC, KC_GRV, MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI));
            }
            break;
        default:
            break;
    }
    if (!record->event.pressed) {
        print("Unknown anykey press:\n");
        print("col = "); pdec(col); print("\n");
        print("row = "); pdec(row); print("\n");
    }
    return ACTION_NO;
}

void action_any_key(keyrecord_t *record, uint8_t layer) {
    action_t action;
    action.code = get_any_key_action(record, layer);
    if (action.code != ACTION_NO) {
        process_action(record, action);
    }
}

uint8_t get_shiftswitch_key(keyrecord_t *record) {
    uint8_t col = record->event.key.col;
    uint8_t row = record->event.key.row;

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
            case 1: return DV_GRV;
            case 2: return DV_LBRC;
            case 3: return DV_RBRC;
        }
    }
    return KC_NO;
}

void action_shiftswitch(keyrecord_t *record) {
    if (!record->event.pressed) return; // tap these keys when they're pressed

    uint8_t keycode = get_shiftswitch_key(record);
    if (keycode == KC_NO) return;

    uint8_t savedmods = get_mods();

    action_t action;
    action.code = ACTION_MODS_KEY(savedmods ? 0 : MOD_LSFT, keycode);

    bool shift_pressed = savedmods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));

    if (shift_pressed) {
        del_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
        send_keyboard_report();
    }
    process_action(record, action);
    record->event.pressed = false;
    process_action(record, action);
    record->event.pressed = true;
    if (shift_pressed) {
        set_mods(savedmods);
        send_keyboard_report();
    }
}

bool is_out_of_order_fkey_release(keyrecord_t *record, uint32_t layer_state) {
    if (!record->event.pressed) return false;

    uint8_t row = record->event.key.row;
    return
        ((row == 0) && (layer_state & 1<<LAYER_NUMPAD)) ||
        ((row == 1) && (layer_state & 1<<LAYER_BLUESHIFT));
}

void action_fkey(keyrecord_t *record) {
    layer_invert(LAYER_FKEYS);
    if (is_out_of_order_fkey_release(record, layer_state)) {
        layer_invert(LAYER_NUMPAD);
        layer_invert(LAYER_BLUESHIFT);
    }
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case PLOVER_SWITCH:
            return action_plover_key(record);
        case ANY_KEY:
            return action_any_key(record, opt);
        case SHIFT_SWITCH:
            return action_shiftswitch(record);
        case FKEY_SWITCH:
            return action_fkey(record);
        default:
            print("Unknown action_function called\n");
            print("id  = "); phex(id); print("\n");
            print("opt = "); phex(opt); print("\n");
            break;
    }
}

const macro_t *get_macro(uint8_t id, uint8_t opt) {
    switch (id) {
        case PASSWORD1: MACRO_PASSWORD1;
        case PASSWORD2: MACRO_PASSWORD2;
        case PASSWORD3: MACRO_PASSWORD3;
    }
    return MACRO_NONE;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    if (record->event.pressed) {
        return get_macro(id, opt);
    }
    return MACRO_NONE;
}

/*
 * Hooks, used here for lighting
 */
void matrix_init_user(void)
{
    ergodox_board_led_on();
    _delay_ms(250);
    ergodox_board_led_off();
}

LEADER_EXTERNS();

void matrix_scan_user(void)
{
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    switch (layer) {
        case 0:
			// none
            break;
        default:
            ergodox_board_led_on();
            break;
    }

    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(DV_Q) {
            action_macro_play(get_macro(PASSWORD1, 0));
        }
        SEQ_ONE_KEY(DV_L) {
            action_macro_play(get_macro(PASSWORD2, 0));
        }
        SEQ_ONE_KEY(DV_K) {
            action_macro_play(get_macro(PASSWORD3, 0));
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    action_t action;
    switch (keycode) {
        case QK_FUNCTION ... QK_FUNCTION_MAX:
            // I've overloaded these to just have function IDs and opts
            // in them, like ACTION_FUNCTION. Instead of referencing into
            // fn_actions[], just call it directly.
            action.code = keycode & 0xFFF;
            action_function(record, action.func.id, action.func.opt);
            return false;
        default:
            break;
    }
    return true;
}

// vim:shiftwidth=4:cindent:expandtab:tabstop=4
