#pragma once

// Most combos are intentionally defined for two adjacent keys of the same column, such that rolling
// key effects do not accidentally trigger a combo. This allows us to choose a rather long combo
// term, which can help if the finger does not precisely hit the gap between the keys.
#define COMBO_TERM 100 // default: 50
#define COMBO_TERM_PER_COMBO // required for homerow-combos
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_MUST_HOLD_PER_COMBO

#define TAPPING_TERM 200 // default: 200
// #define RETRO_TAPPING

#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

