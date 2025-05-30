#include "myMeshRenderer.h"
#include "myGameObject.h"
#include "myApplication.h"
#include "myGraphicDevice_DX11.h"

extern my::Application application;

namespace my
{
	void MeshRenderer::Initialize()
	{
	}

	void MeshRenderer::Update()
	{
	}

	void MeshRenderer::LateUpdate()
	{
	}

	void MeshRenderer::Render(HDC hdc)
	{
		const Transform& transform = GetOwner()->GetComponentMust<Transform>();
		const Mesh* mesh = GetOwner()->GetMesh();
		MY_ASSERT_MSG(mesh, "Game Object의 Mesh가 비어있는 상태에서 mesh가 호출됨");

		application.GetGraphicDevice()->RenderMesh(*mesh, transform);
	}
}
