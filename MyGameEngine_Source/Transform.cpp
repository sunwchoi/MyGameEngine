#include "Transform.h"
#include "myTime.h"


namespace my
{
	Transform::Transform()
		: _x( 0 )
		, _y( 0 )
	{
	}

	void Transform::Initialize()
	{
	}

	void Transform::Run()
	{
	}

	void Transform::Update()
	{
		float speed = 100.f;
		if ( GetAsyncKeyState( VK_LEFT ) & 0x8000 )
			_x -= speed * Time::DeltaTime();

		if ( GetAsyncKeyState( VK_RIGHT ) & 0x8000 )
			_x += speed * Time::DeltaTime();

		if ( GetAsyncKeyState( VK_UP ) & 0x8000 )
			_y -= speed * Time::DeltaTime();

		if ( GetAsyncKeyState( VK_DOWN ) & 0x8000 )
			_y += speed * Time::DeltaTime();
	}

	void Transform::LateUpdate()
	{
	}

	void Transform::Render( HDC hdc )
	{
	}
}