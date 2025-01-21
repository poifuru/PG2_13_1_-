#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include <math.h>

const char kWindowTitle[] = "LC1A_25_マスヤ_ゴウ_タイトル";

int Enemy::isAlive_ = 0;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Player* player = new Player();

	Enemy* enemy1 = new Enemy(300.0f, 300.0f);
	Enemy* enemy2 = new Enemy(700.0f, 400.0f);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player->Update(keys, preKeys);
		enemy1->Update(keys, preKeys);
		enemy2->Update(keys, preKeys);

		//当たり判定
		for (int i = 0; i < 20; i++) {
			if (Enemy::isAlive_) {
				if (player->bullet_[i].isShot) {
					if (powf(static_cast<float>(player->bullet_[i].radius) + enemy1->radius_, 2) >=
						powf(player->bullet_[i].pos.x - enemy1->pos_.x, 2) +
						powf(player->bullet_[i].pos.y - enemy1->pos_.y, 2)) {
						Enemy::isAlive_ = 0;
					}

					if (powf(static_cast<float>(player->bullet_[i].radius) + enemy2->radius_, 2) >=
						powf(player->bullet_[i].pos.x - enemy2->pos_.x, 2) +
						powf(player->bullet_[i].pos.y - enemy2->pos_.y, 2)) {
						Enemy::isAlive_ = 0;
					}
				}
			}
		}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player->Draw();
		enemy1->Draw();
		enemy2->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			delete player;
			delete enemy1;
			delete enemy2;
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
