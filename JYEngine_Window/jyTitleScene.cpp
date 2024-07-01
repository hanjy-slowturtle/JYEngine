#include "jyTitleScene.h"
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
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		bg = object::Instantiate<Player>
			(enums::eLayerType::BackGround);
		SpriteRenderer* sr
			= bg->AddComponent<SpriteRenderer>();
		graphics::Texture* bg = Resources::Find<graphics::Texture>(L"heena");
		sr->SetTexture(bg);

		// ���� ������Ʈ ���� �Ŀ� ���̾�� ���� ������Ʈ���� init �Լ��� ȣ��
		Scene::Initialize();

		Scene::Initialize();
	}
	void TitleScene::Update()
	{
		Scene::Update();
	}
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);
	}
}