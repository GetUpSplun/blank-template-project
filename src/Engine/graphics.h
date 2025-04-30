#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include "global.h"

class Graphics {
public:
	Graphics(const char* name);

	void Clear(SDL_Color color);
	void Render();

	~Graphics();

	SDL_Renderer* GetRenderer();

private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

};

void DrawRect(Graphics& graphics, SDL_Rect rect, SDL_Color color);

void DrawFillRect(Graphics& graphics, SDL_Rect rect, SDL_Color color);

#endif
