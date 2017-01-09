#pragma once
#include "DxLib.h"
#include "define_startmenue.h"

class Titlemenue_system {
public:
	Titlemenue_system(double *define_srsize_, bool *p_push_joyup_flag_, bool *p_push_joydown_flag_, bool *p_push_joyshot_flag_);
	void Check_push_bottan();
	void Select_menue();
	void Run();

	int select_menue_var;

private:
	double *p_define_srsize;
	bool push_bottan_flag;
	bool *p_push_joyup_flag;
	bool *p_push_joydown_flag;
	bool *p_push_joyshot_flag;
};