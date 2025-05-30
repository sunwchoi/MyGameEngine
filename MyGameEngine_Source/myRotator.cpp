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
}
