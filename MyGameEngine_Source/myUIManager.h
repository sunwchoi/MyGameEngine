#pragma once

#include "map.hpp"
#include "vector.hpp"
#include "Common.h"
#include "myMath.h"

#include <string>
#include <functional>
#include <Windows.h>

namespace my
{
	class UIElement;
	class Widget;

	class UIManager
	{
		enum eTraversalState : uint8
		{
			Go,			//��ȸ
			Continue,	//�ڽ� ��ȸ �ߴ�, ���� ������ �ٽ� ��ȸ ����
			Break,		//��ü ��ȸ �ߴ�

			Count
		};

	public:
		template<typename T>
		static T* CreateWidget()
		{
			Widget*& widget = _widgets[T::StaticClassID()];
			
			return static_cast<T*>(widget ? widget : widget = new T());
		}

		template<typename T>
		static T* CreateWidget(const Vector2& position)
		{
			Widget*& widget = _widgets[T::StaticClassID()];

			return static_cast<T*>(widget ? widget : widget = new T(position));
		}
		
		static void AddToViewport(Widget* widget);
		static void RemoveFromParent(Widget* widget);

		static eTraversalState Traverse(Widget* widget, const std::function<eTraversalState(Widget*)>& visitor);

		static void OnUIEvent(UINT message, WPARAM wParam, LPARAM lParam);
	private:
		static map<uint32, Widget*> _widgets;
		static vector<Widget*>		_currentWidgetRoots;
	};

}

