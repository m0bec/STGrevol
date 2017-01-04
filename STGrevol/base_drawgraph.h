#pragma once
#include "DxLib.h"
#include <string>

class Base_drawgraph {
public:

	Base_drawgraph(double *define_srsize_, int *gr_);
private:
	double *define_srsize;
	int *gr;

	void Drawgr();
};