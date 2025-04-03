#pragma once

#include <map>
#include <string>
#include <windows.h>
#include "myScene.h"

namespace my
{

	class SceneManager
	{
	public:
		SceneManager();
		~SceneManager();

		template<typename T>
		static Scene* CreateScene( const std::wstring& name )
		{
			if ( _scenes[name] != nullptr )
				return nullptr;
			
			T* scene = new T( name );

			scene->Initialize();
			_scenes[name] = scene;
			
			// 만들어진 Scene 리턴
			return scene;
		}

		static Scene* LoadScene( const std::wstring& name )
		{
			if (_activeScene)
				_activeScene->OnExit();

			std::map<std::wstring, Scene*>::iterator it = _scenes.find( name );

			if ( it == _scenes.end() )
				return nullptr;

			_activeScene = it->second;
			_activeScene->OnEnter();

			return _activeScene;
		}


		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render( HDC hdc );

		static Scene* getActiveScene() { return _activeScene; };
	private:
		static std::map<std::wstring, Scene*> _scenes;
		static Scene* _activeScene;
	};
}

