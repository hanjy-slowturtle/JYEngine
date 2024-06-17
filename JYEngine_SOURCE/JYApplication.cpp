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
		// 파랑 브러쉬 생성
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		// 파랑 브러쉬 DC에 선택, 그리고 흰색 브러쉬 반환값 저장
		HBRUSH prevBrush = (HBRUSH)SelectObject(mHdc, blueBrush);

		Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		// 원래 브러쉬 선택
		SelectObject(mHdc, prevBrush);

		// 파랑 브러쉬 삭제
		DeleteObject(blueBrush);
	}
}