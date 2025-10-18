#include "myGameObject.h"

namespace my
{
	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
		for (int i = 0; i < _comps.size(); i++)
			delete _comps[i];
	}


	void GameObject::Initialize()
	{
		for (int i = 0; i < _comps.size(); i++)
			_comps[i]->Initialize();
	}

	void GameObject::Update()
	{
		for (int i = 0; i < _comps.size(); i++)
			_comps[i]->Update();
	}

	void GameObject::LateUpdate()
	{
		for (int i = 0; i < _comps.size(); i++)
			_comps[i]->LateUpdate();
	}

	void GameObject::Render( HDC hdc )
	{
		for (int i = 0; i < _comps.size(); i++)
			_comps[i]->Render(hdc);
	}

	void GameObject::SetMesh(const Mesh* const mesh)
	{
		_mesh = mesh;
	}

	const Mesh* GameObject::GetMesh() const
	{
		return _mesh;
	}
}
