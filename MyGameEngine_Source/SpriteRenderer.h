#pragma once
#include "Component.h"
#include "myMath.h"

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

		const Texture*	GetTexture() const { return _texture; }
		void			SetTexture(Texture* texture) { _texture = texture; }
		
		const Vector2&	GetSize() const { return _size; }
		void			SetSize(const Vector2& size) { _size = size; }

	private:
		Texture*	_texture;
		Vector2		_size = Vector2(1.f, 1.f);
	};
}

