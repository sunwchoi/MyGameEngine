#pragma once

#include "Component.h"

namespace my
{
	class Script
		: public Component
	{
	public:
		Script();
		~Script();
		
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
	};
}

