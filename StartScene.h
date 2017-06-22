#pragma once


class StartScene :
	public Scene
{
protected:
	Object *objQuit;
	// main quit basics.bmp

public:
	void Init();
	void Update();
	void Render();
	void Release();

	StartScene() {}
	~StartScene() {}
};