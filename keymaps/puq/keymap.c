#include QMK_KEYBOARD_H
#include "zilpzalp.h"

enum zilpzalp_layers {
    PUQ,
    NEO3,
    NEO4,
    FUNC
};

#define PUQ_MASK  (1 << PUQ)
#define NEO3_MASK (1 << NEO3)
#define NEO4_MASK (1 << NEO4)
#define FUNC_MASK (1 << FUNC)

enum custom_keycodes {
    UNUSED = SAFE_RANGE
};

#define DE_UUML KC_LEFT_BRACKET
#define DE_MINUS KC_SLASH
#define DE_Y KC_Z
#define DE_Z KC_Y
#define DE_HASH KC_BACKSLASH
#define DE_UNDERSCORE S(DE_MINUS)
#define DE_SINGLE_QUOTE S(DE_HASH)
#define DE_BULLET A(DE_UUML)
#define DE_DASH A(DE_MINUS)

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
       │  M │  L │  C │                     │  ,*│ "… │  U │
       │    │    │    ├────┐           ┌────┤    │    │    │
       ├─ F ┼────┼─ P ┤  G │           │  Q ├─ F ┼────┼─ P ┤
       │  N │  R │  T │cg  │           │cg  │  A │  E │  I │
  ┌────┤4   │g   │a   ├────┤           ├────┤a   │g   │4   ├────┐
  │  S ├─ Z ┼────┼─ J ┤  D │           │  O ├─ X ┼────┼─ K ┤  H │
  │3   │  B │  W │  V │cag │           │cag │  _ │  .*│  Y │3   │
  └────┤    │c   │    ├────┘           └────┤    │c   │    ├────┘
       └────┴────┴──┬─┴───┬─────┐ ┌─────┬───┴─┬──┴────┴────┘
                    │  SPC│  ESC│ │  ENT│  SPC│
                    │s    │f    │ │f    │s    │
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
   - `*` indicates that a key_override exists
   - `"…` indicates the compose key. Used to type German umlautes and other stuff.

       ┌────┬────┬────┐                     ┌────┬────┬────┐
       │  M │  L │  C ├─────┐         ┌─────┤  ,*│ "… │  U │
       ├─ F ┼────┼─ P ┤cg G │         │cg Q ├─ F ┼────┼─ P ┤
  ┌────┤4 N │g R │a T ├─────┤         ├─────┤a A │g E │4 I ├────┐
  │3 S ├─ Z ┼────┼─ J ┤cag D│         │cag O├─ X ┼────┼─ K ┤3 H │
  └────┤  B │c W │  V ├─────┘         └─────┤  _ │c .*│  Y ├────┘
       └────┴────┴──┬─┴───┬─────┐ ┌─────┬───┴─┬──┴────┴────┘
                    │s SPC│f ESC│ │f ENT│s SPC│
                    └─────┴─────┘ └─────┴─────┘
*/

#define PUQ_LP LT(NEO3, KC_S)
#define PUQ_L1 KC_B
#define PUQ_L2 MT(MOD_LCTL, KC_W)
#define PUQ_L3 KC_V
#define PUQ_L4 LT(NEO4, KC_N)
#define PUQ_L5 MT(MOD_LGUI, KC_R)
#define PUQ_L6 MT(MOD_LALT, KC_T)
#define PUQ_L7 KC_M
#define PUQ_L8 KC_L
#define PUQ_L9 KC_C
#define PUQ_LA MT(MOD_LCTL|MOD_LGUI, KC_G)
#define PUQ_LB MT(MOD_LCTL|MOD_LALT|MOD_LGUI, KC_D)
#define PUQ_LS MT(MOD_LSFT, KC_SPACE)
#define PUQ_LE LT(FUNC, KC_ESCAPE)
#define PUQ_RP LT(NEO3, KC_H)
#define PUQ_R1 DE_UNDERSCORE
#define PUQ_R2 MT(MOD_LCTL, KC_DOT)
#define PUQ_R3 DE_Y
#define PUQ_R4 MT(MOD_LALT, KC_A)
#define PUQ_R5 MT(MOD_LGUI, KC_E)
#define PUQ_R6 LT(NEO4, KC_I)
#define PUQ_R7 KC_COMMA
#define PUQ_R8 C(KC_F13) // quick-compose key. add SHIFT for full compose key
#define PUQ_R9 KC_U
#define PUQ_RA MT(MOD_LCTL|MOD_LGUI, KC_Q)
#define PUQ_RB MT(MOD_LCTL|MOD_LALT|MOD_LGUI, KC_O)
#define PUQ_RS MT(MOD_LSFT, KC_SPACE)
#define PUQ_RE LT(FUNC, KC_ENTER)

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

#define NEO3_LP XXXXXXX
#define NEO3_L1 XXXXXXX
#define NEO3_L2 XXXXXXX
#define NEO3_L3 XXXXXXX
#define NEO3_L4 XXXXXXX
#define NEO3_L5 XXXXXXX
#define NEO3_L6 XXXXXXX
#define NEO3_L7 XXXXXXX
#define NEO3_L8 XXXXXXX
#define NEO3_L9 XXXXXXX
#define NEO3_LA XXXXXXX
#define NEO3_LB XXXXXXX
#define NEO3_LS XXXXXXX
#define NEO3_LE XXXXXXX
#define NEO3_RP XXXXXXX
#define NEO3_R1 XXXXXXX
#define NEO3_R2 XXXXXXX
#define NEO3_R3 XXXXXXX
#define NEO3_R4 XXXXXXX
#define NEO3_R5 XXXXXXX
#define NEO3_R6 XXXXXXX
#define NEO3_R7 XXXXXXX
#define NEO3_R8 XXXXXXX
#define NEO3_R9 XXXXXXX
#define NEO3_RA XXXXXXX
#define NEO3_RB XXXXXXX
#define NEO3_RS XXXXXXX
#define NEO3_RE XXXXXXX

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

