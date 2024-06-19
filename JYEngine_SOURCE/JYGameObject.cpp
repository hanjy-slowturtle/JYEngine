#include "JYGameObject.h"

namespace jy
{
	GameObject::GameObject()
	{
		mX = 0;
		mY = 0;
		mType = 0;
		mUpKey = eKeyCode::UP;
		mDownKey = eKeyCode::DOWN;
		mLeftKey = eKeyCode::LEFT;
		mRightKey = eKeyCode::RIGHT;
		mColor = RGB(0, 0, 255);
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Update()
	{
		if (Input::GetKey(mLeftKey))
		{
			mX -= 0.01f;
		}
		if (Input::GetKey(mRightKey))
		{
			mX += 0.01f;
		}
		if (Input::GetKey(mUpKey))
		{
			mY -= 0.01f;
		}
		if (Input::GetKey(mDownKey))
		{
			mY += 0.01f;
		}
	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render(HDC hdc)
	{
		// �귯�� ����
		HBRUSH brush = CreateSolidBrush(mColor);

		// �귯�� DC�� ����, �׸��� ���� hdc ��ȯ�� ����
		HBRUSH prevBrush = (HBRUSH)SelectObject(hdc, brush);

		if (mType == 0)
		{
			Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
		}
		else
		{
			Ellipse(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
		}

		// ���� �귯�� ����
		SelectObject(hdc, prevBrush);

		// �귯�� ����
		DeleteObject(brush);
	}
}