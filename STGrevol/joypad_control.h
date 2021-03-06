#pragma once
#include "DxLib.h"
#include <fstream>
#include <iostream>
#include <string>
#define BUTTON_NUM 5

class Joypad_control {
public:
	Joypad_control(std::string filename_);
	void Get_keyconfig();	//keyconfigの直後に使用する
	void Check_allkey();
	void Prev_chattering();
	
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

	bool prev_chattering_flag;
	bool shot_keep_flag;

private:
	std::string filename;
	void Check_key(int button_, bool *flag_);
	void Check_key_prev_chattering(int button_, bool *flag_, bool *keep_flag_);
	
	int str_button_bin[BUTTON_NUM];
	
};