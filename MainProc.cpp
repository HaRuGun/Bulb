#include "stdafx.h"


// ������ ���۵� �� �ʱ�ȭ�� �����ϴ� �Լ�
int Main::Init(HWND hWnd)
{
	igmg = new ImageManager;
	igmg->Init(hWnd);
	scmg = new SceneManager;
	scmg->Init();

	curLBState = false;
	lastLBState = curLBState;
	/* [ INIT START ] */

	first = new Scene;
	first->Init();
	first->SetBackground("./Resource/main background.bmp");

	scmg->SetScene(first);

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

	first->Render();

	/* [ UPDATE END] */
	lastLBState = curLBState;

	return 0;
}


// �� �̹����� �ִϸ��̼��� ����ϴ� �Լ�
int Main::Render()
{
	igmg->RenderOn();
	igmg->SetBackground(scmg->GetCurrentScene()->GetBackground());
	/* [ DRAW SRART ] */

	first->Update();

	/* [ DRAW END ] */
	igmg->RenderOff();
	return 0;
}


// ������ ����� �� ������ �����ϴ� �Լ�
int Main::Release()
{
	act = false;
	/* [ RELEASE START] */

	first->Release();
	delete(first);

	/* [ RELEASE END] */

	// �Ŵ��� Ŭ���� ����
	igmg->Release();
	delete(igmg);

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