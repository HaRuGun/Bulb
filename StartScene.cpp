#include "stdafx.h"


void StartScene::Init()
{
	SetBackground("./Resource/ui/background/main background.bmp");

	objQuit = new Object;
	objQuit->Init("./Resource/ui/main/quit/main quit basics.bmp", RGB(255, 8, 255), 256, 128, 295, 452);

	objCredit = new Object;
	objCredit->Init("./Resource/ui/main/credit/main credit basics.bmp", RGB(255, 8, 255), 256, 128, 295, 387);

	objStart = new Object;
	objStart->Init("./Resource/ui/main/start/main start basics.bmp", RGB(255, 8, 255), 256, 128, 295, 327);
}


void StartScene::Update()
{
	objQuit->Update();
	objCredit->Update();
	objStart->Update();
}


void StartScene::Render()
{
	objQuit->Render();
	IMAGEMANAGER->DrawObject(objQuit);
	objCredit->Render();
	IMAGEMANAGER->DrawObject(objCredit);
	objStart->Render();
	IMAGEMANAGER->DrawObject(objStart);
}


void StartScene::Release()
{
	objQuit->Release();
	delete(objQuit);
	objCredit->Release();
	delete(objCredit);
	objStart->Release();
	delete(objStart);
}