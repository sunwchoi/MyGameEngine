#pragma once

#include "myMath.h"
#include "vector.hpp"
#include "map.hpp"
#include "set.hpp"
#include "Common.h"

#include <Windows.h>
#include <string>

#define GENERATED_WIDGET_BODY() \
public: \
    static uint32 StaticClassID() { \
        static uint32 id = GenerateID(); \
        return id; \
    } \
    virtual uint32 ClassID() const { return StaticClassID(); }

namespace my
{
	class UIManager;
	class UIElement;

	class Widget
	{
	public:
		Widget();
		virtual ~Widget();

		template<typename T>
		T* PlaceElement(const Vector2& pos, const Vector2& size, const std::wstring& text)
		{
			T* element = new T(pos, size, text);
			_elements.push_back(element);

			return element;
		}

		virtual uint32 ClassID() const = 0;

	protected:
		static uint32 GenerateID()
		{
			static uint32 id = 0;
			return id++;
		}

		virtual void Construct();
		virtual void Destroy();

	private:
		bool OnUIEvent(UINT message, WPARAM wParam, LPARAM lParam);

	private:
		vector<UIElement*>		_elements;
		map<HWND, UIElement*>	_hwndMap;
		vector<Widget*>			_children;
	
		friend class UIManager;
	};
}

