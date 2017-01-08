#pragma once
#include "DxLib.h"
#include <fstream>
#include <iostream>
#include <string>
#define BUTTON_NUM 5

class Joypad_control {
public:
	Joypad_control(std::string filename_);
	void Get_keyconfig();
	
	int button_shot;
	int button_bomb;
	int button_slow;
	int button_rightturn;
	int button_leftturn;

private:
	std::string filename;
	int str_button_bin[BUTTON_NUM];
};