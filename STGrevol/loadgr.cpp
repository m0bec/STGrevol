#include "loadgr.h"

void Loadgr::Synchronizing_loadgr() {
	SetUseASyncLoadFlag(true);
	titlegr = LoadGraph("Graph/title.png");
	startgr = LoadGraph("Graph/start.png");
	exitgr = LoadGraph("Graph/exitgr.png");
	SetUseASyncLoadFlag(false);
}