#include "myEditorWidget.h"
#include "myUIText.h"
#include "myUIEdit.h"
#include "myUIButton.h"

namespace my
{
	EditorWidget::EditorWidget()
	{
		PlaceElement<UIText>(Vector2(10.f, 10.f), Vector2(50.f, 20.f), L"Editor");
		PlaceElement<UIEdit>(Vector2(60.f, 10.f), Vector2(50.f, 20.f), L"");
		
		UIButton* button = PlaceElement<UIButton>(Vector2(110.f, 10.f), Vector2(50.f, 20.f), L"Button");

		button->OnClicked.Bind([]() {
				exit(1);
			});
	}

	EditorWidget::~EditorWidget()
	{
	}
}
