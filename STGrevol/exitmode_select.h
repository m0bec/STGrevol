#pragma once
#include "DxLib.h"
#include "base_draw_startmenue.h"

class Exitmode_select : public Base_draw_startmenue {
public:
	using Base_draw_startmenue::Base_draw_startmenue;
	void Select_exit();
	bool Exit_flag();
private:
	bool exit_flag = false;
};