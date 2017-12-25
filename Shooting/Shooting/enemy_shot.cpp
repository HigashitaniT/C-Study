/* enemy_shot.cpp */
/* 素材 ver 1.11以上必要 */
#include "DxLib.h"
#include "ExternGV.h"
#include <math.h>
#define PI 3.141593
#define PATTERN1SPEED 4.0f


void EnemyShotPattern1(int i) {
	if (EnemyShot[i].counter == 0) {
		EnemyShot[i].EnemyShots[0].flag = 1;
		EnemyShot[i].EnemyShots[0].x = EnemyShot[i].mem_ex;
		EnemyShot[i].EnemyShots[0].y = EnemyShot[i].mem_ey;
		EnemyShot[i].Angle[0] = atan2(EnemyShot[i].mem_py - EnemyShot[i].mem_ey, EnemyShot[i].mem_px - EnemyShot[i].mem_ex);
		PlaySoundMem(sound_enemy_shot[0], DX_PLAYTYPE_BACK);
	}
	EnemyShot[i].EnemyShots[0].x += PATTERN1SPEED * cos(EnemyShot[i].Angle[0]);
	EnemyShot[i].EnemyShots[0].y += PATTERN1SPEED * sin(EnemyShot[i].Angle[0]);
}

void EnemyShotControl() {//ショットパターン１を呼ぶための関数enemy.cppのEnemyControl関数と役目一緒
	int i;
	for (i = 0; i<ENEMY_TOTAL_NUM; i++) {//敵の最大数100体だけループ
		if (EnemyShot[i].flag == 1) {//ショットしている玉があれば
			if (EnemyShot[i].pattern == 1)//しかもそれがショットパターン１ならば
				EnemyShotPattern1(i);//ショットパターン１へ
		}
	}
}

void EnemyShotCalcDisp() {//描画と、画面外に出たらフラグを戻す事を行う関数
	for (int i = 0; i<ENEMY_TOTAL_NUM; i++) {//敵の最大数100体だけループ
		if (EnemyShot[i].flag == 1) {//ショットしている弾の組があれば
			EnemyShot[i].counter++;//ショットカウントをアップ
			for (int j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {//調べたショットの組の全ての弾(200個)ループ
				if (EnemyShot[i].EnemyShots[j].flag == 1) {//ショットしている組の弾で、実際にショットしている弾なら
														   //弾を描画、今回はDrawGraphでもいい。
					DrawRotaGraph((int)EnemyShot[i].EnemyShots[j].x, (int)EnemyShot[i].EnemyShots[j].y, 1.0f, 0.0f, img_enemy_shot[EnemyShot[i].img], TRUE);
					//弾が画面より外にあるときは発射フラグを戻す。
					if (EnemyShot[i].EnemyShots[j].x<-20.0 || EnemyShot[i].EnemyShots[j].x>440.0 || EnemyShot[i].EnemyShots[j].y<-20.0 || EnemyShot[i].EnemyShots[j].y>500)
						EnemyShot[i].flag = 0;
				}
			}
		}
	}
	for (int i = 0; i<ENEMY_TOTAL_NUM; i++) {//敵の最大数100体分ループ
		if (EnemyShot[i].flag == 1) {//敵のショットが発射中なら
			for (int j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {//１組200個分のループ
				if (EnemyShot[i].EnemyShots[j].flag == 1) {//1個でも発射中の弾があれば終了
					return;
				}
			}
			EnemyShot[i].flag = 0;//全部発射中でなければその組全体の発射フラグを戻す。
		}
	}
}