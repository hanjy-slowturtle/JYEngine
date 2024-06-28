#pragma once
#include "jyEntity.h"
#include "jyGameObject.h"
#include "jyLayer.h"

namespace jy
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObject, const eLayerType type);
	private:
		void CreateLayers();
		std::vector<Layer*> mLayers;
	};
}

