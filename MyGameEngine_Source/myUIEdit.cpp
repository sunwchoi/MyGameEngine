#include "myUIEdit.h"

namespace my
{
	UIEdit::UIEdit(UIElement* element, const XmlNode* node)
		: UIElement(element, node)
	{
	}

	UIEdit::~UIEdit()
	{
	}

	HWND UIEdit::Construct()
	{
		return __super::Construct();
	}

	void UIEdit::Destroy()
	{
		__super::Destroy();
	}

	bool UIEdit::OnUIEvent(UINT message, WPARAM wParam, LPARAM lParam)
	{
		if (GetHWND() != HWND(lParam))
			return false;

		return true;
	}
}
