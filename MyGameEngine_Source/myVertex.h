#pragma once

#include "myMath.h"

namespace my
{
	class Vertex
	{
    private:
        Vector3 _position;
        Vector3 _normal;

    public:
        Vertex();
        Vertex(const Vector3& position, const Vector3& normal);
        Vertex& operator=(const Vertex& other);
        ~Vertex();

        bool operator==(const Vertex& other) const;
        bool operator!=(const Vertex& other) const;
	};
}
