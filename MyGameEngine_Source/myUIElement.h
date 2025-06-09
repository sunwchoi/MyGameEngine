#pragma once

#include <Windows.h>
#include <myMath.h>
#include <string>

namespace my
{
	class UIElement
	{
	public:
		UIElement(const Vector2& pos, const Vector2& scale, const std::wstring& text);
		virtual ~UIElement();

		virtual HWND Construct();
		virtual void Destroy();

		virtual const wchar_t* GetWindowClassName() = 0;
	
		virtual void OnUIEvent(UINT message, WPARAM wParam, LPARAM lParam) = 0;

	private:
		HWND			_hwnd;
		
		Vector2			_pos;
		Vector2			_scale;
		std::wstring	_text;
	};
}

