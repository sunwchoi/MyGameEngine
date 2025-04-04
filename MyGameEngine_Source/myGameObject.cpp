#include "myGameObject.h"

namespace my
{
	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
		for ( Component* comp : _comps )
			delete comp;
	}


	void GameObject::Initialize()
	{
		for (Component* comp : _comps)
			comp->Initialize();
	}

	void GameObject::Update()
	{
		for ( Component* comp : _comps )
			comp->Update();
	}

	void GameObject::LateUpdate()
	{
		for ( Component* comp : _comps )
			comp->LateUpdate();
	}

	void GameObject::Render( HDC hdc )
	{
		for ( Component* comp : _comps )
			comp->Render( hdc );
	}

}
