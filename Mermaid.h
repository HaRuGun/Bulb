#pragma once


// 물고기 클래스 : 부모 클래스는 오브젝트
class Mermaid :
	public Object
{
protected:
	BOOL isSelect;
	KeyManager *km;

public:
	void Init(LPSTR fileName, COLORREF cr, int lf, int fd, int w, int h, int x, int y, int xd, int yd, int xs, int ys);
	void Update();
	void Render();
	void Release();

	void Click(POINT pos);

	BOOL GetIsSelect();

	Mermaid() {};
	~Mermaid() {};
};

