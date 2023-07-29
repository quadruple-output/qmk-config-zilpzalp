#pragma once
#include "keycodes.h"
#include "keymap_german_mac_iso.h"
#include QMK_KEYBOARD_H
#include "zilpzalp.h"
#include "print.h"

// Utilities for defining combos:
#define LAYER_COMBO(n, layer, a, b) \
    const uint16_t PROGMEM COMBO_ ## layer ## _ ## n[] = {layer ## _ ## a, layer ## _ ## b, COMBO_END}
#define DEF_COMBO(layer, n, key_a, key_b) LAYER_COMBO(n, layer, key_a, key_b)

enum custom_keycodes {
// Macros:
    MACRO_MENU = SAFE_RANGE
};

// Layers:
enum zilpzalp_layers {
    PUQ,
    SYM,
    NAV,
    FCT
};

#define PUQ_MASK (1 << PUQ)
#define SYM_MASK (1 << SYM)
#define NAV_MASK (1 << NAV)
#define FCT_MASK (1 << FCT)

/* naming scheme for Key #defines:
       ┌────┬────┬────┐                     ┌────┬────┬────┐
       │ L7 │ L8 │ L9 ├────┐           ┌────┤ R7 │ R8 │ R9 │
       ├────┼────┼────┤ LA │           │ RA ├────┼────┼────┤
  ┌────┤ L4 │ L5 │ L6 ├────┤           ├────┤ R4 │ R5 │ R6 ├────┐
  │ LP ├────┼────┼────┤ LB │           │ RB ├────┼────┼────┤ RP │
  └────┤ L1 │ L2 │ L3 ├────┘           └────┤ R1 │ R2 │ R3 ├────┘
       └────┴────┴────┼────┬────┐ ┌────┬────┼────┴────┴────┘
                      │ LS │ LE │ │ RE │ RS │
                      └────┴────┘ └────┴────┘
Example: PUQ_LP refers to the binding for the left-hand pinky on the "PUQ" layer.
*/

/* Layer PUQ:

   Legend:
   - Capital letters indicate ordinary characters
   - Lower case letters:
       ⎈: CTRL
       ⌥: Alt
       ⌘: GUI key (CMD on Mac)
       ⇧: Shift
   - `⎄` is the compose key. Used to type German umlauts (and lots of other stuff when used with
         SHFT).

          ┌───────┬───────┬───────┐                           ┌───────┬───────┬───────┐
          │   ●┈┈ , ┈┈◐┈┈ ⌦ ┈┈○   │                           │   ●┈┈ ⌫ ┈┈◐┈┈ . ┈┈○   │
          │   M   │   L   │   C   ├───────┐           ┌───────┤   F   │   ⎄   │   U   │
          │       │       │       │       │           │       │       │       │       │
          ├───────┼───────┼───────┤   G   │           │   Q   ├───────┼───────┼───────┤
          │   ●┈┈NAV┈┈◐┈┈SYM┈┈○   │ ⌥ ⎈ ⌘ │           │ ⌥ ⎈ ⌘ │   ●┈┈SYM┈┈◐┈┈NAV┈┈○   │
          │   N   │   R   │   T   ├───────┤           ├───────┤   A   │   E   │   I   │
          │   ●┈┈┈┈┈ FCT ┈┈┈┈┈●   │       │           │       │   ●┈┈┈┈┈ FCT ┈┈┈┈┈●   │
  ┌───────┼───────┼───────┼───────┤   D   │           │   O   ├───────┼───────┼───────┼───────┐
  │       │   ●┈┈ Z ┈┈◐┈┈ J ┈┈○   │ ⎈     │           │ ⎈     │   ●┈┈ X ┈┈◐┈┈ K ┈┈○   │       │
  │   S   │   B   │   W   │   V   ├───────┘           └───────┤   _   │   P   │   Y   │   H   │
  │ ⌥     │       │       │       │                           │       │       │       │ ⌥     │
  └───────┴───────┴───────┴────┬──┴────┬───────┐ ┌───────┬────┴──┬────┴───────┴───────┴───────┘
                               │       │       │ │       │       │
                               │   ␣   │  Esc  │ │   ⏎   │   ␣   │
                               │ ⇧     │ ⌘     │ │ ⌘     │ ⇧     │
                               └───────┴───────┘ └───────┴───────┘
*/

