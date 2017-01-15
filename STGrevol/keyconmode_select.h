#pragma once
#include "DxLib.h"
#include "base_draw_startmenue.h"
#include <array>
#define KEYCON_MODE_NUM 5	//keycon_select_var == KEYCON_MDE_NUMの時はExitをさす
#define KEYCON_MODE_DRAW_X 220
#define KEYCON_MODE_DRAW_Y 100
#define KEYCON_MDDE_MOVE_DIST 100

class Keyconmode_select : public Base_draw_startmenue {
public:
	Keyconmode_select(bool *p_push_joydown_flag_, int *p_system_var_, double *define_srsize_, int *gr_, int draw_x_, int draw_y_, int rota_cx_, int rota_cy_, double rota_radian_, int *menue_var_, int this_menue_var_, int *keycon_numgr_, int *keycon_exitgr_, int *keycon_backgr_, bool *p_push_joyshot_flag_, bool *p_longpush_joyshot_flag_, bool *p_push_joyup_flag_, bool *p_prev_chattering_flag_) : Base_draw_startmenue(define_srsize_, gr_, draw_x_,  draw_y_,  rota_cx_,  rota_cy_,  rota_radian_,  menue_var_,  this_menue_var_) {
		keycon_numgr = keycon_numgr_;
		keycon_exitgr = keycon_exitgr_;
		p_system_var = p_system_var_;
		p_push_joyshot_flag = p_push_joyshot_flag_;
		p_longpush_joyshot_flag = p_longpush_joyshot_flag_;
		keycon_backgr = keycon_backgr_;
		p_push_joyup_flag = p_push_joyup_flag_;
		p_push_joydown_flag = p_push_joydown_flag_;
		input_pad = 0;
		keycon_select_var = 0;
		input_flag = false;
		p_prev_chattering_flag = p_prev_chattering_flag_;
	}
	void Initialization();
	//void Check_chattering();
	void Change_to_keyconmode();
	void Getinput_param();
	void Judgeinput_param();
	void Check_push_bottan();
	void Keycon_select();
	void Keycon_mode();
	void Exit();

	void Run_title();
	void Run();
	
private:
	std::array<int, KEYCON_MODE_NUM + 1> str_input_pad;
	std::array<int, KEYCON_MODE_NUM + 1> str_directinput_pad;
	int input_pad;
	int str_keyinput;
	int keycon_select_var;
	int input_flag;
	bool *p_prev_chattering_flag;
	int *keycon_numgr;
	int *keycon_exitgr;
	int *keycon_backgr;
	int *p_system_var;
	bool *p_push_joyshot_flag;
	bool *p_longpush_joyshot_flag;
	bool *p_push_joyup_flag;
	bool *p_push_joydown_flag;
};