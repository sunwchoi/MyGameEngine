#pragma once
#include "myScript.h"

namespace my
{
	class  CameraScript : public Script
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void Move();
		void Rotate();

	private:
		float _moveSpeed = 100.f;
		float _rotationSpeed = 1.f;
	};
}

