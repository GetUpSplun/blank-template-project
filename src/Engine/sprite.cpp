#include "sprite.h"

Sprite::Sprite(Graphics& graphics, const char* path, Size2 size) {
	this->rect.w = size.width;
	this->rect.h = size.height;

	this->texture = SDL_CreateTextureFromSurface(graphics.GetRenderer(), IMG_Load(path));
	if (this->texture == NULL)
		std::cout << "can't create texture: " << IMG_GetError() << std::endl;
}

void Sprite::Draw(Graphics& graphics, Vector2 position, SDL_RendererFlip flip) {
	rect.x = position.x;
	rect.y = position.y;

	if (!((rect.x > WINDOW_WIDTH || rect.x < 0 - rect.w) || (rect.y > WINDOW_HEIGHT || rect.y < 0 - rect.h))) {
		SDL_RenderCopyEx(graphics.GetRenderer(), texture, NULL, &rect, 0.0, &point, flip);
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

void SpriteSheetX::Draw(Graphics& graphics, Vector2 position, Size2 size, int frame, SDL_RendererFlip flip) {
	rect.x = position.x;
	rect.y = position.y;
	rect.w = size.width;
	rect.h = size.height;

	SDL_Rect rerect = {source_rect.w/devider * frame, 0, source_rect.w/devider, source_rect.h};

	if (!((rect.x > WINDOW_WIDTH || rect.x < 0 - rect.w) || (rect.y > WINDOW_HEIGHT || rect.y < 0 - rect.h))) {
		SDL_RenderCopyEx(graphics.GetRenderer(), texture, &rerect, &rect, 0.0, &point, flip);
	}
}

SpriteSheetX::~SpriteSheetX() {
	SDL_DestroyTexture(texture);
	texture = NULL;
}
