#pragma once
#include "myUIElement.h"

namespace my
{
	class UIPanel :
		public UIElement
	{
	public:
        UIPanel(UIElement* parent, const XmlNode* node);
        virtual ~UIPanel();

        HWND Construct() override;
        void Destroy() override;

        const wchar_t* GetWindowClassName() override { return L"Button"; };

        bool OnUIEvent(UINT message, WPARAM wParam, LPARAM lParam) override;
	};
}
