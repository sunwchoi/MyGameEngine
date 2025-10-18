#pragma once

#include "myUIElement.h"


namespace my
{
    class UIText :
        public UIElement
    {
    public:
        UIText(UIElement* parent, const XmlNode* node);
        ~UIText();

        virtual HWND Construct();
        virtual void Destroy();

        virtual const wchar_t* GetWindowClassName() override { return L"STATIC"; };

        virtual bool OnUIEvent(UINT message, WPARAM wParam, LPARAM lParam) override;

    };
}

