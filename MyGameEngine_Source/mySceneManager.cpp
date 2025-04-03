#include "mySceneManager.h"
#include "myScene.h"

namespace my
{
	std::map<std::wstring, Scene*> SceneManager::_scenes = {} ;
	Scene* SceneManager::_activeScene = nullptr;

	SceneManager::SceneManager()
	{
	}

	SceneManager::~SceneManager()
	{
	}

	void SceneManager::Initialize()
	{
		for (std::pair<std::wstring, Scene*> scenePair : _scenes)
			scenePair.second->Initialize();
	}

	void SceneManager::Update()
	{
		if ( _activeScene )
			_activeScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		if ( _activeScene )
			_activeScene->LateUpdate();
	}
	void SceneManager::Render( HDC hdc )
	{
		if ( _activeScene )
			_activeScene->Render( hdc );
	}
}
