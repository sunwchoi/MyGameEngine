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
            Idle = 0,
            Walk,
            Run,
            Jump,
            Attack,
            Hurt,

            Count
        };

        enum class ePlayerDirection : uint8
        {
            Left = 0,
            Right,

            Count
        };

    public:
        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

        void Idle();
        void Move();
        void Jump();
        void Attack();
        void Hurt();
    
    private:
        Transform*          _transform;
        Animator*           _animator;
        float               _speed;
        ePlayerDirection    _direction;
        ePlayerState        _state;
    };
}

