#pragma once
#include "Component.h"
#include "myMath.h"
#include "Transform.h"

namespace my
{
    class GameObject;

    class Camera :
        public Component
    {
    public: 
        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

        void SetTarget(GameObject* target);
        const GameObject* GetTarget() const;

        void SetTransform(const Transform& transform);
        const Transform& GetTransform() const;
    
    private:
        GameObject* _target;
        Transform _transform;
    };
}