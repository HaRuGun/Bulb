#include "stdafx.h"


void Shot::Init(LPSTR fileName, COLORREF cr, int lf, int fd, int w, int h, float x, float y, int xd, int yd, int xs, int ys)
{
	Object::Init(fileName, cr, lf, fd, w, h, x, y, xd, yd, xs, ys);
	
	isActive = true;
	dir = 0;
	spd = 0;
	
	return;
}


void Shot::Update()
{
	if (!isActive)
		return;
	
	if (spd == 0)
		return;
	SetPosition(x + cos(radian(dir)) * spd, y + sin(radian(dir)) * spd);
	
	/*
	if (SCREEN_WIDTH < this->x || this->x < 0 - this->width ||
		SCREEN_HEIGHT < this->y || this->y < 0 - this->height)
		isActive = false;
	{
	}
	*/

	return;
}


void Shot::Render()
{
	if (!isActive)
		return;

	Object::Render();

	return;
}


void Shot::Release()
{
	Object::Release();
	return;
}


////////////////////////


void Shot::SetIsActive(bool act)
{
	isActive = act;

	this->x = 0;
	this->y = 0;
	this->dir = 0.0f;
	this->spd = 0.0f;

	return;
}


void Shot::SetDir(double dir)
{
	this->dir = dir;
	return;
}


void Shot::SetSpd(double spd)
{
	this->spd = spd;
	return;
}


///////////////////////////////


bool Shot::GetIsActive()
{
	return isActive;
}


double Shot::GetDir()
{
	return dir;
}


double Shot::GetSpd()
{
	return spd;
}