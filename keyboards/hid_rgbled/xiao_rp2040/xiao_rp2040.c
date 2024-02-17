#include "quantum.h"

void keyboard_pre_init_kb(void) {
    // power up rgbled
    setPinOutput(GP11);
    writePinHigh(GP11);

    keyboard_pre_init_user();
}
