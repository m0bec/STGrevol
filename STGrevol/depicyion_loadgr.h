#pragma once
#include "DXLib.h"

class Depiction_loadgr {
public:
	int titlegr;

	Depiction_loadgr(double *define_srsize_);
	void Draw_loadgr();
	void Asynchronous_load();
	
private:
	double *define_srsize;
	int loadgr;
};