#pragma once
#include "myUIElement.h"

namespace my
{
    class UIEdit :
        public UIElement
    {
    public:
        UIEdit(const Vector2& pos, const Vector2& scale, const std::wstring& text);
        virtual ~UIEdit();

        virtual HWND Construct();
        virtual void Destroy();

        virtual const wchar_t* GetWindowClassName() override { return L"EDIT"; };

        virtual void OnUIEvent(UINT message, WPARAM wParam, LPARAM lParam) override;

    };
}

