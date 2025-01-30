#pragma once

#include "../MyGameEngine_Source/mySceneManager.h"
#include "myPlayScene.h"

namespace my
{
	void LoadScene()
	{
		SceneManager::CreateScene<PlayScene>( L"PlayScene" );
		
		SceneManager::LoadScene( L"PlayScene" );
	}
}