#define PUQ_LP MT(MOD_LALT, DE_S)
#define PUQ_L1 DE_B
#define PUQ_L2 DE_W
#define PUQ_L3 DE_V
#define PUQ_L4 DE_N
#define PUQ_L5 DE_R
#define PUQ_L6 DE_T
#define PUQ_L7 DE_M
#define PUQ_L8 DE_L
#define PUQ_L9 DE_C
#define PUQ_LA MT(MOD_LCTL|MOD_LALT|MOD_LGUI, DE_G)
#define PUQ_LB MT(MOD_LCTL, DE_D)
#define PUQ_LS MT(MOD_LSFT, KC_SPACE)
#define PUQ_LE MT(MOD_LGUI, KC_ESCAPE)
#define PUQ_RP MT(MOD_LALT, DE_H)
#define PUQ_R1 DE_UNDS
#define PUQ_R2 DE_P
#define PUQ_R3 DE_Y
#define PUQ_R4 DE_A
#define PUQ_R5 DE_E
#define PUQ_R6 DE_I
#define PUQ_R7 DE_F
#define PUQ_R8 C(KC_F13) // quick-compose key. add SHIFT for full compose key
#define PUQ_R9 DE_U
#define PUQ_RA MT(MOD_LCTL|MOD_LALT|MOD_LGUI, DE_Q)
#define PUQ_RB MT(MOD_LCTL, DE_O)
#define PUQ_RS MT(MOD_LSFT, KC_SPACE)
#define PUQ_RE MT(MOD_LGUI, KC_ENTER)

DEF_COMBO(PUQ, 01, L1, L2);
#define COMBO_PUQ_01_ACTION DE_Z
DEF_COMBO(PUQ, 02, L2, L3);
#define COMBO_PUQ_02_ACTION DE_J
DEF_COMBO(PUQ, 03, L4, L5);
#define COMBO_PUQ_03_ACTION MO(NAV)
DEF_COMBO(PUQ, 04, L4, L6);
#define COMBO_PUQ_04_ACTION OSL(FCT)
DEF_COMBO(PUQ, 05, L5, L6);
#define COMBO_PUQ_05_ACTION MO(SYM)
DEF_COMBO(PUQ, 06, L7, L8);
#define COMBO_PUQ_06_ACTION DE_COMM
DEF_COMBO(PUQ, 07, L8, L9);
#define COMBO_PUQ_07_ACTION KC_DELETE
DEF_COMBO(PUQ, 08, R1, R2);
#define COMBO_PUQ_08_ACTION DE_X
DEF_COMBO(PUQ, 09, R2, R3);
#define COMBO_PUQ_09_ACTION DE_K
DEF_COMBO(PUQ, 10, R4, R5);
#define COMBO_PUQ_10_ACTION MO(SYM)
DEF_COMBO(PUQ, 11, R4, R6);
#define COMBO_PUQ_11_ACTION OSL(FCT)
DEF_COMBO(PUQ, 12, R5, R6);
#define COMBO_PUQ_12_ACTION MO(NAV)
DEF_COMBO(PUQ, 13, R7, R8);
#define COMBO_PUQ_13_ACTION KC_BACKSPACE
DEF_COMBO(PUQ, 14, R8, R9);
#define COMBO_PUQ_14_ACTION DE_DOT

const key_override_t shift_comma_is_dash = ko_make_with_layers_and_negmods(
        MOD_MASK_SHIFT,
        DE_COMM,
        DE_NDSH,
        PUQ_MASK, // only on PUQ layer
        MOD_MASK_CAG // not when combined with any other modifier
      );
