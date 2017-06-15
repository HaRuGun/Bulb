#pragma once


class Object;

class ImageManager
{
private:
	HWND hWnd;

	HDC hdcFront;
	HDC hdcBack;
	HDC hdcImg;
	HBITMAP hbmBack;
	HBITMAP hbmImg;

	RECT region;

public:
	void Init(HWND hWnd);
	void RenderOn();
	void RenderOff();
	void Release();

	void SetBackground(char* fileName);
	void DrawObject(Object *obj);

	HDC GetHdc();

	ImageManager() {}
	~ImageManager() {}
};