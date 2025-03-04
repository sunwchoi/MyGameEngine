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
		float size = 100.f;

		Transform* transform = GetOwner()->GetComponent<Transform>();
		if ( transform == nullptr )
			return;

		float x = transform->getPosX();
		float y = transform->getPosY();
		Rectangle( hdc, x, y, x + size, y + size );

		Gdiplus::Graphics graphics( hdc );
		graphics.DrawImage( _image, Gdiplus::Rect( x, y, _width, _height ) );
	}

	void SpriteRenderer::ImageLoad( const std::wstring& path )
	{
		_image = Gdiplus::Image::FromFile( path.c_str() );
		_width = _image->GetWidth();
		_height = _image->GetHeight();
	}
}
