#pragma once

#include <Windows.h>
#include <myMath.h>
#include <string>
#include <yoga/Yoga.h>

#include "myITree.h"
#include "vector.hpp"

namespace my
{
	class XmlNode;
}

namespace my
{
	class UIElement : public TwoWayTree<UIElement>
	{
	public:
		UIElement(UIElement* parent, const XmlNode* node);
		virtual ~UIElement();

		virtual HWND Construct();
		virtual void Destroy();
		void AddChild(UIElement* node) override;

		virtual const wchar_t* GetWindowClassName() = 0;
	
		virtual bool OnUIEvent(UINT message, WPARAM wParam, LPARAM lParam) = 0;

		void SetElementText(const std::wstring& text);
		void GetElementText(__out std::wstring& text) const;

		HWND GetHWND() const;
		Vector2 GetPos() const { return _pos; }
		Vector2 GetScale() const { return _scale; }
		YGNodeRef GetYGNodeRef() const { return _ygNodeRef; }

	private:
		vector<UIElement*> _children;
		YGNodeRef _ygNodeRef;
		HWND			_hwnd;
		Vector2			_pos;
		Vector2			_scale;
		std::wstring	_text;
	};
}

