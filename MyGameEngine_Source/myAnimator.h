#pragma once

#include "Component.h"
#include "myTexture.h"
#include "myMath.h"
#include <string>
#include <map>
#include <functional>

namespace my
{
    class Animation;

    class Animator :
        public Component
    {
    public:
        Animator();
        ~Animator();

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

        void CreateAnimation(const std::wstring& name, Texture* SpriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration, bool bReverse = false);
        Animation* FindAnimation(const std::wstring& name);
        void PlayAnimation(const std::wstring& name, bool bLoop = true);

        void BindCompleteEvent(const std::wstring& name, const std::function<void()>& func);
    private:
        std::map<std::wstring, Animation*> _animations;
        
        Animation*  _activeAnimation;
        bool        _bLoop;
    };
}
