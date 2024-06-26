#pragma once
#include "../JYEngine_SOURCE/jyGameObject.h"

namespace jy
{
	class Player : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};
}
