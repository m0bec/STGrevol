#pragma once
#include "DxLib.h"

class Loadgr {
public:
	Loadgr();
	int Titlegr() { return titlegr; }
	int Startgr() { return startgr; }
	int Exitgr() { return exitgr; }

private:
	int titlegr;
	int startgr;
	int exitgr;
};