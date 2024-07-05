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
#include "jyPlayerScript.h"
#include "jyCamera.h"
#include "jyRenderer.h"

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
		// main camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		mPlayer = object::Instantiate<Player>
			(enums::eLayerType::Player);
		SpriteRenderer* sr
			= mPlayer->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(3.0f, 3.0f));
		mPlayer->AddComponent<PlayerScript>();

		graphics::Texture* hayoung =
			Resources::Find<graphics::Texture>(L"hayoung");
		sr->SetTexture(hayoung);

		GameObject* bg = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround);
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		bgSr->SetSize(Vector2(3.0f, 3.0f));

		graphics::Texture* bgTexture =
			Resources::Find<graphics::Texture>(L"heena");
		bgSr->SetTexture(bgTexture);

		// 게임 오브젝트 생성 후에 레이어와 게임 오브젝트들의 init 함수를 호출
		Scene::Initialize();
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