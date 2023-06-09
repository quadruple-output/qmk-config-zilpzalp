#pragma once

// Most combos are intentionally defined for two adjacent keys of the same column, such that rolling
// key effects do not accidentally trigger a combo. This allows us to choose a rather long combo
// term, which can help if the finger does not precisely hit the gap between the keys.
#define COMBO_TERM 100 // default: 50

#define TAPPING_TERM 200 // default: 200

#define PERMISSIVE_HOLD
