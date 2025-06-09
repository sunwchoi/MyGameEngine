#include "myUIManager.h"
#include "myWidget.h"
#include "myAssert.h"

namespace my
{
	map<uint32, Widget*> UIManager::_widgets;
	vector<Widget*> UIManager::_currentWidgetRoots;

	void UIManager::AddToViewport(Widget* widget)
	{
		MY_ASSERT_MSG(widget, "widget이 nullptr입니다");
	
		Traverse(widget, [](Widget* w) -> eTraversalState
			{
				w->Construct();
				return eTraversalState::Go;
			}
		);

		_currentWidgetRoots.push_back(widget);
	}

	void UIManager::RemoveFromParent(Widget* removeTarget)
	{
		MY_ASSERT_MSG(removeTarget, "widget이 nullptr입니다");

		for (int i = 0; i < _currentWidgetRoots.size(); i++)
		{
			// 자식에서 삭제할 widget찾기
			Traverse(_currentWidgetRoots[i], [removeTarget](Widget* widget) -> eTraversalState
				{
					if (widget == removeTarget)
					{
						// 찾은 위젯부터 순회하면서 Destroy
						Traverse(widget, [](Widget* w)->eTraversalState {
							w->Destroy();
							return eTraversalState::Go;
						});

						return eTraversalState::Break;
					}

					return eTraversalState::Go;
				}
			);

			// 삭제된 Widget이 root였다면 삭제
			if (removeTarget == _currentWidgetRoots[i])
			{
				_currentWidgetRoots.erase(_currentWidgetRoots.begin() + i);
				break;
			}
		}

	}

	UIManager::eTraversalState UIManager::Traverse(Widget* widget, const std::function<eTraversalState(Widget*)>& visitor)
	{
		eTraversalState state = visitor(widget);

		if (state == eTraversalState::Go)
		{
			for (Widget* widget : widget->_children)
			{
				state = Traverse(widget, visitor);
				if (state == eTraversalState::Break)
					break;
			}
		}

		return state;
	}

	void UIManager::OnUIEvent(UINT message, WPARAM wParam, LPARAM lParam)
	{
		for (int i = 0; i < _currentWidgetRoots.size(); i++)
			Traverse(_currentWidgetRoots[i], [message, wParam, lParam] (Widget* widget)->eTraversalState
				{
					if (widget->OnUIEvent(message, wParam, lParam))
						return eTraversalState::Break;

					return eTraversalState::Go;
				}
			);
	}

}
