#pragma once

#include "myMath.h"

namespace my
{
	class Rotator
	{
	public:
		Rotator();
		Rotator(float pitch, float yaw, float roll);
		~Rotator();

		Rotator		operator+(const Rotator& other) const;
		Rotator		operator-(const Rotator& other) const;
		Rotator&	operator+=(const Rotator& other);
		Rotator&	operator-=(const Rotator& other);
		bool		operator==(const Rotator& other) const;
		bool		operator!=(const Rotator& other) const;

		Vector3	GetForward() const;
		Vector3	GetRight() const;
		Vector3 GetUp() const;

	public:
		float _pitch;
		float _yaw;
		float _roll;
	};
}

