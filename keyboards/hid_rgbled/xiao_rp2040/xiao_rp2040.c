#include "quantum.h"

void keyboard_post_init_kb(void) {
    // power up rgbled
    setPinOutput(GP11);
    writePinHigh(GP11);

    keyboard_post_init_user();
}
