#pragma once

#include <Windows.h>
#include <vector>

namespace my
{
	class GameObject;

	class Layer
	{
	public:
		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void AddGameObject(GameObject* object);

	private:
		std::vector<GameObject*> _gameObjects;

	};
}
