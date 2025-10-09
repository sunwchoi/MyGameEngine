#include "myDebugDrawer.h"

#include <algorithm>

#include "myApplication.h"
#include "myGraphicDevice_DX11.h"
#include "myMeshRenderer.h"
#include "Transform.h"

extern my::Application application;

namespace my
{
	Mesh DebugDrawer::_coneMesh = Mesh(L"cone");
    Mesh DebugDrawer::_cylinderMesh = Mesh(L"cylinder");
    Mesh DebugDrawer::_boxMesh = Mesh(L"box");

	void DebugDrawer::Initialize()
	{
		Material* material = new Material(L"tmp");
		material->_ambient = Vector3(1, 0, 0);
		_coneMesh.setMaterial(material);
		CreateCone(100.f, 100.f, _coneMesh);

        _cylinderMesh.setMaterial(material);
        CreateCylinder(100.f, 100.f, _cylinderMesh);

        _boxMesh.setMaterial(material);
        CreateBox(100.f, 100.f, 100.f, _boxMesh);
	}

	void DebugDrawer::Render()
	{
        //  application.GetGraphicDevice()->RenderMesh(_coneMesh, Transform());
        //  application.GetGraphicDevice()->RenderMesh(_cylinderMesh, Transform());
        //
        // application.GetGraphicDevice()->RenderMesh(_boxMesh, Transform());

	}

	void DebugDrawer::CreateCone(float radius, float height, __out Mesh& mesh)
	{
		Vector3 origin = Vector3::Zero;
		Vector3 tip = origin + Vector3(0, height, 0);

		const int segments = 12;

		vector<Vector3> vertices(segments + 1);
		vector<uint32> indices(segments * 3);

		vertices[0] = tip;
		for (int i = 1; i < vertices.size(); i++) {
			float angle = (i / float(segments)) * 2 * math::PI;

			vertices[i] = origin + Vector3(cosf(angle) * radius, 0, sinf(angle) * radius);
		}

		for (int i = 0; i < segments; i++)
		{
			indices[i * 3] = 0;
			indices[i * 3 + 1] = i + 1;

			if (i == segments - 1)
				indices[i * 3 + 2] = 1;
			else
				indices[i * 3 + 2] = i + 2;
		}

		mesh.reinputVertices(vertices, indices);
	}

    void DebugDrawer::CreateCylinder(float radius, float height, Mesh& mesh)
    {
        const int segments = 12;
        Vector3 origin = Vector3::Zero;
        Vector3 top = origin + Vector3(0, height, 0);

        vector<Vector3> vertices(segments * 2 + 2);
        vector<uint32> indices;

        // 아래 중심점
        vertices[0] = origin;
        // 위 중심점
        vertices[1] = top;

        // 아래 원과 위 원의 정점들
        for (int i = 0; i < segments; i++)
        {
            float angle = (i / float(segments)) * 2 * math::PI;
            float x = cosf(angle) * radius;
            float z = sinf(angle) * radius;

            // 아래 원 정점
            vertices[2 + i] = origin + Vector3(x, 0, z);
            // 위 원 정점
            vertices[2 + segments + i] = top + Vector3(x, 0, z);
        }

        // 인덱스 생성
        for (int i = 0; i < segments; i++)
        {
            int next = (i + 1) % segments;

            // 아래 면 (origin 중심)
            indices.push_back(0);
            indices.push_back(2 + next);
            indices.push_back(2 + i);

            // 위 면 (top 중심)
            indices.push_back(1);
            indices.push_back(2 + segments + i);
            indices.push_back(2 + segments + next);

            // 옆면 (2개 삼각형)
            int bottomCurrent = 2 + i;
            int bottomNext = 2 + next;
            int topCurrent = 2 + segments + i;
            int topNext = 2 + segments + next;

            // 첫 번째 삼각형
            indices.push_back(bottomCurrent);
            indices.push_back(topCurrent);
            indices.push_back(bottomNext);

            // 두 번째 삼각형
            indices.push_back(bottomNext);
            indices.push_back(topCurrent);
            indices.push_back(topNext);
        }

        mesh.reinputVertices(vertices, indices);
    }

    void DebugDrawer::CreateBox(float width, float depth, float height, Mesh& mesh)
    {
        float halfWidth = width * 0.5f;
        float halfDepth = depth * 0.5f;
        float halfHeight = height * 0.5f;

        // 8개 정점
        vector<Vector3> vertices;
        vertices.push_back(Vector3(-halfWidth, -halfHeight, -halfDepth));  // 0: 왼쪽 아래 뒤
        vertices.push_back(Vector3(halfWidth, -halfHeight, -halfDepth));  // 1: 오른쪽 아래 뒤
        vertices.push_back(Vector3(halfWidth, -halfHeight, halfDepth));  // 2: 오른쪽 아래 앞
        vertices.push_back(Vector3(-halfWidth, -halfHeight, halfDepth));  // 3: 왼쪽 아래 앞

        vertices.push_back(Vector3(-halfWidth, halfHeight, -halfDepth));  // 4: 왼쪽 위 뒤
        vertices.push_back(Vector3(halfWidth, halfHeight, -halfDepth));  // 5: 오른쪽 위 뒤
        vertices.push_back(Vector3(halfWidth, halfHeight, halfDepth));  // 6: 오른쪽 위 앞
        vertices.push_back(Vector3(-halfWidth, halfHeight, halfDepth));  // 7: 왼쪽 위 앞

        // 36개 인덱스 (6면 * 2삼각형 * 3정점)
        uint32 tempIndices[] = {
            0, 2, 1,  0, 3, 2,
            4, 5, 6,  4, 6, 7,
            3, 6, 2,  3, 7, 6,
            1, 5, 4,  1, 4, 0,
            2, 6, 5,  2, 5, 1,
            0, 4, 7,  0, 7, 3
        };
        
        vector<uint32> indices;
        indices.assign(tempIndices, tempIndices + sizeof(tempIndices) / sizeof(uint32));

        mesh.reinputVertices(vertices, indices);
    }
}
