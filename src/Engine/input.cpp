#include "input.h"
#include <iostream>

/* void Input::Update() {

} */

bool Input::IsKeyDown(SDL_Scancode code) {
	return this->key_state[code];
}

bool Input::IsKeyPressed(SDL_Scancode code) {
	for (int i = 0; i < keys.size(); ++i) {
		if (!IsKeyDown(keys[i])) {
			keys.erase(keys.begin()+i);
		}
	}

	if (IsKeyDown(code)) {
		for (int i = 0; i < keys.size(); ++i) {
			if (keys[i] == code) {
				return false; }
		}
		keys.push_back(code);
		return true;
	}
	return false;
}

bool Input::IsMouseDown(Uint32 type) {
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(type)) return true;

	return false;
}

bool Input::IsMousePressed(Uint32 type) {
	for (int i = 0; i < mouse_buttons.size(); ++i) {
		if (!IsMouseDown(mouse_buttons[i])) {
			mouse_buttons.erase(mouse_buttons.begin()+i);
		}
	}
	
	if (IsMouseDown(type)) {
		for (int i = 0; i < mouse_buttons.size(); ++i) {
			if (mouse_buttons[i] == type) {
				return false;
			}
		}
		mouse_buttons.push_back(type);
		return true;
	}
	return false;
}
