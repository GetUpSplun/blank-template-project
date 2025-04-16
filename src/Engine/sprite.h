#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL_image.h>
#include <iostream>
#include "graphics.h"
#include "vector.hpp"
#include "global.h"

class Sprite {
public:
	Sprite(Graphics& graphics, const char* path, int width, int height);
	void Draw(Graphics& graphics, Vector2 position);
	~Sprite();

private:
	SDL_Texture* texture;
	SDL_Rect rect;
};

class SpriteSheetX {
public:
	SpriteSheetX(Graphics& graphics, const char* path, SDL_Rect source_rect, int devider);
	void Draw(Graphics& graphics, Vector2 position, int width, int height, int frame);
	~SpriteSheetX();

private:
	SDL_Texture* texture;
	SDL_Rect rect;
	SDL_Rect source_rect;
	int devider = 0;
};

#endif
