#include "stdafx.h"
#include "Scene.h"

// 게임이 시작될 때 초기화를 실행하는 함수
int Main::Init(HWND hWnd)
{
	IMAGEMANAGER->Init(hWnd);
	SCENEMANAGER->Init();

	curLBState = false;
	lastLBState = curLBState;
	/* [ INIT START ] */

	stScene = new StartScene;
	stScene->Init();
	SCENEMANAGER->SetScene(stScene);

	/* [ INIT END ] */
	act = true;
	return 0;
}


// 매 프레임마다 호출되는 함수
int Main::Update(HWND hWnd)
{
	::GetCursorPos(&mousePos);
	::ScreenToClient(hWnd, &mousePos);
	/* [ UPDATE START] */
	
	stScene->Update();

	/* [ UPDATE END] */
	lastLBState = curLBState;

	return 0;
}


// 각 이미지와 애니메이션을 출력하는 함수
int Main::Render()
{
	char * CurrentBackground = SCENEMANAGER->GetCurrentScene()->GetBackground();
	IMAGEMANAGER->RenderOn();
	IMAGEMANAGER->SetBackground(CurrentBackground);
	/* [ DRAW SRART ] */

	stScene->Render();

	/* [ DRAW END ] */
	IMAGEMANAGER->RenderOff();
	return 0;
}


// 게임이 종료될 때 해제를 실행하는 함수
int Main::Release()
{
	act = false;
	/* [ RELEASE START] */

	stScene->Release();
	delete(stScene);

	/* [ RELEASE END] */

	// 매니저 클래스 해제
	IMAGEMANAGER->Release();
	SCENEMANAGER->Release();

	PostQuitMessage(0);
	exit(0);
	return 0;
}


///////////////////////////
// Mouse

int Main::LButtonDown()
{
	curLBState = true;
	return 1;
}


int Main::LButtonUp()
{
	curLBState = false;
	return 1;
}


BOOL Main::LButtonClick(Object *hit)
{
	if (!curLBState)
		return false;

	if (mousePos.x >= hit->GetX() && mousePos.x <= hit->GetX() + hit->GetWidth()
		&& mousePos.y >= hit->GetY() && mousePos.y <= hit->GetY() + hit->GetHeight())
	{
		return true;
	}
	else
	{
		return false;
	}
}


///////////////////////////
// Get


BOOL Main::GetAct()
{
	return act;
}