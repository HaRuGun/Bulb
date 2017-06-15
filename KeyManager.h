#pragma once

#define KEYMAX 256

enum KETSTATE
{
	KS_NONE, KS_DOWN, KS_STAY, KS_UP
};

class KeyManager
{
private:
	bool keyState[KEYMAX];
	bool prevKeyState[KEYMAX];

public:
	void Init();
	void Update();

	inline int GetKeyState(int key)
	{
		if (keyState[key])
		{
			if (prevKeyState[key])
				return KS_STAY;
			else
				return KS_DOWN;
		}
		else
		{
			if (prevKeyState[key])
				return KS_UP;
			else
				return KS_NONE;
		}
	}

	KeyManager() {}
	~KeyManager() {}
};