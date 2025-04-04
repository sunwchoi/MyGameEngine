#include "myPlayScene.h"
#include "myGameObject.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "mySceneManager.h"
#include "myResources.h"
#include "myTexture.h"
#include "myPlayerScript.h"

namespace my
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::PlayScene( const std::wstring& name )
		: Scene( name )
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		_player = new GameObject();
		_player->AddComponent<Transform>();

		SpriteRenderer* spriteRenderer = _player->AddComponent<SpriteRenderer>();
		spriteRenderer->SetTexture(Resources::Find<Texture>(L"Background"));

		_player->AddComponent<PlayerScript>();

		AddGameObject(_player, eLayerType::BackGround);
	
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
			SceneManager::LoadScene(L"TitleScene");
	}

	void PlayScene::Render( HDC hdc )
	{
		Scene::Render( hdc );
	}

	void PlayScene::OnExit()
	{
		Transform* transform = _player->GetComponent<Transform>();
	
		transform->setPos(0, 0);
	}
}
