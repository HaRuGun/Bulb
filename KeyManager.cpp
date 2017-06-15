#include "stdafx.h"


void KeyManager::Init()
{
	memset(keyState, false, sizeof(keyState));
	memset(prevKeyState, false, sizeof(prevKeyState));
}

void KeyManager::Update()
{
	memcpy(prevKeyState, keyState, sizeof(prevKeyState));

	for (int i = 0; i < KEYMAX; i++)
		keyState[i] = GetAsyncKeyState(i) & 0x8000;
}