#pragma once
/* GlobalVariable.h */

// グローバル宣言

#define PLAYER_MAX_SHOT_LANE 11
#define PLAYER_MAX_SHOT_POINT 15

#define ENEMY_TOTAL_NUM 100
#define ENEMY_TOTAL_SHOT_NUM 200

#define MONSTER_X_SIZE 140.0
#define MONSTER_Y_SIZE 128.0

/*グローバル宣言*/
int counter = 0;
int color_white;
char Key[256];

int ShotLevel = 11;

//画像ファイルハンドル
int img_background[2];
int img_player[4];
int img_enemy[5];

//球の画像
int img_player_shot[2];
int img_enemy_shot[20];

//効果音ファイルハンドル
int sound_player_shot[2];
int sound_enemy_shot[2];
int sound_enemy_death;

//構造体
//自機
typedef struct {
	double x, y;
	int status, counter;
	int shot[11][15];
} BODY_player_t;

BODY_player_t Player;

//敵
typedef struct {
	double x, y, size;
	int flag, counter, hp, pattern, range;
} BODY_enemy_t;

BODY_enemy_t enemy[ENEMY_TOTAL_NUM];

//弾
typedef struct {
	double x, y;
	int flag;
} SHOT_t;

SHOT_t PlayerShot[PLAYER_MAX_SHOT_LANE][PLAYER_MAX_SHOT_POINT];

typedef struct {
	int flag;
	double x, y;
} ENENMY_SHOTS_t;

typedef struct {
	int flag, pattern, counter, img;
	double mem_ex, mem_ey, mem_px, mem_py, Angle[ENEMY_TOTAL_SHOT_NUM];
	ENENMY_SHOTS_t EnemyShots[ENEMY_TOTAL_SHOT_NUM];
} ENEMY_SHOT_t;
ENEMY_SHOT_t EnemyShot[ENEMY_TOTAL_NUM];