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
		Widget* widget = UIManager::CreateWidget<EditorObjectViewWidget>("..\\myml\\EditorObjectView.myml", Vector2::Zero);
		SetChild(widget);
	}

	EditorWidget::~EditorWidget()
	{
	}
}
