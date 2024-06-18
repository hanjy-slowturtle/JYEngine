#pragma once
#include "CommonInclude.h"

namespace jy
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}
		void SetType(int type)
		{
			mType = type;
		}
		void SetKey(int upKey, int downKey, int leftKey, int rightKey)
		{
			mUpKey = upKey;
			mDownKey = downKey;
			mLeftKey = leftKey;
			mRightKey = rightKey;
		}
		void SetColor(COLORREF color)
		{
			mColor = color;
		}
	private:
		float mX;
		float mY;
		int mType;
		int mUpKey;
		int mDownKey;
		int mLeftKey;
		int mRightKey;
		COLORREF mColor;
	};
}