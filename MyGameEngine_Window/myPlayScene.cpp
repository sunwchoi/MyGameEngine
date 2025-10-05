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
#include "myAnimator.h"
#include "myMeshRenderer.h"
#include "mySkeletalMesh.h"
#include "myApplication.h"
#include "myCameraScript.h"

extern my::Application application;

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
		MeshRenderer* meshRenderer = _player->AddComponent<MeshRenderer>();
		meshRenderer->SetSkeletalMesh(Resources::Find<SkeletalMesh>(L"SkeletalMesh"));
		//meshRenderer->SetMesh(Resources::Find<Mesh>(L"BasicMesh"));
		_player->AddComponent<PlayerScript>();

		AddGameObject(_player, eLayerType::Player);


		//SpriteRenderer* playerSpriteRenderer = _player->AddComponent<SpriteRenderer>();
		//playerSpriteRenderer->SetTexture(Resources::Find<Texture>(L"Player"));
		//playerSpriteRenderer->SetSize(Vector2(0.5f, 0.5f));


		_camera = new GameObject();
		_camera->AddComponent<Transform>();
		_camera->AddComponent<CameraScript>();
		renderer::mainCamera = _camera->AddComponent<Camera>();

		AddGameObject(_camera, eLayerType::Player);

		//Animator* animator = _player->AddComponent<Animator>();
		//animator->CreateAnimation(L"LeftIdle", Resources::Find<Texture>(L"Idle"), Vector2(0, 0.f), Vector2(128.f, 128.f), Vector2(0.f, 0.f), 5, 0.2f, true);
		//animator->CreateAnimation(L"RightIdle", Resources::Find<Texture>(L"Idle"), Vector2(0.f, 0.f), Vector2(128.f, 128.f), Vector2(0.f, 0.f), 5, 0.2f);
		//animator->CreateAnimation(L"LeftWalk", Resources::Find<Texture>(L"Walk"), Vector2(0.f, 0.f), Vector2(128.f, 128.f), Vector2(0.f, 0.f), 9, 0.2f, true);
		//animator->CreateAnimation(L"RightWalk", Resources::Find<Texture>(L"Walk"), Vector2(0.f, 0.f), Vector2(128.f, 128.f), Vector2(0.f, 0.f), 9, 0.2f);
		//animator->CreateAnimation(L"LeftRun", Resources::Find<Texture>(L"Run"), Vector2(0.f, 0.f), Vector2(128.f, 128.f), Vector2(0.f, 0.f), 8, 0.2f, true);
		//animator->CreateAnimation(L"RightRun", Resources::Find<Texture>(L"Run"), Vector2(0.f, 0.f), Vector2(128.f, 128.f), Vector2(0.f, 0.f), 8, 0.2f);
		//animator->CreateAnimation(L"LeftAttack1", Resources::Find<Texture>(L"Attack1"), Vector2(0.f, 0.f), Vector2(128.f, 128.f), Vector2(0.f, 0.f), 4, 0.1f, true);
		//animator->CreateAnimation(L"RightAttack1", Resources::Find<Texture>(L"Attack1"), Vector2(0.f, 0.f), Vector2(128.f, 128.f), Vector2(0.f, 0.f), 4, 0.1f);
		//animator->CreateAnimation(L"LeftAttack2", Resources::Find<Texture>(L"Attack2"), Vector2(0.f, 0.f), Vector2(128.f, 128.f), Vector2(0.f, 0.f), 5, 0.08f, true);
		//animator->CreateAnimation(L"RightAttack2", Resources::Find<Texture>(L"Attack2"), Vector2(0.f, 0.f), Vector2(128.f, 128.f), Vector2(0.f, 0.f), 5, 0.08f);
		//animator->CreateAnimation(L"LeftAttack3", Resources::Find<Texture>(L"Attack3"), Vector2(0.f, 0.f), Vector2(128.f, 128.f), Vector2(0.f, 0.f), 4, 0.1f, true);
		//animator->CreateAnimation(L"RightAttack3", Resources::Find<Texture>(L"Attack3"), Vector2(0.f, 0.f), Vector2(128.f, 128.f), Vector2(0.f, 0.f), 4, 0.1f);
		//animator->PlayAnimation(L"RightIdle");


		// 임시 선택
		application.SetSelectedObject(_player);
	
		// background 추가
		//GameObject* background = new GameObject();
		//background->AddComponent<Transform>();

		// camera
		Transform tf = renderer::mainCamera->GetTransform();
		tf.SetPosition(Vector3(0, 100, -150));
		//tf.SetRotation(Rotator(0, 0, 0));
		
		renderer::mainCamera->SetTransform(tf);

		//SpriteRenderer* backgroundSpriteRenderer = background->AddComponent<SpriteRenderer>();
		//backgroundSpriteRenderer->SetTexture(Resources::Find<Texture>(L"Background"));
		//backgroundSpriteRenderer->SetSize(Vector2(5.f, 5.f));
		//AddGameObject(background, eLayerType::BackGround);

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
	
		//transform->SetPosition(0, 0);
	}
}
