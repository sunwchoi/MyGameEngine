#include "myPlayScene.h"
#include "myGameObject.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "mySceneManager.h"
#include "myResources.h"
#include "myTexture.h"
#include "myPlayerScript.h"
#include "myCamera.h"
#include "myRenderer.h"

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
		//player 추가
		_player = new GameObject();
		_player->AddComponent<Transform>();

		renderer::mainCamera = _player->AddComponent<Camera>();

		SpriteRenderer* playerSpriteRenderer = _player->AddComponent<SpriteRenderer>();
		playerSpriteRenderer->SetTexture(Resources::Find<Texture>(L"Player"));
		playerSpriteRenderer->SetSize(Vector2(0.5f, 0.5f));

		_player->AddComponent<PlayerScript>();

		AddGameObject(_player, eLayerType::Player);
	
		// background 추가
		GameObject* background = new GameObject();
		background->AddComponent<Transform>();

		SpriteRenderer* backgroundSpriteRenderer = background->AddComponent<SpriteRenderer>();
		backgroundSpriteRenderer->SetTexture(Resources::Find<Texture>(L"Background"));
		backgroundSpriteRenderer->SetSize(Vector2(5.f, 5.f));
		AddGameObject(background, eLayerType::BackGround);

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
	
		transform->SetPosition(0, 0);
	}
}
