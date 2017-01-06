#include "loadgr.h"

void Loadgr::Synchronizing_loadgr() {
	SetUseASyncLoadFlag(true);
	titlegr = LoadGraph("Graph/title.png");
	startgr = LoadGraph("Graph/start.png");
	exitgr = LoadGraph("Graph/exit.png");
	keycongr = LoadGraph("Graph/keyconfig.png");
	manualgr = LoadGraph("Graph/manual.png");
	keycon_num = LoadGraph("Graph/keycon_num");
	SetUseASyncLoadFlag(false);
}