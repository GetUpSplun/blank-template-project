#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <vector>

#include "global.h"
#include "graphics.h"
#include "sprite.h"
#include "player.h"
#include "input.h"
#include "tile_manager.h"

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

	Player player{graphics};

	const std::vector<const char*> textures_level1 = {"", "../assets/block.png"};
	Tilemap map{"../assets/map.txt", graphics, textures_level1};

};
