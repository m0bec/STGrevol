#pragma once
#include "DxLib.h"
#include "base_draw_startmenue.h"
#define KEYCON_MODE_NUM 5

class Keyconmode_select : public Base_draw_startmenue {
public:
	using Base_draw_startmenue::Base_draw_startmenue;

	void Getinput_param();
	int Judgeinput_param();
	void Keycon_select();
private:
	int input_pad = 0;
	int keycon_select_var = 0;
};