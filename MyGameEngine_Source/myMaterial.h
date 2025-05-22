#pragma once
#include "myResource.h"
#include "myMath.h"

namespace my
{
    class Material :
        public Resource
    {
    public:
        Material(const std::wstring& name);
        virtual ~Material() override;

        virtual void Load(const std::wstring& path) override;
    
    private:
        Vector3 _ambient;
        Vector3 _diffuse;
        Vector3 _specular;

        float _shininess = 0.f;
        float _refractionIndex = 0.f;
        float _transparency = 0.f;

        uint32 _illumModel;
    };
}
