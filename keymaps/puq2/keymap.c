#include QMK_KEYBOARD_H
#include "zilpzalp.h"
#include "print.h"

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

typedef enum {
    KBLOCK_UNDEF,
    KBLOCK_LEFT,
    KBLOCK_RIGHT,
} kb_block_t;

typedef struct {
    bool active_left_before;
    bool active_left;
    bool active_right_before;
    bool active_right;
    kb_block_t last_change;
} block_activity_t;

static block_activity_t block_activity;

void matrix_init_user(void) {
    block_activity.active_left_before = false;
    block_activity.active_left = false;
    block_activity.active_right_before = false;
    block_activity.active_right = false;
    block_activity.last_change = KBLOCK_UNDEF;
}

void matrix_scan_user(void) {
    // see zilpzalp.h for matrix layout
    block_activity.active_left  = (matrix_get_row(0) | matrix_get_row(1) | matrix_get_row(2)) != 0;
    block_activity.active_right = (matrix_get_row(4) | matrix_get_row(5) | matrix_get_row(6)) != 0;
    if (block_activity.active_left && block_activity.active_left != block_activity.active_left_before) {
        if (block_activity.last_change != KBLOCK_LEFT) {
            print("[l]\n");
            block_activity.last_change = KBLOCK_LEFT;
        };
    } else if (block_activity.active_right && block_activity.active_right != block_activity.active_right_before) {
        if (block_activity.last_change != KBLOCK_RIGHT) {
            print("[r]\n");
            block_activity.last_change = KBLOCK_RIGHT;
        };
    } else if (!block_activity.active_left && !block_activity.active_right) {
        if (block_activity.last_change != KBLOCK_UNDEF) {
            print("[u]\n");
            block_activity.last_change = KBLOCK_UNDEF;
        }
    }
    block_activity.active_left_before = block_activity.active_left;
    block_activity.active_right_before = block_activity.active_right;
}

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

enum custom_keycodes {
    MY_MENU = SAFE_RANGE
};

// This layout assumes that the OS layout is set to "German (no dead keys)"
// We define `DE`-versions for symbols that do not match their US keyboard positions.
// An underscore at the end of the symbol name indicates that it includes a modifier (preventing its
// use in some QMK functions like LT or MT).
#define DE_CARET          KC_GRAVE           // ^
#define DE_EXCLAMATION_   S(KC_1)            // !
#define DE_DOUBLE_QUOTE_  S(KC_2)            // "
#define DE_DOLLAR_        S(KC_4)            // $
#define DE_PERCENT_       S(KC_5)            // %
#define DE_LEFT_BRACKET_  A(KC_5)            // %
#define DE_AMPERSAND_     S(KC_6)            // &
#define DE_RIGHT_BRACKET_ A(KC_6)            // &
#define DE_SLASH_         S(KC_7)            // /
#define DE_PIPE_          A(KC_7)            // |
#define DE_BACKSLASH_     S(A(KC_7))         // |
#define DE_LEFT_PAREN_    S(KC_8)            // (
#define DE_LEFT_BRACE_    A(KC_8)            // {
#define DE_RIGHT_PAREN_   S(KC_9)            // )
#define DE_RIGHT_BRACE_   A(KC_9)            // }
#define DE_EQUAL_         S(KC_0)            // =
#define DE_SZLIG          KC_MINUS           // ß
#define DE_QUESTION_      S(DE_SZLIG)        // ?
#define DE_ACUTE          KC_EQUAL           // ´
#define DE_BACKQUOTE_     S(DE_ACUTE)        // `
#define DE_Q              KC_Q               // q
#define DE_W              KC_W               // w
#define DE_E              KC_E               // e
#define DE_R              KC_R               // r
#define DE_T              KC_T               // t
#define DE_Z              KC_Y               // z
#define DE_U              KC_U               // u
#define DE_I              KC_I               // i
#define DE_O              KC_O               // o
#define DE_P              KC_P               // p
#define DE_UUML           KC_LEFT_BRACKET    // ü
#define DE_BULLET_        A(DE_UUML)         // •
#define DE_PLUS           KC_RIGHT_BRACKET   // +
#define DE_ASTERISK_      S(DE_PLUS)         // *
#define DE_A              KC_A               // a
#define DE_S              KC_S               // s
#define DE_D              KC_D               // d
#define DE_F              KC_F               // f
#define DE_G              KC_G               // g
#define DE_H              KC_H               // h
#define DE_J              KC_J               // j
#define DE_K              KC_K               // k
#define DE_L              KC_L               // l
#define DE_AT_            A(DE_L)            // @
#define DE_OUML           KC_SEMICOLON       // ö
#define DE_AUML           KC_QUOTE           // ä
#define DE_HASH           KC_BACKSLASH       // #
#define DE_QUOTE_         S(DE_HASH)         // '
#define DE_LESS_THAN      KC_NONUS_BACKSLASH // <
#define DE_GREATER_THAN_  S(DE_LESS_THAN)    // >
#define DE_Y              KC_Z               // y
#define DE_X              KC_X               // x
#define DE_C              KC_C               // c
#define DE_V              KC_V               // v
#define DE_B              KC_B               // b
#define DE_N              KC_N               // n
#define DE_TILDE_         A(DE_N)            // ~
#define DE_M              KC_M               // m
#define DE_COMMA          KC_COMMA           // ,
#define DE_SEMICOLON_     S(DE_COMMA)        // ;
#define DE_DOT            KC_DOT             // .
#define DE_COLON_         S(DE_DOT)          // :
#define DE_ELLIPSIS_      A(DE_DOT)          // …
#define DE_MINUS          KC_SLASH           // -
#define DE_UNDERSCORE_    S(DE_MINUS)        // _
#define DE_DASH_          A(DE_MINUS)        // –

