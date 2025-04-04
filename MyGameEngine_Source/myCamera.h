#pragma once
#include "Component.h"
#include "myMath.h"

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

        Vector2 CalculatePosition(const Vector2& pos) const;

    private:
        GameObject* _target;

        Vector2 _distance;
        Vector2 _resolution;
        Vector2 _lookPosition;
    };
}