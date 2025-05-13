#ifndef TEXT_H
#define TEXT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "graphics.h"

class Text {
public:
	Text(SDL_Color color, TTF_Font* font, int size);

	void Render(Graphics& graphics, const char* text, SDL_Rect rect);

	void SetColor(SDL_Color color);

	~Text();

private:
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;

	SDL_Color color;
	TTF_Font* font;

};

#endif
