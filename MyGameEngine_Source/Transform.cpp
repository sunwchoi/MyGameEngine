#include "Transform.h"
#include "myTime.h"
#include "Input.h"

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
		if (Input::GetKey(eKeyCode::A))
			_x -= speed * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::D))
			_x += speed * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::W))
			_y -= speed * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::S))
			_y += speed * Time::DeltaTime();
	}

	void Transform::LateUpdate()
	{
	}

	void Transform::Render( HDC hdc )
	{
	}
}