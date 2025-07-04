#include "myMeshRenderer.h"
#include "myGameObject.h"
#include "myApplication.h"
#include "myGraphicDevice_DX11.h"
#include "mySkeletalMesh.h"

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
		const Transform* transform = GetOwner()->GetComponent<Transform>();

		application.GetGraphicDevice()->PreRender();

		if (_skeletalMesh)
		{
			for (const Mesh& mesh : _skeletalMesh->GetSubMesh())
				application.GetGraphicDevice()->RenderMesh(mesh, *transform);
		}
		else if (_mesh)
		{
			application.GetGraphicDevice()->RenderMesh(*_mesh, *transform);
		}

		application.GetGraphicDevice()->PostRender();

	}

	void MeshRenderer::SetMesh(Mesh* mesh)
	{
		_mesh = mesh;
	}

	const Mesh* MeshRenderer::GetMesh() const
	{
		return _mesh;
	}

	void MeshRenderer::SetSkeletalMesh(SkeletalMesh* mesh)
	{
		_skeletalMesh = mesh;
	}

	const SkeletalMesh* MeshRenderer::GetSkeletalMesh() const
	{
		return _skeletalMesh;
	}
}
