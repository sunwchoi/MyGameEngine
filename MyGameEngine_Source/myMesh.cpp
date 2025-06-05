#include "myMesh.h"
#include "myResources.h"

namespace my
{
    Mesh::Mesh(const std::wstring& name)
        : Resource(name, eResourceType::Mesh)
    {
    }

    Mesh::~Mesh()
    {
    }

    void Mesh::Load(const std::wstring& path)
    {
        const std::wstring ext = path.substr(path.find_last_of(L".") + 1);
        MY_ASSERT_MSG(ext == L"obj", ".obj이외의 파일은 아직 기능 없음");

        if (ext == L"obj")
        {
            //obj파일 파싱
            std::string pathStr;
            pathStr.assign(path.begin(), path.end());

            FILE* file = nullptr;

            fopen_s(&file, pathStr.c_str(), "r");
            MY_ASSERT_MSG(file, ".obj파일 open 실패");

            vector<Vector3> vertices;
            vector<uint32> indices;
            char mtlPath[1024];

            char id[1024];
            while (!feof(file)) {

                fscanf_s(file, "%s", id, sizeof(id));
                if (id[0] == 'v' && !id[1])
                    parseVertex(file, vertices);
                else if (id[0] == 'f' && !id[1])
                    parseIndex(file, indices);
                else if (std::string(id) == "mtllib")
                    fscanf_s(file, "%s", mtlPath, sizeof(mtlPath));
            }
            fclose(file);
            
            //메시 데이터로 재입력
            reinputVertices(vertices, indices);


            //mtl 파일 로드
            std::string mtlPathStr(mtlPath);
            std::wstring resourceDir = L"..\\Resource\\" + std::wstring(mtlPathStr.begin(), mtlPathStr.end());
            
            _material = Resources::Load<Material>(getName() + L"Material", resourceDir);
        }
    }

    void Mesh::parseVertex(FILE* file, vector<Vector3>& vertices)
    {
        float x, y, z;

        fscanf_s(file, "%f %f %f", &x, &y, &z);
        vertices.push_back(Vector3(x, y, z));
    }

    void Mesh::parseIndex(FILE* file, vector<uint32>& indices)
    {
        vector<unsigned int> index;
        char buffer[1024] = { 0, };

        fgets(buffer, 1024, file);
        char* context = nullptr;
        for (char* token = strtok_s(buffer, " ", &context); token; token = strtok_s(nullptr, " ", &context)) {
            index.push_back(std::stol(token) - 1);
        }

        if (index.size() == 3) {
            indices.push_back(index[0]);
            indices.push_back(index[1]);
            indices.push_back(index[2]);

        }
        else if (index.size() == 4) {
            indices.push_back(index[0]);
            indices.push_back(index[1]);
            indices.push_back(index[2]);

            indices.push_back(index[0]);
            indices.push_back(index[2]);
            indices.push_back(index[3]);
        }
    }

    void Mesh::reinputVertices(vector<Vector3>& vertices, vector<uint32>& indices)
    {
        //메시 데이터로 재입력
        for (int i = 0; i < indices.size(); i += 3) {
            Vector3 v1 = vertices[indices[i]],
                v2 = vertices[indices[i + 1]],
                v3 = vertices[indices[i + 2]];

            Vector3 norm = math::GetNormal(v1, v2, v3);

            _vertices.push_back(Vertex(v1, norm));
            _vertices.push_back(Vertex(v2, norm));
            _vertices.push_back(Vertex(v3, norm));
        }
    }


    const void* Mesh::getBufferData() const {
        return _vertices.data();
    }

    uint32 Mesh::getBufferStride() const {
        return sizeof(Vertex);
    }

    uint32 Mesh::getBufferSize() const {
        return _vertices.size();
    }

    uint32 Mesh::getByteWidth() const
    {
        return _vertices.size() * sizeof(Vertex);
    }

    void* Mesh::getVertexOffset() const {
        return (void*)0;
    }

    void* Mesh::getNormalOffset() const {
        return (void*)sizeof(Vertex);
    }

    Material* Mesh::getMaterial() const
    {
        return _material;
    }
}