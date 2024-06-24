#pragma once
#include "../JYEngine_SOURCE/jySceneManager.h"
#include "jyPlayScene.h"

namespace jy
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}