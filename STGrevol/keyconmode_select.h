#pragma once
#include "DxLib.h"
#include "base_draw_startmenue.h"

class Keyconmode_select : public Base_draw_startmenue {
public:
	using Base_draw_startmenue::Base_draw_startmenue;

	int Getinput_param();
private:
	int input_pad;
};