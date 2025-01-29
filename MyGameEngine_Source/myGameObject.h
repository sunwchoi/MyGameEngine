#pragma once

#include <windows.h>

namespace my
{
	class GameObject
	{
	public:
		void Update();
		void Render( HDC hdc );

		void setPos( float x, float y ) { _x = x; _y = y; }
		float getPosX() { return _x; }
		float getPosY() { return _y; }
	
	private:
		float _x;
		float _y;
	};
}

