#pragma once


// 오브젝트 기본 클래스
class Object
{
protected:
	HBITMAP hBitmap;
	COLORREF color;
	LPSTR fileName;
	RECT region;

	int currentFrame;
	int lastFrame;
	int frameDir;
	int width, height;

	float x, y;
	int xDir, yDir;
	int xSpd, ySpd;

public:
	void Init(LPSTR fileName, COLORREF cr, int lf, int fd, int w, int h, float x, float y, int xd, int yd, int xs, int ys);
	void Update();
	void Render();
	void Release();

	void SetPosition(float x, float y);
	void SetFrameDir(int fd);

	HBITMAP GetImage();
	float GetX();
	float GetY();
	int GetXspd();
	int GetYspd();
	int GetWidth();
	int GetHeight();
	COLORREF GetColor();
	RECT GetRegion();

	Object() {}
	~Object() {}
};