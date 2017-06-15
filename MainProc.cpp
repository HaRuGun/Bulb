#include "stdafx.h"


// ������ ���۵� �� �ʱ�ȭ�� �����ϴ� �Լ�
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


// �� �����Ӹ��� ȣ��Ǵ� �Լ�
int Main::Update(HWND hWnd)
{
	::GetCursorPos(&mousePos);
	::ScreenToClient(hWnd, &mousePos);
	/* [ UPDATE START] */



	/* [ UPDATE END] */
	lastLBState = curLBState;

	return 0;
}


// �� �̹����� �ִϸ��̼��� ����ϴ� �Լ�
int Main::Render()
{
	im->RenderOn();
	//im->SetBackground(""); // This coad have to use background.bmp
	/* [ DRAW SRART ] */

	

	/* [ DRAW END ] */
	im->RenderOff();
	return 0;
}


// ������ ����� �� ������ �����ϴ� �Լ�
int Main::Release()
{
	act = false;
	/* [ RELEASE START] */



	/* [ RELEASE END] */
	// �Ŵ��� Ŭ���� ����
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