/* initial.cpp */

#include "DxLib.h"
#include "ExternGV.h"


void initialization() {
	int i;
	Player.x = 200.0;
	Player.y = 400.0;
	Player.counter = 0;
	Player.status = 0;
	for (i = 0; i < PLAYER_MAX_SHOT_LANE; i++)
	{
		for (int j = 0; j < PLAYER_MAX_SHOT_POINT; j++)
		{
			PlayerShot[i][j].flag = 0;
		}
	}
	for (i = 0; i < ENEMY_TOTAL_NUM; i++) {
		enemy[i].flag = 0;
		EnemyShot[i].flag = 0;
		for (int j = 0; j < ENEMY_TOTAL_SHOT_NUM; j++) {
			EnemyShot[i].EnemyShots[j].flag = 0;
		}
	}
}

void SetColor() {
	color_white = GetColor(255, 255, 255);                   //”’Fƒnƒ“ƒhƒ‹‚ðŽæ“¾
}