#ifndef PHYSICS_H
#define PHYSICS_H

#include <SDL2/SDL.h>

#include "vector.h"
#include "tile_manager.h"

class Physics {
public:
	static bool isColliding(Vector2 aObj, Vector2 bObj);


private:

};

#endif
