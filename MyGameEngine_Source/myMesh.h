#pragma once

#include "vector.hpp"
#include "myVertex.h"
#include "myMath.h"
#include "myResource.h"
#include "myMaterial.h"

namespace my
{

	class Mesh
        : public Resource
	{
    public:

        Mesh(const std::wstring& name);
        virtual ~Mesh() override;

        //Mesh(const vector<Vector3>& vertices, const vector<unsigned int>& indices, const Material& material);

        virtual void Load(const std::wstring& path) override;
        void parseVertex(FILE* file, vector<Vector3>& vertices);
        void parseIndex(FILE* file, vector<uint32>& indices);

        const void*     getBufferData() const;
        unsigned int    getBufferStride() const;
        unsigned int    getBufferSize() const;
        void*           getVertexOffset() const;
        void*           getNormalOffset() const;

        Material*       getMaterial() const;

    private:
        vector<Vertex>  _vertices;
        Material*       _material;
	};
}

