#include "myWidget.h"

#include "myUIButton.h"
#include "myUIEdit.h"
#include "myUIElement.h"
#include "myUIPanel.h"
#include "myUIText.h"
#include "myXmlUtil.h"

namespace my
{
	Widget::Widget()
	{
	}

	Widget::Widget(const std::string& xmlFile, const Vector2& position)
		: _position(position)
	{
		XmlNode* root = LoadMymlFile(xmlFile);
		UIElement* parent = nullptr;
		root->TraverseSafely(
			[ & ](const XmlNode* node)
			{
				UIElement* element = nullptr;
				if (node->_tag == "button")
					element = new UIButton(parent, node);
				else if (node->_tag == "text")
					element = new UIText(parent, node);
				else if (node->_tag == "edit")
					element = new UIEdit(parent, node);
				else if (node->_tag == "panel")
					element = new UIPanel(parent, node);

				MY_ASSERT(element);

				if (parent == nullptr)
				{
					_rootElement = element;
					YGNodeStyleSetHeight(_rootElement->GetYGNodeRef(), 500.f);
					YGNodeStyleSetWidth(_rootElement->GetYGNodeRef(), 500.f);
					YGNodeStyleSetFlexDirection(_rootElement->GetYGNodeRef(), YGFlexDirectionRow);
					YGNodeStyleSetJustifyContent(_rootElement->GetYGNodeRef(), YGJustifyFlexStart);
					YGNodeStyleSetAlignItems(_rootElement->GetYGNodeRef(), YGAlignFlexStart);
				}

				parent = element;
			},
			[&](const XmlNode* node)
			{
				parent = parent != nullptr ? parent->GetParent() : nullptr;
			}
		);


	}

	Widget::~Widget()
	{
		if (_rootElement == nullptr)
			return;

		_rootElement->Destroy();
		_rootElement = nullptr;
	}
	
	void Widget::Construct()
	{
		if (_rootElement == nullptr)
			return;

		YGNodeCalculateLayout(_rootElement->GetYGNodeRef(), YGUndefined, YGUndefined, YGDirectionLTR);
		
		_rootElement->Traverse([](UIElement* element) {
			element->Construct();
		}, [](UIElement*) {});
	}

	void Widget::Destroy()
	{
		if (_rootElement == nullptr)
			return;

		_rootElement->Destroy();
	}

	void Widget::SetChild(Widget* widget)
	{
		_children.push_back(widget);
	}

	void Widget::SetPosition(const Vector2& position)
	{
		_position = position;
	}

	bool Widget::OnUIEvent(UINT message, WPARAM wParam, LPARAM lParam)
	{
		if (_rootElement == nullptr)
			return false;

		return _rootElement->OnUIEvent(message, wParam, lParam);
	}
}
