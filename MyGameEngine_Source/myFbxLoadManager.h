#pragma once

#include "map.hpp"
#include "vector.hpp"
#include "myMesh.h"

#include <string>
#include <fbxsdk.h>

namespace my
{
	class FbxLoadManager
	{
	public:
		FbxLoadManager();
		~FbxLoadManager();

		void LoadSubMesh(const std::wstring& path, __out vector<Mesh>& subMesh);
	
	private:
		FbxScene* ImportScene(const std::wstring& path);
		void Traverse(FbxNode* node, __out vector<Mesh>& subMesh);

	private:
		map<std::wstring, FbxScene*>	_scenes;
		FbxManager* _manager;
	};
}

