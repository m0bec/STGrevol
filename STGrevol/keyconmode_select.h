#pragma once
#include "DxLib.h"
#include "base_draw_startmenue.h"
#include <array>
#define KEYCON_MODE_NUM 5	//keycon_select_var == KEYCON_MDE_NUM‚ÌŽž‚ÍExit‚ð‚³‚·

class Keyconmode_select : public Base_draw_startmenue {
public:
	using Base_draw_startmenue::Base_draw_startmenue;

	void Getinput_param();
	void Judgeinput_param();
	void Keycon_select();
	void Keycon_mode();
	
private:
	std::array<int, KEYCON_MENUE_NUMBER + 1> str_input_pad;
	int input_pad = 0;
	int keycon_select_var = 0;
};