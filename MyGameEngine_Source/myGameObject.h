#pragma once

#include <windows.h>

namespace my
{
	class GameObject
	{
	public:
		GameObject();
		explicit GameObject( float x, float y );
		~GameObject();
		
		void Update();
		void LateUpdate();
		void Render( HDC hdc );

		void setPos( float x, float y ) { _x = x; _y = y; }
		float getPosX() { return _x; }
		float getPosY() { return _y; }
	
	private:
		float _x;
		float _y;
	};
}

