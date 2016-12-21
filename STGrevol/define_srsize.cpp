#include "define_srsize.h"

Define_srsize::Define_srsize(std::string filename_) {
	filename = filename_;
}

int Define_srsize::Read_file() {
	std::ifstream ifs(filename, std::ios::binary);
	if (ifs.fail()) {
		std::cerr << filename << " is noy found!" << std::endl;
		std:: exit(1);
	}

	ifs.read(static_cast<char*>(static_cast<void*>(&read_buffer)), 4);
	
	if (read_buffer % 10 > 0 && read_buffer % 10 < 4 && read_buffer - 10 > -10 && read_buffer - 10 < 4) {
		return read_buffer;
	}
	else {
		std::cerr << filename << " is abnormality" << std::endl;
		std::exit(1);
	}
}

void Define_srsize::Srsize() {
	int define_srsize_prm = Read_file();

	if (define_srsize_prm - 10 > 0) {
		ChangeWindowMode(false);
	}
	else {
		ChangeWindowMode(true);
	}

	if (define_srsize_prm % 10 == 1) {
		SetGraphMode(640, 480, 16);
		enlargement_factor = 1.0;
	}
	else if (define_srsize_prm % 10 == 2) {
		SetGraphMode(960, 720, 16);
		enlargement_factor = 1.5;
	}
	else if (define_srsize_prm % 10 == 3) {
		SetGraphMode(1280, 960, 16);
		enlargement_factor = 2.0;
	}
}

double Define_srsize::Get_enlargement_factor() {
	return Get_enlargement_factor();
}