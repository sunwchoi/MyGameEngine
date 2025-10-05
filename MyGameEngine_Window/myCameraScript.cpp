#include "myCameraScript.h"

#include <iostream>

#include "Input.h"
#include "myGameObject.h"
#include "myTime.h"
#include "Transform.h"

namespace my
{
	void CameraScript::Initialize()
	{
	}

	void CameraScript::Update()
	{
		if (Input::GetKey(eKeyCode::RBUTTON))
		{
			Move();
			Rotate();
		}
	}

	void CameraScript::LateUpdate()
	{
	}

	void CameraScript::Render(HDC hdc)
	{
	}

	void CameraScript::Move()
	{
		Transform& transform = GetOwner()->GetComponentMust<Transform>();
		if (Input::GetKey(eKeyCode::W))
		{
			transform.SetPosition(transform.GetForward() * _moveSpeed * Time::DeltaTime() + transform.GetPosition());
		}

		if (Input::GetKey(eKeyCode::S))
		{
			transform.SetPosition(transform.GetForward() * -_moveSpeed * Time::DeltaTime() + transform.GetPosition());
		}

		if (Input::GetKey(eKeyCode::A))
		{
			transform.SetPosition(transform.GetRight() * -_moveSpeed * Time::DeltaTime() + transform.GetPosition());
		}

		if (Input::GetKey(eKeyCode::D))
		{
			transform.SetPosition(transform.GetRight() * _moveSpeed * Time::DeltaTime() + transform.GetPosition());
		}
	}

	void CameraScript::Rotate()
	{
		Transform& transform = GetOwner()->GetComponentMust<Transform>();

		const Vector2& mouseDelta = Input::GetMouseDelta();
		transform.SetRotation(transform.GetRotation() + Rotator(-mouseDelta._y * _rotationSpeed * Time::DeltaTime(), -mouseDelta._x * _rotationSpeed * Time::DeltaTime(), 0));
	}
}
