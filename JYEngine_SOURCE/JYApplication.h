#pragma once
#include "JYGameObject.h"

namespace jy
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();
		void Update();
		void LateUpdate();
		void Render();
	private:
		HWND mHwnd;
		HDC mHdc;
		GameObject mPlayer;
		std::vector<GameObject> mPlayerList;
	};
}