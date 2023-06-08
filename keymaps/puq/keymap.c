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
       │  M │  L │  C │                     │  , │ "… │  U │
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

#define PUQ_LP LT(NEO3, KC_S)
#define PUQ_L1 KC_NO
#define PUQ_L2 KC_NO
#define PUQ_L3 KC_NO
#define PUQ_L4 KC_NO
#define PUQ_L5 KC_NO
#define PUQ_L6 KC_NO
#define PUQ_L7 KC_NO
#define PUQ_L8 KC_NO
#define PUQ_L9 KC_NO
#define PUQ_LA KC_NO
#define PUQ_LB KC_NO
#define PUQ_LS KC_NO
#define PUQ_LE KC_NO
#define PUQ_RP LT(NEO3, KC_H)
#define PUQ_R1 KC_NO
#define PUQ_R2 KC_NO
#define PUQ_R3 KC_NO
#define PUQ_R4 KC_NO
#define PUQ_R5 KC_NO
#define PUQ_R6 KC_NO
#define PUQ_R7 KC_NO
#define PUQ_R8 KC_NO
#define PUQ_R9 KC_NO
#define PUQ_RA KC_NO
#define PUQ_RB KC_NO
#define PUQ_RS KC_NO
#define PUQ_RE KC_NO

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

#define NEO3_LP KC_NO
#define NEO3_L1 KC_NO
#define NEO3_L2 KC_NO
#define NEO3_L3 KC_NO
#define NEO3_L4 KC_NO
#define NEO3_L5 KC_NO
#define NEO3_L6 KC_NO
#define NEO3_L7 KC_NO
#define NEO3_L8 KC_NO
#define NEO3_L9 KC_NO
#define NEO3_LA KC_NO
#define NEO3_LB KC_NO
#define NEO3_LS KC_NO
#define NEO3_LE KC_NO
#define NEO3_RP KC_NO
#define NEO3_R1 KC_NO
#define NEO3_R2 KC_NO
#define NEO3_R3 KC_NO
#define NEO3_R4 KC_NO
#define NEO3_R5 KC_NO
#define NEO3_R6 KC_NO
#define NEO3_R7 KC_NO
#define NEO3_R8 KC_NO
#define NEO3_R9 KC_NO
#define NEO3_RA KC_NO
#define NEO3_RB KC_NO
#define NEO3_RS KC_NO
#define NEO3_RE KC_NO

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

#define NEO4_LP KC_NO
#define NEO4_L1 KC_NO
#define NEO4_L2 KC_NO
#define NEO4_L3 KC_NO
#define NEO4_L4 KC_NO
#define NEO4_L5 KC_NO
#define NEO4_L6 KC_NO
#define NEO4_L7 KC_NO
#define NEO4_L8 KC_NO
#define NEO4_L9 KC_NO
#define NEO4_LA KC_NO
#define NEO4_LB KC_NO
#define NEO4_LS KC_NO
#define NEO4_LE KC_NO
#define NEO4_RP KC_NO
#define NEO4_R1 KC_NO
#define NEO4_R2 KC_NO
#define NEO4_R3 KC_NO
#define NEO4_R4 KC_NO
#define NEO4_R5 KC_NO
#define NEO4_R6 KC_NO
#define NEO4_R7 KC_NO
#define NEO4_R8 KC_NO
#define NEO4_R9 KC_NO
#define NEO4_RA KC_NO
#define NEO4_RB KC_NO
#define NEO4_RS KC_NO
#define NEO4_RE KC_NO

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

#define FUNC_LP KC_NO
#define FUNC_L1 KC_NO
#define FUNC_L2 KC_NO
#define FUNC_L3 KC_NO
#define FUNC_L4 KC_NO
#define FUNC_L5 KC_NO
#define FUNC_L6 KC_NO
#define FUNC_L7 KC_NO
#define FUNC_L8 KC_NO
#define FUNC_L9 KC_NO
#define FUNC_LA KC_NO
#define FUNC_LB KC_NO
#define FUNC_LS KC_NO
#define FUNC_LE KC_NO
#define FUNC_RP KC_NO
#define FUNC_R1 KC_NO
#define FUNC_R2 KC_NO
#define FUNC_R3 KC_NO
#define FUNC_R4 KC_NO
#define FUNC_R5 KC_NO
#define FUNC_R6 KC_NO
#define FUNC_R7 KC_NO
#define FUNC_R8 KC_NO
#define FUNC_R9 KC_NO
#define FUNC_RA KC_NO
#define FUNC_RB KC_NO
#define FUNC_RS KC_NO
#define FUNC_RE KC_NO

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
              PUQ_L7, PUQ_L8, PUQ_L9, PUQ_LA,         PUQ_RA, PUQ_R7, PUQ_R8, PUQ_R9,
      PUQ_LP, PUQ_L4, PUQ_L5, PUQ_L6, PUQ_LB,         PUQ_RB, PUQ_R4, PUQ_R5, PUQ_R6, PUQ_RP,
              PUQ_L1, PUQ_L2, PUQ_L3,                         PUQ_R1, PUQ_R2, PUQ_R3,
                                  PUQ_LS, PUQ_LE,  PUQ_RE, PUQ_RS
    ),

    [NEO3] = LAYOUT(
               NEO3_L7, NEO3_L8, NEO3_L9, NEO3_LA,         NEO3_RA, NEO3_R7, NEO3_R8, NEO3_R9,
      NEO3_LP, NEO3_L4, NEO3_L5, NEO3_L6, NEO3_LB,         NEO3_RB, NEO3_R4, NEO3_R5, NEO3_R6, NEO3_RP,
               NEO3_L1, NEO3_L2, NEO3_L3,                           NEO3_R1, NEO3_R2, NEO3_R3,
                                     NEO3_LS, NEO3_LE,  NEO3_RE, NEO3_RS
    ),

    [NEO4] = LAYOUT(
               NEO4_L7, NEO4_L8, NEO4_L9, NEO4_LA,         NEO4_RA, NEO4_R7, NEO4_R8, NEO4_R9,
      NEO4_LP, NEO4_L4, NEO4_L5, NEO4_L6, NEO4_LB,         NEO4_RB, NEO4_R4, NEO4_R5, NEO4_R6, NEO4_RP,
               NEO4_L1, NEO4_L2, NEO4_L3,                           NEO4_R1, NEO4_R2, NEO4_R3,
                                     NEO4_LS, NEO4_LE,  NEO4_RE, NEO4_RS
    ),

    [FUNC] = LAYOUT(
               FUNC_L7, FUNC_L8, FUNC_L9, FUNC_LA,         FUNC_RA, FUNC_R7, FUNC_R8, FUNC_R9,
      FUNC_LP, FUNC_L4, FUNC_L5, FUNC_L6, FUNC_LB,         FUNC_RB, FUNC_R4, FUNC_R5, FUNC_R6, FUNC_RP,
               FUNC_L1, FUNC_L2, FUNC_L3,                           FUNC_R1, FUNC_R2, FUNC_R3,
                                     FUNC_LS, FUNC_LE,  FUNC_RE, FUNC_RS
    )
};
