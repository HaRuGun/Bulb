#pragma once

// ������ ���� ����� ���ư��� Ŭ����
class Main
{
private:
	// �̹��� �޴��� ������ ����
	ImageManager *im;

	BOOL act;
	POINT mousePos;

	BOOL curLBState;
	BOOL lastLBState;

	/* [ OBJECT START ] */



	/* [ OBJECT END ] */

public:
	int Init(HWND hWnd);
	int Update(HWND hWnd);
	int Render();
	int Release();

	int LButtonDown();
	int LButtonUp();
	BOOL GetAct();

	Main() {};
	~Main() {};
};