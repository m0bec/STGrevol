#pragma once
#include "DxLib.h"
#include <fstream>

class Joypad_control {
public:
	Joypad_control();
	void Get_keyconfig();

	int button_shot;
	int button_bomb;
	int button_slow;
	int button_rightturn;
	int button_leftturn;
};