#include "SpriteRenderer.h"
#include "myGameObject.h"
#include "Transform.h"
#include "myTexture.h"
#include "myCamera.h"
#include "myRenderer.h"
#include <mmsystem.h>
#include <dinput.h>
#include <gdiplus.h>

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

		const Vector2& pos = renderer::mainCamera->CalculatePosition(transform->GetPosition());

		BLENDFUNCTION blendFunction;

		blendFunction.BlendOp = AC_SRC_OVER;
		blendFunction.BlendFlags = 0;
		blendFunction.AlphaFormat = AC_SRC_ALPHA;
		blendFunction.SourceConstantAlpha = 255;

		AlphaBlend(hdc, pos._x, pos._y, _texture->GetWidth(), _texture->GetHeight(), _texture->GetHDC(), 0, 0, _texture->GetWidth(), _texture->GetHeight(), blendFunction);
		
	}
}
