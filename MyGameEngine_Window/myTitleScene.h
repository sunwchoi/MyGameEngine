#pragma once

#include "myScene.h"

namespace my
{
	class TitleScene 
		: public Scene
	{
	public:
		TitleScene() {};
		TitleScene(const std::wstring& name) : Scene(name) {};
		~TitleScene() {};

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	};
}

