#pragma once
#include "DxLib.h"
#include "base_draw_startmenue.h"

class Exitmode_select : public Base_draw_startmenue {
public:
	//using Base_draw_startmenue::Base_draw_startmenue;
	Exitmode_select(double *define_srsize_, int *gr_, int draw_x_, int draw_y_, int rota_cx_, int rota_cy_, double rota_radian_, int *menue_var_, int this_menue_var_, bool *p_push_joyshot_flag_, bool *p_prev_chattering_flag_) : Base_draw_startmenue(define_srsize_, gr_, draw_x_, draw_y_, rota_cx_, rota_cy_, rota_radian_, menue_var_, this_menue_var_) {
		p_push_joyshot_flag = p_push_joyshot_flag_;
		p_prev_chattering_flag = p_prev_chattering_flag_;
		exit_flag = false;
	}
	void Select_exit();
	bool Exit_flag();
private:
	bool exit_flag;
	bool *p_push_joyshot_flag;
	bool *p_prev_chattering_flag;
};