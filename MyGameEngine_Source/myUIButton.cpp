#include "myUIButton.h"

namespace my
{
	UIButton::UIButton(const Vector2& pos, const Vector2& scale, const std::wstring& text)
		: UIElement(pos, scale, text)
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

	void UIButton::OnUIEvent(UINT message, WPARAM wParam, LPARAM lParam)
	{
		int code = HIWORD(wParam);

		if (code == BN_CLICKED)
			OnClicked.Execute();
	}
}
