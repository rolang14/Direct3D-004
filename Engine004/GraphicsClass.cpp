#include "GraphicsClass.h"

//나중에 내용들이 채워져야 함.
GraphicsClass::GraphicsClass()
{
	//생성자 호출 시 포인터 변수 초기화
	m_D3D = 0;
}

GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}

GraphicsClass::~GraphicsClass()
{
}

//여기서 D3D 객체를 생성함.
bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;

	//새로운 Direct 3D 객체 생성
	m_D3D = new D3DClass;
	if (!m_D3D)
	{
		return false;
	}

	//Direct3D 객체 초기화
	result = m_D3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D", L"Error", MB_OK);
		return false;
	}

	return true;
}

//종료 시 D3D 객체도 정리
void GraphicsClass::Shutdown()
{
	//Direct3D 객체가 있으면 삭제하고 NULL
	if (m_D3D)
	{
		m_D3D->Shutdown();
		delete m_D3D;
		m_D3D = 0;
	}

	return;
}

//매 프레임마다 Render 함수 호출
bool GraphicsClass::Frame()
{
	bool result;

	//그래픽 렌더링을 수행
	result = Render();
	if (!result)
	{
		return false;
	}

	return true;
}

//이제 렌더를 진행할것임.
bool GraphicsClass::Render()
{
	//씬을 그리기 위해 버퍼의 내용을 지움
	//들어가는 내용은 코드보면 알겠지만 openGL 0~1 컬러임 (RGBA)
	m_D3D->BeginScene(1.0f, 1.0f, 0.0f, 1.0f);

	//버퍼에 그려진 씬을 화면에 표시함
	m_D3D->EndScene();

	return true;
}