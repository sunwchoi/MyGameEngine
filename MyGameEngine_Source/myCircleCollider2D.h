#pragma once
#include "myCollider2D.h"

namespace my
{
    class CircleCollider2D :
        public Collider2D
    {
    public:
        CircleCollider2D();
        ~CircleCollider2D();
  
        virtual void Initialize() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render(HDC hdc) override;

        uint32 GetRadius() const { return _radius; }
        void SetRadius(uint32 radius) { _radius = radius; }

    private:
        uint32 _radius;

#ifdef _DEBUG
    public:
        void SetDebugDraw(bool bDebugDraw) { _bDebugDraw = bDebugDraw; }
        
    private:
        bool    _bDebugDraw;
#endif // _DEBUG

    };
}

