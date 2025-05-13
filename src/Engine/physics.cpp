#include "physics.h"

bool Physics::IsColliding(Vector2 aPos, Vector2 bPos, Size2 aSize, Size2 bSize) {
	return ((aPos.x + aSize.width > bPos.x && aPos.x < bPos.x + bSize.width) && (aPos.y + aSize.height > bPos.y && aPos.y < bPos.y + bSize.height));
}

int Physics::IsMapColliding(Tilemap* map, Vector2* position, Size2 object_size) {
	for (int i = 0; i < map->GetArray().size(); ++i) {
		Vector2 tile_position = {(float)(i%map->GetWidth()*tile_size.width), (float)(i/map->GetWidth()*tile_size.height)};
		if (IsColliding(*position, tile_position, object_size, tile_size) && map->GetArray()[i] != 0) {
			return i;
		}
	}
	return -1;
}

void Physics::MapCollision(Tilemap* map, Vector2* position, Size2 object_size) {
	float infelicity = 2;
	if (IsMapColliding(map, position, object_size) != -1) {
		Vector2 tile_position = {(IsMapColliding(map, position, object_size)%map->GetWidth()*tile_size.width),(IsMapColliding(map, position, object_size)/map->GetWidth()*tile_size.height)};
		if (position->x + object_size.width - infelicity < tile_position.x) {
			position->x = tile_position.x - object_size.width;
		} else if (position->x > tile_position.x + tile_size.width - infelicity) {
			position->x = tile_position.x + tile_size.width;
		} else if (position->y + object_size.height - infelicity < tile_position.y) {
			position->y = tile_position.y - object_size.height;
		} else if (position->y > tile_position.y + tile_size.height - infelicity) {
			position->y = tile_position.y + tile_size.height;
		}
	}
}
