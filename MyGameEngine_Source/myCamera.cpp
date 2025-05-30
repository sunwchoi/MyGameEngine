#include "myCamera.h"
#include "myApplication.h"
#include "Transform.h"

extern my::Application application;

namespace my
{
	void Camera::Initialize()
	{
		_resolution._x = application.GetWidth();
		_resolution._y = application.GetHeight();
	}

	void Camera::Update()
	{
		Transform* transform = _target ? _target->GetComponent<Transform>() : GetOwner()->GetComponent<Transform>();

		//_lookPosition = transform->GetPosition();
		//_distance = _lookPosition - (_resolution / 2.0f);
	}

	void Camera::LateUpdate()
	{
	}

	void Camera::Render(HDC hdc)
	{
	}
	Vector2 Camera::CalculatePosition(const Vector2& pos) const
	{
		return pos - _distance;
	}
	Vector2 Camera::DecalculatePosition(const Vector2& pos) const
	{
		return pos + _distance;
	}
}
