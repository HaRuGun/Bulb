#pragma once


// ����� Ŭ���� : �θ� Ŭ������ ������Ʈ
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

