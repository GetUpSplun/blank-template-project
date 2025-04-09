#include "tile_manager.h"

int x = 0, y = 0;

Tilemap::Tilemap(const char* path, Graphics& graphics, const std::vector<const char*> paths_textures): map_size_x(10), map_size_y(10) {
	for (int i = 0; i < paths_textures.size(); ++i) {
		std::cout << "texture loading to array\n";
		tiles.push_back(new Sprite(graphics, paths_textures[i], 50, 50));
	}

	std::ifstream file(path);
	
	if (file.fail()) {
		std::cout << "error open file map!";
	}

	char character;
	while (file.get(character)) {
		if (character == ' ' || character == '\n') {
			++x;
			if (x == map_size_x) {
				++y;
				x = 0;
				// std::cout << "\n";
			}
		}	else {
				map[x][y] = character - '0';
				// std::cout << map[x][y] << " ";
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

void Tilemap::Draw(Graphics& graphics) {
	for (int i = 0; i < map_size_y; ++i) {
		for (int j = 0; j < map_size_x; ++j) {
			if (map[j][i] == 1) {
				tiles[map[j][i]]->Draw(graphics, (Vector2){(float)(j*50),(float)(i*50)});
			}	
		}
	}
}
