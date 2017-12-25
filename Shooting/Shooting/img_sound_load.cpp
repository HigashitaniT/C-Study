/* img_sound_load.cpp */

#include "DxLib.h"
#include "ExternGV.h"

void img_sound_load() {
	//画像ハンドル取得
	img_background[0] = LoadGraph("Sh/img/back/background0.png");
	img_background[1] = LoadGraph("Sh/img/back/background1.png");
	img_player_shot[0] = LoadGraph("Sh/img/shot/player/1.png");
	img_player_shot[1] = LoadGraph("Sh/img/shot/player/2.png");
	img_enemy_shot[0] = LoadGraph("Sh/img/shot/enemy/shot1.png");
	img_enemy[0] = LoadGraph("Sh/img/mons/mons1_0.png");
	img_enemy[1] = LoadGraph("Sh/img/mons/mons1_1.png");
	img_enemy[2] = LoadGraph("Sh/img/mons/mons1_2.png");
	img_enemy[3] = LoadGraph("Sh/img/mons/mons1_3.png");
	img_enemy[4] = LoadGraph("Sh/img/mons/mons1_4.png");
	LoadDivGraph("Sh/img/char/player.png", 4, 4, 1, 32, 48, img_player);
	//音楽ハンドル取得
	sound_player_shot[0] = LoadSoundMem("Sh/sound/Player/shot.ogg");
	sound_enemy_shot[0] = LoadSoundMem("Sh/sound/enemy/normalshot.ogg");
	sound_enemy_death = LoadSoundMem("Sh/sound/enemy/death.ogg");
}