#pragma once


class SceneManager
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