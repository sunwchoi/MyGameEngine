#pragma once
#include "myUIElement.h"

namespace my
{
    class UIEdit :
        public UIElement
    {
    public:
        UIEdit(UIElement* element, const XmlNode* node);
        virtual ~UIEdit();

        virtual HWND Construct();
        virtual void Destroy();

        virtual const wchar_t* GetWindowClassName() override { return L"EDIT"; };

        virtual bool OnUIEvent(UINT message, WPARAM wParam, LPARAM lParam) override;


    };
}

