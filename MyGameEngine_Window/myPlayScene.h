#pragma once
#include "myScene.h"

namespace my
{
	class PlayScene :
		public Scene
	{
	public :
		PlayScene();
		PlayScene(const std::wstring& name);
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render( HDC hdc ) override;
	};
}

