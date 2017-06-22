#include "stdafx.h"


void StartScene::Init()
{
	SetBackground("./Resource/main background.bmp");

	objQuit = new Object;
	objQuit->Init("./Resource/main quit basics.bmp", RGB(255, 8, 255), 256, 128, 295, 452);
}


void StartScene::Update()
{
	objQuit->Update();
}


void StartScene::Render()
{
	objQuit->Render();
	IMAGEMANAGER->DrawObject(objQuit);
}


void StartScene::Release()
{
	objQuit->Release();
	delete(objQuit);
}