#include "keyconmode_select.h"

void Keyconmode_select::Getinput_param() {
	input_pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
}

int Keyconmode_select::Judgeinput_param() {
	for (int i = 0; i < 28; i++) {
		if (input_pad & (1 << i)) {
			return i;
		}
	}
}

void Keyconmode_select::Keycon_select() {
	if ((input_pad & PAD_INPUT_DOWN) == 1) {
		keycon_select_var++;
	}
	else if ((input_pad & PAD_INPUT_UP) == 1) {
		keycon_select_var--;
	}

	if (keycon_select_var < 0) {
		keycon_select_var = 0;
	}
	else if (keycon_select_var > KEYCON_MODE_NUM) {
		keycon_select_var = KEYCON_MODE_NUM;
	}
}