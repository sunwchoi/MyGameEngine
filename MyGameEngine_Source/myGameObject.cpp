#include "myGameObject.h"
#include "myTime.h"

namespace my
{
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

	void GameObject::Render( HDC hdc )
	{
		HBRUSH blueBrush = CreateSolidBrush( RGB( 0, 0, 255 ) );
		HBRUSH oldBrush = ( HBRUSH )SelectObject( hdc, blueBrush );

		Rectangle( hdc, 100 + _x, 100 + _y, 200 + _x, 200 + _y );

		SelectObject( hdc, oldBrush );
		DeleteObject( blueBrush );
	}

}
