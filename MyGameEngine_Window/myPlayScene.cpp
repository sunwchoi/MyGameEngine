#include "myPlayScene.h"
#include "myGameObject.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "mySceneManager.h"

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
		Scene::Initialize();

		_player = new GameObject();
		_player->AddComponent<Transform>();
		SpriteRenderer* spriteRenderer = _player->AddComponent<SpriteRenderer>();

		spriteRenderer->ImageLoad( L"..\\Resource\\CloudOcean.png" );
		AddGameObject(_player, eLayerType::BackGround);
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
