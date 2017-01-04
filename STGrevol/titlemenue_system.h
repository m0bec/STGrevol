#pragma once
#define MAX_MENUE_NUMBER 2	//ƒƒjƒ…[‚Ì”@
#include "DxLib.h"

class Titlemenue_system {
public:
	Titlemenue_system(double *define_srsize_);
	void Select_menue();
	int select_menue_var;

private:
	double *p_define_srsize;
};