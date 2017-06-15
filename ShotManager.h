#pragma once
using namespace std;


class ShotManager
{
public:
	const int objectSize = 120;

protected:
	vector<Shot*> manager;
	
public:
	void Init();
	void Update();
	void Render();
	void Release();

	vector<Shot*> GetVector();

	ShotManager() {}
	~ShotManager() {}
};