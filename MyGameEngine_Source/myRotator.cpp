#include "myRotator.h"

#include <cmath> // cos, sin

namespace my
{
	Rotator::Rotator() : _pitch(0.f), _yaw(0.f), _roll(0.f)
	{
	}

	Rotator::Rotator(float pitch, float yaw, float roll) : _pitch(pitch), _yaw(yaw), _roll(roll)
	{
	}

	Rotator::~Rotator()
	{
	}

	Rotator Rotator::operator+(const Rotator& other) const
	{
		return Rotator(_pitch + other._pitch, _yaw + other._yaw, _roll + other._roll);
	}

	Rotator Rotator::operator-(const Rotator& other) const
	{
		return Rotator(_pitch - other._pitch, _yaw - other._yaw, _roll - other._roll);
	}

	Rotator& Rotator::operator+=(const Rotator& other)
	{
		_pitch += other._pitch;
		_yaw += other._yaw;
		_roll += other._roll;
		
		return *this;
	}

	Rotator& Rotator::operator-=(const Rotator& other)
	{
		_pitch -= other._pitch;
		_yaw -= other._yaw;
		_roll -= other._roll;

		return *this;
	}

	bool Rotator::operator==(const Rotator& other) const
	{
		return (_pitch == other._pitch && _yaw == other._yaw && _roll == other._roll);
	}

	bool Rotator::operator!=(const Rotator& other) const
	{
		return (_pitch == other._pitch && _yaw == other._yaw && _roll == other._roll) == false;
	}

	Vector3 Rotator::GetForward() const
	{
		return Vector3(sinf(_yaw) * cosf(_pitch), -sinf(_pitch), cosf(_yaw) * cosf(_pitch));
	}

	Vector3 Rotator::GetRight() const
	{
		return Vector3(
			cosf(_yaw) * cosf(_roll) + sinf(_yaw) * sinf(_pitch) * sinf(_roll),
			cosf(_pitch) * sinf(_roll),
			-sinf(_yaw) * cosf(_roll) + cosf(_yaw) * sinf(_pitch) * sinf(_roll)
		);
	}

	Vector3 Rotator::GetUp() const
	{
		return Vector3(
			-cosf(_yaw) * sinf(_roll) + sinf(_yaw) * sinf(_pitch) * cosf(_roll),
			cosf(_pitch) * cosf(_roll),
			sinf(_yaw) * sinf(_roll) + cosf(_yaw) * sinf(_pitch) * cosf(_roll)
		);
	}
}
