#pragma once

#include <myGameObject.h>
#include <Layer.h>
#include <mySceneManager.h>

namespace my::object
{
	template<typename T>
	T* Instantiate(GameObject* gameObject, eLayerType layerType)
	{
		Scene* scene = SceneManager::getActiveScene();

		scene->AddGameObject(gameObject, layerType);

		return gameObject;
	}
}
