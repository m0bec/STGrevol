#pragma once
#define MAX_MENUE_NUMBER 2
#include "DxLib.h"

class Titlemenue_system {
public:
	Titlemenue_system(double *define_srsize_);
	void Select_menue();

private:
	double *p_define_srsize;
	int select_menue_var;
};