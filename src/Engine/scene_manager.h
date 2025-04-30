#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <vector>
#include <string>

#include "tile_manager.h"

class IScene {
public:
	virtual void Load(Graphics& graphics) = 0;

	virtual void Update(float delta_time, SDL_Event& event) = 0;

	virtual void Draw(Graphics& graphics) = 0;

	virtual void Unload() = 0;

};

class SceneManager {
public:
	SceneManager();

	IScene* GetScene();

	void NewScene(IScene* scene);

	~SceneManager();

private:
	std::vector<IScene*> scenes;
	
};

#endif
