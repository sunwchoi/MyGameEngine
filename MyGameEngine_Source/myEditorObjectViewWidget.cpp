#include "myEditorObjectViewWidget.h"
#include "myUIText.h"
#include "myUIEdit.h"
#include "myUIButton.h"
#include "myApplication.h"
#include "Transform.h"
#include "myGameObject.h"

//소수 출력용 임시 헤더
#include <sstream>
#include <iomanip>

extern my::Application application;

namespace my
{
	std::wstring floatToWstr(float value)
	{
		std::wstringstream wss;
		wss << std::fixed << std::setprecision(2) << value;
		return wss.str();
	}

	EditorObjectViewWidget::EditorObjectViewWidget()
	{
		PlaceElement<UIText>(Vector2(10.f, 10.f), Vector2(100.f, 20.f), L"ObjectView");
		PlaceElement<UIText>(Vector2(10.f, 30.f), Vector2(50.f, 20.f), L"POS");

		posXEdit = PlaceElement<UIEdit>(Vector2(60.f, 30.f), Vector2(50.f, 20.f), L"");
		posYEdit = PlaceElement<UIEdit>(Vector2(110.f, 30.f), Vector2(50.f, 20.f), L"");
		posZEdit = PlaceElement<UIEdit>(Vector2(160.f, 30.f), Vector2(50.f, 20.f), L"");

		UIButton* button = PlaceElement<UIButton>(Vector2(110.f, 10.f), Vector2(50.f, 20.f), L"Update");

		button->OnClicked.Bind([this]()
			{
				const GameObject* object = application.GetSelectedObject();

				const Transform* tf = object->GetComponent<Transform>();
				if (tf == nullptr)
					return;

				Vector3& pos = const_cast<Vector3&>(tf->GetPosition());

				std::wstring buffer;

				buffer.resize(256);
				posXEdit->GetElementText(buffer);
				pos._x = std::stoi(buffer);

				posYEdit->GetElementText(buffer);
				pos._y = std::stoi(buffer);

				posZEdit->GetElementText(buffer);
				pos._z = std::stoi(buffer);
			}
		);
	}

	EditorObjectViewWidget::~EditorObjectViewWidget()
	{
	}

	void EditorObjectViewWidget::Construct()
	{
		__super::Construct();

		const GameObject* object = application.GetSelectedObject();

		const Transform* tf = object->GetComponent<Transform>();
		if (tf == nullptr)
			return;

		const Vector3& pos = tf->GetPosition();

		posXEdit->SetElementText(floatToWstr(pos._x));
		posYEdit->SetElementText(floatToWstr(pos._y));
		posZEdit->SetElementText(floatToWstr(pos._z));
	}
}
