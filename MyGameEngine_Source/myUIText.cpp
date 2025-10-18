#include "myUIText.h"

namespace my
{
	UIText::UIText(UIElement* parent, const XmlNode* node)
		: UIElement(parent, node)
	{
	}

	UIText::~UIText()
	{
	}

	HWND UIText::Construct()
	{
		return __super::Construct();
	}

	void UIText::Destroy()
	{
		__super::Destroy();
	}

	bool UIText::OnUIEvent(UINT message, WPARAM wParam, LPARAM lParam)
	{
		if (GetHWND() != HWND(lParam))
			return false;

		return true;
	}
}
