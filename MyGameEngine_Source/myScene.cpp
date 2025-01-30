#include "myScene.h"
#include "myGameObject.h"

namespace my
{
	Scene::Scene()
	{
	}

	Scene::Scene(const std::wstring& name)
		: _name ( name )
	{
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
	}

	void Scene::Update()
	{
		for (GameObject* object : _gameObjects)
			object->Update();
	}
	void Scene::LateUpdate()
	{
		for (GameObject* object : _gameObjects)
			object->LateUpdate();
	}
	void Scene::Render(HDC hdc)
	{
		for (GameObject* object : _gameObjects)
			object->Render( hdc );
	}
	void Scene::AddGameObject(GameObject* object)
	{
		_gameObjects.push_back( object );
	}
}
