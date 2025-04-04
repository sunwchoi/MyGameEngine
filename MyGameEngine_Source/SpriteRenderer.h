#pragma once
#include "Component.h"

namespace my
{
	class Texture;

	class SpriteRenderer : public Component
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render( HDC hdc ) override;

		const Texture* GetTexture() const { return _texture; }
		void SetTexture(Texture* texture) { _texture = texture; }

	private:
		Texture* _texture;
	};
}

