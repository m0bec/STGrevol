#include "titlemenue_system.h"

Titlemenue_system::Titlemenue_system(double *define_srsize_, bool *p_push_joyup_flag_, bool *p_push_joydown_flag_, bool *p_push_joyshot_flag_) {
	p_define_srsize = define_srsize_;
	select_menue_var = 0;
	push_bottan_flag = false;
	p_push_joyup_flag = p_push_joyup_flag_;
	p_push_joydown_flag = p_push_joydown_flag_;
	p_push_joyshot_flag = p_push_joyshot_flag_;
}

void Titlemenue_system::Check_push_bottan() {
	if (CheckHitKey(KEY_INPUT_UP) == 0 && CheckHitKey(KEY_INPUT_DOWN) == 0 && *p_push_joyup_flag == false && *p_push_joydown_flag == false) {
		push_bottan_flag = false;
	}
}

void Titlemenue_system::Select_menue() {
	if ((CheckHitKey(KEY_INPUT_UP) || *p_push_joyup_flag) && push_bottan_flag == false) {
		select_menue_var--;
		push_bottan_flag = true;
	}
	if ((CheckHitKey(KEY_INPUT_DOWN) || *p_push_joydown_flag) && push_bottan_flag == false) {
		select_menue_var++;
		push_bottan_flag = true;
	}

	if (select_menue_var < 0) {
		select_menue_var = MAX_MENUE_NUMBER - 1;
	}
	else if (select_menue_var > MAX_MENUE_NUMBER - 1) {
		select_menue_var = 0;
	}
}

void Titlemenue_system::Run() {
	Check_push_bottan();
	Select_menue();
}