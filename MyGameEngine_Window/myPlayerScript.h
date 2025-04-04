#pragma once
#include "myScript.h"

namespace my
{
    class Transform;

    class PlayerScript :
        public Script
    {
    public:
        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;
    
    private:
        Transform*  _playerTransform;
        float       _speed;
    };
}

