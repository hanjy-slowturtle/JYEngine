#pragma once
#include "../JYEngine_SOURCE/jySceneManager.h"
#include "jyPlayScene.h"
#include "jyTitleScene.h"

namespace jy
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}