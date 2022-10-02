#include "GraphicsClass.h"

//���߿� ������� ä������ ��.
GraphicsClass::GraphicsClass()
{
	//������ ȣ�� �� ������ ���� �ʱ�ȭ
	m_D3D = 0;
}

GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}

GraphicsClass::~GraphicsClass()
{
}

//���⼭ D3D ��ü�� ������.
bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;

	//���ο� Direct 3D ��ü ����
	m_D3D = new D3DClass;
	if (!m_D3D)
	{
		return false;
	}

	//Direct3D ��ü �ʱ�ȭ
	result = m_D3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D", L"Error", MB_OK);
		return false;
	}

	return true;
}

//���� �� D3D ��ü�� ����
void GraphicsClass::Shutdown()
{
	//Direct3D ��ü�� ������ �����ϰ� NULL
	if (m_D3D)
	{
		m_D3D->Shutdown();
		delete m_D3D;
		m_D3D = 0;
	}

	return;
}

//�� �����Ӹ��� Render �Լ� ȣ��
bool GraphicsClass::Frame()
{
	bool result;

	//�׷��� �������� ����
	result = Render();
	if (!result)
	{
		return false;
	}

	return true;
}

//���� ������ �����Ұ���.
bool GraphicsClass::Render()
{
	//���� �׸��� ���� ������ ������ ����
	//���� ������ �ڵ庸�� �˰����� openGL 0~1 �÷��� (RGBA)
	m_D3D->BeginScene(1.0f, 1.0f, 0.0f, 1.0f);

	//���ۿ� �׷��� ���� ȭ�鿡 ǥ����
	m_D3D->EndScene();

	return true;
}