#include "SpriteRenderer.h"
#include "myGameObject.h"
#include "Transform.h"
#include "myTexture.h"
#include "myCamera.h"
#include "myRenderer.h"
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

		const Vector2& position = renderer::mainCamera->CalculatePosition(transform->GetPosition());
		
		Gdiplus::Graphics graphics( hdc );
		graphics.DrawImage( _texture->GetImage(), Gdiplus::Rect(position._x - _texture->GetWidth() / 2, position._y - _texture->GetHeight() / 2, _texture->GetWidth(), _texture->GetHeight()));
	}
}
