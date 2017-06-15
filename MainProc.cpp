#include "stdafx.h"


// 게임이 시작될 때 초기화를 실행하는 함수
int Main::Init(HWND hWnd)
{
	im = new ImageManager;
	im->Init(hWnd);

	curLBState = false;
	lastLBState = curLBState;
	/* [ INIT START ] */



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



	/* [ UPDATE END] */
	lastLBState = curLBState;

	return 0;
}


// 각 이미지와 애니메이션을 출력하는 함수
int Main::Render()
{
	im->RenderOn();
	//im->SetBackground(""); // This coad have to use background.bmp
	/* [ DRAW SRART ] */

	

	/* [ DRAW END ] */
	im->RenderOff();
	return 0;
}


// 게임이 종료될 때 해제를 실행하는 함수
int Main::Release()
{
	act = false;
	/* [ RELEASE START] */



	/* [ RELEASE END] */
	// 매니저 클래스 해제
	im->Release();
	delete(im);

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


///////////////////////////
// Get


BOOL Main::GetAct()
{
	return act;
}