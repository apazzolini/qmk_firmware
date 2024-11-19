qmk compile -kb keebio/quefrency/rev6 -km apazzolini
qmk flash -kb keebio/quefrency/rev6 -km apazzolini

DYNAMIC_TAPPING_TERM_ENABLE in the config can be enabled and then
DT_PRNT,  DT_DOWN,  DT_UP
can be added as keys to dynamically configure the tap-hold timeout.

I think that TAPPING_FORCE_HOLD was replaced by HOLD_ON_OTHER_KEY_PRESS
in newer QMK. Tap-hold seems to behave as expected on the new keyboard
when this option is set. Didn't need to mess with the tapping term timeout,
but set to 125 anyways because it seems fine.

TODO: Disable the dynamic term configuration after a week or two if everything
is still feeling good on the 125 delay.