enum tapdances {
    // Layer-Tabs or Mod-Tabs that require key codes with modifers:
    TD_LT_NAV_SLASH,
    TD_MT_GUI_LEFT_BRACE,
    TD_MT_ALT_RIGHT_BRACE,
    TD_MT_CTL_PIPE,
    TD_MT_ALT_LEFT_PAREN,
    TD_MT_GUI_RIGHT_PAREN,
    TD_MT_CTL_DOUBLE_QUOTE,
    // higher F-Keys:
    TD_F01_F11,
    TD_F02_F12,
    TD_F03_F13,
    TD_F04_F14,
    TD_F05_F15,
    TD_F06_F16,
    TD_F07_F17,
    TD_F08_F18,
    TD_F09_F19,
    // On a Mac, function keys above F20 are ignored.
};

/*
 *  Tap-Dance functions.
 *
 *  These functions are required because MT and LT do not support key codes with modifiers.
 *  See https://docs.qmk.fm/#/feature_tap_dance?id=example-5
 */

// Define a type containing as many tapdance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
} td_state_t;

// Create a global instance of the tapdance state type
// (I use a single instance for all tap-dances, although I am no sure if this is correct in all
// possible situations.)
static td_state_t td_state;

// Function to determine the current tapdance state
td_state_t cur_dance(tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void neo4_slash_finished(tap_dance_state_t *state, void *user_data);
void neo4_slash_reset(tap_dance_state_t *state, void *user_data);
void gui_left_brace_finished(tap_dance_state_t *state, void *user_data);
void gui_left_brace_reset(tap_dance_state_t *state, void *user_data);
void alt_right_brace_finished(tap_dance_state_t *state, void *user_data);
void alt_right_brace_reset(tap_dance_state_t *state, void *user_data);
void ctl_pipe_finished(tap_dance_state_t *state, void *user_data);
void ctl_pipe_reset(tap_dance_state_t *state, void *user_data);
void alt_left_paren_finished(tap_dance_state_t *state, void *user_data);
void alt_left_paren_reset(tap_dance_state_t *state, void *user_data);
void gui_right_paren_finished(tap_dance_state_t *state, void *user_data);
void gui_right_paren_reset(tap_dance_state_t *state, void *user_data);
void ctl_double_quote_finished(tap_dance_state_t *state, void *user_data);
void ctl_double_quote_reset(tap_dance_state_t *state, void *user_data);

tap_dance_action_t tap_dance_actions[] = {
    [TD_LT_NAV_SLASH]        = ACTION_TAP_DANCE_FN_ADVANCED(NULL, neo4_slash_finished, neo4_slash_reset),
    [TD_MT_GUI_LEFT_BRACE]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, gui_left_brace_finished, gui_left_brace_reset),
    [TD_MT_ALT_RIGHT_BRACE]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_right_brace_finished, alt_right_brace_reset),
    [TD_MT_CTL_PIPE]          = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctl_pipe_finished, ctl_pipe_reset),
    [TD_MT_ALT_LEFT_PAREN]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_left_paren_finished, alt_left_paren_reset),
    [TD_MT_GUI_RIGHT_PAREN]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, gui_right_paren_finished, gui_right_paren_reset),
    [TD_MT_CTL_DOUBLE_QUOTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctl_double_quote_finished, ctl_double_quote_reset),
    [TD_F01_F11] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F11),
    [TD_F02_F12] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F12),
    [TD_F03_F13] = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_F13),
    [TD_F04_F14] = ACTION_TAP_DANCE_DOUBLE(KC_F4, KC_F14),
    [TD_F05_F15] = ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_F15),
    [TD_F06_F16] = ACTION_TAP_DANCE_DOUBLE(KC_F6, KC_F16),
    [TD_F07_F17] = ACTION_TAP_DANCE_DOUBLE(KC_F7, KC_F17),
    [TD_F08_F18] = ACTION_TAP_DANCE_DOUBLE(KC_F8, KC_F18),
    [TD_F09_F19] = ACTION_TAP_DANCE_DOUBLE(KC_F9, KC_F19),
};

