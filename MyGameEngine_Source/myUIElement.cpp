#include "myUIElement.h"
#include "myEditorApplication.h"
#include "myXmlUtil.h"

extern my::EditorApplication editor;

namespace my
{
	UIElement::UIElement(UIElement* parent, const XmlNode* node)
	{
		_ygNodeRef = YGNodeNew();

		auto it = node->_attributes.find("x");
		if (it != node->_attributes.end())
			_pos._x = std::stoi(it->second);

		it = node->_attributes.find("y");
		if (it != node->_attributes.end())
			_pos._y = std::stoi(it->second);

		it = node->_attributes.find("width");
		if (it != node->_attributes.end())
			YGNodeStyleSetWidth(_ygNodeRef, std::stoi(it->second));
		else
			YGNodeStyleSetWidth(_ygNodeRef, 100.f);

		it = node->_attributes.find("height");
		if (it != node->_attributes.end())
			YGNodeStyleSetHeight(_ygNodeRef, std::stoi(it->second));
		else
			YGNodeStyleSetHeight(_ygNodeRef, 30.f);

		_text = std::wstring(node->_text.begin(), node->_text.end());

		if (parent)
			parent->AddChild(this);
	}

	UIElement::~UIElement()
	{
		Destroy();
	}

	HWND UIElement::Construct()
	{
		float x = YGNodeLayoutGetLeft(_ygNodeRef);
		float y = YGNodeLayoutGetTop(_ygNodeRef);
		float width = YGNodeLayoutGetWidth(_ygNodeRef);
		float height = YGNodeLayoutGetHeight(_ygNodeRef);

		_hwnd = CreateWindow(GetWindowClassName(), _text.c_str(),
			WS_VISIBLE | WS_CHILD,
			x, y, width, height,
			editor.GetHWND(), NULL, NULL, NULL);

		return _hwnd;
	}

	void UIElement::Destroy()
	{
		DestroyWindow(_hwnd);
	}

	void UIElement::AddChild(UIElement* node)
	{
		__super::AddChild(node);
		YGNodeRef childYgNodeRef = node->GetYGNodeRef();
		YGNodeInsertChild(_ygNodeRef, childYgNodeRef, YGNodeGetChildCount(_ygNodeRef));
	}

	void UIElement::SetElementText(const std::wstring& text)
	{
		SetWindowText(_hwnd, text.c_str());
	}

	void UIElement::GetElementText(std::wstring& text) const
	{
		GetWindowText(_hwnd, text.data(), 256);
	}

	HWND UIElement::GetHWND() const
	{
		return _hwnd;
	}
}
