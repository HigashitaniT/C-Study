/* main.cpp */

#include "DxLib.h"
#include "GlobalVariable.h"


int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	extern void img_sound_load();
	extern void initialization();
	extern void SetColor();
	extern void Background();
	extern void PlayerShotCalc();
	extern void PlayerShotDisp();
	extern void PlayerControl();
	extern void EnemyControl();
	extern void EnemyCalcDisp();
	extern void EnemyShotControl();
	extern void EnemyShotCalcDisp();
	extern void CollisionDetection();
	extern void Background2();
	extern void FpsTimeFanction();
	int RefreshTime = 0;

	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;

	SetDrawScreen(DX_SCREEN_BACK);                  //裏画面を使用する。

	img_sound_load();
	initialization();
	SetColor();

	while (ProcessMessage() == 0 && GetHitKeyStateAll(Key) == 0) {
		RefreshTime = GetNowCount();              //今の時間を取得
		ClearDrawScreen();                                        //裏画面のデータを全て削除

		Background();

		PlayerShotCalc();

		PlayerShotDisp();

		PlayerControl();

		EnemyControl();

		EnemyCalcDisp();

		EnemyShotControl();

		EnemyShotCalcDisp();

		CollisionDetection();

		Background2();

		FpsTimeFanction();

		ScreenFlip();                                            //裏画面データを表画面へ反映

		counter++;

		if (Key[KEY_INPUT_ESCAPE] == 1)    break;  //Escapeが押されたら終了
		while (GetNowCount() - RefreshTime < 17);//1周の処理が17ミリ秒になるまで待つ
	}

	DxLib_End();
	return 0;
}