/* naming scheme for #defines:
       ┌────┬────┬────┐                     ┌────┬────┬────┐
       │ L7 │ L8 │ L9 ├────┐           ┌────┤ R7 │ R8 │ R9 │
       ├────┼────┼────┤ LA │           │ RA ├────┼────┼────┤
  ┌────┤ L4 │ L5 │ L6 ├────┤           ├────┤ R4 │ R5 │ R6 ├────┐
  │ LP ├────┼────┼────┤ LB │           │ RB ├────┼────┼────┤ RP │
  └────┤ L1 │ L2 │ L3 ├────┘           └────┤ R1 │ R2 │ R3 ├────┘
       └────┴────┴────┼────┬────┐ ┌────┬────┼────┴────┴────┘
                      │ LS │ LE │ │ RE │ RS │
                      └────┴────┘ └────┴────┘
*/

/* Layer PUQ:

   Legend:
   - Capital letters indicate ordinary characters
   - Lower case letters and numbers:
       c: CTRL
       a: Alt
       g: GUI key (CMD on Mac)
       s: Shift
       t: indicates a tap dance function
       3: Layer SYM
       4: Layer NAV
       f: Layer FCT
   - `*` indicates that a key override exists
   - `⎄` is the compose key. Used to type German umlauts (and lots of other stuff when used with
         SHFT).

   OTHER version ("PUQ"):
         ┌──────┬──────┬──────┐                         ┌──────┬──────┬──────┐
         │      │      │      │                         │      │      │      │
         │   M  │   L  │   C  ├──────┐           ┌──────┤  ,*  │   ⎄  │   U  │
         │      │      │      │      │           │      │      │      │      │
         ├── F ─┼──────┼── P ─┤ cg G │           │ cg Q ├─ F ──┼──────┼── P ─┤
         │      │      │      │      │           │      │      │      │      │
         │4  N  │ g R  │ a T  ├──────┤           ├──────┤a A   │ g E  │ 4 I  │
         │      │      │      │      │           │      │      │      │      │
  ┌──────┼── Z ─┼──────┼── J ─┤cag D │           │cag O ├─ X ──┼──────┼── K ─┼──────┐
  │      │      │      │      │      │           │      │      │      │      │      │
  │ 3 S  │   B  │ c W  │   V  ├──────┘           └──────┤  _   │ c .* │   Y  │ 3 H  │
  │      │      │      │      │                         │      │      │      │      │
  └──────┴──────┴──────┴────┬─┴────┬──────┐ ┌──────┬────┴─┬────┴──────┴──────┴──────┘
                            │      │      │ │      │      │
                            │s SPC │f ESC │ │f ENT │s SPC │
                            │      │      │ │      │      │
                            └──────┴──────┘ └──────┴──────┘

   THIS version ("PUQ2"): 
          ┌───────┬───────┬───────┐                           ┌───────┬───────┬───────┐
          │   ●┈┈┈,┈┈┈◐┈┈┈⌦┈┈┈○   │                           │   ●┈┈┈⌫┈┈┈◐┈┈┈.┈┈┈○   │
          │   M   │   L   │   C   ├───────┐           ┌───────┤   F   │   ⎄   │   U   │
          │       │       │       │       │           │       │       │       │       │
          ├───────┼───────┼───────┤   G   │           │   Q   ├───────┼───────┼───────┤
          │   ●┈┈NAV┈┈◐┈┈SYM┈┈○   │ cag   │           │ cag   │   ●┈┈SYM┈┈◐┈┈NAV┈┈○   │
          │   N   │   R   │   T   ├───────┤           ├───────┤   A   │   E   │   I   │
          │   ●┈┈┈┈┈┈FCT┈┈┈┈┈┈●   │       │           │       │   ●┈┈┈┈┈┈FCT┈┈┈┈┈┈●   │
  ┌───────┼───────┼───────┼───────┤   D   │           │   O   ├───────┼───────┼───────┼───────┐
  │       │   ●┈┈┈Z┈┈┈◐┈┈┈J┈┈┈○   │ c     │           │ c     │   ●┈┈┈X┈┈┈◐┈┈┈K┈┈┈○   │       │
  │   S   │   B   │   W   │   V   ├───────┘           └───────┤   _   │   P   │   Y   │   H   │
  │ a     │       │       │       │                           │       │       │       │ a     │
  └───────┴───────┴───────┴────┬──┴────┬───────┐ ┌───────┬────┴──┬────┴───────┴───────┴───────┘
                               │       │       │ │       │       │
                               │  SPC  │  ESC  │ │  ENT  │  SPC  │
                               │ s     │ g     │ │ g     │ s     │
                               └───────┴───────┘ └───────┴───────┘
*/

