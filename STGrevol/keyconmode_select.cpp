#include "keyconmode_select.h"

int Keyconmode_select::Getinput_param() {
	input_pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	for (int i = 0; i < 28; i++) {
		if (input_pad & (1 << i)) {
			return i;
		}
	}
}