#pragma once


// 오브젝트 기본 클래스
class Object
{
protected:
	HBITMAP hBitmap;
	COLORREF color;
	LPSTR fileName;
	RECT region;

	int width, height;
	float x, y;

public:
	void Init(LPSTR fileName, COLORREF cr, int w, int h, float x, float y);
	void Update();
	void Render();
	void Release();

	void SetPosition(float x, float y);

	HBITMAP GetImage();
	COLORREF GetColor();
	RECT GetRegion();
	int GetWidth();
	int GetHeight();
	float GetX();
	float GetY();

	Object() {}
	~Object() {}
};