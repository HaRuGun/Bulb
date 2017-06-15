#pragma once

class Shot :
	public Object
{
protected:
	bool isActive;

	double dir;
	double spd;

public:
	void Init(LPSTR fileName, COLORREF cr, int lf, int fd, int w, int h, float x, float y, int xd, int yd, int xs, int ys);
	void Update();
	void Render();
	void Release();

	void SetIsActive(bool act);
	void SetDir(double dir);
	void SetSpd(double spd);

	bool GetIsActive();
	double GetDir();
	double GetSpd();

	Shot() {}
	~Shot() {}
};