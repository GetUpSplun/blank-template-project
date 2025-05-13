#ifndef PHYSICS_H
#define PHYSICS_H

#include <SDL.h>
#include <vector>

#include "vector.hpp"
#include "tile_manager.h"

class Physics {
public:
	static bool IsColliding(Vector2 aPos, Vector2 bPos, Size2 aSize, Size2 bSize);

	static int IsMapColliding(Tilemap* map, Vector2* position, Size2 object_size);

	static void MapCollision(Tilemap* map, Vector2* position, Size2 object_size);

private:

};

#endif
