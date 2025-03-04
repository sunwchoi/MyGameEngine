#pragma once
#include "Component.h"

namespace my
{
	class SpriteRenderer : public Component
	{
	public:
		void Initialize() override;
		void Run() override;
		void Update() override;
		void LateUpdate() override;
		void Render( HDC hdc ) override;
	};
}

