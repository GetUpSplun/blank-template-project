#include "physics.h"

bool Physics::isColliding(Vector2 aPos, Vector2 bPos, Size2 aSize, Size2 bSize) {
	return ((aPos.x + aSize.width > bPos.x && aPos.x < bPos.x + bSize.width) && (aPos.y + aSize.height > bPos.y && aPos.y < bPos.y + bSize.height));
}

int Physics::isMapColliding(Tilemap* map, Vector2* position) {
	for (int i = 0; i < map->GetArray().size(); ++i) {
		Vector2 tile_position = {(float)(i%10*tile_size.width), (float)(i/10*tile_size.height)};
		if (isColliding(*position, tile_position, (Size2){50,50}, tile_size) && map->GetArray()[i] != 0) {
			return i;
		}
	}
	return -1;
}

void Physics::mapCollision(Tilemap* map, Vector2* position, Size2 player_size) {
	float infelicity = 2;
	if (isMapColliding(map, position) != -1) {
		Vector2 tile_position = {(isMapColliding(map, position)%10*tile_size.width),(isMapColliding(map, position)/10*tile_size.height)};
		if (position->x + player_size.width - infelicity < tile_position.x) {
			position->x = tile_position.x - player_size.width;
		} else if (position->x > tile_position.x + tile_size.width - infelicity) {
			position->x = tile_position.x + tile_size.width;
		} else if (position->y + player_size.height - infelicity < tile_position.y) {
			position->y = tile_position.y - player_size.height;
		} else if (position->y > tile_position.y + tile_size.height - infelicity) {
			position->y = tile_position.y + tile_size.height;
		}
	}
}
