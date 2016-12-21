#pragma once
#include <iostream>
#include <fstream>
#include "DxLib.h"
#include <string>

class Define_srsize {
public:
	Define_srsize(std::string filename_);
	void Srsize();
	double Get_enlargement_factor();

private:
	int read_buffer;
	double enlargement_factor;
	std::string filename;

	int Read_file();
};