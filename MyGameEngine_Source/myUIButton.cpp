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

}
