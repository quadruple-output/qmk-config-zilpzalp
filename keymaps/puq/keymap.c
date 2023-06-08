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

// This layout assumes that the OS layout is set to "German (no dead keys)"
// We define `DE`-versions for symbols that do not match their US keyboard positions:
#define DE_CARET         KC_GRAVE           // ^
#define DE_EXCLAMATION   S(KC_1)            // !
#define DE_DOUBLE_QUOTE  S(KC_2)            // "
#define DE_DOLLAR        S(KC_4)            // $
#define DE_PERCENT       S(KC_5)            // %
#define DE_LEFT_BRACKET  A(KC_5)            // %
#define DE_AMPERSAND     S(KC_6)            // &
#define DE_RIGHT_BRACKET A(KC_6)            // &
#define DE_SLASH         S(KC_7)            // /
#define DE_PIPE          A(KC_7)            // |
#define DE_BACKSLASH     S(A(KC_7))         // |
#define DE_LEFT_PAREN    S(KC_8)            // (
#define DE_LEFT_BRACE    A(KC_8)            // {
#define DE_RIGHT_PAREN   S(KC_9)            // )
#define DE_RIGHT_BRACE   A(KC_9)            // }
#define DE_EQUAL         S(KC_0)            // =
#define DE_SZLIG         KC_MINUS           // ß
#define DE_QUESTION      S(DE_SZLIG)        // ?
#define DE_ACUTE         KC_EQUAL           // ´
#define DE_BACKQUOTE     S(DE_ACUTE)        // `
#define DE_Q             KC_Q               // q
#define DE_W             KC_W               // w
#define DE_E             KC_E               // e
#define DE_R             KC_R               // r
#define DE_T             KC_T               // t
#define DE_Z             KC_Y               // z
#define DE_U             KC_U               // u
#define DE_I             KC_I               // i
#define DE_O             KC_O               // o
#define DE_P             KC_P               // p
#define DE_UUML          KC_LEFT_BRACKET    // ü
#define DE_BULLET        A(DE_UUML)         // •
#define DE_PLUS          KC_RIGHT_BRACKET   // +
#define DE_ASTERISK      S(DE_PLUS)         // *
#define DE_A             KC_A               // a
#define DE_S             KC_S               // s
#define DE_D             KC_D               // d
#define DE_F             KC_F               // f
#define DE_G             KC_G               // g
#define DE_H             KC_H               // h
#define DE_J             KC_J               // j
#define DE_K             KC_K               // k
#define DE_L             KC_L               // l
#define DE_AT            A(DE_L)            // @
#define DE_OUML          KC_SEMICOLON       // ö
#define DE_AUML          KC_QUOTE           // ä
#define DE_HASH          KC_BACKSLASH       // #
#define DE_QUOTE         S(DE_HASH)         // '
#define DE_LESS_THAN     KC_NONUS_BACKSLASH // <
#define DE_GREATER_THAN  S(DE_LESS_THAN)    // >
#define DE_Y             KC_Z               // y
#define DE_X             KC_X               // x
#define DE_C             KC_C               // c
#define DE_V             KC_V               // v
#define DE_B             KC_B               // b
#define DE_N             KC_N               // n
#define DE_TILDE         A(DE_N)            // ~
#define DE_M             KC_M               // m
#define DE_COMMA         KC_COMMA           // ,
#define DE_SEMICOLON     S(DE_COMMA)        // ;
#define DE_DOT           KC_DOT             // .
#define DE_COLON         S(DE_DOT)          // :
#define DE_ELLIPSIS      A(DE_DOT)          // …
#define DE_MINUS         KC_SLASH           // -
#define DE_UNDERSCORE    S(DE_MINUS)        // _
#define DE_DASH          A(DE_MINUS)        // –

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
       3: Layer NEO3
       4: Layer NEO4
       f: Layer FUNC
   - `*` indicates that a key override exists
   - `"…` indicates the compose key. Used to type German umlautes (and other stuff).

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

#define PUQ_LP LT(NEO3, DE_S)
#define PUQ_L1 DE_B
#define PUQ_L2 MT(MOD_LCTL, DE_W)
#define PUQ_L3 DE_V
#define PUQ_L4 LT(NEO4, DE_N)
#define PUQ_L5 MT(MOD_LGUI, DE_R)
#define PUQ_L6 MT(MOD_LALT, DE_T)
#define PUQ_L7 DE_M
#define PUQ_L8 DE_L
#define PUQ_L9 DE_C
#define PUQ_LA MT(MOD_LCTL|MOD_LGUI, DE_G)
#define PUQ_LB MT(MOD_LCTL|MOD_LALT|MOD_LGUI, DE_D)
#define PUQ_LS MT(MOD_LSFT, KC_SPACE)
#define PUQ_LE LT(FUNC, KC_ESCAPE)
#define PUQ_RP LT(NEO3, DE_H)
#define PUQ_R1 DE_UNDERSCORE
#define PUQ_R2 MT(MOD_LCTL, DE_DOT)
#define PUQ_R3 DE_Y
#define PUQ_R4 MT(MOD_LALT, DE_A)
#define PUQ_R5 MT(MOD_LGUI, DE_E)
#define PUQ_R6 LT(NEO4, DE_I)
#define PUQ_R7 DE_COMMA
#define PUQ_R8 C(KC_F13) // quick-compose key. add SHIFT for full compose key
#define PUQ_R9 DE_U
#define PUQ_RA MT(MOD_LCTL|MOD_LGUI, DE_Q)
#define PUQ_RB MT(MOD_LCTL|MOD_LALT|MOD_LGUI, DE_O)
#define PUQ_RS MT(MOD_LSFT, KC_SPACE)
#define PUQ_RE LT(FUNC, KC_ENTER)

