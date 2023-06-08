#include QMK_KEYBOARD_H
#include "zilpzalp.h"

enum zilpzalp_layers {
    PUQ,
    NEO3,
    NEO4,
    FUNC
};

enum custom_keycodes {
    UNUSED = SAFE_RANGE
};

/* #defines:
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
       ┌────┬────┬────┐                     ┌────┬────┬────┐
       │  M │  L │  C │                     │  , │  " │  U │
       │    │    │    ├────┐           ┌────┤    │    │    │
       ├─ F ┼────┼─ P ┤  G │           │  Q ├─ F ┼────┼─ P ┤
       │  N │  R │  T │cg  │           │cg  │  A │  E │  I │
  ┌────┤4   │g   │a   ├────┤           ├────┤a   │g   │4   ├────┐
  │  S ├─ Z ┼────┼─ J ┤  D │           │  O ├─ X ┼────┼─ K ┤  H │
  │3   │  B │  W │  V │cag │           │cag │  _ │  . │  Y │3   │
  └────┤    │c   │    ├────┘           └────┤    │c   │    ├────┘
       └────┴────┴──┬─┴───┬─────┐ ┌─────┬───┴─┬──┴────┴────┘
                    │  SPC│  ESC│ │  ENT│  SPC│
                    │s    │f    │ │f    │s    │
                    └─────┴─────┘ └─────┴─────┘
       ┌────┬────┬────┐                     ┌────┬────┬────┐
       │  M │  L │  C ├─────┐         ┌─────┤  , │  " │  U │
       ├─ F ┼────┼─ P ┤cg G │         │cg Q ├─ F ┼────┼─ P ┤
  ┌────┤4 N │g R │a T ├─────┤         ├─────┤a A │g E │4 I ├────┐
  │3 S ├─ Z ┼────┼─ J ┤cag D│         │cag O├─ X ┼────┼─ K ┤3 H │
  └────┤  B │c W │  V ├─────┘         └─────┤  _ │c . │  Y ├────┘
       └────┴────┴──┬─┴───┬─────┐ ┌─────┬───┴─┬──┴────┴────┘
                    │s SPC│f ESC│ │f ENT│s SPC│
                    └─────┴─────┘ └─────┴─────┘
   Legend:
   - Capital letters ordinary characters
   - Lower case letters and numbers:
       a: Alt
       c: CTRL
       g: GUI key (CMD on Mac)
       s: Shift
       3: Layer NEO3
       4: Layer NEO4
       f: Layer FUNC
*/

#define PUQ_LP
#define PUQ_L1
#define PUQ_L2
#define PUQ_L3
#define PUQ_L4
#define PUQ_L5
#define PUQ_L6
#define PUQ_L7
#define PUQ_L8
#define PUQ_L9
#define PUQ_LA
#define PUQ_LB
#define PUQ_LS
#define PUQ_LE
#define PUQ_RP
#define PUQ_R1
#define PUQ_R2
#define PUQ_R3
#define PUQ_R4
#define PUQ_R5
#define PUQ_R6
#define PUQ_R7
#define PUQ_R8
#define PUQ_R9
#define PUQ_RA
#define PUQ_RB
#define PUQ_RS
#define PUQ_RE

/* Layer NEO3:
       ┌────┬────┬────┐                     ┌────┬────┬────┐
       │  … │  [ │  ] ├────┐           ┌────┤  < │  > │  = │
       ├────┼────┼────┤  ^ │           │  ! ├────┼────┼─ & ┤
  ┌────┤  / │g { │a } ├────┤           ├────┤a ( │g ) │4 - ├────┐
  │  \ ├─ # ┼────┼─ ` ┤  * │           │  ? ├─ + ┼────┼─ ; ┤3 : │
  └────┤  $ │c | │  ~ ├────┘           └────┤  % │c " │  ' ├────┘
       └────┴────┴──┬─┴───┬─────┐ ┌─────┬───┴─┬──┴────┴────┘
                    │ SPC │ ESC │ │ ENT │ SPC │
                    └─────┴─────┘ └─────┴─────┘
*/

