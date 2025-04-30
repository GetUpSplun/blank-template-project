#include "graphics.h"

Graphics::Graphics(const char* name) {
	window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Graphics::~Graphics() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	window = NULL;
	renderer = NULL;
}

void Graphics::Clear(SDL_Color color) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(renderer);
}

void Graphics::Render() {
	SDL_RenderPresent(renderer);
}

SDL_Renderer* Graphics::GetRenderer() {
	return renderer;
}

void DrawRect(Graphics& graphics, SDL_Rect rect, SDL_Color color) {
	SDL_SetRenderDrawColor(graphics.GetRenderer(), color.r, color.g, color.b, color.a);
	SDL_RenderDrawRect(graphics.GetRenderer(), &rect);
}

void DrawFillRect(Graphics& graphics, SDL_Rect rect, SDL_Color color) {
	SDL_SetRenderDrawColor(graphics.GetRenderer(), color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(graphics.GetRenderer(), &rect);
}