#define PUQ_LP LT(SYM, DE_S)
#define PUQ_L1 DE_B
#define PUQ_L2 MT(MOD_LCTL, DE_W)
#define PUQ_L3 DE_V
#define PUQ_L4 LT(NAV, DE_N)
#define PUQ_L5 MT(MOD_LGUI, DE_R)
#define PUQ_L6 MT(MOD_LALT, DE_T)
#define PUQ_L7 DE_M
#define PUQ_L8 DE_L
#define PUQ_L9 DE_C
#define PUQ_LA MT(MOD_LCTL|MOD_LGUI, DE_G)
#define PUQ_LB MT(MOD_LCTL|MOD_LALT|MOD_LGUI, DE_D)
#define PUQ_LS MT(MOD_LSFT, KC_SPACE)
#define PUQ_LE LT(FCT, KC_ESCAPE)
#define PUQ_RP LT(SYM, DE_H)
#define PUQ_R1 DE_UNDERSCORE_
#define PUQ_R2 MT(MOD_LCTL, DE_DOT)
#define PUQ_R3 DE_Y
#define PUQ_R4 MT(MOD_LALT, DE_A)
#define PUQ_R5 MT(MOD_LGUI, DE_E)
#define PUQ_R6 LT(NAV, DE_I)
#define PUQ_R7 DE_COMMA
#define PUQ_R8 C(KC_F13) // quick-compose key. add SHIFT for full compose key
#define PUQ_R9 DE_U
#define PUQ_RA MT(MOD_LCTL|MOD_LGUI, DE_Q)
#define PUQ_RB MT(MOD_LCTL|MOD_LALT|MOD_LGUI, DE_O)
#define PUQ_RS MT(MOD_LSFT, KC_SPACE)
#define PUQ_RE LT(FCT, KC_ENTER)

/* Layer SYM:
          ┌───────┬───────┬───────┐                           ┌───────┬───────┬───────┐
          │       │   ●┈┈┈⌦┈┈┈●   │                           │   ●┈┈┈⌫┈┈┈◐┈┈┈&┈┈┈○   │
          │   …   │   [   │   ]   ├───────┐           ┌───────┤   <   │   >   │   =   │
          │       │       │       │       │           │       │       │       │       │
          ├───────┼───────┼───────┤   ^   │           │   !   ├───────┼───────┼───────┤
          │   ●┈┈NAV┈┈●   │       │       │           │       │       │   ●┈┈NAV┈┈●   │
          │   /   │   {   │   }   ├───────┤           ├───────┤   (   │   )   │   -   │
          │       │       │       │       │           │       │       │       │       │
  ┌───────┼───────┼───────┼───────┤   *   │           │   ?   ├───────┼───────┼───────┼───────┐
  │       │   ●┈┈┈#┈┈┈◐┈┈┈`┈┈┈○   │       │           │       │   ●┈┈┈+┈┈┈◐┈┈┈;┈┈┈○   │       │
  │   \   │   $   │   |   │   ~   ├───────┘           └───────┤   %   │   "   │   '   │   :   │
  │       │       │       │       │                           │       │       │       │       │
  └───────┴───────┴───────┴────┬──┴────┬───────┐ ┌───────┬────┴──┬────┴───────┴───────┴───────┘
                               │       │       │ │       │       │
                               │  SPC  │  ESC  │ │  ENT  │  SPC  │
                               │       │       │ │       │       │
                               └───────┴───────┘ └───────┴───────┘
*/

