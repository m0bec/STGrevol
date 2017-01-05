#pragma once
#include "DxLib.h"
#include <string>

class Base_draw_startmenue {
public:

	Base_draw_startmenue(double *define_srsize_, int *gr_, int draw_x_, int draw_y_, int rota_cx_, int rota_cy_, double rota_radian_, int *menue_var_, int this_menue_var_);
	void Drawgr();

protected:
	double *p_define_srsize;
	int *p_gr;
	int draw_x;
	int draw_y;
	int rota_cx;
	int rota_cy;
	double rota_radian;
	int *menue_var;
	int this_menue_var;
};