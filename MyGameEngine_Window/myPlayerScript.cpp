#include "myPlayerScript.h"
#include "myRenderer.h"
#include "../MyGameEngine_Source/myGameObject.h"
#include "../MyGameEngine_Source/Transform.h"
#include "../MyGameEngine_Source/Input.h"
#include "../MyGameEngine_Source/myTime.h"
#include "myAnimator.h"
#include "myResources.h"

namespace my
{
	const int _dirPreset[2][2] = { { -1, 0 }, { 1, 0 } };
	const std::wstring _animPreset[2][3] = { { L"LeftIdle", L"LeftWalk", L"LeftRun"},
											 { L"RightIdle", L"RightWalk", L"RightRun" } };
	void PlayerScript::Initialize()
	{
		_transform = GetOwner()->GetComponent<Transform>();
		_animator = GetOwner()->GetComponent<Animator>();
		_speed = 100.f;
	}

	void PlayerScript::Update()
	{
		ePlayerDirection currentDirection = ePlayerDirection::Count;

		if (Input::GetKey(eKeyCode::LEFT))
			currentDirection = ePlayerDirection::Left;

		if (Input::GetKey(eKeyCode::RIGHT))
			currentDirection = ePlayerDirection::Right;

		if (Input::GetKeyDown(eKeyCode::SHIFT))
			_speed = 200.f;
		else if (Input::GetKeyUp(eKeyCode::SHIFT))
			_speed = 100.f;

		if (currentDirection == ePlayerDirection::Count)
		{
			_animator->PlayAnimation(_animPreset[(int)_direction][(int)ePlayerState::Idle]);
		}
		else
		{
			_direction = currentDirection;
			if (_speed == 200.f)
				_animator->PlayAnimation(_animPreset[(int)_direction][(int)ePlayerState::Run]);
			else
				_animator->PlayAnimation(_animPreset[(int)_direction][(int)ePlayerState::Walk]);

			_transform->Move(_dirPreset[(int)currentDirection][0] * _speed * Time::DeltaTime(), _dirPreset[(int)currentDirection][1] * _speed * Time::DeltaTime());
		}
	}

	void PlayerScript::LateUpdate()
	{
	}

	void PlayerScript::Render(HDC hdc)
	{
	}
}
