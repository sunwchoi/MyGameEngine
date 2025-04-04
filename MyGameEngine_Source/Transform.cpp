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

	void Transform::Update()
	{
	}

	void Transform::LateUpdate()
	{
	}

	void Transform::Render( HDC hdc )
	{
	}
	void Transform::Move(float dx, float dy)
	{
		_x += dx;
		_y += dy;
	}
}