#define NEO3_LP
#define NEO3_L1
#define NEO3_L2
#define NEO3_L3
#define NEO3_L4
#define NEO3_L5
#define NEO3_L6
#define NEO3_L7
#define NEO3_L8
#define NEO3_L9
#define NEO3_LA
#define NEO3_LB
#define NEO3_LS
#define NEO3_LE
#define NEO3_RP
#define NEO3_R1
#define NEO3_R2
#define NEO3_R3
#define NEO3_R4
#define NEO3_R5
#define NEO3_R6
#define NEO3_R7
#define NEO3_R8
#define NEO3_R9
#define NEO3_RA
#define NEO3_RB
#define NEO3_RS
#define NEO3_RE

/* Layer NEO4:
       ┌────┬────┬────┐                     ┌────┬────┬────┐
       │<[X]│  ↑ │ [X]├────┐           ┌────┤  7 │  8 │  9 │
       ├ PG↑┼────┼────┤ PG↓│           │  * ├────┼────┼────┤
  ┌────┤  ← │g ↓ │a → ├────┤           ├────┤a 4 │g 5 │  6 ├────┐
  │ ←← ├────┼────┼────┤ →→ │           │  / ├────┼────┼─ - ┤3 + │
  └────┤ ->|│c \/│ <─┘├────┘           └────┤  1 │c 2 │  3 ├────┘
       └────┴────┴──┬─┴───┬─────┐ ┌─────┬───┴────┴────┴────┘
                    │ SPC │ ESC │ │ ENT │ SPC │
                    └─────┴─────┘ └─────┴─────┘
*/

#define NEO4_LP
#define NEO4_L1
#define NEO4_L2
#define NEO4_L3
#define NEO4_L4
#define NEO4_L5
#define NEO4_L6
#define NEO4_L7
#define NEO4_L8
#define NEO4_L9
#define NEO4_LA
#define NEO4_LB
#define NEO4_LS
#define NEO4_LE
#define NEO4_RP
#define NEO4_R1
#define NEO4_R2
#define NEO4_R3
#define NEO4_R4
#define NEO4_R5
#define NEO4_R6
#define NEO4_R7
#define NEO4_R8
#define NEO4_R9
#define NEO4_RA
#define NEO4_RB
#define NEO4_RS
#define NEO4_RE

/* Layer FUNC:
       ┌────┬────┬────┐                     ┌────┬────┬────┐
       │ F7 │ F8 │ F9 ├────┐           ┌────┤Vol-│Mute│Vol+│
       ├────┼────┼────┤ F10│           │  * ├────┼────┼────┤
  ┌────┤ F6 │ F5 │ F6 ├────┤     ┌─────┴────┤a <<│g||>│ >> ├────┐
  │ F12├────┼────┼────┤ F11│     │ LK cag / ├────┼────┼────┤Menu│
  └────┤ F1 │ F2 │ F3 ├────┘     └──────────┤BRI↓│c   │BRI↑├────┘
       └────┴────┴──┬─┴───┬─────┐ ┌─────┬───┴─┬──┴────┴────┘
                    │ LMB │ RMB │ │ LMB │ RMB │
                    └─────┴─────┘ └─────┴─────┘
*/

#define FUNC_LP
#define FUNC_L1
#define FUNC_L2
#define FUNC_L3
#define FUNC_L4
#define FUNC_L5
#define FUNC_L6
#define FUNC_L7
#define FUNC_L8
#define FUNC_L9
#define FUNC_LA
#define FUNC_LB
#define FUNC_LS
#define FUNC_LE
#define FUNC_RP
#define FUNC_R1
#define FUNC_R2
#define FUNC_R3
#define FUNC_R4
#define FUNC_R5
#define FUNC_R6
#define FUNC_R7
#define FUNC_R8
#define FUNC_R9
#define FUNC_RA
#define FUNC_RB
#define FUNC_RS
#define FUNC_RE

