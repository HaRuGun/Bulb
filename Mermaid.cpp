#include "stdafx.h"


void Mermaid::Init(LPSTR fileName, COLORREF cr, int lf, int fd, int w, int h, int x, int y, int xd, int yd, int xs, int ys)
{
	Object::Init(fileName, cr, lf, fd, w, h, x, y, xd, yd, xs, ys);
	isSelect = false;

	km = new KeyManager;
	km->Init();

	return;
}


void Mermaid::Update()
{
	km->Update();

	if (!isSelect)
	{
		Object::Update();
	}
	else if (isSelect)
	{
		if (km->GetKeyState('W') == KS_STAY)
		{
			yDir = -1;
			SetPosition(x, y - ySpd);
		}

		if (km->GetKeyState('A') == KS_STAY)
		{
			frameDir = 0;
			SetPosition(x - xSpd, y);
		}

		if (km->GetKeyState('S') == KS_STAY)
		{
			yDir = 1;
			SetPosition(x, y + ySpd);
		}

		if (km->GetKeyState('D') == KS_STAY)
		{
			frameDir = 2;
			SetPosition(x + xSpd, y);
		}
	}

	// 화면 안에 가둔다
	if (x <= 0)
	{
		x = 0;
		xDir = 1;
		frameDir = 1;
		currentFrame = 0;
	}
	else if (x >= SCREEN_WIDTH - width)
	{
		x = SCREEN_WIDTH - width;
		xDir = -1;
		frameDir = 3;
		currentFrame = 0;
	}

	if (y <= 0)
	{
		y = 0;
		yDir = 1;
	}
	else if (y >= SCREEN_HEIGHT - height)
	{
		y = SCREEN_HEIGHT - height;
		yDir = -1;
	}

	return;
}


void Mermaid::Render()
{
	Object::Render();
	return;
}


void Mermaid::Release()
{
	delete(km);

	Object::Release();
	return;
}


////////////////////////


void Mermaid::Click(POINT pos)
{
	if ((this->x <= pos.x && pos.x <= this->x + this->width)
		&& (this->y <= pos.y && pos.y <= this->y + this->height))
		isSelect = !isSelect;

	return;
}


//////////////////////////////////////
// Get


BOOL Mermaid::GetIsSelect()
{
	return isSelect;
}