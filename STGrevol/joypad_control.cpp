#include "joypad_control.h"

Joypad_control::Joypad_control(std::string filename_) {
	filename = filename_;
	std::basic_ifstream<int> ifs(filename, std::ios_base::binary);
	//std::ifstream ifs(filename, std::ios_base::binary);
	try {
		if (ifs.fail()) {
			throw 99;
		}
		ifs.read(&button_shot, 1);
		ifs.read(&button_bomb, 1);
		ifs.read(&button_slow, 1);
		ifs.read(&button_rightturn, 1);
		ifs.read(&button_leftturn, 1);
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
		std::basic_ofstream<int> ofs(filename, std::ios_base::binary | std::ios_base::trunc);
		ofs.write(&button_shot, 1);
		ofs.write(&button_bomb, 1);
		ofs.write(&button_slow, 1);
		ofs.write(&button_rightturn, 1);
		ofs.write(&button_leftturn, 1);
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