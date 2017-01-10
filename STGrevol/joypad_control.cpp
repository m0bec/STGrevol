#include "joypad_control.h"

Joypad_control::Joypad_control(std::string filename_) {
	filename = filename_;
	std::ifstream ifs(filename, std::ios_base::binary);
	try {
		if (ifs.fail()) {
			throw 99;
		}
		ifs.read(static_cast<char*>(static_cast<void*>(&button_shot)), sizeof(int));
		ifs.read(static_cast<char*>(static_cast<void*>(&button_bomb)), sizeof(int));
		ifs.read(static_cast<char*>(static_cast<void*>(&button_slow)), sizeof(int));
		ifs.read(static_cast<char*>(static_cast<void*>(&button_rightturn)), sizeof(int));
		ifs.read(static_cast<char*>(static_cast<void*>(&button_leftturn)), sizeof(int));
		shot_flag = false;
		bomb_flag = false;
		slow_flag = false;
		rightturn_flag = false;
		leftturn_flag = false;
		upkey_flag = false;
		downkey_flag = false;
		rightkey_flag = false;
		leftkey_flag = false;
	}
	catch (int error) {
		std::cerr << "error " << error << std::endl;
		ifs.close();
		button_shot = PAD_INPUT_1;
		button_bomb = PAD_INPUT_2;
		button_slow = PAD_INPUT_3;
	    button_rightturn = PAD_INPUT_4;
		button_leftturn = PAD_INPUT_5;
		std::ofstream ofs(filename, std::ios_base::binary | std::ios_base::trunc);
		ofs.write(static_cast<char*>(static_cast<void*>(&button_shot)), sizeof(button_shot));
		ofs.write(static_cast<char*>(static_cast<void*>(&button_bomb)), sizeof(button_bomb));
		ofs.write(static_cast<char*>(static_cast<void*>(&button_slow)), sizeof(button_slow));
		ofs.write(static_cast<char*>(static_cast<void*>(&button_rightturn)), sizeof(button_rightturn));
		ofs.write(static_cast<char*>(static_cast<void*>(&button_leftturn)), sizeof(button_leftturn));
		std::exit(1);
	}
}

void Joypad_control::Get_keyconfig() {
	std::ifstream ifs(filename, std::ios_base::binary);
	try {
		if (ifs.fail()) {
			throw 99;
		}
		ifs.read(reinterpret_cast<char*>(str_button_bin), BUTTON_NUM * sizeof(int));
		button_shot = str_button_bin[0];
		button_bomb = str_button_bin[1];
		button_slow = str_button_bin[2];
		button_rightturn = str_button_bin[3];
		button_leftturn = str_button_bin[4];
	}
	catch (int error) {
		std::cerr << "error keyconfig‚ª‚È‚¢@" << error << std::endl;
		std::exit(1);
	}
}

void Joypad_control::Check_key(int button_, bool *flag_) {
	if ((GetJoypadInputState(DX_INPUT_PAD1) & button_) == button_) {
		*flag_ = true;
	}
	else {
		*flag_ = false;
	}
}

void Joypad_control::Check_allkey() {
	Check_key(button_shot, &shot_flag);
	Check_key(button_bomb, &bomb_flag);
	Check_key(button_slow, &slow_flag);
	Check_key(button_rightturn, &rightturn_flag);
	Check_key(button_leftturn, &leftturn_flag);
	Check_key(PAD_INPUT_UP, &upkey_flag);
	Check_key(PAD_INPUT_DOWN, &downkey_flag);
	Check_key(PAD_INPUT_RIGHT, &rightkey_flag);
	Check_key(PAD_INPUT_LEFT, &leftkey_flag);
}