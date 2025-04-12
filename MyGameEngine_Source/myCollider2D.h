#pragma once
#include "Component.h"
#include "myMath.h"
#include "Common.h"

namespace my
{
    class Collider2D :
        public Component
    {
    public:
        enum class eColliderType : uint8
        {
            Circle,
            Box,

            Count
        };

    public:
        Collider2D(eColliderType type);
        ~Collider2D();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render(HDC hdc) override;

        const Vector2& GetOffset() const { return _offset; }
        eColliderType GetType() const { return _type; }

        void SetOffset(const Vector2& offset) { _offset = offset; }
        void SetType(eColliderType type) { _type = type; }
    
        void Enable() { _bEnable = true; };
        void Disable() { _bEnable = false; }
        bool IsEnable() const { return _bEnable; }

    private:
        Vector2         _offset;
        eColliderType   _type;
        bool            _bEnable = true;
    };
}

