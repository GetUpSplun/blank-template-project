#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "SDL2/SDL.h"
#include <vector>

class Input {
public:
	bool IsKeyDown(SDL_Scancode code);
	bool IsKeyPressed(SDL_Scancode code);

	bool IsMouseDown(SDL_Event& event, Uint32 type);
	bool IsMousePressed(SDL_Event& event, Uint32 type);

	// void Update();

private:
	const Uint8* key_state = SDL_GetKeyboardState(NULL);

	std::vector<SDL_Scancode> keys;
	std::vector<Uint32> mouse_buttons;

};

#endif
