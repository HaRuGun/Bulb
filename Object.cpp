#include "stdafx.h"


void Object::Init(LPSTR fileName, COLORREF cr, int lf, int fd, int w, int h, float x, float y, int xd, int yd, int xs, int ys)
{
	color = cr;
	width = w;
	height = h;
	this->x = x;
	this->y = y;
	xDir = xd;
	yDir = yd;
	xSpd = xs;
	ySpd = ys;

	currentFrame = 0;
	lastFrame = lf;
	frameDir = fd;

	hBitmap = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	if (hBitmap == NULL)
	{
		MessageBox(NULL, "이미지 없다.", "오류", MB_OK);
		exit(0);
	}

	return;
}


void Object::Update()
{
	SetPosition(x + xSpd * xDir, y + ySpd * yDir);

	return;
}


void Object::Render()
{
	region.left = currentFrame * width;
	region.top = frameDir * height;
	region.right = region.left + width;
	region.bottom = region.top + height;

	currentFrame++;
	if (currentFrame >= lastFrame)
	{
		currentFrame = 0;
		if (frameDir == 1 || frameDir == 3) frameDir++;
		if (frameDir > 3) frameDir = 0;
	}

	return;
}


void Object::Release()
{
	if (hBitmap)
		DeleteObject(hBitmap);

	return;
}


///////////////////////////////////
// Set


void Object::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;

	return;
}


void Object::SetFrameDir(int fd)
{
	frameDir = fd;

	return;
}


///////////////////////////////////
// Get


HBITMAP Object::GetImage()
{
	return hBitmap;
}

float Object::GetX()
{
	return x;
}

float Object::GetY()
{
	return y;
}

int Object::GetXspd()
{
	return xSpd;
}

int Object::GetYspd()
{
	return ySpd;
}

int Object::GetWidth()
{
	return width;
}

int Object::GetHeight()
{
	return height;
}

COLORREF Object::GetColor()
{
	return color;
}

RECT Object::GetRegion()
{
	return region;
}