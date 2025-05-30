#pragma once

#include <windows.h>
#include "Component.h"
#include "vector.hpp"
#include "myMesh.h"

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

		template<typename T>
		T& GetComponentMust()
		{
			T* ret = nullptr;
			for (Component* comp : _comps)
			{
				ret = dynamic_cast<T*>(comp);
				if (ret)
					return *ret;
			}

			MY_ASSERT_MSG(false, "반드시 있어야하는 Component가 없습니다.");
			return *ret;
		}

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render( HDC hdc );

		void SetMesh(const Mesh* const mesh);
		const Mesh* GetMesh() const;

	private:
		vector<Component*> _comps;

		const Mesh* _mesh;
	};
}

