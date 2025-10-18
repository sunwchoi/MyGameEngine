#pragma once
#include "myGameObject.h"

namespace my
{
	class DebugDrawer
	{
	public:
		static void Initialize();
		static void Render();

	private:
		static void CreateCone(float radius, float height, __out Mesh& mesh);
		static void CreateCylinder(float radius, float height, __out Mesh& mesh);
		static void CreateBox(float width, float depth, float height, __out Mesh& mesh);

	private:
		static Mesh _coneMesh;
		static Mesh _cylinderMesh;
		static Mesh _boxMesh;
	};

}
