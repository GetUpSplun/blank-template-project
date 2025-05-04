#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL_image.h>
#include <iostream>
#include "graphics.h"
#include "vector.hpp"
#include "global.h"

class Sprite {
public:
	Sprite(Graphics& graphics, const char* path, Size2 size);
	void Draw(Graphics& graphics, Vector2 position, SDL_RendererFlip flip);
	~Sprite();

private:
	SDL_Texture* texture;
	SDL_Rect rect;
	const SDL_Point point = {0,0};
};

class SpriteSheetX {
public:
	SpriteSheetX(Graphics& graphics, const char* path, SDL_Rect source_rect, int devider);
	void Draw(Graphics& graphics, Vector2 position, Size2 size, int frame, SDL_RendererFlip flip);
	~SpriteSheetX();

private:
	SDL_Texture* texture;
	SDL_Rect rect;
	SDL_Rect source_rect;
	int devider = 0;
	const SDL_Point point = {0,0};
};

#endif
