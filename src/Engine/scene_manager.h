#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <vector>
#include <string>

#include "tile_manager.h"

class IScene {
public:
	virtual void Load(Graphics& graphics) = 0;

	virtual void Update(float delta_time) = 0;

	virtual void Draw(Graphics& graphics) = 0;

	virtual void Unload() = 0;

};

class SceneManager {
public:
	SceneManager();

	IScene* GetScene();

	void NewScene(IScene* scene);

	void PushScene(IScene* scene);
	
	void PopScene();

	void Clear();

	~SceneManager();

private:
	std::vector<IScene*> scenes;
	
};

#endif
