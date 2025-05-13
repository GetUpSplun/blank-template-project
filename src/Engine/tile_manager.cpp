#include "tile_manager.h"

int x = 0, y = 0;

Tilemap::Tilemap(const char* path, Graphics& graphics, const std::vector<const char*> paths_textures, int size_x, int size_y): map_size_x(size_x), map_size_y(--size_y) {
	for (int i = 0; i < paths_textures.size(); ++i) {
		tiles.push_back(new Sprite(graphics, paths_textures[i], tile_size));
	}

	std::ifstream file(path);
	
	if (file.fail()) {
		std::cout << "error open file map!";
	}

	char character;
	while (file.get(character)) {
		if (character == ' ' || character == '\n' || character == ',' || character == '.' || character == '|') {
			++x;
			if (x == map_size_x) {
				x = 0;
				// std::cout << "\n";
			}
		} else {
			map.push_back(character-'0');
			// std::cout << map[map.size()-1] << " ";
		}
	}

	file.close();
}

Tilemap::~Tilemap() {
	for (int i = 0; i < tiles.size(); ++i) {
		delete tiles[i];
		tiles[i] = NULL;
	}
}

int Tilemap::GetWidth() {return map_size_x;}
int Tilemap::GetHeight() {return map_size_y;}

void Tilemap::Draw(Graphics& graphics) {
	for (int i = 0; i < map.size(); ++i) {
		tiles[map[i]]->Draw(graphics, (Vector2){(float)(i%map_size_x*tile_size.width)-camera_position.x,(float)(i/map_size_x*tile_size.height)-camera_position.y}, SDL_FLIP_NONE);
	}
}
