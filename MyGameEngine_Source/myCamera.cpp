#include "myCamera.h"
#include "myApplication.h"

extern my::Application application;

namespace my
{
	Camera::Camera()
		: _fov(45.f)
	{
	}

	Camera::~Camera()
	{
	}

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
		GetOwner()->GetComponentMust<Transform>() = transform;
	}

	const Transform& Camera::GetTransform() const
	{
		return GetOwner()->GetComponentMust<Transform>();
	}

	void Camera::SetFOV(float fov)
	{
		_fov = fov;
	}

	float Camera::GetFOV() const
	{
		return _fov;
	}
}
