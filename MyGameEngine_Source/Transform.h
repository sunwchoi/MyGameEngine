#pragma once
#include "Component.h"
#include "myMath.h"
#include "myRotator.h"

namespace my
{
	class Transform : public Component
	{
	public:
		Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render( HDC hdc ) override;

		void SetPosition(const Vector3& position);
		const Vector3& GetPosition() const;

		void SetRotation(const Rotator& rotation);
		const Rotator& GetRotation() const;

		void SetScale(const Vector3& scale);
		const Vector3& GetScale() const;

		void GetLocalAxes(__out Vector3& right, __out Vector3& up, __out Vector3& forward) const;

		Vector3 GetForward() const;
		Vector3 GetRight() const;
		Vector3 GetUp() const;

	private:
		Vector3 _position;
		Vector3 _scale;
		Rotator _rotation;
	};

}

