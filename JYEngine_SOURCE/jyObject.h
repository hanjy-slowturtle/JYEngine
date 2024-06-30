#pragma once
#include "jyComponent.h"
#include "jyGameObject.h"
#include "jyLayer.h"
#include "jyScene.h"
#include "jySceneManager.h"
#include "jyTransform.h"

namespace jy
{
	namespace object
	{
		template <typename T>
		static T* Instantiate(jy::enums::eLayerType type)
		{
			T* gameObject = new T();
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);

			return gameObject;
		}

		template <typename T>
		static T* Instantiate(jy::enums::eLayerType type, math::Vector2 position)
		{
			T* gameObject = new T();
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);

			Transform* tr = gameObject->GetComponent<Transform>();
			tr->SetPosition(position);

			return gameObject;
		}
	}
}