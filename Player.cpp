#include "Player.h"

Player::Player() {
	pos_ = { 640.0f, 600 };
	speed_ = { 10.0f, 10.0f };
	radius_ = 30;

	for (int i = 0; i < 20; i++) {
		bullet_[i].pos = {};
		bullet_[i].speed = { 0.0f, 10.0f };
		bullet_[i].radius = 10;
		bullet_[i].isShot = 0;
	}
}

void Player::Update(const char* keys, const char* preKeys) {
	//移動
	if (keys[DIK_W]) {
		pos_.y -= speed_.y;
	}
	if (keys[DIK_S]) {
		pos_.y += speed_.y;
	}
	if (keys[DIK_A]) {
		pos_.x -= speed_.x;
	}
	if (keys[DIK_D]) {
		pos_.x += speed_.x;
	}

	//bulletの処理
	for (int i = 0; i < 20; i++) {
		//発射
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			if (!bullet_[i].isShot) {
				bullet_[i].isShot = 1;
				break;
			}
		}

		//isShotが0の時に座標をプレイヤーに合わせる
		if (!bullet_[i].isShot) {
			bullet_[i].pos = pos_;
			bullet_[i].speed = { 0.0f, 10.0f };
		}

		//弾の挙動
		if (bullet_[i].isShot) {
			bullet_[i].pos.y -= bullet_[i].speed.y;
		}

		//弾が画面外に出たらisShotを0に
		if ((bullet_[i].pos.y + bullet_[i].radius) <= 0) {
			bullet_[i].isShot = 0;
		}
	}
}

void Player::Draw() {
	for (int i = 0; i < 20; i++) {
		if (bullet_[i].isShot) {
			Novice::DrawEllipse(
				static_cast<int>(bullet_[i].pos.x), static_cast<int>(bullet_[i].pos.y),
				bullet_[i].radius, bullet_[i].radius, 0.0f, WHITE, kFillModeSolid
			);
		}
	}

	Novice::DrawEllipse(
		static_cast<int>(pos_.x), static_cast<int>(pos_.y),
		radius_, radius_, 0.0f, GREEN, kFillModeSolid
	);
}