/* Layer NEO3:
       ┌────┬────┬────┐                     ┌────┬────┬────┐
       │  … │  [ │  ] ├────┐           ┌────┤  < │  > │  = │
       ├────┼────┼────┤  ^ │           │  ! ├────┼────┼─ & ┤
  ┌────┤4 / │  { │  } ├────┤           ├────┤  ( │  ) │4 - ├────┐
  │  \ ├─ # ┼────┼─ ` ┤  * │           │  ? ├─ + ┼────┼─ ; ┤  : │
  └────┤  $ │  | │  ~ ├────┘           └────┤  % │  " │  ' ├────┘
       └────┴────┴──┬─┴───┬─────┐ ┌─────┬───┴─┬──┴────┴────┘
                    │ SPC │ ESC │ │ ENT │ SPC │
                    └─────┴─────┘ └─────┴─────┘
*/

#define NEO3_LP DE_BACKSLASH
#define NEO3_L1 DE_DOLLAR
#define NEO3_L2 DE_PIPE
#define NEO3_L3 DE_TILDE
#define NEO3_L4 LT(NEO4, DE_SLASH)
#define NEO3_L5 DE_LEFT_BRACE
#define NEO3_L6 DE_RIGHT_BRACE
#define NEO3_L7 DE_ELLIPSIS
#define NEO3_L8 DE_LEFT_BRACKET
#define NEO3_L9 DE_RIGHT_BRACKET
#define NEO3_LA DE_CARET
#define NEO3_LB DE_ASTERISK
#define NEO3_LS KC_SPACE
#define NEO3_LE KC_ESCAPE
#define NEO3_RP DE_COLON
#define NEO3_R1 DE_PERCENT
#define NEO3_R2 DE_DOUBLE_QUOTE
#define NEO3_R3 DE_QUOTE
#define NEO3_R4 DE_LEFT_PAREN
#define NEO3_R5 DE_RIGHT_PAREN
#define NEO3_R6 LT(NEO4, DE_MINUS)
#define NEO3_R7 DE_LESS_THAN
#define NEO3_R8 DE_GREATER_THAN
#define NEO3_R9 DE_EQUAL
#define NEO3_RA DE_EXCLAMATION
#define NEO3_RB DE_QUESTION
#define NEO3_RS KC_SPACE
#define NEO3_RE KC_ENTER

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

// Combos:
const uint16_t PROGMEM puq_l1_l4[] = {PUQ_L1, PUQ_L4, COMBO_END};
const uint16_t PROGMEM puq_l3_l6[] = {PUQ_L3, PUQ_L6, COMBO_END};
const uint16_t PROGMEM puq_l4_l7[] = {PUQ_L4, PUQ_L7, COMBO_END};
const uint16_t PROGMEM puq_l6_l9[] = {PUQ_L6, PUQ_L9, COMBO_END};
const uint16_t PROGMEM puq_r1_r4[] = {PUQ_R1, PUQ_R4, COMBO_END};
const uint16_t PROGMEM puq_r3_r6[] = {PUQ_R3, PUQ_R6, COMBO_END};
const uint16_t PROGMEM puq_r4_r7[] = {PUQ_R4, PUQ_R7, COMBO_END};
const uint16_t PROGMEM puq_r6_r9[] = {PUQ_R6, PUQ_R9, COMBO_END};
const uint16_t PROGMEM neo3_l1_l4[] = {NEO3_L1, NEO3_L4, COMBO_END};
const uint16_t PROGMEM neo3_l3_l6[] = {NEO3_L3, NEO3_L6, COMBO_END};
const uint16_t PROGMEM neo3_r1_r4[] = {NEO3_R1, NEO3_R4, COMBO_END};
const uint16_t PROGMEM neo3_r3_r6[] = {NEO3_R3, NEO3_R6, COMBO_END};
const uint16_t PROGMEM neo3_r6_r9[] = {NEO3_R6, NEO3_R9, COMBO_END};

combo_t key_combos[] = {
    COMBO(puq_l1_l4, DE_Z),
    COMBO(puq_l3_l6, DE_J),
    COMBO(puq_l4_l7, DE_F),
    COMBO(puq_l6_l9, DE_P),
    COMBO(puq_r1_r4, DE_X),
    COMBO(puq_r3_r6, DE_K),
    COMBO(puq_r4_r7, DE_F),
    COMBO(puq_r6_r9, DE_P),

    COMBO(neo3_l1_l4, DE_HASH),
    COMBO(neo3_l3_l6, DE_BACKQUOTE),
    COMBO(neo3_r1_r4, DE_PLUS),
    COMBO(neo3_r3_r6, DE_SEMICOLON),
    COMBO(neo3_r6_r9, DE_AMPERSAND),
};

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

// Keymaps (not much info here):
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
