#pragma once

#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_

//이제 D3D 사용을 위해 D3D 헤더를 추가해줌.
#include "D3DClass.h"

//풀스크린 모드
const bool FULL_SCREEN = true;
//V-싱크 모드
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame();

private:
	bool Render();
	//m_을 앞에 붙이는 이유는 누구의 멤버 변수인지 알려주기 위해..
	//m_D3D는 D3D의 멤버 변수구나.
	D3DClass* m_D3D;
};

#endif
