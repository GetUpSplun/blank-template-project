#include "sprite.h"

Sprite::Sprite(Graphics& graphics, const char* path, int width, int height) {
	this->rect.w = width;
	this->rect.h = height;

	this->texture = SDL_CreateTextureFromSurface(graphics.GetRenderer(), IMG_Load(path));
	if (this->texture == NULL)
		std::cout << "can't create texture: " << IMG_GetError() << std::endl;
}

void Sprite::Draw(Graphics& graphics, Vector2 position) {
	rect.x = position.x;
	rect.y = position.y;

	if (!(rect.x > WINDOW_WIDTH || rect.x < 0) || !(rect.y > WINDOW_HEIGHT || rect.y < 0)) {
		SDL_RenderCopy(graphics.GetRenderer(), texture, NULL, &rect);
	}
}

Sprite::~Sprite() {
	SDL_DestroyTexture(texture);
	texture = NULL;
}

SpriteSheetX::SpriteSheetX(Graphics& graphics, const char* path, SDL_Rect source_rect, int devider) {
	this->source_rect = source_rect;
	this->devider = devider;

	this->texture = SDL_CreateTextureFromSurface(graphics.GetRenderer(), IMG_Load(path));
	if (this->texture == NULL)
		std::cout << "can't create texture: " << IMG_GetError() << std::endl;
}

void SpriteSheetX::Draw(Graphics& graphics, Vector2 position, int width, int height, int frame) {
	rect.x = position.x;
	rect.y = position.y;
	rect.w = width;
	rect.h = height;

	SDL_Rect rerect = {source_rect.w/devider * frame, 0, source_rect.w/devider, source_rect.h};

	if (!(rect.x > WINDOW_WIDTH || rect.x < 0) || !(rect.y > WINDOW_HEIGHT || rect.y < 0)) {
		SDL_RenderCopy(graphics.GetRenderer(), texture, &rerect, &rect);
	}
}

SpriteSheetX::~SpriteSheetX() {
	SDL_DestroyTexture(texture);
	texture = NULL;
}
