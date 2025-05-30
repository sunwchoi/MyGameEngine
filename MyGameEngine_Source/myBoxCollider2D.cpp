#include "myBoxCollider2D.h"
#include "Transform.h"
#include "myGameObject.h"
#include "myRenderer.h"

namespace my
{
	BoxCollider2D::BoxCollider2D()
		:Collider2D(eColliderType::Box)
	{
	}

	BoxCollider2D::~BoxCollider2D()
	{
	}

	void BoxCollider2D::Initialize()
	{
	}

	void BoxCollider2D::Update()
	{
	}

	void BoxCollider2D::LateUpdate()
	{
	}

	void BoxCollider2D::Render(HDC hdc)
	{
#ifdef _DEBUG
		if (_bDebugDraw)
		{
			//Transform* transform = GetOwner()->GetComponent<Transform>();
			//const Vector2& pos = renderer::mainCamera->CalculatePosition(transform->GetPosition());
			//const Vector2& offset = GetOffset();

			//HBRUSH nullBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
			//HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, nullBrush);

			//HPEN debugPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
			//HPEN oldPen = (HPEN)SelectObject(hdc, debugPen);

			//float left = pos._x + offset._x - _size._x / 2;
			//float top = pos._y + offset._y - _size._y / 2;
			//Rectangle(hdc, left, top, left + _size._x, top + _size._y);

			//SelectObject(hdc, oldBrush);
			//SelectObject(hdc, oldPen);
			//
			//DeleteObject(debugPen);
		}

#endif
	}
}
