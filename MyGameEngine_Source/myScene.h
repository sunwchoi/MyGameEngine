#pragma once

#include <vector>
#include <string>
#include <windows.h>

namespace my
{
	class GameObject;

	class Scene
	{
	public:
		Scene();
		explicit Scene( const std::wstring& name );
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject( GameObject* object );
	
	private:
		std::vector<GameObject*> _gameObjects;
		std::wstring _name;
	};
}

