#pragma once
#include "myUIElement.h"
#include "myDelegate.h"

DECLARE_DELEGATE(ButtonClickDelegate)

namespace my
{
    class UIButton :
        public UIElement
    {
    public:
        UIButton(UIElement* parent, const XmlNode* node);
        virtual ~UIButton();

        virtual HWND Construct();
        virtual void Destroy();

        virtual const wchar_t* GetWindowClassName() { return L"Button"; };

        virtual bool OnUIEvent(UINT message, WPARAM wParam, LPARAM lParam) override;


        ButtonClickDelegate OnClicked;
    };
}

