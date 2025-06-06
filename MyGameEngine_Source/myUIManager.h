#pragma once

#include "map.hpp"
#include "Common.h"

#include <string>

namespace my
{
	class UIElement;
	class Widget;

	class UIManager
	{
	public:
		template<typename T>
		static T* CreateWidget()
		{
			Widget*& widget = _widgets[T::StaticClassID()];
			
			return static_cast<T*>(widget ? widget : widget = new T());
		}

		static void AddToViewport(Widget* widget);

	private:
		static map<uint32, Widget*> _widgets;
		static Widget* _currentWidget;
	};

}

