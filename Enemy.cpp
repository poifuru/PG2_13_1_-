#include "Enemy.h"

Enemy::Enemy(float x, float y) {
	isAlive_ = true;
	pos_ = { x, y };
	speed_ = { 5.0f, 0.0f };
	radius_ = 15;
}

Enemy::~Enemy() {
}

void Enemy::Update(const char* keys, const char* preKeys) {
	if (isAlive_) {
		pos_.x += speed_.x;

		if (pos_.x - radius_ <= 0) {
			speed_.x *= -1;
		}
		else if (pos_.x + radius_ >= 1280) {
			speed_.x *= -1;
		}
	}

	if (keys[DIK_R] && !preKeys[DIK_R]) {
		isAlive_ = 1;
	}
}

void Enemy::Draw() {
	if (isAlive_) {
		Novice::DrawEllipse(
			int(pos_.x), int(pos_.y),
			radius_, radius_, 0.0f, RED, kFillModeSolid
		);
	}
}