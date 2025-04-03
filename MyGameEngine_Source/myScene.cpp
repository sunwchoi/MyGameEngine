#include "myScene.h"
#include "Layer.h"

namespace my
{
	Scene::Scene()
	{
	}

	Scene::Scene(const std::wstring& name)
		: Entity(name)
	{
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
		size_t count = (size_t)eLayerType::Count;
		
		_layers.resize(count);
		for (int i = 0; i < count; i++)
			_layers[i] = new Layer();
	}

	void Scene::Update()
	{
		for (Layer* object : _layers)
			object->Update();
	}
	void Scene::LateUpdate()
	{
		for (Layer* object : _layers)
			object->LateUpdate();
	}
	void Scene::Render(HDC hdc)
	{
		for (Layer* object : _layers)
			object->Render( hdc );
	}

	void Scene::AddGameObject(GameObject* gameObject, eLayerType layerType)
	{
		_layers[(uint8)layerType]->AddGameObject(gameObject);
	}

	void Scene::OnEnter()
	{
	}

	void Scene::OnExit()
	{
	}

}
