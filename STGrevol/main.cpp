#include "main.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	define_srsize.Srsize();

	// �c�w���C�u��������������
	if (DxLib_Init() == -1) return -1;

	depiction_loadgr.Asynchronous_load();
	loadgr.Synchronizing_loadgr();

	// �O���t�B�b�N�̕`���𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);

	while (1) {
		// ��ʂ�������(�^�����ɂ���)
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

		// ����ʂ̓��e��\��ʂɃR�s�[����
		ScreenFlip();

		// Windows ���L�̖ʓ|�ȏ������c�w���C�u�����ɂ�点��
		// -1 ���Ԃ��Ă����烋�[�v�𔲂���
		if (ProcessMessage() < 0) break;

		// �����d�r�b�L�[��������Ă����烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) || exitmode_select.Exit_flag()) break;
	}

	DxLib_End();
	return 0;
}