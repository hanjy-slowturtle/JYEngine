#include "jyPlayScene.h"
#include "jyGameObject.h"
#include "jyPlayer.h"
#include "jyTransform.h"
#include "jySpriteRenderer.h"
#include "jyInput.h"
#include "jySceneManager.h"
#include "jyObject.h"
#include "jyTexture.h"
#include "jyResources.h"

namespace jy
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		{
			bg = object::Instantiate<Player>
				(enums::eLayerType::BackGround);
			SpriteRenderer* sr
				= bg->AddComponent<SpriteRenderer>();
			graphics::Texture* bg = Resources::Find<graphics::Texture>(L"hayoung");
			sr->SetTexture(bg);

			// 게임 오브젝트 생성 후에 레이어와 게임 오브젝트들의 init 함수를 호출
			Scene::Initialize();
		}
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}