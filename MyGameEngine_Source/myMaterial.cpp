#include "myMaterial.h"
#include "myAssert.h"

namespace my
{
	Material::Material(const std::wstring& name)
		: Resource(name, eResourceType::Material)
	{
	}

	Material::~Material()
	{
	}

	void Material::Load(const std::wstring& path)
	{
		FILE* file = nullptr;

		std::string pathStr(path.begin(), path.end());
		
		fopen_s(&file, pathStr.c_str(), "r");
		MY_ASSERT_MSG(file, ".mtl파일 open 실패");

		char id[1024];

		while (!feof(file)) {

			fscanf_s(file, "%s", id, sizeof(id));
			if (id[0] == 'K' && id[1] == 'a') {
				fscanf_s(file, "%f %f %f", &_ambient._x, &_ambient._y, &_ambient._z);
			}
			else if (id[0] == 'K' && id[1] == 'd') {
				fscanf_s(file, "%f %f %f", &_diffuse._x, &_diffuse._y, &_diffuse._z);
			}
			else if (id[0] == 'K' && id[1] == 's') {
				fscanf_s(file, "%f %f %f", &_specular._x, &_specular._y, &_specular._z);
			}
			else if (id[0] == 'N' && id[1] == 's') {
				fscanf_s(file, "%f", &_shininess);
			}
			else if (id[0] == 'N' && id[1] == 'i') {
				fscanf_s(file, "%f", &_refractionIndex);
			}
			else if (id[0] == 'd') {
				fscanf_s(file, "%f", &_transparency);
			}
			else if (std::string(id) == "illum") {
				fscanf_s(file, "%u", &_illumModel);
			}
		}
	}

}
