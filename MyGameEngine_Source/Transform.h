#pragma once
#include "Component.h"
#include "myMath.h"

namespace my
{
	class Transform : public Component
	{
	public:
		Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render( HDC hdc ) override;

		void SetPosition(float x, float y) { _position._x = x; _position._y = y; }
		void SetPosition(const Vector2 position) { _position = position; }
		const Vector2& GetPosition() const { return _position; }

		void Move(float dx, float dy);

	private:
		Vector2 _position;
	};

}

