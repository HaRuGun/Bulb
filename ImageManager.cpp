#include "stdafx.h"


void ImageManager::Init(HWND hWnd)
{
	this->hWnd = hWnd;

	GetClientRect(hWnd, &region);
	hdcFront = GetDC(hWnd);

	hdcBack = CreateCompatibleDC(hdcFront);
	hbmBack = CreateCompatibleBitmap(
		hdcFront,
		region.right - region.left,
		region.bottom - region.top);
	SelectObject(hdcBack, hbmBack);

	hdcImg = CreateCompatibleDC(hdcFront);
}


void ImageManager::RenderOn()
{
	HPEN hPen, oldPen;
	HBRUSH hBrush, oldBrush;
	int x1, x2, y1, y2;

	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	hBrush = CreateSolidBrush(RGB(0, 0, 0));

	oldPen = (HPEN)SelectObject(hdcBack, hPen);
	oldBrush = (HBRUSH)SelectObject(hdcBack, hBrush);

	x1 = region.left;	x2 = region.right;
	y1 = region.top;	y2 = region.bottom;

	Rectangle(hdcBack, x1, y1, x2, y2);

	SelectObject(hdcBack, oldPen);
	SelectObject(hdcBack, oldBrush);

	DeleteObject(hBrush);
	DeleteObject(hPen);
}


void ImageManager::RenderOff()
{
	int destWidth = region.right - region.left;
	int destHeight = region.bottom - region.top;

	BitBlt(hdcFront, region.left, region.top, destWidth, destHeight, hdcBack, 0, 0, SRCCOPY);
}


void ImageManager::Release()
{
	if (hbmImg != NULL)
		DeleteObject(hbmImg);
	DeleteObject(hbmBack);
	DeleteDC(hdcImg);
	DeleteDC(hdcBack);
	DeleteDC(hdcFront);
}


////////////////////////////////////////////////////


void ImageManager::SetBackground(char* fileName)
{
	hbmImg = (HBITMAP)LoadImage(NULL, fileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	SelectObject(hdcImg, hbmImg);

	BitBlt(hdcBack, 0, 0, region.right, region.bottom, hdcImg, 0, 0, SRCCOPY);
}


void ImageManager::DrawObject(Object *obj)
{

	SelectObject(hdcImg, obj->GetImage());

	int destWidth = obj->GetRegion().right - obj->GetRegion().left;
	int destHeight = obj->GetRegion().bottom - obj->GetRegion().top;

	TransparentBlt(hdcBack, obj->GetX(), obj->GetY(), obj->GetWidth(), obj->GetHeight(),
		hdcImg, obj->GetRegion().left, obj->GetRegion().top, destWidth, destHeight, obj->GetColor());
}


////////////////////////////////////////////////////

HDC ImageManager::GetHdc()
{
	return hdcBack;
}