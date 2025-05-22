#include "myMeshRenderer.h"

namespace my
{
	void MeshRenderer::Initialize()
	{
	}

	void MeshRenderer::Update()
	{
		MY_ASSERT_MSG(_mesh, "Mesh Render의 mesh가 비어있으면 안됨");
	}

	void MeshRenderer::LateUpdate()
	{
		MY_ASSERT_MSG(_mesh, "Mesh Render의 mesh가 비어있으면 안됨");
	}

	void MeshRenderer::Render(HDC hdc)
	{
		MY_ASSERT_MSG(_mesh, "Mesh Render의 mesh가 비어있으면 안됨");
	

	}
}
