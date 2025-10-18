#pragma once

#include <vector>
#include <string>
#include <windows.h>
#include "myEnum.h"
#include "myEntity.h"

namespace my
{
	class GameObject;
	class Layer;

	class Scene
		: public Entity
	{
	public:
		Scene();
		explicit Scene( const std::wstring& name );
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject, eLayerType layerType);

		virtual void OnEnter();
		virtual void OnExit();

	private:
		std::vector<Layer*> _layers;
	};
}

