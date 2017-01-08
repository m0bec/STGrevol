#pragma once
#include "DxLib.h"
#include <fstream>
#include <iostream>
#include <string>
#define BUTTON_NUM 5

class Joypad_control {
public:
	Joypad_control(std::string filename_);
	void Get_keyconfig();	//keyconfig‚Ì’¼Œã‚ÉŽg—p‚·‚é
	void Check_button_shot();
	void Check_button_bomb();
	void Check_button_slow();
	void Check_button_rightturn();
	void Check_button_leftturn();
	void Check_up_key();
	void Check_down_key();
	void Check_right_key();
	void Check_left_key();
	void Check_key();

	int button_shot;
	int button_bomb;
	int button_slow;
	int button_rightturn;
	int button_leftturn;

	bool shot_flag;
	bool bomb_flag;
	bool slow_flag;
	bool rightturn_flag;
	bool leftturn_flag;
	bool upkey_flag;
	bool downkey_flag;
	bool rightkey_flag;
	bool leftkey_flag;

private:
	std::string filename;
	int str_button_bin[BUTTON_NUM];
	
};