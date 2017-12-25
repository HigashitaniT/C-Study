/* enemy.cpp */
#include "DxLib.h"
#include "ExternGV.h"
#include <math.h>
#define PI 3.141593
/*
void EnemyPattern1(int i){
enemy[i].y+=1.5f;
}
*/
void EnemyPattern2(int i) {//前章で説明した通り
	int j;
	if (enemy[i].counter<50)
		enemy[i].y += 4.0f;

	if (enemy[i].counter == 75) {
		for (j = 0; j<ENEMY_TOTAL_NUM; j++)
			if (EnemyShot[j].flag == 0)
				break;
		EnemyShot[j].mem_ex = enemy[i].x;
		EnemyShot[j].mem_ey = enemy[i].y;
		EnemyShot[j].mem_px = Player.x;
		EnemyShot[j].mem_py = Player.y;
		EnemyShot[j].counter = 0;
		EnemyShot[j].flag = 1;
		EnemyShot[j].pattern = 1;
		EnemyShot[j].img = 0;
	}

	if (enemy[i].counter>100)
		enemy[i].y -= 4.0f;
}
/*
void EnemyPattern3(int i){
enemy[i].x+=sin(PI*enemy[i].counter/40.0f)*5.0f;
enemy[i].y+=1.5f;
}
void EnemyPattern4(int i){
if(enemy[i].counter<100)
enemy[i].y+=2.5f;
if(enemy[i].counter>=100){
enemy[i].x+=sin(PI*(enemy[i].counter-100.0f)/160.0f)*2.5f;
enemy[i].y+=sin(PI*(enemy[i].counter-20.0f )/160.0f)*2.5f;
}
}
*/
void EnemyControl() {//現在はパターン２の動きだけさせる
	for (int i = 0; i<100; i++) {
		if (enemy[i].flag == 1) {
			//                      if(enemy[i].pattern==1)
			//                              EnemyPattern1(i);
			if (enemy[i].pattern == 2)
				EnemyPattern2(i);
			//                      if(enemy[i].pattern==3)
			//                              EnemyPattern3(i);
			//                      if(enemy[i].pattern==4)
			//                              EnemyPattern4(i);
		}
	}
}

void EnemyCalcDisp() {
	int i;
	for (i = 0; i<100; i++)
		if (enemy[i].flag == 0)
			break;
	switch (counter) {//今回はパターン２の動きだけさせる
	case 50:
		enemy[i].pattern = 2; //どういう軌道を描くか
		enemy[i].flag = 1;   //出現フラグを立てる
		enemy[i].counter = 0;//出現して何カウント目か測るカウンター初期化
		enemy[i].size = 0.5f;//敵の大きさ
		enemy[i].range = (MONSTER_X_SIZE - 60) / 2.0f*enemy[i].size;
		enemy[i].x = 100.0;  //ｘの初期座標
		enemy[i].y = -10.0;  //ｙの初期座標
		break;
	default:
		break;
	}

	int enemy_img[8] = { 0,1,2,3,4,3,2,1 };
	for (i = 0; i<100; i++) {
		if (enemy[i].flag == 1) {
			enemy[i].counter++;
			DrawRotaGraph((int)enemy[i].x, (int)enemy[i].y, enemy[i].size, 0.0f, img_enemy[enemy_img[counter % 32 / 4]], TRUE);
			if (enemy[i].x<0.0 - MONSTER_X_SIZE / 2.0*enemy[i].size || enemy[i].x>420.0 + MONSTER_X_SIZE / 2.0*enemy[i].size ||
				enemy[i].y<0.0 - MONSTER_Y_SIZE / 2.0*enemy[i].size || enemy[i].y<0.0 - MONSTER_Y_SIZE / 2.0*enemy[i].size)
				enemy[i].flag = 0;
		}
	}
}