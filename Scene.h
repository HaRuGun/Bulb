#pragma once


class Scene
{
protected:
	char *backgroundBmp;

public:
	virtual void Init() {}
	virtual void Update() {}
	virtual void Render() {}
	virtual void Release() {}

	void SetBackground(char *fileName);
	char* GetBackground();

	Scene() {}
	virtual ~Scene() {}
};