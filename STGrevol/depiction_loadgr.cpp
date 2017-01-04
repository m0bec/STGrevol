#include "depiction_loadgr.h"

Depiction_loadgr::Depiction_loadgr(double *define_srsize_) {
	define_srsize = define_srsize_;
}

void Depiction_loadgr::Asynchronous_load() {
	SetUseASyncLoadFlag(true);
	loadgr = LoadGraph("Graph/load.png");
	titlegr = LoadGraph("Graph/title.png");
	SetUseASyncLoadFlag(false);
}

void Depiction_loadgr::Draw_loadgr() {
	if (CheckHandleASyncLoad(loadgr) == false)
	{
		DrawRotaGraph2(0, 0, 0, 0, *define_srsize, 0.0, loadgr, true, false);
		DrawGraph(0, 0, loadgr, true);
	}
}

