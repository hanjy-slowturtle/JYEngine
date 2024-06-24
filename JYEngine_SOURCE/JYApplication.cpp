#include "jyApplication.h"
#include "jyInput.h"
#include "jyTime.h"
#include "jySceneManager.h"

namespace jy
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBitmap(NULL)

	{
	}
	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
		//mPlayerList = std::vector<GameObject>(2);
		//mPlayerList[1].SetPosition(300, 300);
		//mPlayerList[1].SetType(1);
		//mPlayerList[1].SetKey(eKeyCode::W, eKeyCode::S, eKeyCode::A, eKeyCode::D);
		//mPlayerList[1].SetColor(RGB(255, 0, 0));
		SceneManager::Initialize();

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = width;
		mHeight = height;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		// 윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// 백버퍼를 가르킬 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP prevBitmap = (HBITMAP) SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(prevBitmap);

		Input::Initialize();
		Time::Initialize();
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		Input::Update();
		Time::Update();
		SceneManager::Update();
	}
	void Application::LateUpdate()
	{
	}
	void Application::Render()
	{
		clearRenderTarget();

		Time::Render(mBackHdc);

		SceneManager::Render(mBackHdc);

		copyRenderTarget(mBackHdc, mHdc);
	}

	void Application::clearRenderTarget()
	{
		// clear
		Rectangle(mBackHdc, -1, -1, mWidth + 1, mHeight + 1);
	}

	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		// BackBuffer에 있는걸 원본 Buffer에 복사(그려준다)
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}
}