const key_override_t shift_dot_is_bullet = ko_make_with_layers_and_negmods(
        MOD_MASK_SHIFT,
        DE_DOT,
        DE_BULT,
        PUQ_MASK, // only on PUQ layer
        MOD_MASK_CAG // not when combined with any other modifier
      );

/* Layer SYM:
          ┌───────┬───────┬───────┐                           ┌───────┬───────┬───────┐
          │   ○┈┈ … ┈┈◑┈┈ ⌦ ┈┈●   │                           │   ●┈┈ ⌫ ┈┈●   │       │
          │   &   │   [   │   ]   ├───────┐           ┌───────┤   <   │   >   │   =   │
          │       │       │       │       │           │       │       │       │       │
          ├───────┼───────┼───────┤   ^   │           │   !   ├───────┼───────┼───────┤
          │       │       │       │       │           │       │       │       │       │
          │   /   │   {   │   }   ├───────┤           ├───────┤   (   │   )   │   -   │
          │       │       │       │       │           │       │       │       │       │
  ┌───────┼───────┼───────┼───────┤   *   │           │   ?   ├───────┼───────┼───────┼───────┐
  │       │       │       │       │       │           │       │       │       │       │       │
  │   \   │   $   │   |   │   ~   ├───────┘           └───────┤   %   │   "   │   '   │   :   │
  │       │       │       │       │                           │       │       │       │       │
  └───────┴───────┴───────┴────┬──┴────┬───────┐ ┌───────┬────┴──┬────┴───────┴───────┴───────┘
                               │       │       │ │       │       │
                               │   #   │   `   │ │   +   │   ;   │
                               │       │       │ │       │       │
                               └───────┴───────┘ └───────┴───────┘
*/

#define SYM_LP DE_BSLS
#define SYM_L1 DE_DLR
#define SYM_L2 DE_PIPE
#define SYM_L3 DE_TILD
#define SYM_L4 DE_SLSH
#define SYM_L5 DE_LCBR
#define SYM_L6 DE_RCBR
#define SYM_L7 DE_AMPR
#define SYM_L8 DE_LBRC
#define SYM_L9 DE_RBRC
#define SYM_LA DE_CIRC
#define SYM_LB DE_ASTR
#define SYM_LS DE_HASH
#define SYM_LE DE_GRV
#define SYM_RP DE_COLN
#define SYM_R1 DE_PERC
#define SYM_R2 DE_DQUO
#define SYM_R3 DE_QUOT
#define SYM_R4 DE_LPRN
#define SYM_R5 DE_RPRN
#define SYM_R6 DE_MINS
#define SYM_R7 DE_LABK
#define SYM_R8 DE_RABK
#define SYM_R9 DE_EQL
#define SYM_RA DE_EXLM
#define SYM_RB DE_QUES
#define SYM_RS DE_SCLN
#define SYM_RE DE_PLUS

DEF_COMBO(SYM, 01, L7, L8);
#define COMBO_SYM_01_ACTION DE_ELLP
DEF_COMBO(SYM, 02, L8, L9);
#define COMBO_SYM_02_ACTION KC_DELETE
DEF_COMBO(SYM, 03, R7, R8);
#define COMBO_SYM_03_ACTION KC_BACKSPACE

/* Layer NAV:
          ┌───────┬───────┬───────┐                           ┌───────┬───────┬───────┐
          │   ○┈┈ ⌫ ┈┈◑┈┈ ⌦ ┈┈●   │                           │   ●┈┈ ⌫ ┈┈●   │       │
          │   ⇞   │   ↑   │   ⇟   ├───────┐           ┌───────┤   7   │   8   │   9   │
          │       │       │       │       │           │       │       │       │       │
          ├───────┼───────┼───────┤       │           │   *   ├───────┼───────┼───────┤
          │       │       │       │       │           │       │       │   ●┈┈ = ┈┈●   │
          │   ←   │   ↓   │   →   ├───────┤           ├───────┤   4   │   5   │   6   │
          │       │       │       │       │           │       │       │       │       │
  ┌───────┼───────┼───────┼───────┤   ↠   │           │   /   ├───────┼───────┼───────┼───────┐
  │       │       │       │       │       │           │ ⎈     │   ●┈┈ . ┈┈◐┈┈ - ┈┈○   │       │
  │   ↞   │   ⇥   │   ⎀   │   ⏎   ├───────┘           └───────┤   1   │   2   │   3   │   +   │
  │       │       │       │       │                           │       │       │       │ ⌥     │
  └───────┴───────┴───────┴────┬──┴────┬───────┐ ┌───────┬────┴──┬────┴───────┴───────┴───────┘
                               │       │       │ │       │       │
                               │   ␣   │  Esc  │ │   ⏎   │   0   │
                               │ ⇧     │ ⌘     │ │ ⌘     │ ⇧     │
                               └───────┴───────┘ └───────┴───────┘
*/

