/* enemy_shot.cpp */
/* �f�� ver 1.11�ȏ�K�v */
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

void EnemyShotControl() {//�V���b�g�p�^�[���P���ĂԂ��߂̊֐�enemy.cpp��EnemyControl�֐��Ɩ�ڈꏏ
	int i;
	for (i = 0; i<ENEMY_TOTAL_NUM; i++) {//�G�̍ő吔100�̂������[�v
		if (EnemyShot[i].flag == 1) {//�V���b�g���Ă���ʂ������
			if (EnemyShot[i].pattern == 1)//���������ꂪ�V���b�g�p�^�[���P�Ȃ��
				EnemyShotPattern1(i);//�V���b�g�p�^�[���P��
		}
	}
}

void EnemyShotCalcDisp() {//�`��ƁA��ʊO�ɏo����t���O��߂������s���֐�
	for (int i = 0; i<ENEMY_TOTAL_NUM; i++) {//�G�̍ő吔100�̂������[�v
		if (EnemyShot[i].flag == 1) {//�V���b�g���Ă���e�̑g�������
			EnemyShot[i].counter++;//�V���b�g�J�E���g���A�b�v
			for (int j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {//���ׂ��V���b�g�̑g�̑S�Ă̒e(200��)���[�v
				if (EnemyShot[i].EnemyShots[j].flag == 1) {//�V���b�g���Ă���g�̒e�ŁA���ۂɃV���b�g���Ă���e�Ȃ�
														   //�e��`��A�����DrawGraph�ł������B
					DrawRotaGraph((int)EnemyShot[i].EnemyShots[j].x, (int)EnemyShot[i].EnemyShots[j].y, 1.0f, 0.0f, img_enemy_shot[EnemyShot[i].img], TRUE);
					//�e����ʂ��O�ɂ���Ƃ��͔��˃t���O��߂��B
					if (EnemyShot[i].EnemyShots[j].x<-20.0 || EnemyShot[i].EnemyShots[j].x>440.0 || EnemyShot[i].EnemyShots[j].y<-20.0 || EnemyShot[i].EnemyShots[j].y>500)
						EnemyShot[i].flag = 0;
				}
			}
		}
	}
	for (int i = 0; i<ENEMY_TOTAL_NUM; i++) {//�G�̍ő吔100�̕����[�v
		if (EnemyShot[i].flag == 1) {//�G�̃V���b�g�����˒��Ȃ�
			for (int j = 0; j<ENEMY_TOTAL_SHOT_NUM; j++) {//�P�g200���̃��[�v
				if (EnemyShot[i].EnemyShots[j].flag == 1) {//1�ł����˒��̒e������ΏI��
					return;
				}
			}
			EnemyShot[i].flag = 0;//�S�����˒��łȂ���΂��̑g�S�̂̔��˃t���O��߂��B
		}
	}
}