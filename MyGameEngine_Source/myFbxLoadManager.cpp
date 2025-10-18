#include "myFbxLoadManager.h"

namespace my
{
	FbxLoadManager::FbxLoadManager()
		: _manager(nullptr)
	{

	}

	FbxLoadManager::~FbxLoadManager()
	{
		_manager->Destroy(); // scene도 같이 Destroy됨
	}

	void FbxLoadManager::LoadSubMesh(const std::wstring& path, vector<Mesh>& subMesh)
	{
		MY_ASSERT_MSG(subMesh.empty(), "SubMesh는 여기서 비어있어야 함");

		if (_manager == nullptr)
		{
			_manager = FbxManager::Create();
			FbxIOSettings* ios = FbxIOSettings::Create(_manager, IOSROOT);
			_manager->SetIOSettings(ios);
		}

		FbxScene* scene = ImportScene(path);
		FbxNode* root = scene->GetRootNode();
		
		Traverse(root, subMesh);


	}

	FbxScene* FbxLoadManager::ImportScene(const std::wstring& path)
	{
		FbxScene*& scene = _scenes[path];

		if (scene == nullptr)
		{
			scene = FbxScene::Create(_manager, "");

			FbxImporter* importer = FbxImporter::Create(_manager, "");

			std::string pathStr;
			pathStr.assign(path.begin(), path.end());

			importer->Initialize(pathStr.c_str(), -1, _manager->GetIOSettings());
			importer->Import(scene);
			importer->Destroy();
		}

		return scene;
	}

	void FbxLoadManager::Traverse(FbxNode* node, vector<Mesh>& subMesh)
	{
		if (node->GetNodeAttribute() && node->GetNodeAttribute()->GetAttributeType() == FbxNodeAttribute::eMesh)
		{
			FbxMesh* mesh = (FbxMesh*)node->GetNodeAttribute();
			
			// Vertex
			int controlPointsCount = mesh->GetControlPointsCount();
			FbxVector4* controlPoints = mesh->GetControlPoints();

			vector<Vector3> vertices(controlPointsCount);
			for (int i = 0; i < controlPointsCount; ++i)
			{
				FbxVector4& v = controlPoints[i];

				vertices[i] = Vector3(v[0], v[1], v[2]);
			}

			// Index
			int polygonCount = mesh->GetPolygonCount();
			vector<uint32> Indices;
			for (int i = 0; i < polygonCount; ++i) {
				int polySize = mesh->GetPolygonSize(i);

				if (polySize == 3)
				{
					Indices.push_back(mesh->GetPolygonVertex(i, 0));
					Indices.push_back(mesh->GetPolygonVertex(i, 1));
					Indices.push_back(mesh->GetPolygonVertex(i, 2));
				}
				else if (polySize == 4)
				{
					Indices.push_back(mesh->GetPolygonVertex(i, 0));
					Indices.push_back(mesh->GetPolygonVertex(i, 1));
					Indices.push_back(mesh->GetPolygonVertex(i, 2));

					Indices.push_back(mesh->GetPolygonVertex(i, 0));
					Indices.push_back(mesh->GetPolygonVertex(i, 2));
					Indices.push_back(mesh->GetPolygonVertex(i, 3));
				}
			}

			

			subMesh.push_back(Mesh(L"subMesh"));
			subMesh.back().reinputVertices(vertices, Indices);
			subMesh.back().setMaterial(new Material(L"subMeshMtl"));

			int materialCount = node->GetMaterialCount();
			MY_ASSERT_MSG(materialCount >= 1, "1개의 material만 처리");

			FbxSurfaceMaterial* material = node->GetMaterial(0);
			Vector3& diffuse = subMesh.back().getMaterial()->_diffuse;
			Vector3& ambient = subMesh.back().getMaterial()->_ambient;
			Vector3& specular = subMesh.back().getMaterial()->_specular;
			float& shininess = subMesh.back().getMaterial()->_shininess;
			if (material->GetClassId().Is(FbxSurfacePhong::ClassId)) {
				FbxSurfacePhong* phong = (FbxSurfacePhong*)material;

				FbxDouble3 fbxDiffuse = phong->Diffuse.Get();
				diffuse._x = fbxDiffuse[0]; diffuse._y = fbxDiffuse[1]; diffuse._z = fbxDiffuse[2];

				FbxDouble3 fbxAmbient = phong->Ambient.Get();
				ambient._x = fbxAmbient[0]; ambient._y = fbxAmbient[1]; ambient._z = fbxAmbient[2];

				FbxDouble3 fbxSpecular = phong->Specular.Get();
				specular._x = fbxSpecular[0]; specular._y = fbxSpecular[1]; specular._z = fbxSpecular[2];

				shininess = phong->Shininess.Get();
			}
		}

		for (int i = 0; i < node->GetChildCount(); ++i) {
			Traverse(node->GetChild(i), subMesh);
		}
	}
}
