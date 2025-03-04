#pragma once
#include "Component.h"

namespace my
{
	class Transform : public Component
	{
	public:
		Transform();

		void Initialize() override;
		void Run() override;
		void Update() override;
		void LateUpdate() override;
		void Render( HDC hdc ) override;

		void setPos( float x, float y ) { _x = x; _y = y; }
		float getPosX() { return _x; }
		float getPosY() { return _y; }

	private:
		float _x;
		float _y;
	};

}