#define SYM_LP DE_BACKSLASH_
#define SYM_L1 DE_DOLLAR_
// #define SYM_L2 MT(MOD_LCTL, DE_PIPE_) <- does not work: DE_PIPE_ is shifted (not supported by LT)
#define SYM_L2 DE_PIPE_
// #define SYM_L2 TD(TD_MT_CTL_PIPE)
#define SYM_L3 DE_TILDE_
// #define SYM_L4 LT(NAV, DE_SLASH_) <- does not work
#define SYM_L4 DE_SLASH_
// #define SYM_L4 TD(TD_LT_NAV_SLASH)
// #define SYM_L5 MT(MOD_LGUI, DE_LEFT_BRACE_) <- does not work
#define SYM_L5 DE_LEFT_BRACE_
// #define SYM_L5 TD(TD_MT_GUI_LEFT_BRACE)
//#define SYM_L6 MT(MOD_LALT, DE_RIGHT_BRACE_) <- does not work
#define SYM_L6 DE_RIGHT_BRACE_
// #define SYM_L6 TD(TD_MT_ALT_RIGHT_BRACE)
#define SYM_L7 DE_ELLIPSIS_
#define SYM_L8 DE_LEFT_BRACKET_
#define SYM_L9 DE_RIGHT_BRACKET_
#define SYM_LA DE_CARET
#define SYM_LB DE_ASTERISK_
#define SYM_LS KC_SPACE
#define SYM_LE KC_ESCAPE
#define SYM_RP DE_COLON_
#define SYM_R1 DE_PERCENT_
// #define SYM_R2 MT(MOD_LCTL, DE_DOUBLE_QUOTE_) <- does not work
#define SYM_R2 DE_DOUBLE_QUOTE_
// #define SYM_R2 TD(TD_MT_CTL_DOUBLE_QUOTE)
#define SYM_R3 DE_QUOTE_
// #define SYM_R4 MT(MOD_LALT, DE_LEFT_PAREN_) <- does not work
#define SYM_R4 DE_LEFT_PAREN_
// #define SYM_R4 TD(TD_MT_ALT_LEFT_PAREN)
// #define SYM_R5 MT(MOD_LGUI, DE_RIGHT_PAREN_) <- does not work
#define SYM_R5 DE_RIGHT_PAREN_
// #define SYM_R5 TD(TD_MT_GUI_RIGHT_PAREN)
#define SYM_R6 LT(NAV, DE_MINUS)
#define SYM_R7 DE_LESS_THAN
#define SYM_R8 DE_GREATER_THAN_
#define SYM_R9 DE_EQUAL_
#define SYM_RA DE_EXCLAMATION_
#define SYM_RB DE_QUESTION_
#define SYM_RS KC_SPACE
#define SYM_RE KC_ENTER

/* Layer NAV:
          ┌───────┬───────┬───────┐                           ┌───────┬───────┬───────┐
          │   ●┈┈┈⇞┈┈┈●   │       │                           │       │       │       │
          │   ⌫   │   ↑   │   ⌦   ├───────┐           ┌───────┤   7   │   8   │   9   │
          │       │       │       │       │           │       │       │       │       │
          ├───────┼───────┼───────┤   ⇟   │           │   *   ├───────┼───────┼───────┤
          │       │       │       │       │           │       │       │       │       │
          │   ←   │   ↓   │   →   ├───────┤           ├───────┤   4   │   5   │   6   │
          │       │       │       │       │           │       │       │       │       │
  ┌───────┼───────┼───────┼───────┤   ↠   │           │   /   ├───────┼───────┼───────┼───────┐
  │       │       │       │       │       │           │ c     │   ●┈┈ . ┈┈◐┈┈ - ┈┈○   │       │
  │   ↞   │   ⇥   │   ⎀   │   ⏎   ├───────┘           └───────┤   1   │   2   │   3   │   +   │
  │       │       │       │       │                           │       │       │       │ a     │
  └───────┴───────┴───────┴────┬──┴────┬───────┐ ┌───────┬────┴──┬────┴───────┴───────┴───────┘
                               │       │       │ │       │       │
                               │  SPC  │  ESC  │ │  ENT  │  SPC  │
                               │ s     │ g     │ │ g     │ s     │
                               └───────┴───────┘ └───────┴───────┘
*/

