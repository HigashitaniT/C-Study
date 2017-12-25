/* fps.cpp */

#include "DxLib.h"
#include "ExternGV.h"


void FpsTimeFanction() {
	static int FpsTime[2] = { 0, }, FpsTime_i = 0;
	static double Fps = 0.0;

	if (FpsTime_i == 0)
		FpsTime[0] = GetNowCount();                           //1周目の時間取得
	if (FpsTime_i == 49) {
		FpsTime[1] = GetNowCount();                           //50周目の時間取得
		Fps = 1000.0f / ((FpsTime[1] - FpsTime[0]) / 50.0f);//測定した値からfpsを計算
		FpsTime_i = 0;
	}
	else
		FpsTime_i++;                                          //現在何周目かカウント
	if (Fps != 0)
		DrawFormatString(565, 460, color_white, "FPS %.1f", Fps); //fpsを表示
	return;
}