#define NAV_LP G(KC_LEFT)
#define NAV_L1 KC_TAB
#define NAV_L2 KC_INSERT
#define NAV_L3 KC_ENTER
#define NAV_L4 KC_LEFT
#define NAV_L5 KC_DOWN
#define NAV_L6 KC_RIGHT
#define NAV_L7 KC_PAGE_UP
#define NAV_L8 KC_UP
#define NAV_L9 KC_PAGE_DOWN
#define NAV_LA XXXXXXX
#define NAV_LB G(KC_RIGHT)
#define NAV_LS MT(MOD_LSFT, KC_SPACE)
#define NAV_LE MT(MOD_LGUI, KC_ESCAPE)
#define NAV_RP MT(MOD_LALT, KC_KP_PLUS)
// We don't use the keypad numbers (KC_KP_...) here, because the normal number keys are more
// universal. Some apps may have special semantics for keypad numbers, and bindings in
// DefaultKeyBindings.dict are based on the normal numbers, as well.
#define NAV_R1 KC_1
#define NAV_R2 KC_2
#define NAV_R3 KC_3
#define NAV_R4 KC_4
#define NAV_R5 KC_5
#define NAV_R6 KC_6
#define NAV_R7 KC_7
#define NAV_R8 KC_8
#define NAV_R9 KC_9
#define NAV_RA KC_KP_ASTERISK
#define NAV_RB MT(MOD_LCTL, KC_KP_SLASH)
#define NAV_RS MT(MOD_LSFT, KC_0)
#define NAV_RE MT(MOD_LGUI, KC_ENTER)

DEF_COMBO(NAV, 01, L7, L8);
#define COMBO_NAV_01_ACTION KC_BACKSPACE
DEF_COMBO(NAV, 02, L8, L9);
#define COMBO_NAV_02_ACTION KC_DELETE
DEF_COMBO(NAV, 03, R1, R2);
#define COMBO_NAV_03_ACTION KC_KP_DOT
DEF_COMBO(NAV, 04, R2, R3);
#define COMBO_NAV_04_ACTION KC_KP_MINUS
DEF_COMBO(NAV, 05, R5, R6);
#define COMBO_NAV_05_ACTION DE_EQL
DEF_COMBO(NAV, 06, R7, R8);
#define COMBO_NAV_06_ACTION KC_BACKSPACE

/* Layer FCT:
          ┌───────┬───────┬───────┐                           ┌───────┬───────┬───────┐
          │       │       │       │                           │       │       │       │
          │   F7  │   F8  │   F9  ├───────┐           ┌───────┤   🔉  │   🔇  │   🔊  │
          │       │       │       │       │           │       │       │       │       │
          ├───────┼───────┼───────┤  F10  │           │       ├───────┼───────┼───────┤
          │       │       │       │ ⌥ ⎈ ⌘ │           │ ⌥ ⎈ ⌘ │       │       │       │
          │   F4  │   F5  │   F6  ├───────┤           ├───────┤   ⏮   │   ⏯   │   ⏭   │
          │       │       │       │       │           │       │       │       │       │
  ┌───────┼───────┼───────┼───────┤  F11  │           │       ├───────┼───────┼───────┼───────┐
  │       │       │       │       │ ⎈     │           │ ⎈     │       │       │       │       │
  │  F12  │   F1  │   F2  │   F3  ├───────┘           └───────┤   🔅  │  F20  │   🔆  │   ☰   │
  │ ⌥     │       │       │       │                           │       │       │       │ ⌥     │
  └───────┴───────┴───────┴────┬──┴────┬───────┐ ┌───────┬────┴──┬────┴───────┴───────┴───────┘
                               │       │       │ │       │       │
                               │  L-🐭 │  R-🐭 │ │  L-🐭 │  R-🐭 │
                               │ ⇧     │ ⌘     │ │ ⌘     │ ⇧     │
                               └───────┴───────┘ └───────┴───────┘
*/

