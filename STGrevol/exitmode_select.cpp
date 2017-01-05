#include "exitmode_select.h"

void Exitmode_select::Select_exit() {
	if (*menue_var == this_menue_var && (CheckHitKey(KEY_INPUT_Z) || CheckHitKey(KEY_INPUT_RETURN) || CheckHitKey(KEY_INPUT_SPACE))) {
		exit_flag = true;
	}
}

bool Exitmode_select::Exit_flag() {
	return exit_flag;
}