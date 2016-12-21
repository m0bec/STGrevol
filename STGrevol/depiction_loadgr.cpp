#include "depicyion_loadgr.h"

void Depiction_loadgr::Asynchronous_load() {
	SetUseASyncLoadFlag(true);
	loadgr = LoadGraph("Graph/load.png");
	titlegr = LoadGraph("Graph/title.png");
	SetUseASyncLoadFlag(false);
}

void Depiction_loadgr::Draw_loadgr() {
	if (CheckHandleASyncLoad(loadgr) == false)
	{
		DrawGraph(0, 0, loadgr, true);
	}
}

