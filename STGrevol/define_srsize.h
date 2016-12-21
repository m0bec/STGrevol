#pragma once
#include <iostream>
#include <fstream>
#include "DxLib.h"
#include <string>

class Define_srsize {
public:
	Define_srsize(std::string filename_);
	void Srsize();

private:
	int read_buffer;
	std::string filename;

	int Read_file();
};