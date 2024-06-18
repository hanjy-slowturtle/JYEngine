#include "JYApplication.h"
#include "CommonInclude.h"

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
		mPlayerList = std::vector<GameObject>();
		GameObject mPlayer1 = GameObject();
		mPlayer1.SetPosition(0, 0);
		mPlayer1.SetType(0);
		mPlayer1.SetKey(VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT);
		mPlayer1.SetColor(RGB(0, 0, 255));
		mPlayerList.push_back(mPlayer1);
		GameObject mPlayer2 = GameObject();
		mPlayer2.SetPosition(300, 300);
		mPlayer2.SetType(1);
		mPlayer2.SetKey('W', 'S', 'A', 'D');
		mPlayer2.SetColor(RGB(255, 0, 0));
		mPlayerList.push_back(mPlayer2);
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
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