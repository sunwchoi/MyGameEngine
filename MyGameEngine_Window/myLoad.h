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
		Resources::Load<Texture>(L"RightIdle", L"..\\Resource\\Samurai_Archer\\Idle.png");
		Resources::Load<Texture>(L"RightWalk", L"..\\Resource\\Samurai_Archer\\Walk.png");
		Resources::Load<Texture>(L"RightRun", L"..\\Resource\\Samurai_Archer\\Run.png");
		Resources::Load<Texture>(L"LeftIdle", L"..\\Resource\\Samurai_Archer\\LeftIdle.png");
		Resources::Load<Texture>(L"LeftWalk", L"..\\Resource\\Samurai_Archer\\LeftWalk.png");
		Resources::Load<Texture>(L"LeftRun", L"..\\Resource\\Samurai_Archer\\LeftRun.png");
	}

	void LoadScene()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");

		SceneManager::LoadScene(L"TitleScene");
	}
}