#define NAV_LP G(KC_LEFT)
#define NAV_L1 KC_TAB
#define NAV_L2 MT(MOD_LCTL, KC_INSERT)
#define NAV_L3 KC_ENTER
#define NAV_L4 KC_LEFT
#define NAV_L5 MT(MOD_LGUI, KC_DOWN)
#define NAV_L6 MT(MOD_LALT, KC_RIGHT)
#define NAV_L7 KC_BACKSPACE
#define NAV_L8 KC_UP
#define NAV_L9 KC_DELETE
#define NAV_LA KC_PAGE_DOWN
#define NAV_LB G(KC_RIGHT)
#define NAV_LS MT(MOD_LSFT, KC_SPACE)
#define NAV_LE KC_ESCAPE
#define NAV_RP KC_KP_PLUS
#define NAV_R1 KC_KP_1
#define NAV_R2 MT(MOD_LCTL, KC_KP_2)
#define NAV_R3 KC_KP_3
#define NAV_R4 MT(MOD_LALT, KC_KP_4)
#define NAV_R5 MT(MOD_LGUI, KC_KP_5)
#define NAV_R6 KC_KP_6
#define NAV_R7 KC_KP_7
#define NAV_R8 KC_KP_8
#define NAV_R9 KC_KP_9
#define NAV_RA KC_KP_ASTERISK
#define NAV_RB KC_KP_SLASH
#define NAV_RS MT(MOD_LSFT, KC_KP_0)
#define NAV_RE KC_ENTER

/* Layer FCT:
          ┌───────┬───────┬───────┐                           ┌───────┬───────┬───────┐
          │       │       │       │                           │       │       │       │
          │   F7  │   F8  │   F9  ├───────┐           ┌───────┤   🔉  │   🔇  │   🔊  │
          │       │       │       │       │           │       │       │       │       │
          ├───────┼───────┼───────┤  F10  │           │       ├───────┼───────┼───────┤
          │       │       │       │       │           │       │       │       │       │
          │   F4  │   F5  │   F6  ├───────┤           ├───────┤   ⏮   │   ⏯   │   ⏭   │
          │       │       │       │       │           │       │       │       │       │
  ┌───────┼───────┼───────┼───────┤  F11  │           │       ├───────┼───────┼───────┼───────┐
  │       │       │       │       │ c     │           │ c     │       │       │       │       │
  │  F12  │   F1  │   F2  │   F3  ├───────┘           └───────┤   🔅  │  F20  │   🔆  │   ☰   │
  │ a     │       │       │       │                           │       │       │       │ a     │
  └───────┴───────┴───────┴────┬──┴────┬───────┐ ┌───────┬────┴──┬────┴───────┴───────┴───────┘
                               │       │       │ │       │       │
                               │  LMB  │  RMB  │ │  LMB  │  RMB  │
                               │ s     │ g     │ │ g     │ s     │
                               └───────┴───────┘ └───────┴───────┘
*/

#define FCT_LP KC_F12
#define FCT_L1 TD(TD_F01_F11)
#define FCT_L2 TD(TD_F02_F12)
#define FCT_L3 TD(TD_F03_F13)
#define FCT_L4 TD(TD_F04_F14)
#define FCT_L5 TD(TD_F05_F15)
#define FCT_L6 TD(TD_F06_F16)
#define FCT_L7 TD(TD_F07_F17)
#define FCT_L8 TD(TD_F08_F18)
#define FCT_L9 TD(TD_F09_F19)
#define FCT_LA KC_F10
#define FCT_LB KC_F11
#define FCT_LS KC_MS_BTN1
#define FCT_LE KC_MS_BTN2
#define FCT_RP MY_MENU
#define FCT_R1 KC_BRIGHTNESS_UP
#define FCT_R2 MT(MOD_LCTL, KC_F20) // mapped to `mic key` in BetterTouchTool
#define FCT_R3 KC_BRIGHTNESS_DOWN
#define FCT_R4 MT(MOD_LALT, KC_MEDIA_PREV_TRACK)
#define FCT_R5 MT(MOD_LGUI, KC_MEDIA_PLAY_PAUSE)
#define FCT_R6 KC_MEDIA_NEXT_TRACK
#define FCT_R7 KC_AUDIO_VOL_DOWN
#define FCT_R8 KC_AUDIO_MUTE
#define FCT_R9 KC_AUDIO_VOL_UP
#define FCT_RA XXXXXXX
#define FCT_RB XXXXXXX
#define FCT_RS KC_MS_BTN2
#define FCT_RE KC_MS_BTN1

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Custom Key Codes (Macros):
    switch (keycode) {
        case MY_MENU:
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

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return true; // Immediately select the hold action when another key is tapped.
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    bool result = false;
    print("get_hold_on_other_key_press. ");
    switch (keycode) {
        // Immediately select the hold action when a key from the opposite block is pressed
        case PUQ_LP:
            if (block_activity.last_change == KBLOCK_RIGHT) {
                print("right block activated -> hold");
                result = true;
            }
        case PUQ_RP:
            if (block_activity.last_change == KBLOCK_LEFT) {
                print("left block activated -> hold");
                result = true;
            }
    }
    print("\n");
    return result;
}

