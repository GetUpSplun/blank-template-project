#include "text.h"

Text::Text(SDL_Color color, TTF_Font* font, int size) {
	this->color = color;
	this->font = font;
	this->font_size = size;
}

void Text::Render(Graphics& graphics, const char* text, SDL_Rect rect) {
	surface = TTF_RenderText_Solid(font, text, color);
	texture = SDL_CreateTextureFromSurface(graphics.GetRenderer(), surface);
	SDL_RenderCopy(graphics.GetRenderer(), texture, NULL, &rect);
	SDL_FreeSurface(surface);
	surface = NULL;
	SDL_DestroyTexture(texture);
	texture = NULL;
}

Text::~Text() {
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}
