#pragma once


class CreditScene :
	public Scene
{
protected:
	Object *objMain;
	// main quit basics.bmp

public:
	void Init();
	void Update();
	void Render();
	void Release();

	CreditScene() {}
	~CreditScene() {}
};