#include "jyPlayer.h"
#include "jyInput.h"
#include "jyTransform.h"
#include "jyTime.h"

namespace jy
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}
	void Player::Update()
	{
		GameObject::Update();
	}
	void Player::LateUpdate()
	{
		GameObject::LateUpdate();

		if (Input::GetKey(eKeyCode::RIGHT))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
	}
	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}