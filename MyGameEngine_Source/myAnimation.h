#pragma once
#include "myResource.h"
#include "myMath.h"
#include <vector>

namespace my
{
    class Animator;
    class Texture;

    class Animation :
        public Resource
    {
    public:
        struct Sprite
        {
            Vector2 _leftTop;
            Vector2 _size;
            Vector2 _offset;
            float   _duration = 0;
        };

    public:
        Animation(const std::wstring& name);
        ~Animation();

        void Load(const std::wstring& path) override;

        void Update();
        void Render(HDC hdc);

        void CreateAnimation(Animator* animator, Texture* SpriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration, bool bReverse);
        void Reset();

        bool isComplete() const { return _bComplete; }
    private:
        Animator*   _animator;
        Texture*    _spriteSheet;

        std::vector<Sprite> _animationSheet;
        int     _index;
        float   _time;
        bool    _bComplete;
        bool    _bReverse;
    };
}

