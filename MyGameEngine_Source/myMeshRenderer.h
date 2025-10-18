#pragma once

#include "Component.h"

namespace my
{
    class SkeletalMesh;
    class Mesh;

    class MeshRenderer :
        public Component
    {
    public:
        virtual void Initialize() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render(HDC hdc) override;

        void SetMesh(Mesh* mesh);
        const Mesh* GetMesh() const;

        void SetSkeletalMesh(SkeletalMesh* mesh);
        const SkeletalMesh* GetSkeletalMesh() const;

    private:
        SkeletalMesh* _skeletalMesh;
        Mesh* _mesh;
    };
}

