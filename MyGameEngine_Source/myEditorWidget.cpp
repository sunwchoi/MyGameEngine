#include "myEditorWidget.h"
#include "myUIText.h"
#include "myUIEdit.h"
#include "myUIButton.h"
#include "myUIManager.h"
#include "myEditorObjectViewWidget.h"

namespace my
{
	EditorWidget::EditorWidget()
	{
		Widget* widget = UIManager::CreateWidget<EditorObjectViewWidget>();
		SetChild(widget);
	}

	EditorWidget::~EditorWidget()
	{
	}
}
