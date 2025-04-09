#include "game.h"

#include <iostream>

bool isRunning = true;

Game::Game() {
	if (SDL_Init(SDL_INIT_EVERYTHING) > 0) {
		std::cout << "init error: " << SDL_GetError() << std::endl;
		isRunning = false;
	}
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		std::cout << "image init error: " << IMG_GetError() << std::endl;
		isRunning = false;
	}

	while (isRunning) {
		this->Update();
		this->Draw();
	}
}

Game::~Game() {
	IMG_Quit();
	SDL_Quit();
}

void Game::Draw() {
	graphics.Clear((SDL_Color){255,255,255,255});

	graphics.Render();
}

void Game::Update() {
	float current_time = SDL_GetTicks();
	delta_time = (current_time - last_time)/1000;

	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			isRunning = false;
		}
	}

	last_time = current_time;
}
