#include "myUIButton.h"

namespace my
{
	UIButton::UIButton(UIElement* parent, const XmlNode* node)
		: UIElement(parent, node)
	{
	}

	UIButton::~UIButton()
	{
	}

	HWND UIButton::Construct()
	{
		return __super::Construct();
	}

	void UIButton::Destroy()
	{
		__super::Destroy();
	}

	bool UIButton::OnUIEvent(UINT message, WPARAM wParam, LPARAM lParam)
	{
		if (GetHWND() != HWND(lParam))
			return false;

		int code = HIWORD(wParam);
		if (code == BN_CLICKED)
			OnClicked.Execute();

		return true;
	}
}
