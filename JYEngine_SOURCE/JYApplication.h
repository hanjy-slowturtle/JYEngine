#pragma once
#include "jyGameObject.h"

namespace jy
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

		HDC GetHDC() { return mHdc; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
	private:
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);

		HWND mHwnd;
		HDC mHdc;
		GameObject mPlayer;
		std::vector<GameObject> mPlayerList;
		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;
	};
}