#define FCT_LP MT(MOD_LALT, KC_F12)
#define FCT_L1 KC_F1
#define FCT_L2 KC_F2
#define FCT_L3 KC_F3
#define FCT_L4 KC_F4
#define FCT_L5 KC_F5
#define FCT_L6 KC_F6
#define FCT_L7 KC_F7
#define FCT_L8 KC_F8
#define FCT_L9 KC_F9
#define FCT_LA MT(MOD_LCTL|MOD_LALT|MOD_LGUI, KC_F10)
#define FCT_LB MT(MOD_LCTL, KC_F11)
#define FCT_LS MT(MOD_LSFT, KC_MS_BTN1)
#define FCT_LE MT(MOD_LGUI, KC_MS_BTN2)
#define FCT_RP MT(MOD_LALT, MACRO_MENU)
#define MACRO_MENU_KEY FCT_RP
#define FCT_R1 KC_BRIGHTNESS_DOWN
#define FCT_R2 KC_F20 // mapped to `mic key` in BetterTouchTool
#define FCT_R3 KC_BRIGHTNESS_UP
#define FCT_R4 KC_MEDIA_PREV_TRACK
#define FCT_R5 KC_MEDIA_PLAY_PAUSE
#define FCT_R6 KC_MEDIA_NEXT_TRACK
#define FCT_R7 KC_AUDIO_VOL_DOWN
#define FCT_R8 KC_AUDIO_MUTE
#define FCT_R9 KC_AUDIO_VOL_UP
#define FCT_RA C(A(KC_LGUI))
#define FCT_RB KC_LCTL
#define FCT_RS MT(MOD_LSFT, KC_MS_BTN2)
#define FCT_RE MT(MOD_LGUI, KC_MS_BTN1)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Custom Key Codes (Macros):
    switch (keycode) {
        case MACRO_MENU_KEY:
            if (record->event.pressed) {
                // I have mapped double tapping the CMD key to show the context menu in BetterTouchTool.
                tap_code(KC_LGUI);
                tap_code(KC_LGUI);
                // Since not all apps seem to define a propper context menu, we try S(KC_F10) as
                // well:
                tap_code16(S(KC_F10));
            }
            break;
    }
    return true; // continue processing the keycode
}

// We want HOLD_ON_OTHER_KEY_PRESS for all combos, but not for the single-finger CTRL and ALT mod-taps:
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PUQ_LP:
        case PUQ_RP:
        case PUQ_LA:
        case PUQ_RA:
        case PUQ_LB:
        case PUQ_RB:
            return false;
        default:
            return true;
    }
}

// Key Overrides:
const key_override_t **key_overrides = (const key_override_t *[]){
    &shift_comma_is_dash,
    &shift_dot_is_bullet,
    NULL // terminator
};

