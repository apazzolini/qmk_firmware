qmk compile -kb keebio/quefrency/rev6 -km apazzolini
qmk flash -kb keebio/quefrency/rev6 -km apazzolini

qmk compile -kb keebio/quefrency/rev5 -km apazzolini
qmk flash -kb keebio/quefrency/rev5 -km apazzolini

# 2026-07-27

Updated for deskhop. Flashed both rev5 and rev6 keyboards.
Committed version is for rev6 board.

# 2026-06-10

The rev5 board's encoder is in reverse from the rev6 one (bought on Amazon).
Flashing with the reversed mapping, but not committing that change - will
keep the authoritative mapping the rev6 mapping.

# 2026-05-18

Updated onto upstream/master, flashed to replacement rev6 left side board.
Also flashed right side board for consistency. I think everything is working.

Also flashed both rev5 boards with the same keymap but haven't fully tested
the advanced / custom features.

qmk compile -kb keebio/quefrency/rev5 -km apazzolini
qmk flash -kb keebio/quefrency/rev5 -km apazzolini

# Old - I did the TODO below on 2026/03/04

DYNAMIC_TAPPING_TERM_ENABLE in the config can be enabled and then
DT_PRNT, DT_DOWN, DT_UP
can be added as keys to dynamically configure the tap-hold timeout.

I think that TAPPING_FORCE_HOLD was replaced by HOLD_ON_OTHER_KEY_PRESS
in newer QMK. Tap-hold seems to behave as expected on the new keyboard
when this option is set. Didn't need to mess with the tapping term timeout,
but set to 125 anyways because it seems fine.

TODO: Disable the dynamic term configuration after a week or two if everything
is still feeling good on the 125 delay.
