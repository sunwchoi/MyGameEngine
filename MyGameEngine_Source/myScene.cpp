#include "myScene.h"
#include "Layer.h"

namespace my
{
	Scene::Scene()
	{
		size_t count = (size_t)eLayerType::Count;
		
		_layers.resize(count);
		for (int i = 0; i < count; i++)
			_layers[i] = new Layer();
	}

	Scene::Scene(const std::wstring& name)
		: Entity(name)
	{
		size_t count = (size_t)eLayerType::Count;

		_layers.resize(count);
		for (int i = 0; i < count; i++)
			_layers[i] = new Layer();
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
		for (Layer* layer : _layers)
			layer->Initialize();
	}

	void Scene::Update()
	{
		for (Layer* layer : _layers)
			layer->Update();
	}
	void Scene::LateUpdate()
	{
		for (Layer* layer : _layers)
			layer->LateUpdate();
	}
	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : _layers)
			layer->Render( hdc );
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
