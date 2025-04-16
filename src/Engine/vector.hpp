#ifndef GAME_LOGIC_MATH
#define GAME_LOGIC_MATH

#include <cmath>
#include <SDL2/SDL.h>
#include <algorithm>

class Vector2 {
public:
	float x, y;

	void normalize();

	Vector2 operator+(const Vector2& obj) {
		Vector2 res;
		res.x = this->x + obj.x;
		res.y = this->y + obj.y;
		return res;
	}

	Vector2 operator-(const Vector2& obj) {
		Vector2 res;
		res.x = this->x - obj.x;
		res.y = this->y - obj.y;
		return res;
	}

	Vector2 operator/(const Vector2& obj) {
		Vector2 res;
		res.x = this->x / obj.x;
		res.y = this->y / obj.y;
		return res;
	}

	Vector2 operator*(const Vector2& obj) {
		Vector2 res;
		res.x = this->x * obj.x;
		res.y = this->y * obj.y;
		return res;
	}
};

class Size2 {
public:
	float width, height;
};

#endif
