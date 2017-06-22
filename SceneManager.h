#pragma once
#include "Singleton.h"


class SceneManager
	: public Singleton<SceneManager>
{
protected:
	Scene *currentScene;

public:
	void Init();
	void Update();
	void Render();
	void Release();

	void SetScene(Scene *nextScene);
	Scene* GetCurrentScene();

	SceneManager() {}
	virtual ~SceneManager() {}
};

#define SCENEMANAGER SceneManager::GetSingleton()