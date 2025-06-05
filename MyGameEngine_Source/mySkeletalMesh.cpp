#include "mySkeletalMesh.h"
#include "myFbxLoadManager.h"

extern my::FbxLoadManager g_fbxLoadManager;

namespace my
{
	SkeletalMesh::SkeletalMesh(const std::wstring& name)
		: Resource(name, eResourceType::SkeletalMesh)
	{
	}

	SkeletalMesh::~SkeletalMesh()
	{
	}

	void SkeletalMesh::Load(const std::wstring& path)
	{
		const std::wstring ext = path.substr(path.find_last_of(L".") + 1);
		MY_ASSERT_MSG(ext == L"fbx", ".fbx이외의 파일은 기능 없음");

		g_fbxLoadManager.LoadSubMesh(path, _subMesh);
	}

	const vector<Mesh>& SkeletalMesh::GetSubMesh() const
	{
		return _subMesh;
	}

}
