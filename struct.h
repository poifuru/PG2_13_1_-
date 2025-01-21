#pragma once

template <typename T>
struct Vector2 {
	T x;
	T y;
};

struct Bullet {
	Vector2 <float> pos;
	Vector2 <float> speed;
	int radius;
	int isShot;
};

struct Obj {
	Vector2 <float> pos;
	Vector2 <float> speed;
	int radius;
};