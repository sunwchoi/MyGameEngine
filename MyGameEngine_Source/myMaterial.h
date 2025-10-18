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
    
    public:
        Vector3 _ambient;
        Vector3 _diffuse;
        Vector3 _specular;

        float _shininess = 0.1f;
        float _refractionIndex;
        float _transparency;

        uint32 _illumModel;
    };
}
