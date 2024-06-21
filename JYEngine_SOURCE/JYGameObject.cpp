#include "JYGameObject.h"
#include "jyTime.h"

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
		const float speed = 100.0f * Time::DeltaTime();
		if (Input::GetKey(mLeftKey))
		{
			mX -= speed;
		}
		if (Input::GetKey(mRightKey))
		{
			mX += speed;
		}
		if (Input::GetKey(mUpKey))
		{
			mY -= speed;
		}
		if (Input::GetKey(mDownKey))
		{
			mY += speed;
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