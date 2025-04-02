#include "Layer.h"
#include "myGameObject.h"


namespace my
{
	void Layer::Update()
	{
		for (GameObject* gameObject : _gameObjects)
			gameObject->Update();
	}

	void Layer::LateUpdate()
	{
		for (GameObject* gameObject : _gameObjects)
			gameObject->LateUpdate();
	}

	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameObject : _gameObjects)
			gameObject->Render(hdc);
	}

	void Layer::AddGameObject(GameObject* object)
	{
		_gameObjects.push_back(object);
	}
}
