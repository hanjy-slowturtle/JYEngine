#include "JYApplication.h"
#include "CommonInclude.h"

namespace jy
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mSpeed(0.0f)
		, mX(0.0f)
		, mY(0.0f)
	{
	}
	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		mSpeed += 0.01f;

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX -= 0.01f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01f;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.01f;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.01f;
		}
	}
	void Application::LateUpdate()
	{
	}
	void Application::Render()
	{
		// �Ķ� �귯�� ����
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		// �Ķ� �귯�� DC�� ����, �׸��� ��� �귯�� ��ȯ�� ����
		HBRUSH prevBrush = (HBRUSH)SelectObject(mHdc, blueBrush);

		Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		// ���� �귯�� ����
		SelectObject(mHdc, prevBrush);

		// �Ķ� �귯�� ����
		DeleteObject(blueBrush);
	}
}