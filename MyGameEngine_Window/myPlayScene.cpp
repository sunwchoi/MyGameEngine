#include "myPlayScene.h"
#include "myGameObject.h"
#include "Transform.h"
#include "SpriteRenderer.h"

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

		GameObject* object = new GameObject();
		object->AddComponent<Transform>();
		SpriteRenderer* spriteRenderer = object->AddComponent<SpriteRenderer>();

		spriteRenderer->ImageLoad( L"..\\Resource\\CloudOcean.png" );
		AddGameObject( object );
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render( HDC hdc )
	{
		Scene::Render( hdc );
	}
}
