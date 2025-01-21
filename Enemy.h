#pragma once
#include <Novice.h>
#include "struct.h"

class Enemy {
public:
	//静的メンバ変数
	static int isAlive_;

	//メンバ変数
	Vector2 <float> pos_;
	Vector2 <float> speed_;
	int radius_;

	//コンストラクタ,デストラクタ
	Enemy(float x, float y);
	~Enemy();

	//メンバ関数
	void Update(const char* keys, const char* preKeys);
	void Draw();
};