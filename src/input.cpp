#include "input.h"

void Input::Update() {
	// key_state = SDL_GetKeyboardState(NULL);
}

bool Input::IsKeyDown(SDL_Scancode code) {
	return this->key_state[code];
}