// LEFT HAND HOME ROW MODS
#define CTL_A MT(MOD_LCTL, KC_A)
#define ALT_S MT(MOD_LALT, KC_S)
#define GUI_D MT(MOD_LGUI, KC_D)
#define SFT_F MT(MOD_LSFT, KC_F)
#define RALT_G MT(MOD_RALT, KC_G)
// RIGHT HAND HOME ROW MODS
#define RALT_H MT(MOD_RALT, KC_H)
#define SFT_J MT(MOD_RSFT, KC_J)
#define GUI_K MT(MOD_RGUI, KC_K)
#define ALT_L MT(MOD_LALT, KC_L)
#define CTL_P MT(MOD_RCTL, KC_P)
// LAYER TAP BEHAVIORS
#define NUM_ESC LT(_NUM, KC_ESC)
#define NAV_SPC LT(_NAV, KC_SPC)
#define SYM_KCN LT(_SYM, KC_N)
#define FUN_ENT LT(_FUN, KC_ENT)

enum combo_events {
    CAPSWORD_COMBO,
    CAPSLOCK_COMBO,
    Q_COMBO,
    Z_COMBO,
    B_COMBO,
    MINUS_COMBO,
    SLASH_COMBO,
    SEMI_COMBO,
    QUOT_COMBO,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM capsword_combo[] = {SFT_F, SFT_J, COMBO_END};
const uint16_t PROGMEM capslock_combo[] = {KC_W, KC_O, COMBO_END};
const uint16_t PROGMEM q_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM z_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM b_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM minus_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM slash_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM semi_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM quot_combo[] = {KC_U, KC_I, COMBO_END};

combo_t key_combos[] = {
    [CAPSWORD_COMBO] = COMBO(capsword_combo, CW_TOGG),
    [CAPSLOCK_COMBO] = COMBO(capslock_combo, KC_CAPS),
    [Q_COMBO] = COMBO(q_combo, KC_Q),
    [Z_COMBO] = COMBO(z_combo, KC_Z),
    [B_COMBO] = COMBO(b_combo, KC_B),
    [MINUS_COMBO] = COMBO(minus_combo, KC_MINUS),
    [SLASH_COMBO] = COMBO(slash_combo, KC_SLASH),
    [SEMI_COMBO] = COMBO(semi_combo, KC_SCLN),
    [QUOT_COMBO] = COMBO(quot_combo, KC_QUOT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [PUQ] = LAYOUT(
              PUQ_00, PUQ_01, PUQ_02, PUQ_03,         PUQ_04, PUQ_05, PUQ_06, PUQ_07,
      PUQ_08, PUQ_09, PUQ_10, PUQ_11, PUQ_12,         PUQ_13, PUQ_14, PUQ_15, PUQ_16, PUQ_17,
              PUQ_18, PUQ_19, PUQ_20,                         PUQ_21, PUQ_22, PUQ_23,
                                  PUQ_24, PUQ_25,  PUQ_26, PUQ_27
    ),

    [NEO3] = LAYOUT(
               NEO3_00, NEO3_01, NEO3_02, NEO3_03,         NEO3_04, NEO3_05, NEO3_06, NEO3_07,
      NEO3_08, NEO3_09, NEO3_10, NEO3_11, NEO3_12,         NEO3_13, NEO3_14, NEO3_15, NEO3_16, NEO3_17,
               NEO3_18, NEO3_19, NEO3_20,                           NEO3_21, NEO3_22, NEO3_23,
                                     NEO3_24, NEO3_25,  NEO3_26, NEO3_27
    ),

    [NEO4] = LAYOUT(
               NEO4_00, NEO4_01, NEO4_02, NEO4_03,         NEO4_04, NEO4_05, NEO4_06, NEO4_07,
      NEO4_08, NEO4_09, NEO4_10, NEO4_11, NEO4_12,         NEO4_13, NEO4_14, NEO4_15, NEO4_16, NEO4_17,
               NEO4_18, NEO4_19, NEO4_20,                           NEO4_21, NEO4_22, NEO4_23,
                                     NEO4_24, NEO4_25,  NEO4_26, NEO4_27
    ),

    [FUNC] = LAYOUT(
               FUNC_00, FUNC_01, FUNC_02, FUNC_03,         FUNC_04, FUNC_05, FUNC_06, FUNC_07,
      FUNC_08, FUNC_09, FUNC_10, FUNC_11, FUNC_12,         FUNC_13, FUNC_14, FUNC_15, FUNC_16, FUNC_17,
               FUNC_18, FUNC_19, FUNC_20,                           FUNC_21, FUNC_22, FUNC_23,
                                     FUNC_24, FUNC_25,  FUNC_26, FUNC_27
    )
};
