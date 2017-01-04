#pragma once
#include "DxLib.h"

class Loadgr {
public:
	Loadgr();
	int titlegr();
	int startgr();
	int exitgr();

private:
	int titlegr;
	int startgr;
	int exitgr;
};