#pragma once

#include <Windows.h>
#include <myMath.h>
#include <string>

#include "myITree.h"
#include "vector.hpp"

namespace my
{
	class UIElement : public TwoWayTree<UIElement>
	{
	public:
		UIElement(const Vector2& pos, const Vector2& scale, const std::wstring& text);
		virtual ~UIElement();

		virtual HWND Construct();
		virtual void Destroy();

		virtual const wchar_t* GetWindowClassName() = 0;
	
		virtual bool OnUIEvent(UINT message, WPARAM wParam, LPARAM lParam) = 0;

		void SetElementText(const std::wstring& text);
		void GetElementText(__out std::wstring& text) const;

		HWND GetHWND() const;
		Vector2 GetPos() const { return _pos; }
		Vector2 GetScale() const { return _scale; }

	private:
		vector<UIElement*> _children;
		HWND			_hwnd;
		
		Vector2			_pos;
		Vector2			_scale;
		std::wstring	_text;
	};
}

