/* player.cpp */

#include "DxLib.h"
#include "ExternGV.h"
#include <math.h>

void PlayerControl() {
	if (Key[KEY_INPUT_LEFT] == 1)
	{
		Player.x -= 4.0f;
		if (Player.x < 0)
		{
			Player.x = 0;
		}
	}
	if (Key[KEY_INPUT_RIGHT] == 1)
	{
		Player.x += 4.0f;
		if (Player.x > 385.0)
		{
			Player.x = 385.0;
		}
	}
	if (Key[KEY_INPUT_UP])
	{
		Player.y -= 4.0f;
		if (Player.y < 15.0)
		{
			Player.y = 15.0f;
		}
	}
	if (Key[KEY_INPUT_DOWN] == 1)
	{
		Player.y += 4.0f;
		if (Player.y > 435.0)
		{
			Player.y = 435.0;
		}
	}

	DrawGraph((int)Player.x, (int)Player.y, img_player[0], TRUE);
}

void PlayerShotCalc() {
	int i, j;
	int positionx[11] = { 0,-10,10,-10,10,-15,15,-10,10,-10,10 },
		positiony[11] = { -15,-2,-2,6,6,-6,-6,2,2,10,10 };
	if (Key[KEY_INPUT_Z] == 1 && counter % 5 == 0) {
		for(i = 0; i < ShotLevel; i++){
			for (j = 0; j < PLAYER_MAX_SHOT_POINT; j++) {
				if (PlayerShot[i][j].flag == 0) {
					PlayerShot[i][j].flag = 1;
					PlayerShot[i][j].x = (Player.x + 16) + (double)positionx[i];
					PlayerShot[i][j].y = Player.y + (double)positiony[i];
					if (CheckSoundMem(sound_player_shot[0]) == 0)
						PlaySoundMem(sound_player_shot[0], DX_PLAYTYPE_BACK);
					break;
				}
			}
		}
	}
	int sab[11] = { 0,-1,1,-3,3,0,0,-2,2,-5,5 };
	for (i = 0; i < PLAYER_MAX_SHOT_LANE; i++){
		for (j = 0; j < PLAYER_MAX_SHOT_POINT; j++) {
			if (PlayerShot[i][j].flag == 1) {
				PlayerShot[i][j].x += (double)sab[i];
				PlayerShot[i][j].y -= 10.0;
				if (PlayerShot[i][j].y < -20)
					PlayerShot[i][j].flag = 0;
			}
		}
	}
}

void PlayerShotDisp() {
	int i, j;
	for (i = 0; i < PLAYER_MAX_SHOT_LANE; i++){
		for (j = 0; j < PLAYER_MAX_SHOT_POINT; j++) {
			if (PlayerShot[i][j].flag == 1) {
				switch (i) {
				case 0:
				case 5:
				case 6:
					DrawGraph((int)PlayerShot[i][j].x - 10, (int)PlayerShot[i][j].y - 18, img_player_shot[0], TRUE);
					break;
				default:
					DrawGraph((int)PlayerShot[i][j].x - 8, (int)PlayerShot[i][j].y - 10, img_player_shot[1], TRUE);
					break;
				}
			}
		}
	}
}

void CollisionDetection() {
	for (int i = 0; i < PLAYER_MAX_SHOT_LANE; i++) {
		for(int j = 0; j < PLAYER_MAX_SHOT_POINT; j++) {
			if (PlayerShot[i][j].flag == 1) {
				for (int s = 0; s < ENEMY_TOTAL_NUM; s++) {
					if (enemy[s].flag == 1) {
						double x, y;
						int range;
						x = (int)(PlayerShot[i][j].x - enemy[s].x);
						y = (int)(PlayerShot[i][j].y - enemy[s].y);
						switch (i)
						{
						case 0:
						case 5:
						case 6:
							range = 12;
							break;
						default:
							range = 9;
							break;
						}
						if ((int)sqrt(x*x + y * y) < range + enemy[s].range) {
							enemy[s].flag = 0;
							PlayerShot[i][j].flag = 0;
							if (CheckSoundMem(sound_enemy_death) == 1) {
								StopSoundMem(sound_enemy_death);
							}
							PlaySoundMem(sound_enemy_death, DX_PLAYTYPE_BACK);
						}
					}
				}
			}
		}
	}
}