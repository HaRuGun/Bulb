#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>
#include <timeapi.h>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "msimg32.lib")

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include "SimpleFunction.h"

#include "ImageManager.h"
#include "KeyManager.h"

#include "Object.h"

#include "Scene.h"
#include "SceneManager.h"
#include "StartScene.h"

#include "MainProc.h"
#include "WinMain.h"