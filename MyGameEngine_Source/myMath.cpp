#include "myMath.h"
#include "myAssert.h"
#include <cmath>

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
		MY_ASSERT_MSG(value != 0, "Division By Zero");

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
		MY_ASSERT_MSG(value != 0, "Division By Zero");

		_x /= value;
		_y /= value;

		return *this;
	}

	bool Vector2::operator==(const Vector2& other) const
	{
		return fabs(_x - other._x) < 1e-6f && fabs(_y - other._y) < 1e-6f;
	}

	bool Vector2::operator!=(const Vector2& other) const
	{
		return !(*this == other);
	}

	Vector2 operator*(float value, Vector2 rhs)
	{
		return rhs * value;
	}



/***Vector3**************************************************************************/

	const Vector3 Vector3::Zero(0, 0, 0);

	Vector3 Vector3::operator+(const Vector3& other) const
	{
		return Vector3(_x + other._x, _y + other._y, _z + other._z);
	}

	Vector3 Vector3::operator-(const Vector3& other) const
	{
		return Vector3(_x - other._x, _y - other._y, _z - other._z);
	}

	Vector3 Vector3::operator*(float value) const
	{
		return Vector3(_x * value, _y * value, _z * value);
	}

	Vector3 Vector3::operator/(float value) const
	{
		MY_ASSERT_MSG(value != 0, "Division By Zero");
		return Vector3(_x / value, _y / value, _z / value);
	}

	Vector3& Vector3::operator+=(const Vector3& other)
	{
		_x += other._x;
		_y += other._y;
		_z += other._z;

		return *this;
	}

	Vector3& Vector3::operator-=(const Vector3& other)
	{
		_x -= other._x;
		_y -= other._y;
		_z -= other._z;

		return *this;
	}

	Vector3& Vector3::operator*=(float value)
	{
		_x *= value;
		_y *= value;
		_z *= value;

		return *this;
	}

	Vector3& Vector3::operator/=(float value)
	{
		MY_ASSERT_MSG(value != 0, "Division By Zero");

		_x /= value;
		_y /= value;
		_z /= value;

		return *this;
	}

	bool Vector3::operator==(const Vector3& other) const
	{
		return (_x == other._x && _y == other._y && _z == other._z);
	}

	bool Vector3::operator!=(const Vector3& other) const
	{
		return !(*this == other);
	}

	Vector3 Vector3::Cross(const Vector3& other)
	{
		return Vector3(
			_y * other._z - _z * other._y,
			_z * other._x - _x * other._z,
			_x * other._y - _y * other._x
		);
	}

	float Vector3::Dot(const Vector3& other)
	{
		return _x * other._x + _y * other._y + _z * other._z;
	}

	Vector3 Vector3::Normalize() const
	{
		float size = Size();

		return Vector3(_x / size, _y / size, _z / size);
	}

	float Vector3::Size() const
	{
		return sqrt(_x * _x + _y * _y + _z * _z);
	}

	Vector3 operator*(float value, Vector3 rhs)
	{
		return Vector3(value * rhs._x, value * rhs._y, value * rhs._z);
	}

	namespace math
	{
		Vector3 Cross(const Vector3& a, const Vector3& b) {

			return Vector3(
				a._y * b._z - a._z * b._y,
				a._z * b._x - a._x * b._z,
				a._x * b._y - a._y * b._x
			);
		}

		float Dot(const Vector3& a, const Vector3& b) {
			return a._x * b._x + a._y * b._y + a._z * b._z;
		}

		Vector3 Normalize(const Vector3& v)
		{
			float magnitude = std::sqrt(v._x * v._x + v._y * v._y + v._z * v._z);

			return Vector3(
				v._x / magnitude,
				v._y / magnitude,
				v._z / magnitude
			);
		}

		Vector3 GetNormal(const Vector3& a, const Vector3& b, const Vector3& c)
		{
			Vector3 edge1 = b - a;
			Vector3 edge2 = c - a;

			return (edge1.Cross(edge2)).Normalize();
		}

	}
}