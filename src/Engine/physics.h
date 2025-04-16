#ifndef PHYSICS_H
#define PHYSICS_H

#include <SDL.h>
#include <vector>

#include "vector.hpp"
#include "tile_manager.h"

class Physics {
public:
	static bool isColliding(Vector2* aPos, Vector2* bPos, Size2 aSize, Size2 bSize);

	static int isMapColliding(Tilemap* map, Vector2* position);

	static void mapCollision(Tilemap* map, Vector2* position, Size2 player_size);

private:

};

#endif
