#pragma once
#include "myScript.h"
#include "Common.h"

namespace my
{
    class Transform;
    class Animator;
    class BoxCollider2D;
    class CircleCollider2D;

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

        void JumpEnd();
        void AttackEnd();
        void HurtEnd();
    private:
        //Component
        Transform*          _transform;
        Animator*           _animator;
        BoxCollider2D*      _bodyCollider;
        CircleCollider2D*   _attackCollider;

        // State 관련
        ePlayerDirection    _direction;
        ePlayerState        _state;
        
        // Attack관련
        bool                _bAttack;
        uint8               _comboIndex;
        float               _comboTime;
    };
}

