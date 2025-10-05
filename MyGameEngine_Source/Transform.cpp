#include "Transform.h"
#include "myTime.h"
#include "Input.h"

namespace my
{
	Transform::Transform()
		: _scale(1, 1, 1)
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

	void Transform::SetPosition(const Vector3& position)
	{
		_position = position;
	}
	const Vector3& Transform::GetPosition() const
	{
		return _position;
	}

	void Transform::SetRotation(const Rotator& rotation)
	{
		_rotation = rotation;
	}

	const Rotator& Transform::GetRotation() const
	{
		return _rotation;
	}
	
	void Transform::SetScale(const Vector3& scale)
	{
		_scale = scale;
	}

	const Vector3& Transform::GetScale() const
	{
		return _scale;
	}

	void Transform::GetLocalAxes(Vector3& right, Vector3& up, Vector3& forward) const
	{

		float cosPitch = cosf(_rotation._pitch);
		float sinPitch = sinf(_rotation._pitch);
		float cosYaw = cosf(_rotation._yaw);
		float sinYaw = sinf(_rotation._yaw);
		float cosRoll = cosf(_rotation._roll);
		float sinRoll = sinf(_rotation._roll);

		// 회전된 기준 벡터들
		right._x = cosYaw * cosRoll + sinYaw * sinPitch * sinRoll;
		right._y = cosPitch * sinRoll;
		right._z = -sinYaw * cosRoll + cosYaw * sinPitch * sinRoll;

		up._x = -cosYaw * sinRoll + sinYaw * sinPitch * cosRoll;
		up._y = cosPitch * cosRoll;
		up._z = sinYaw * sinRoll + cosYaw * sinPitch * cosRoll;

		forward._x = sinYaw * cosPitch;
		forward._y = -sinPitch;
		forward._z = cosYaw * cosPitch;
	}

	Vector3 Transform::GetForward() const
	{
		return _rotation.GetForward();
	}

	Vector3 Transform::GetRight() const
	{
		return _rotation.GetRight();
	}

	Vector3 Transform::GetUp() const
	{
		return _rotation.GetUp();
	}
}
