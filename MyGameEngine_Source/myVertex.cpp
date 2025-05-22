#include "myVertex.h"

namespace my
{
	Vertex::Vertex()
	{
	}

	Vertex::Vertex(const Vector3& position, const Vector3& normal)
		: _position(position)
		, _normal(normal)
	{
	}

	Vertex& Vertex::operator=(const Vertex& other)
	{
		_position = other._position;
		_normal = other._normal;

		return *this;
	}

	Vertex::~Vertex()
	{
	}

	bool Vertex::operator==(const Vertex& other) const
	{
		return (this->_position == other._position && this->_normal == other._normal);
	}

	bool Vertex::operator!=(const Vertex& other) const
	{
		return !(*this != other);
	}

}
