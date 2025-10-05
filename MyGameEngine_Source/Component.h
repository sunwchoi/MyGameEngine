#pragma once

#include <windows.h>

namespace my
{
	class GameObject;

	class Component
	{
	public:
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render( HDC hdc );

		void		SetOwner( GameObject* owner ) { _owner = owner; }
		GameObject* GetOwner() const { return _owner; }

	private:
		GameObject* _owner;
	};
}

