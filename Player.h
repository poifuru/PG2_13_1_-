#pragma once
#include <Novice.h>
#include <struct.h>

class Player {
public:
	//メンバ変数
	Vector2 <float> pos_;
	Vector2 <float> speed_;
	int radius_;

	Bullet bullet_[20];

	//コンストラクタ
	Player();

	//メンバ関数
	void Update(const char* keys, const char* preKeys);
	void Draw();
};

