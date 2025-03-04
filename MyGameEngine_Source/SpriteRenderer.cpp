#include "SpriteRenderer.h"
#include "myGameObject.h"
#include "Transform.h"

namespace my
{
	void SpriteRenderer::Initialize()
	{
	}

	void SpriteRenderer::Run()
	{
	}

	void SpriteRenderer::Update()
	{
	}

	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render( HDC hdc )
	{

		HBRUSH blueBrush = CreateSolidBrush( RGB( 0, 0, 255 ) );
		HBRUSH oldBrush = ( HBRUSH ) SelectObject( hdc, blueBrush );

		float size = 100.f;

		Transform* transform = GetOwner()->GetComponent<Transform>();
		if ( transform == nullptr )
			return;

		float x = transform->getPosX();
		float y = transform->getPosY();
		Rectangle( hdc, x, y, x + size, y + size );

		SelectObject( hdc, oldBrush );
		DeleteObject( blueBrush );
	}
}
