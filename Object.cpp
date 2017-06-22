#include "stdafx.h"


void Object::Init(LPSTR fileName, COLORREF cr, int w, int h, float x, float y)
{
	color = cr;
	width = w;
	height = h;
	this->x = x;
	this->y = y;

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

	return;
}


void Object::Render()
{
	region.left = 0;
	region.top = 0;
	region.right = width;
	region.bottom = height;

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


///////////////////////////////////
// Get


HBITMAP Object::GetImage()
{
	return hBitmap;
}

COLORREF Object::GetColor()
{
	return color;
}

RECT Object::GetRegion()
{
	return region;
}

int Object::GetWidth()
{
	return width;
}

int Object::GetHeight()
{
	return height;
}

float Object::GetX()
{
	return x;
}

float Object::GetY()
{
	return y;
}