// Keymaps (not much info here):
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [PUQ] = LAYOUT(
              PUQ_L7, PUQ_L8, PUQ_L9, PUQ_LA,         PUQ_RA, PUQ_R7, PUQ_R8, PUQ_R9,
      PUQ_LP, PUQ_L4, PUQ_L5, PUQ_L6, PUQ_LB,         PUQ_RB, PUQ_R4, PUQ_R5, PUQ_R6, PUQ_RP,
              PUQ_L1, PUQ_L2, PUQ_L3,                         PUQ_R1, PUQ_R2, PUQ_R3,
                                  PUQ_LS, PUQ_LE,  PUQ_RE, PUQ_RS
    ),

    [SYM] = LAYOUT(
              SYM_L7, SYM_L8, SYM_L9, SYM_LA,         SYM_RA, SYM_R7, SYM_R8, SYM_R9,
      SYM_LP, SYM_L4, SYM_L5, SYM_L6, SYM_LB,         SYM_RB, SYM_R4, SYM_R5, SYM_R6, SYM_RP,
              SYM_L1, SYM_L2, SYM_L3,                         SYM_R1, SYM_R2, SYM_R3,
                                  SYM_LS, SYM_LE,  SYM_RE, SYM_RS
    ),

    [NAV] = LAYOUT(
              NAV_L7, NAV_L8, NAV_L9, NAV_LA,         NAV_RA, NAV_R7, NAV_R8, NAV_R9,
      NAV_LP, NAV_L4, NAV_L5, NAV_L6, NAV_LB,         NAV_RB, NAV_R4, NAV_R5, NAV_R6, NAV_RP,
              NAV_L1, NAV_L2, NAV_L3,                         NAV_R1, NAV_R2, NAV_R3,
                                  NAV_LS, NAV_LE,  NAV_RE, NAV_RS
    ),

    [FCT] = LAYOUT(
              FCT_L7, FCT_L8, FCT_L9, FCT_LA,         FCT_RA, FCT_R7, FCT_R8, FCT_R9,
      FCT_LP, FCT_L4, FCT_L5, FCT_L6, FCT_LB,         FCT_RB, FCT_R4, FCT_R5, FCT_R6, FCT_RP,
              FCT_L1, FCT_L2, FCT_L3,                         FCT_R1, FCT_R2, FCT_R3,
                                  FCT_LS, FCT_LE,  FCT_RE, FCT_RS
    )
};

// Combos:
combo_t key_combos[] = {
    COMBO(COMBO_PUQ_01, COMBO_PUQ_01_ACTION),
    COMBO(COMBO_PUQ_02, COMBO_PUQ_02_ACTION),
    COMBO(COMBO_PUQ_03, COMBO_PUQ_03_ACTION),
    COMBO(COMBO_PUQ_04, COMBO_PUQ_04_ACTION),
    COMBO(COMBO_PUQ_05, COMBO_PUQ_05_ACTION),
    COMBO(COMBO_PUQ_06, COMBO_PUQ_06_ACTION),
    COMBO(COMBO_PUQ_07, COMBO_PUQ_07_ACTION),
    COMBO(COMBO_PUQ_08, COMBO_PUQ_08_ACTION),
    COMBO(COMBO_PUQ_09, COMBO_PUQ_09_ACTION),
    COMBO(COMBO_PUQ_10, COMBO_PUQ_10_ACTION),
    COMBO(COMBO_PUQ_11, COMBO_PUQ_11_ACTION),
    COMBO(COMBO_PUQ_12, COMBO_PUQ_12_ACTION),
    COMBO(COMBO_PUQ_13, COMBO_PUQ_13_ACTION),
    COMBO(COMBO_PUQ_14, COMBO_PUQ_14_ACTION),

    COMBO(COMBO_SYM_01, COMBO_SYM_01_ACTION),
    COMBO(COMBO_SYM_02, COMBO_SYM_02_ACTION),
    COMBO(COMBO_SYM_03, COMBO_SYM_03_ACTION),

    COMBO(COMBO_NAV_01, COMBO_NAV_01_ACTION),
    COMBO(COMBO_NAV_02, COMBO_NAV_02_ACTION),
    COMBO(COMBO_NAV_03, COMBO_NAV_03_ACTION),
    COMBO(COMBO_NAV_04, COMBO_NAV_04_ACTION),
    COMBO(COMBO_NAV_05, COMBO_NAV_05_ACTION),
    COMBO(COMBO_NAV_06, COMBO_NAV_06_ACTION),
};

