#include "myCamera.h"
#include "myApplication.h"

extern my::Application application;

namespace my
{
	void Camera::Initialize()
	{
	}

	void Camera::Update()
	{
	}

	void Camera::LateUpdate()
	{
	}

	void Camera::Render(HDC hdc)
	{
	}

	void Camera::SetTarget(GameObject* target)
	{
		_target = target;
	}

	const GameObject* Camera::GetTarget() const
	{
		return _target;
	}

	void Camera::SetTransform(const Transform& transform)
	{
		_transform = transform;
	}

	const Transform& Camera::GetTransform() const
	{
		return _transform;
	}
}
