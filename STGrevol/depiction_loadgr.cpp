#include "depicyion_loadgr.h"

void Depiction_loadgr::Asynchronous_load() {
	SetUseASyncLoadFlag(true);
	loadgr = LoadGraph("Graph/load.png");
	SetUseASyncLoadFlag(false);
}

void Depiction_loadgr::Draw_loadgr() {
	Asynchronous_load();
	if (CheckHandleASyncLoad(loadgr) == false)
	{
		DrawGraph(0, 0, loadgr, true);
	}
}