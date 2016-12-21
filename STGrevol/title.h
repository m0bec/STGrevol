#pragma once
#include "DXLib.h"

class Title {
public:
	Title(double *define_srsize_, int *titlegr_);
	void Control();
private:
	void Drawtitle();
	double *define_srsize;
	int *titlegr;
};