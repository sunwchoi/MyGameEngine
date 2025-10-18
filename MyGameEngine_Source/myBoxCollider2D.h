#pragma once
#include "myCollider2D.h"

namespace my
{
    class BoxCollider2D :
        public Collider2D
    {
    public:
        BoxCollider2D();
        ~BoxCollider2D();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render(HDC hdc) override;

        const Vector2& GetSize() const { return _size; }
        void SetSize(const Vector2& size) { _size = size; }

        void SetDebugDraw(bool bDebugDraw) { _bDebugDraw = bDebugDraw; }
    private:
        Vector2 _size;

#ifdef _DEBUG
        bool    _bDebugDraw;
#endif
    };
}
