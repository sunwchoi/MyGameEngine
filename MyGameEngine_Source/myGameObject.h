#pragma once

#include <windows.h>
#include "Component.h"
#include <vector>

namespace my
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		template<typename T>
		T* AddComponent()
		{
			T* comp = new T();

			comp->SetOwner( this );
			_comps.push_back( comp );

			return comp;
		}

		template<typename T>
		T* GetComponent()
		{
			T* ret = nullptr;
			for ( Component* comp : _comps )
			{
				ret = dynamic_cast< T* >( comp );
				if ( ret )
					break;
			}

			return ret;
		}

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render( HDC hdc );

	private:
		std::vector<Component*> _comps;
	};
}

