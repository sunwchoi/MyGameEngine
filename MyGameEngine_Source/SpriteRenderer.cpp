#include "SpriteRenderer.h"
#include "myGameObject.h"
#include "Transform.h"
#include "myTexture.h"

#include <mmsystem.h>
#include <dinput.h>
#pragma comment(lib, "Msimg32.lib");
#pragma comment(lib, "winmm.lib");

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib");

namespace my
{
	void SpriteRenderer::Initialize()
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
		float size = 100.f;

		Transform* transform = GetOwner()->GetComponent<Transform>();
		if ( transform == nullptr )
			return;

		float x = transform->getPosX();
		float y = transform->getPosY();
		Rectangle( hdc, x, y, x + size, y + size );

		Gdiplus::Graphics graphics( hdc );
		graphics.DrawImage( _texture->GetImage(), Gdiplus::Rect(x, y, _texture->GetWidth(), _texture->GetHeight()));
	}
}
