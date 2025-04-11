#include "vector.hpp"

void Vector2::normalize() {
	if (sqrt(this->x*this->x+this->y*this->y) > 0) {
		this->x *= 1/sqrt(this->x*this->x+this->y*this->y);
		this->y *= 1/sqrt(this->x*this->x+this->y*this->y);
	}
}

bool CheckRecs(SDL_Rect* rect1, SDL_Rect* rect2) {
	return rect1->x+rect1->w > rect2->x && rect1->x < rect2->x+(rect2->w) && rect1->y+rect1->h > rect2->y && rect1->y < rect2->y+(rect2->h);
}