// Combos:
const uint16_t PROGMEM puq_l1_l4[] = {PUQ_L1, PUQ_L4, COMBO_END};
const uint16_t PROGMEM puq_l3_l6[] = {PUQ_L3, PUQ_L6, COMBO_END};
const uint16_t PROGMEM puq_l4_l5[] = {PUQ_L4, PUQ_L5, COMBO_END};
const uint16_t PROGMEM puq_l4_l6[] = {PUQ_L5, PUQ_L6, COMBO_END};
const uint16_t PROGMEM puq_l4_l7[] = {PUQ_L4, PUQ_L7, COMBO_END};
const uint16_t PROGMEM puq_l6_l9[] = {PUQ_L6, PUQ_L9, COMBO_END};
const uint16_t PROGMEM puq_r1_r4[] = {PUQ_R1, PUQ_R4, COMBO_END};
const uint16_t PROGMEM puq_r1_r2[] = {PUQ_R1, PUQ_R2, COMBO_END};
const uint16_t PROGMEM puq_r2_r3[] = {PUQ_R2, PUQ_R3, COMBO_END};
const uint16_t PROGMEM puq_r3_r6[] = {PUQ_R3, PUQ_R6, COMBO_END};
const uint16_t PROGMEM puq_r4_r5[] = {PUQ_R4, PUQ_R5, COMBO_END};
const uint16_t PROGMEM puq_r4_r6[] = {PUQ_R4, PUQ_R6, COMBO_END};
const uint16_t PROGMEM puq_r4_r7[] = {PUQ_R4, PUQ_R7, COMBO_END};
const uint16_t PROGMEM puq_r5_r6[] = {PUQ_R5, PUQ_R6, COMBO_END};
const uint16_t PROGMEM puq_r6_r9[] = {PUQ_R6, PUQ_R9, COMBO_END};

const uint16_t PROGMEM neo3_l1_l4[] = {SYM_L1, SYM_L4, COMBO_END};
const uint16_t PROGMEM neo3_l3_l6[] = {SYM_L3, SYM_L6, COMBO_END};
const uint16_t PROGMEM neo3_r1_r4[] = {SYM_R1, SYM_R4, COMBO_END};
const uint16_t PROGMEM neo3_r1_r2[] = {SYM_R1, SYM_R2, COMBO_END};
const uint16_t PROGMEM neo3_r2_r3[] = {SYM_R2, SYM_R3, COMBO_END};
const uint16_t PROGMEM neo3_r3_r6[] = {SYM_R3, SYM_R6, COMBO_END};
const uint16_t PROGMEM neo3_r6_r9[] = {SYM_R6, SYM_R9, COMBO_END};

const uint16_t PROGMEM neo4_l4_l7[] = {NAV_L4, NAV_L7, COMBO_END};
const uint16_t PROGMEM neo4_r1_r2[] = {NAV_R1, NAV_R2, COMBO_END};
const uint16_t PROGMEM neo4_r2_r3[] = {NAV_R2, NAV_R3, COMBO_END};

combo_t key_combos[] = {
    COMBO(puq_l1_l4, DE_Z),
    COMBO(puq_l3_l6, DE_J),
    COMBO(puq_l4_l5, MO(SYM)),
    COMBO(puq_l4_l6, MO(NAV)),
    COMBO(puq_l4_l7, DE_F),
    COMBO(puq_l6_l9, DE_P),
    COMBO(puq_r1_r4, DE_X),
    COMBO(puq_r3_r6, DE_K),
    COMBO(puq_r4_r6, MO(NAV)),
    COMBO(puq_r4_r7, DE_F),
    COMBO(puq_r5_r6, MO(SYM)),
    COMBO(puq_r6_r9, DE_P),

    COMBO(neo3_l1_l4, DE_HASH),
    COMBO(neo3_l3_l6, DE_BACKQUOTE_),
    COMBO(neo3_r1_r4, DE_PLUS),
    COMBO(neo3_r3_r6, DE_SEMICOLON_),
    COMBO(neo3_r6_r9, DE_AMPERSAND_),

    COMBO(neo4_l4_l7, KC_PAGE_UP),

    // BACKSPACE & DELETE on (almost) all layers:
    COMBO(puq_r1_r2, KC_BACKSPACE),
    COMBO(puq_r2_r3, KC_DELETE),
    COMBO(neo3_r1_r2, KC_BACKSPACE),
    COMBO(neo3_r2_r3, KC_DELETE),
    COMBO(neo4_r1_r2, KC_BACKSPACE),
    COMBO(neo4_r2_r3, KC_DELETE),
};

