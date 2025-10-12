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
		Widget(const std::string& xmlFile, const Vector2& position);
		virtual ~Widget();

		//template<typename T>
		//T* PlaceElement(const Vector2& pos, const Vector2& size, const std::wstring& text)
		//{
		//	 T* element = new T(_position + pos, size, text);
		//	 _elements.push_back(element);

		//	return element;
		//}

		virtual uint32 ClassID() const = 0;

		virtual void Construct();
		virtual void Destroy();
	protected:
		static uint32 GenerateID()
		{
			static uint32 id = 0;
			return id++;
		}

		void SetChild(Widget* widget);
		void SetPosition(const Vector2& position);

	private:
		bool OnUIEvent(UINT message, WPARAM wParam, LPARAM lParam);

	private:
		UIElement* _rootElement;
		vector<Widget*>			_children;
		Vector2					_position;
	
		friend class UIManager;
	};
}

