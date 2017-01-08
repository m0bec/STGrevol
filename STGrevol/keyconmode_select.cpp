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
	for (int i = 0; i < KEYCON_MODE_NUM + 1; i++) {
		if (i < KEYCON_MODE_NUM) {
			if (keycon_select_var == i) {
				DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 100 * str_input_pad[i], 0, 100, 100, *keycon_numgr, true, false);
			}
			else {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
				DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 100 * str_input_pad[i], 0, 100, 100, *keycon_numgr, true, false);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
		}
		else {
			if (keycon_select_var == i) {
				DrawGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, *keycon_exitgr, true);
			}
			else {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
				DrawGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, *keycon_exitgr, true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
		}
		
		/*switch (str_input_pad[i]) {
		case 0:
			DrawRectGraph(KEYCON_MODE_DRAW_X , KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 1:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 100, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 2:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 200, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 3:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 300, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 4:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 400, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 5:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 6:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 7:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 8:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 9:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 10:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 11:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 12:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 13:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 14:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 15:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 16:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 17:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 18:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 19:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 20:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 21:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 22:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 23:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 24:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 25:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 26:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 27:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;

		case 28:
			DrawRectGraph(KEYCON_MODE_DRAW_X, KEYCON_MODE_DRAW_Y + KEYCON_MDDE_MOVE_DIST * i, 0, 0, 100, 100, *keycon_numgr, true, false);
			break;
		}*/
	}
}

void Keyconmode_select::Exit() {
	if (keycon_select_var == KEYCON_MODE_NUM) {
		
	}
}

void Keyconmode_select::Run() {
	Getinput_param();
	Judgeinput_param();
	Keycon_select();
	Keycon_mode();
}