uint16_t get_combo_term(uint16_t _index, combo_t *combo) {
    switch (combo->keycode) {
        case KC_BACKSPACE:
        case KC_DELETE:
        case MO(SYM):
        case MO(NAV):
            // these combos are on the home row and must have an extremely short TERM
            return 20;
    }
    return COMBO_TERM;
}

bool get_combo_must_hold(uint16_t _index, combo_t *combo) {
    switch (combo->keycode) {
        case MO(SYM):
        case MO(NAV):
            return true;
        default:
            return false;
    }
}

bool get_combo_must_tap(uint16_t _index, combo_t *combo) {
    switch (combo->keycode) {
        case MO(SYM):
        case MO(NAV):
            return false;
        default:
            return true;
    }
/*
    // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in its chord, to be
    // tap-only, this is for you:
    uint16_t key;
    uint8_t i = 0;
    while ((key = pgm_read_word(&combo->keys[i])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP...QK_MOD_TAP_MAX:
            case QK_LAYER_TAP...QK_LAYER_TAP_MAX:
            case QK_MOMENTARY...QK_MOMENTARY_MAX:
                return true;
        }
        i += 1;
    }
    return false;
*/
}

// Key Overrides:
const key_override_t shift_comma_is_dash = ko_make_with_layers_and_negmods(
        MOD_MASK_SHIFT,
        PUQ_R7,
        DE_DASH_,
        PUQ_MASK, // only on PUQ layer
        MOD_MASK_CAG // not when combined with any other modifier
      );
const key_override_t shift_dot_is_bullet = ko_make_with_layers_and_negmods(
        MOD_MASK_SHIFT,
        PUQ_R2,
        DE_BULLET_,
        PUQ_MASK, // only on PUQ layer
        MOD_MASK_CAG // not when combined with any other modifier
      );

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

/*
 * Implementations of tap-dance functions:
 */

// Determine the tapdance state to return
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }
    return TD_UNKNOWN;
}

void neo4_slash_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code16(DE_SLASH_); break;
        case TD_SINGLE_HOLD: layer_on(NAV); break;
        default: break;
    }
}

void neo4_slash_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code16(DE_SLASH_); break;
        case TD_SINGLE_HOLD: layer_off(NAV); break;
        default: break;
    }
}

void gui_left_brace_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code16(DE_LEFT_BRACE_); break;
        case TD_SINGLE_HOLD: register_mods(MOD_BIT(KC_LGUI)); break;
        default: break;
    }
}

void gui_left_brace_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code16(DE_LEFT_BRACE_); break;
        case TD_SINGLE_HOLD: unregister_mods(MOD_BIT(KC_LGUI)); break;
        default: break;
    }
}

void alt_right_brace_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code16(DE_RIGHT_BRACE_); break;
        case TD_SINGLE_HOLD: register_mods(MOD_BIT(KC_LALT)); break;
        default: break;
    }
}

void alt_right_brace_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code16(DE_RIGHT_BRACE_); break;
        case TD_SINGLE_HOLD: unregister_mods(MOD_BIT(KC_LALT)); break;
        default: break;
    }
}

void ctl_pipe_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code16(DE_PIPE_); break;
        case TD_SINGLE_HOLD: register_mods(MOD_BIT(KC_LCTL)); break;
        default: break;
    }
}

void ctl_pipe_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code16(DE_PIPE_); break;
        case TD_SINGLE_HOLD: unregister_mods(MOD_BIT(KC_LCTL)); break;
        default: break;
    }
}

void alt_left_paren_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code16(DE_LEFT_PAREN_); break;
        case TD_SINGLE_HOLD: register_mods(MOD_BIT(KC_LALT)); break;
        default: break;
    }
}

void alt_left_paren_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code16(DE_LEFT_PAREN_); break;
        case TD_SINGLE_HOLD: unregister_mods(MOD_BIT(KC_LALT)); break;
        default: break;
    }
}

void gui_right_paren_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code16(DE_RIGHT_PAREN_); break;
        case TD_SINGLE_HOLD: register_mods(MOD_BIT(KC_LGUI)); break;
        default: break;
    }
}

void gui_right_paren_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code16(DE_RIGHT_PAREN_); break;
        case TD_SINGLE_HOLD: unregister_mods(MOD_BIT(KC_LGUI)); break;
        default: break;
    }
}

void ctl_double_quote_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code16(DE_DOUBLE_QUOTE_); break;
        case TD_SINGLE_HOLD: register_mods(MOD_BIT(KC_LCTL)); break;
        default: break;
    }
}

void ctl_double_quote_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code16(DE_DOUBLE_QUOTE_); break;
        case TD_SINGLE_HOLD: unregister_mods(MOD_BIT(KC_LCTL)); break;
        default: break;
    }
}
