#include "myUIPanel.h"

namespace my
{
	UIPanel::UIPanel(UIElement* parent, const XmlNode* node)
		: UIElement(parent, node)
	{
	}

	UIPanel::~UIPanel()
	{
	}

	HWND UIPanel::Construct()
	{
		// 레이아웃 계산용 객체이므로 다른 처리없이 nullptr 리턴
		return nullptr;
	}

	void UIPanel::Destroy()
	{
	}

	bool UIPanel::OnUIEvent(UINT message, WPARAM wParam, LPARAM lParam)
	{
		return false;
	}
}
