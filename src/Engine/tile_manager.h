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
	Tilemap(const char* path, Graphics& graphics, const std::vector<const char*> paths_texture, int size_x, int size_y);

	~Tilemap();

	void Draw(Graphics& graphics);

	int GetWidth();
	int GetHeight();

	std::vector<int> GetArray() {
		return map;
	}

private:
	std::vector<int> map;

	int map_size_x, map_size_y;

	std::vector<Sprite*> tiles;

};

#endif
