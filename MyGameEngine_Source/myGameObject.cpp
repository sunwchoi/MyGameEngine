#include "myGameObject.h"
#include "myTime.h"

namespace my
{
	GameObject::GameObject()
		: _x( 0 )
		, _y( 0 )
	{
	}

	GameObject::GameObject( float x, float y )
		: _x ( x )
		, _y ( y )
	{
	}

	GameObject::~GameObject()
	{
	}


	void GameObject::Update()
	{
		float speed = 100.f;
		if ( GetAsyncKeyState( VK_LEFT ) & 0x8000 )
			_x -= speed * Time::DeltaTime();

		if ( GetAsyncKeyState( VK_RIGHT ) & 0x8000 )
			_x += speed * Time::DeltaTime();

		if ( GetAsyncKeyState( VK_UP) & 0x8000 )
			_y -= speed * Time::DeltaTime();
	
		if ( GetAsyncKeyState( VK_DOWN ) & 0x8000 )
			_y += speed * Time::DeltaTime();
	}

	void GameObject::LateUpdate()
	{
	}

	void GameObject::Render( HDC hdc )
	{
		HBRUSH blueBrush = CreateSolidBrush( RGB( 0, 0, 255 ) );
		HBRUSH oldBrush = ( HBRUSH )SelectObject( hdc, blueBrush );

		float size = 100.f;
		Rectangle( hdc, _x, _y, _x + size, _y + size);

		SelectObject( hdc, oldBrush );
		DeleteObject( blueBrush );
	}

}
