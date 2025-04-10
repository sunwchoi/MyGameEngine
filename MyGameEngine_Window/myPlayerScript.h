#pragma once
#include "myScript.h"
#include "Common.h"

namespace my
{
    class Transform;
    class Animator;

    class PlayerScript :
        public Script
    {
        enum class ePlayerState : uint8
        {
            Idle,
            Walk,
            Run,
            Attack,

            Count
        };

        enum class ePlayerDirection : uint8
        {
            Left,
            Right,
            Up,
            Down,

            Count
        };

    public:
        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;
    
    private:
        Transform*          _transform;
        Animator*           _animator;
        float               _speed;
        ePlayerDirection    _direction;
        ePlayerState        _state;
    };
}

