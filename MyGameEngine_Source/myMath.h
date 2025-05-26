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

	class Vector3
	{
	public:
		Vector3() : _x(0.f), _y(0.f), _z(0.f) {}
		Vector3(float x, float y, float z) : _x(x), _y(y), _z(z) {}
		~Vector3() {}

		Vector3 operator+(const Vector3& other) const;
		Vector3 operator-(const Vector3& other) const;
		Vector3 operator*(float value) const;
		Vector3 operator/(float value) const;

		Vector3& operator+=(const Vector3& other);
		Vector3& operator-=(const Vector3& other);
		Vector3& operator*=(float value);
		Vector3& operator/=(float value);

		bool operator==(const Vector3& other) const;

		bool operator!=(const Vector3& other) const;

		Vector3 Cross(const Vector3& other);

		float Dot(const Vector3& other);

		Vector3 Normalize() const;

		float Size() const;

		float	_x;
		float	_y;
		float	_z;
	};

	namespace math
	{
		float Dot(const Vector3& a, const Vector3& b);
		Vector3 Cross(const Vector3& a, const Vector3& b);
		Vector3 Normalize(const Vector3& v);
		Vector3 GetNormal(const Vector3& a, const Vector3& b, const Vector3& c);

	}



}