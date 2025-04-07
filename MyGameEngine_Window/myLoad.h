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
		Resources::Load<Texture>(L"Background", L"..\\Resource\\Map.png");
		Resources::Load<Texture>(L"Player", L"..\\Resource\\Original_PacMan.png");
		Resources::Load<Texture>(L"Cat", L"..\\Resource\\ChickenAlpha.bmp");
	}

	void LoadScene()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");

		SceneManager::LoadScene(L"TitleScene");
	}
}