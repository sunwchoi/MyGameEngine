#pragma once
#include "myUIElement.h"

namespace my
{
    class UIButton :
        public UIElement
    {
    public:
        UIButton(const Vector2& pos, const Vector2& scale, const std::wstring& text);
        virtual ~UIButton();

        virtual HWND Construct();
        virtual void Destroy();

        virtual const wchar_t* GetWindowClassName() { return L"Button"; };

    };
}

