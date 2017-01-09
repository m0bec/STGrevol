#include "main.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	define_srsize.Srsize();

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) return -1;

	depiction_loadgr.Asynchronous_load();
	loadgr.Synchronizing_loadgr();

	// グラフィックの描画先を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	while (1) {
		// 画面を初期化(真っ黒にする)
		ClearDrawScreen();

		if (GetASyncLoadNum() != 0) {
			depiction_loadgr.Draw_loadgr();
		}
		else {
			joypad_control.Check_allkey();
			titlemenue_system.Run();
			title.Drawgr();
			startmode_select.Drawgr();
			exitmode_select.Drawgr();
			manualmode_select.Drawgr();
			keyconmode_select.Drawgr();

			exitmode_select.Select_exit();
		}

		// 裏画面の内容を表画面にコピーする
		ScreenFlip();

		// Windows 特有の面倒な処理をＤＸライブラリにやらせる
		// -1 が返ってきたらループを抜ける
		if (ProcessMessage() < 0) break;

		// もしＥＳＣキーが押されていたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) || exitmode_select.Exit_flag()) break;
	}

	DxLib_End();
	return 0;
}