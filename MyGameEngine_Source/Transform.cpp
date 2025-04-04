#include "Transform.h"
#include "myTime.h"
#include "Input.h"

namespace my
{
	Transform::Transform()
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
		_position._x += dx;
		_position._y += dy;
	}
}