#define NEO4_LP XXXXXXX
#define NEO4_L1 XXXXXXX
#define NEO4_L2 XXXXXXX
#define NEO4_L3 XXXXXXX
#define NEO4_L4 XXXXXXX
#define NEO4_L5 XXXXXXX
#define NEO4_L6 XXXXXXX
#define NEO4_L7 XXXXXXX
#define NEO4_L8 XXXXXXX
#define NEO4_L9 XXXXXXX
#define NEO4_LA XXXXXXX
#define NEO4_LB XXXXXXX
#define NEO4_LS XXXXXXX
#define NEO4_LE XXXXXXX
#define NEO4_RP XXXXXXX
#define NEO4_R1 XXXXXXX
#define NEO4_R2 XXXXXXX
#define NEO4_R3 XXXXXXX
#define NEO4_R4 XXXXXXX
#define NEO4_R5 XXXXXXX
#define NEO4_R6 XXXXXXX
#define NEO4_R7 XXXXXXX
#define NEO4_R8 XXXXXXX
#define NEO4_R9 XXXXXXX
#define NEO4_RA XXXXXXX
#define NEO4_RB XXXXXXX
#define NEO4_RS XXXXXXX
#define NEO4_RE XXXXXXX

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

#define FUNC_LP XXXXXXX
#define FUNC_L1 XXXXXXX
#define FUNC_L2 XXXXXXX
#define FUNC_L3 XXXXXXX
#define FUNC_L4 XXXXXXX
#define FUNC_L5 XXXXXXX
#define FUNC_L6 XXXXXXX
#define FUNC_L7 XXXXXXX
#define FUNC_L8 XXXXXXX
#define FUNC_L9 XXXXXXX
#define FUNC_LA XXXXXXX
#define FUNC_LB XXXXXXX
#define FUNC_LS XXXXXXX
#define FUNC_LE XXXXXXX
#define FUNC_RP XXXXXXX
#define FUNC_R1 XXXXXXX
#define FUNC_R2 XXXXXXX
#define FUNC_R3 XXXXXXX
#define FUNC_R4 XXXXXXX
#define FUNC_R5 XXXXXXX
#define FUNC_R6 XXXXXXX
#define FUNC_R7 XXXXXXX
#define FUNC_R8 XXXXXXX
#define FUNC_R9 XXXXXXX
#define FUNC_RA XXXXXXX
#define FUNC_RB XXXXXXX
#define FUNC_RS XXXXXXX
#define FUNC_RE XXXXXXX

// Key Overrides:
const key_override_t shift_comma_is_dash = ko_make_with_layers_and_negmods(
        MOD_MASK_SHIFT,
        PUQ_R7,
        DE_DASH,
        PUQ_MASK, // only on PUQ layer
        MOD_MASK_CAG // not when combined with any other modifier
      );
const key_override_t shift_dot_is_bullet = ko_make_with_layers_and_negmods(
        MOD_MASK_SHIFT,
        PUQ_R2,
        DE_BULLET,
        PUQ_MASK, // only on PUQ layer
        MOD_MASK_CAG // not when combined with any other modifier
      );

const key_override_t **key_overrides = (const key_override_t *[]){
    &shift_comma_is_dash,
    &shift_dot_is_bullet,
    NULL // terminator
};

// Combos:
const uint16_t PROGMEM puq_l1_l4[] = {PUQ_L1, PUQ_L4, COMBO_END};
const uint16_t PROGMEM puq_l3_l6[] = {PUQ_L3, PUQ_L6, COMBO_END};
const uint16_t PROGMEM puq_l4_l7[] = {PUQ_L4, PUQ_L7, COMBO_END};
const uint16_t PROGMEM puq_l6_l9[] = {PUQ_L6, PUQ_L9, COMBO_END};
const uint16_t PROGMEM puq_r1_r4[] = {PUQ_R1, PUQ_R4, COMBO_END};
const uint16_t PROGMEM puq_r3_r6[] = {PUQ_R3, PUQ_R6, COMBO_END};
const uint16_t PROGMEM puq_r4_r7[] = {PUQ_R4, PUQ_R7, COMBO_END};
const uint16_t PROGMEM puq_r6_r9[] = {PUQ_R6, PUQ_R9, COMBO_END};

combo_t key_combos[] = {
    COMBO(puq_l1_l4, DE_Z),
    COMBO(puq_l3_l6, KC_J),
    COMBO(puq_l4_l7, KC_F),
    COMBO(puq_l6_l9, KC_P),
    COMBO(puq_r1_r4, KC_X),
    COMBO(puq_r3_r6, KC_K),
    COMBO(puq_r4_r7, KC_F),
    COMBO(puq_r6_r9, KC_P),
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
