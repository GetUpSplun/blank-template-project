#include "input.h"

void Input::Update() {
	// key_state = SDL_GetKeyboardState(NULL);
		for (int i = 0; i < array.size(); ++i) {
			if (!IsKeyDown(array[i])) {
				array.erase(array.begin()+i);
			}
		}
}

bool Input::IsKeyDown(SDL_Scancode code) {
	return this->key_state[code];
}

bool Input::IsKeyPressed(SDL_Scancode code) {
	if (IsKeyDown(code)) {
		for (int i = 0; i < array.size(); ++i) {
			if (array[i] == code) {
				return false;
			}
		}
		array.push_back(code);
		return true;
	}
	return false;
}
