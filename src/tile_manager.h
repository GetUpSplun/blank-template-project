#ifndef TILE_MANAGER_H
#define TILE_MANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "graphics.h"
#include "sprite.h"

class Tilemap {
public:
	Tilemap(const char* path, Graphics& graphics, const std::vector<const char*> paths_texture);

	~Tilemap();

	void Draw(Graphics& graphics);

private:
	int map[100][100];
	int map_size_x, map_size_y;

	std::vector<Sprite*> tiles;

};

#endif
