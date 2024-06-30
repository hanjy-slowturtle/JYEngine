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

		void AddGameObject(GameObject* gameObject, const enums::eLayerType type);
		Layer* GetLayer(enums::eLayerType type) { return mLayers[(UINT)type];  }
	private:
		void createLayers();
		std::vector<Layer*> mLayers;
	};
}

