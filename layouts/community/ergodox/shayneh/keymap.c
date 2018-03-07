#include QMK_KEYBOARD_H
#include "keymap_dvorak.h"
#include "keymap_plover.h"

#include "sendstring_dvorak.h"

#ifdef SHAYNEH_MACROS_H
#include "macro.h"
#else
#include "macro_example.h"
#endif

/* id for user defined functions */
/* using the 3-bit opt field here limits this list to length 8 */
/* the id field specifies an 8-bit parameter unless otherwise specified */
enum function_id {
    FUNCTION_NULLARY, // for functions with no parameters; use id to specify
    SPECIAL_KEY,
    TOGGLE_SHIFT,
    TWO_KEY_FUNCTION_LAYER,
    SEND_MACRO,
    LAST_FUNCTION_ID // unused; this needs to be at the end for the assert below to work
};
_Static_assert(LAST_FUNCTION_ID <= 8,
    "Too many function IDs to fit in the 3-bit opt field");

/* limited to 256 */
/* keeping these together because there's lots of room, but could be split into groups */
/* e.g. nullary_functions, macro_id, special_key, ... */
enum function_parameter {
    PLOVER_SWITCH,
    // macro ids
    MACRO_Q,
    MACRO_P,
    MACRO_K,
    // special keys
    APOSTROPHE_CMD_TICK,
    ESCAPE_CMD_TICK,
    MEDIA_FORWARD_BACK,
    // placeholder
    LAST_FUNCTION_PARAM
};
_Static_assert(LAST_FUNCTION_PARAM <= 256,
    "Too many function parameters (max 256); consider breaking this enum up");

/* TMK limits this to 32 */
/* TWO_KEY_FUNCTION_LAYER and most actions only take 16 */
enum named_layer {
    LAYER_BASE = 0,
    LAYER_PLOVER = 4,
    LAYER_NUMPAD = 5,
    LAYER_MOVEMENT = 6,
    LAYER_BLUESHIFT = 7,
    LAYER_FKEYS = 8,
};

/* put 8-bit options into id field, shorter id goes in 3-bit opt */
#define FUNCTION_PARAMS(fn,param,tap) FUNC((0xFFF & ACTION_FUNCTION_OPT(param, ((tap ? FUNC_TAP : 0) | fn))))
#define FPARAM_TAP(fn,param) FUNCTION_PARAMS(fn,param,1)
#define FPARAM(fn,param) FUNCTION_PARAMS(fn,param,0)

#define FUNCTION(fn) FPARAM(FUNCTION_NULLARY, fn)
#define PLOVER FUNCTION(PLOVER_SWITCH)

#define SENDMACRO(fn) FPARAM(SEND_MACRO, fn)
#define MACROQ SENDMACRO(MACRO_Q)
#define MACROP SENDMACRO(MACRO_P)
#define MACROK SENDMACRO(MACRO_K)

#define SPECIALKEY(key) FPARAM(SPECIAL_KEY, key)
#define SP_APCD SPECIALKEY(APOSTROPHE_CMD_TICK)
#define SP_ESCD SPECIALKEY(ESCAPE_CMD_TICK)
#define SP_MDFB SPECIALKEY(MEDIA_FORWARD_BACK)

#define TOGGLE_SHIFT(key) FPARAM(TOGGLE_SHIFT,key)
#define TSFT_1 TOGGLE_SHIFT(KC_1)
#define TSFT_2 TOGGLE_SHIFT(KC_2)
#define TSFT_3 TOGGLE_SHIFT(KC_3)
#define TSFT_4 TOGGLE_SHIFT(KC_4)
#define TSFT_5 TOGGLE_SHIFT(KC_5)
#define TSFT_6 TOGGLE_SHIFT(KC_6)
#define TSFT_7 TOGGLE_SHIFT(KC_7)
#define TSFT_8 TOGGLE_SHIFT(KC_8)
#define TSFT_9 TOGGLE_SHIFT(KC_9)
#define TSFT_0 TOGGLE_SHIFT(KC_0)
#define TSFT_GR TOGGLE_SHIFT(DV_GRV)
#define TSFT_LB TOGGLE_SHIFT(DV_LBRC)
#define TSFT_RB TOGGLE_SHIFT(DV_RBRC)

