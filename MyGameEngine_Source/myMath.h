#pragma once

namespace my
{
	class Vector2
	{
	public:
		Vector2() : _x(0), _y(0) {}
		Vector2(float x, float y) : _x(x), _y(y) {}
		~Vector2() {}

		Vector2 operator+(const Vector2& other) const;
		Vector2 operator-(const Vector2& other) const;
		Vector2 operator*(float value) const;
		Vector2 operator/(float value) const;

		Vector2& operator+=(const Vector2& other);
		Vector2& operator-=(const Vector2& other);
		Vector2& operator*=(float value);
		Vector2& operator/=(float value);

		float	_x;
		float	_y;

		friend Vector2 operator*(float value, Vector2 rhs);
	};


}