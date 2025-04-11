#pragma once

#include "../MyGameEngine_Source/mySceneManager.h"
#include "../MyGameEngine_Source/myTexture.h"
#include "../MyGameEngine_Source/myResources.h"
#include "myTitleScene.h"
#include "myPlayScene.h"

namespace my
{
	void LoadResource()
	{
		//Resources::Load<Texture>(L"Cat", L"..\\Resource\\ChickenAlpha.bmp");
		Resources::Load<Texture>(L"Background", L"..\\Resource\\Map.png");
		Resources::Load<Texture>(L"Idle", L"..\\Resource\\Samurai_Commander\\Idle.png");
		Resources::Load<Texture>(L"Walk", L"..\\Resource\\Samurai_Commander\\Walk.png");
		Resources::Load<Texture>(L"Run", L"..\\Resource\\Samurai_Commander\\Run.png");
		Resources::Load<Texture>(L"Attack1", L"..\\Resource\\Samurai_Commander\\Attack_1.png");
		Resources::Load<Texture>(L"Attack2", L"..\\Resource\\Samurai_Commander\\Attack_2.png");
		Resources::Load<Texture>(L"Attack3", L"..\\Resource\\Samurai_Commander\\Attack_3.png");
	}

	void LoadScene()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");

		SceneManager::LoadScene(L"TitleScene");
	}
}