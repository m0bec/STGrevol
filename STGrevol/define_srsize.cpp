#include "define_srsize.h"

int define_srsize::Read_file() {
	std::ifstream ifs("data", std::ios::binary);
	if (ifs.fail()) {
		return -1;
	}

	ifs.read(static_cast<char*>(static_cast<void*>(&read_buffer)), 4);
	
	return read_buffer;
}