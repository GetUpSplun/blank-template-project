#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <vector>

#include "global.h"
#include "graphics.h"

class Game {
public:
	Game();

	~Game();

private:
	void Draw();
	void Update();

	Graphics graphics{"THE GAME"};
	
	SDL_Event e;

	float last_time = 0;
	float delta_time = 0;

};
