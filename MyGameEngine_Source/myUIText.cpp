#include "myUIText.h"

namespace my
{
	UIText::UIText(const Vector2& pos, const Vector2& scale, const std::wstring& text)
		: UIElement(pos, scale, text)
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

	void UIText::OnUIEvent(UINT message, WPARAM wParam, LPARAM lParam)
	{
	}
}
