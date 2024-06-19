#include "JYApplication.h"
#include "jyInput.h"

namespace jy
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
	{
	}
	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
		mPlayerList = std::vector<GameObject>(2);
		mPlayerList[1].SetPosition(300, 300);
		mPlayerList[1].SetType(1);
		mPlayerList[1].SetKey(eKeyCode::W, eKeyCode::S, eKeyCode::A, eKeyCode::D);
		mPlayerList[1].SetColor(RGB(255, 0, 0));

		Input::Initialize();
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

		for(int i = 0; i < 2; i++)
		{
			mPlayerList[i].Update();
		}
		//mPlayer.Update();
	}
	void Application::LateUpdate()
	{
	}
	void Application::Render()
	{
		for (int i = 0; i < 2; i++)
		{
			mPlayerList[i].Render(mHdc);
		}
		//mPlayer.Render(mHdc);
	}
}