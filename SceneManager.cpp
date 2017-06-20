#include "stdafx.h"


void SceneManager::Init()
{
	currentScene = nullptr;
}


void SceneManager::Update()
{

}


void SceneManager::Render()
{

}


void SceneManager::Release()
{

}


////////////////////////////////////////////////
// Set

void SceneManager::SetScene(Scene *nextScene)
{
	if (currentScene != nullptr)
		currentScene->Release();
	nextScene->Init();
	
	currentScene = nextScene;
}

///////////////////////////////////////////////
// Get

Scene* SceneManager::GetCurrentScene()
{
	return currentScene;
}