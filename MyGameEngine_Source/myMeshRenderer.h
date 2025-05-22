#pragma once

#include "Component.h"
#include "myMesh.h"

namespace my
{
    class MeshRenderer :
        public Component
    {
    public:
        virtual void Initialize() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render(HDC hdc) override;

    
    private:
        Mesh* _mesh = nullptr;
    };
}

