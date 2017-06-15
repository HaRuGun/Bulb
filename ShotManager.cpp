#include "stdafx.h"


void ShotManager::Init()
{
	manager.reserve(objectSize);

	for (int i = 0; i < objectSize; i++)
	{
		manager.push_back(new Shot);
		manager.at(i)->Init("./Resource/shot.bmp", RGB(0, 0, 0), 1, 0, 40, 40, SCREEN_WIDTH / 2 - 20, SCREEN_HEIGHT / 2 - 20, 0, 0, 0, 0);
		manager.at(i)->SetDir(i * 3);
		manager.at(i)->SetSpd(5);
	}

	return;
}


void ShotManager::Update()
{
	for (int i = 0; i < objectSize; i++)
	{
		manager.at(i)->Update();
		manager.at(i)->SetDir(manager.at(i)->GetDir() + i % 10);
	}

	return;
}


void ShotManager::Render()
{
	for (int i = 0; i < objectSize; i++)
		manager.at(i)->Render();

	return;
}


void ShotManager::Release()
{
	for (int i = 0; i < objectSize; i++)
	{
		manager.at(i)->Release();
		delete(manager.at(i));
	}

	return;
}


/////////////////////////


vector<Shot*> ShotManager::GetVector()
{
	return manager;
}