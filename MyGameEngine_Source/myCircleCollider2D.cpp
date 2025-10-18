#include "myCircleCollider2D.h"
#include "Transform.h"
#include "myGameObject.h"
#include "myRenderer.h"

namespace my
{
	CircleCollider2D::CircleCollider2D()
		: Collider2D(eColliderType::Circle)
	{
	}

	CircleCollider2D::~CircleCollider2D()
	{
	}

	void CircleCollider2D::Initialize()
	{
	}

	void CircleCollider2D::Update()
	{
	}

	void CircleCollider2D::LateUpdate()
	{
	}

	void CircleCollider2D::Render(HDC hdc)
	{
#ifdef _DEBUG
		if (_bDebugDraw)
		{
			//Transform* transform = GetOwner()->GetComponent<Transform>();
			//const Vector2& pos = renderer::mainCamera->CalculatePosition(transform->GetPosition());
			//const Vector2& offset = GetOffset();

			//HBRUSH nullBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
			//HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, nullBrush);

			//HPEN debugPen = CreatePen(PS_SOLID, 2, IsEnable() ? RGB(255, 0, 0) : RGB(0, 0, 255));
			//HPEN oldPen = (HPEN)SelectObject(hdc, debugPen);

			//float left = pos._x + offset._x - _radius;
			//float top = pos._y + offset._y - _radius;
			//Ellipse(hdc, left, top, left + 2 * _radius, top + 2 * _radius);

			//SelectObject(hdc, oldBrush);
			//SelectObject(hdc, oldPen);

			//DeleteObject(debugPen);
		}
#endif // _DEBUG

	}

}
