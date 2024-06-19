#pragma once
#include "jyInput.h"

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
		void SetKey(eKeyCode upKey, eKeyCode downKey, eKeyCode leftKey, eKeyCode rightKey)
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
		eKeyCode mUpKey;
		eKeyCode mDownKey;
		eKeyCode mLeftKey;
		eKeyCode mRightKey;
		COLORREF mColor;
	};
}