#define TWO_LAYERS(inter, cumul) FPARAM_TAP(TWO_KEY_FUNCTION_LAYER, inter<<4 | cumul)
#define NUM_FN TWO_LAYERS(LAYER_NUMPAD, LAYER_FKEYS)
#define BLU_FN TWO_LAYERS(LAYER_BLUESHIFT, LAYER_FKEYS)

#define TO_BASE TO(LAYER_BASE)
#define TT_BLUE TT(LAYER_BLUESHIFT)
#define TT_NUM TT(LAYER_NUMPAD)
#define LT_MOVE LT(LAYER_MOVEMENT, KC_F21)
#define ALTTAB LGUI(KC_TAB)

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

    [LAYER_BASE] = KEYMAP(  // customized qwerty with symbol row switched
        // left hand
        SP_ESCD,TSFT_1, TSFT_2, TSFT_3, TSFT_4, TSFT_5, KC_F17,
        KC_TAB, SP_APCD,KC_W,   KC_E,   KC_R,   KC_T,   LT_MOVE,
        KC_LSFT,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_LCTL,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_DEL,
        NUM_FN, BLU_FN, KC_LCTL,KC_LALT,KC_LGUI,
                                                PLOVER, KC_LEAD,
                                                        KC_F16,
                                       KC_BSPC,KC_LSFT,KC_LGUI,
        // right hand
                KC_F18, TSFT_6, TSFT_7, TSFT_8, TSFT_9, TSFT_0, KC_MPLY,
                TT_NUM, KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   SP_MDFB,
                        KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_RSFT,
                KC_DEL, KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RCTL,
                                KC_RGUI,KC_RALT,KC_RCTL,ALTTAB, LT_MOVE,
        SCRNSVR,KC_MPLY,
        KC_F14,
        KC_ENT, TT_BLUE,KC_SPC
    ),

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
        NUM_FN, BLU_FN, KC_LCTL,KC_LALT,KC_LGUI,
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

    [LAYER_NUMPAD] = KEYMAP(  // mouse + numpad
        #define NUM_CLN LSFT(DV_SCLN)
        // left hand
        TO_BASE,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_PAUS,KC_PSCR,
        _______,XXXXXXX,KC_WH_U,KC_MS_U,KC_WH_D,KC_BTN2,_______,
        _______,XXXXXXX,KC_MS_L,KC_MS_D,KC_MS_R,KC_BTN1,
        _______,NUM_CLN,XXXXXXX,XXXXXXX,XXXXXXX,KC_BTN3,_______,
        _______,_______,_______,_______,_______,
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

    [LAYER_MOVEMENT] = KEYMAP(  // F-keys + cursor
        // left hand
        TO_BASE,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
        RESET,  XXXXXXX,KC_PGUP,KC_UP,  KC_PGDN,XXXXXXX,_______,
        _______,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END,
        _______,XXXXXXX,XXXXXXX,KC_END, KC_HOME,XXXXXXX,_______,
        _______,_______,_______,MACROQ, MACROP,
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

    [LAYER_BLUESHIFT] = KEYMAP(  // "BlueShift"
        // left hand
        TO_BASE,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
        _______,TSFT_GR,TSFT_LB,TSFT_RB,KC_PSCR,KC_BSLS,_______,
        _______,KC_APP, KC_TAB, DV_EQL, DV_MINS,KC_INS,
        _______,_______,_______,_______,KC_CAPS,_______,_______,
        _______,_______,_______,_______,_______,
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

    // MODIFIERS THAT WON'T BE STICKY

    [LAYER_FKEYS] = KEYMAP(  // F-keys only
        // left hand
        TO_BASE,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        _______,KC_F13, KC_F14, KC_F15, KC_F16, XXXXXXX,_______,
        _______,KC_F17, KC_F18, KC_F19, KC_F20, XXXXXXX,
        _______,KC_F21, KC_F22, KC_F23, KC_F24, XXXXXXX,_______,
        _______,_______,_______,KC_LALT,KC_LGUI,
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

void function_plover_key(keyrecord_t *record)
{
    if (record->event.pressed) return;
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

bool are_mods_pressed(uint8_t mods, keyrecord_t *record)
{
    // save mod state that will persist until the unpress
    static bool mods_pressed;
    if (record->event.pressed) {
        mods_pressed = (get_mods() & mods);
    }
    return mods_pressed;
}

uint16_t function_special_key_get_keycode(keyrecord_t *record, uint8_t param)
{
    switch (param) {
        case APOSTROPHE_CMD_TICK:
            return are_mods_pressed(MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI), record)
                ? KC_GRV: DV_QUOT;
        case ESCAPE_CMD_TICK:
            return are_mods_pressed(MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI), record)
                ? KC_GRV: KC_ESC;
        case MEDIA_FORWARD_BACK:
            return are_mods_pressed(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT), record)
                ? KC_MEDIA_PREV_TRACK: KC_MEDIA_NEXT_TRACK;
        default:
            break;
    }
    if (!record->event.pressed) {
        print("Unknown special key press option: "); pdec(param); print("\n");
    }
    return KC_NO;
}

void function_special_key(keyrecord_t *record, uint8_t param)
{
    action_t action;
    uint16_t keycode = function_special_key_get_keycode(record, param);
    if (keycode != KC_NO) {
        action.code = ACTION_MODS_KEY(0, keycode);
        process_action(record, action);
    }
}

void function_toggle_shift(keyrecord_t *record, uint8_t keycode)
{
    if (!record->event.pressed) return; // tap these keys only when they're pressed
    if (keycode == KC_NO) return;
    uint8_t savedmods = get_mods();
    action_t action = {.code = ACTION_MODS_KEY(savedmods ? 0 : MOD_LSFT, keycode)};
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

/* Coordinate switching to cumulative_layer with two buttons, each pointing to a different intermediate_layer */
/* Both layers must be <= 15 */
void function_two_layer_switch(keyrecord_t *record, uint8_t param)
{
    uint8_t intermediate_layer = param >> 4;
    uint8_t cumulative_layer = param & 0xF;
    static uint16_t one_active = 0; // bit at position L is on if a single layer in a pair leading to L is on
    bool was_on = IS_LAYER_ON(intermediate_layer);
    action_t action_intermediate = { .code = ACTION_LAYER_TAP_TOGGLE(intermediate_layer) };
    process_action(record, action_intermediate);
    bool transitioned = was_on != (bool) IS_LAYER_ON(intermediate_layer);
    if (transitioned) {
        uint16_t mask = 1<<cumulative_layer;
        if (!!(one_active & mask) != was_on) { // xor
            action_t action_cumulative = { .code = ACTION_LAYER_TAP_TOGGLE(cumulative_layer) };
            process_action(record, action_cumulative);
        }
        one_active ^= mask;
    }
}

void function_send_macro(keyrecord_t *record, uint8_t param)
{
    if (!record->event.pressed) return;
    switch (param) {
        case MACRO_Q: MACRO_DEF_Q;
        case MACRO_P: MACRO_DEF_P;
        case MACRO_K: MACRO_DEF_K;
        default:
            print("Unknown macro called\n");
            print("param  = "); phex(param); print("\n");
            return;
    }
}

/* override hook */
/* note that I've repurposed the opt and id fields */
void action_function(keyrecord_t *record, uint8_t param /* TMK's id */, uint8_t short_id /* TMK's opt */)
{
    short_id &= 0x7; // ignore taps
    switch (short_id) {
        case FUNCTION_NULLARY:
            switch(param) {
                case PLOVER_SWITCH: return function_plover_key(record);
                default:
                    print("Unknown nullary_function called\n");
                    print("param  = "); phex(param); print("\n");
                    return;
            }
        case SPECIAL_KEY:
            return function_special_key(record, param);
        case TOGGLE_SHIFT:
            return function_toggle_shift(record, param);
        case TWO_KEY_FUNCTION_LAYER:
            return function_two_layer_switch(record, param);
        case SEND_MACRO:
            return function_send_macro(record, param);
        default:
            print("Unknown action_function called\n");
            print("short_id  = "); phex(short_id); print("\n");
            print("param = "); phex(param); print("\n");
            return;
    }
}

/* override hook */
void matrix_init_user(void)
{
    ergodox_board_led_on();
    _delay_ms(250);
    ergodox_board_led_off();
}

LEADER_EXTERNS();

/* override hook */
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
            MACRO_DEF_Q;
        }
        SEQ_ONE_KEY(DV_L) {
            MACRO_DEF_P;
        }
        SEQ_ONE_KEY(DV_K) {
            MACRO_DEF_K;
        }
    }
}

/* override hook */
uint16_t keymap_function_id_to_action( uint16_t packed )
{
    /* instead of referring to fn_actions, compute the action directly */
    return ACTION_FUNCTION(packed);
}

// vim:shiftwidth=4:cindent:expandtab:tabstop=4
