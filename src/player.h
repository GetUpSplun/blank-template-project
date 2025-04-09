#ifndef PLAYER_HERE_H
#define PLAYER_HERE_H

#include "global.h"
#include "sprite.h"
#include "input.h"
#include "vector.hpp"

class Player {
public:
	Player(Graphics& graphics);

	~Player();

	void Draw(Graphics& graphics); 

	void Update(float delta_time);

private:
	Vector2 position = {WINDOW_WIDTH/2, WINDOW_HEIGHT/2};
	Vector2 velocity = {0,0};

	SpriteSheetX* ptr_sprite = NULL;

	float speed = 150;

	Input input;
};

#endif
