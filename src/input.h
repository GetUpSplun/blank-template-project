#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "SDL2/SDL.h"

class Input {
public:
	bool IsKeyDown(SDL_Scancode code);

	void Update();

private:
	const Uint8* key_state = SDL_GetKeyboardState(NULL);
};

#endif
