#include "myUIElement.h"
#include "myEditorApplication.h"

extern my::EditorApplication editor;

namespace my
{
	UIElement::UIElement(const Vector2& pos, const Vector2& scale, const std::wstring& text)
		: _pos(pos)
		, _scale(scale)
		, _text(text)
	{
	}

	UIElement::~UIElement()
	{
		Destroy();
	}

	HWND UIElement::Construct()
	{
		_hwnd = CreateWindow(GetWindowClassName(), _text.c_str(),
			WS_VISIBLE | WS_CHILD,
			_pos._x, _pos._y, _scale._x, _scale._y,
			editor.GetHWND(), NULL, NULL, NULL);

		return _hwnd;
	}

	void UIElement::Destroy()
	{
		DestroyWindow(_hwnd);
	}

	void UIElement::SetElementText(const std::wstring& text)
	{
		SetWindowText(_hwnd, text.c_str());
	}

	void UIElement::GetElementText(std::wstring& text) const
	{
		GetWindowText(_hwnd, text.data(), 256);
	}

}
