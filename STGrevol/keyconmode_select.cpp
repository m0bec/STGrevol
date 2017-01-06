#include "keyconmode_select.h"

void Keyconmode_select::Getinput_param() {
	input_pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
}

void Keyconmode_select::Judgeinput_param() {
	for (int i = 0; i < 28; i++) {
		if (input_pad & (1 << i)) {
			str_input_pad[keycon_select_var] = input_pad;
			break;
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

void Keyconmode_select::Keycon_mode() {
	for (int i = 0; i < KEYCON_MENUE_NUMBER; i++) {
		switch (str_input_pad[i]) {
		case 0:
			break;

		case 1:
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:
			break;

		case 5:
			break;

		case 6:
			break;

		case 7:
			break;

		case 8:
			break;

		case 9:
			break;

		case 10:
			break;

		case 11:
			break;

		case 12:
			break;

		case 13:
			break;

		case 14:
			break;

		case 15:
			break;

		case 16:
			break;

		case 17:
			break;

		case 18:
			break;

		case 19:
			break;

		case 20:
			break;

		case 21:
			break;

		case 22:
			break;

		case 23:
			break;

		case 24:
			break;

		case 25:
			break;

		case 26:
			break;

		case 27:
			break;

		case 28:
			break;
		}
	}
}