#include "myMeshRenderer.h"

namespace my
{
	void MeshRenderer::Initialize()
	{
	}

	void MeshRenderer::Update()
	{
		MY_ASSERT_MSG(_mesh, "Mesh Render�� mesh�� ��������� �ȵ�");
	}

	void MeshRenderer::LateUpdate()
	{
		MY_ASSERT_MSG(_mesh, "Mesh Render�� mesh�� ��������� �ȵ�");
	}

	void MeshRenderer::Render(HDC hdc)
	{
		MY_ASSERT_MSG(_mesh, "Mesh Render�� mesh�� ��������� �ȵ�");
	

	}
}
