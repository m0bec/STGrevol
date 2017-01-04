#include "titlemenue_system.h"

Titlemenue_system::Titlemenue_system(double *define_srsize_) {
	p_define_srsize = define_srsize_;
	select_menue_var = 0;
}

void Titlemenue_system::Select_menue() {
	if (CheckHitKey(KEY_INPUT_UP)) {
		select_menue_var--;
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		select_menue_var++;
	}

	if (select_menue_var < 0) {
		select_menue_var = MAX_MENUE_NUMBER - 1;
	}
	else if (select_menue_var > MAX_MENUE_NUMBER - 1) {
		select_menue_var = 0;
	}
}