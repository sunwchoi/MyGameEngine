#include "myMath.h"

namespace my
{
	Vector2 Vector2::operator+(const Vector2& other) const
	{
		return Vector2(_x + other._x, _y + other._y);
	}

	Vector2 Vector2::operator-(const Vector2& other) const
	{
		return Vector2(_x - other._x, _y - other._y);
	}

	Vector2 Vector2::operator*(float value) const
	{
		return Vector2(_x * value, _y * value);
	}

	Vector2 Vector2::operator/(float value) const
	{
		return Vector2(_x / value, _y / value);
	}

	Vector2& Vector2::operator+=(const Vector2& other)
	{
		_x += other._x;
		_y += other._y;

		return *this;
	}

	Vector2& Vector2::operator-=(const Vector2& other)
	{
		_x -= other._x;
		_y -= other._y;

		return *this;
	}

	Vector2& Vector2::operator*=(float value)
	{
		_x *= value;
		_y *= value;

		return *this;
	}

	Vector2& Vector2::operator/=(float value)
	{
		_x /= value;
		_y /= value;

		return *this;
	}

	Vector2 operator*(float value, Vector2 rhs)
	{
		return rhs * value;
	}
}