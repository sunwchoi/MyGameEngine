#include "myWidget.h"
#include "myUIElement.h"

namespace my
{
	Widget::Widget()
	{
	}

	Widget::~Widget()
	{
		for (int i = 0; i < _elements.size(); i++)
			_elements[i]->Destroy();
	}
	
	void Widget::Construct()
	{
		for (int i = 0; i < _elements.size(); i++)
		{
			HWND hwnd = _elements[i]->Construct();
			
			_hwndMap[hwnd] = _elements[i];
		}
	}

	void Widget::Destroy()
	{
		for (int i = 0; i < _elements.size(); i++)
			_elements[i]->Destroy();

		_hwndMap.clear();
	}
}
