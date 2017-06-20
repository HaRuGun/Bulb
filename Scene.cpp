#include "stdafx.h"


///////////////////////////////////////////////////////
// Set

void Scene::SetBackground(char *fileName)
{
	this->backgroundBmp = fileName;
}


//////////////////////////////////////////////////////
// Get

char* Scene::GetBackground()
{
	return backgroundBmp;
}