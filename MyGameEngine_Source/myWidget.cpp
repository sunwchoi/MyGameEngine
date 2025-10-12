#include "myWidget.h"

#include "myUIButton.h"
#include "myUIEdit.h"
#include "myUIElement.h"
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
		XmlNode* root = LoadXmlFile(xmlFile);
		UIElement* parent = nullptr;
		root->Traverse([ & ](const XmlNode* node)
			{
				// 포지션, 사이즈 계산
				Vector2 pos = parent? parent->GetPos() : position;
				Vector2 scale = parent ? parent->GetScale() : Vector2::Zero;

				auto it = node->_attributes.find("x");
				if (it != node->_attributes.end())
					pos._x = std::stoi(it->second);

				it = node->_attributes.find("y");
				if (it != node->_attributes.end())
					pos._y = std::stoi(it->second);

				it = node->_attributes.find("width");
				if (it != node->_attributes.end())
					scale._x = std::stoi(it->second);

				it = node->_attributes.find("height");
				if (it != node->_attributes.end())
					scale._y = std::stoi(it->second);

				UIElement* element = nullptr;
				if (node->_tag == "button")
					element = new UIButton(pos, scale, L"button");
				else if (node->_tag == "text")
				{
					std::wstring tmp;
					tmp.assign(node->_text.begin(), node->_text.end());
					element = new UIText(pos, scale, tmp);
				}
				else if (node->_tag == "edit")
					element = new UIEdit(pos, scale, L"edit");

				MY_ASSERT(element);

				if (parent)
					parent->AddChild(element);
				else
					_rootElement = element;

				parent = element;
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

		_rootElement->Construct();
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
