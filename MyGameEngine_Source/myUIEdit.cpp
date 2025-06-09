#include "myUIEdit.h"

namespace my
{
	UIEdit::UIEdit(const Vector2& pos, const Vector2& scale, const std::wstring& text)
		: UIElement(pos, scale, text)
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

	void UIEdit::OnUIEvent(UINT message, WPARAM wParam, LPARAM lParam)
	{
	}
}
