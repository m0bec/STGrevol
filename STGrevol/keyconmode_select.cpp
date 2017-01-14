#include "keyconmode_select.h"

void Keyconmode_select::Change_to_keyconmode() {
	if (*menue_var == this_menue_var && (CheckHitKey(KEY_INPUT_Z) || CheckHitKey(KEY_INPUT_RETURN) || CheckHitKey(KEY_INPUT_SPACE) || *p_push_joyshot_flag == true)) {
		*p_system_var = 1;
		Initialization();
	}
}

void Keyconmode_select::Initialization() {
	keycon_select_var = 0;
	input_flag = false;
}

void Keyconmode_select::Getinput_param() {
	input_pad = GetJoypadInputState(DX_INPUT_PAD1);
}

void Keyconmode_select::Judgeinput_param() {
	for (int i = 4; i < 32; i++) {
		if ((input_pad & (1 << i)) != 0) {
			str_directinput_pad[keycon_select_var] = input_pad;
			str_input_pad[keycon_select_var] = i;
			break;
		}
	}
}

void Keyconmode_select::Check_push_bottan() {
	if (CheckHitKey(KEY_INPUT_UP) == 0 && CheckHitKey(KEY_INPUT_DOWN) == 0 && *p_push_joyup_flag == false && *p_push_joydown_flag == false) {
		input_flag = false;
	}
}

void Keyconmode_select::Keycon_select() {
	if ((CheckHitKey(KEY_INPUT_DOWN) || *p_push_joydown_flag) && input_flag == false) {
		keycon_select_var++;
		input_flag = true;
	}
	if ((CheckHitKey(KEY_INPUT_UP) || *p_push_joyup_flag) && input_flag == false) {
		keycon_select_var--;
		input_flag = true;
	}

	if (keycon_select_var < 0) {
		keycon_select_var = KEYCON_MODE_NUM;
	}
	else if (keycon_select_var > KEYCON_MODE_NUM) {
		keycon_select_var = 0;
	}
}

void Keyconmode_select::Keycon_mode() {
	DrawRotaGraph2(0, 0, 0, 0, *p_define_srsize, 0, *keycon_backgr, true, false);
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
	}
}

void Keyconmode_select::Exit() {
	if (keycon_select_var == KEYCON_MODE_NUM && (CheckHitKey(KEY_INPUT_Z) || CheckHitKey(KEY_INPUT_RETURN) || CheckHitKey(KEY_INPUT_SPACE) || *p_push_joyshot_flag == true)) {
		*p_system_var = 0;
	}
}

void Keyconmode_select::Run() {
	Getinput_param();
	Judgeinput_param();
	Keycon_select();
	Exit();
	Keycon_mode();
	Check_push_bottan();
}