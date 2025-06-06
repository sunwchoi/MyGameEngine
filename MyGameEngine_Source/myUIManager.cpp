#include "myUIManager.h"
#include "myWidget.h"
#include "myAssert.h"

namespace my
{
	map<uint32, Widget*> UIManager::_widgets;
	Widget* UIManager::_currentWidget = nullptr;

	void UIManager::AddToViewport(Widget* widget)
	{
		MY_ASSERT_MSG(widget, "widget이 nullptr입니다");

		if (_currentWidget)
			_currentWidget->Destroy();

		_currentWidget = widget;
		_currentWidget->Construct();
	}
}
