#pragma once

#include "myResource.h"
#include "vector.hpp"
#include "myMesh.h"

namespace my
{
	class SkeletalMesh : public Resource
	{
	public:
		SkeletalMesh(const std::wstring& name);
		virtual ~SkeletalMesh() override;

		virtual void Load(const std::wstring& path) override;

		const vector<Mesh>& GetSubMesh() const;

	private:
		vector<Mesh> _subMesh;
	};
}
