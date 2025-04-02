#pragma once

#include "../MyGameEngine_Source/mySceneManager.h"
#include "myTitleScene.h"
#include "myPlayScene.h"

namespace my
{
	void LoadScene()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");

		SceneManager::LoadScene(L"TitleScene");
	}
}