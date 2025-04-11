#include "myPlayerScript.h"
#include "myRenderer.h"
#include "../MyGameEngine_Source/myGameObject.h"
#include "../MyGameEngine_Source/Transform.h"
#include "../MyGameEngine_Source/Input.h"
#include "../MyGameEngine_Source/myTime.h"
#include "myAnimator.h"
#include "myResources.h"
#include "myAssert.h"

namespace my
{
	void PlayerScript::Initialize()
	{
		_transform = GetOwner()->GetComponent<Transform>();
		_animator = GetOwner()->GetComponent<Animator>();
		_speed = 100.f;
	}

	void PlayerScript::Update()
	{
		switch (_state)
		{
		case ePlayerState::Idle:
			Idle();
			break;
		case ePlayerState::Walk:
		case ePlayerState::Run:
			Move();
			break;
		case ePlayerState::Jump:
			Jump();
			break;
		case ePlayerState::Attack:
			Attack();
			break;
		case ePlayerState::Hurt:
			Hurt();
			break;
		}
	}

	void PlayerScript::LateUpdate()
	{
	}

	void PlayerScript::Render(HDC hdc)
	{
	}

	void PlayerScript::Idle()
	{
		//Attack 快急 贸府
		if (Input::GetKey(eKeyCode::A))
		{
			_state = ePlayerState::Attack;
		}
		else if (Input::GetKey(eKeyCode::LEFT))
		{
			_direction = ePlayerDirection::Left;
			_state = ePlayerState::Walk;
		}
		else if (Input::GetKey(eKeyCode::RIGHT))
		{
			_direction = ePlayerDirection::Right;
			_state = ePlayerState::Walk;
		}
		else
		{
			constexpr const wchar_t* animPreset[2] = { L"LeftIdle", L"RightIdle" };

			_animator->PlayAnimation(animPreset[(uint8)_direction]);
		}
	}

	void PlayerScript::Move()
	{
		
		if (Input::GetKey(eKeyCode::A)) //Attack 快急 贸府
		{
			_state = ePlayerState::Attack;
			return;
		}
		else if ((_direction == ePlayerDirection::Left && Input::GetKeyUp(eKeyCode::LEFT))
				|| (_direction == ePlayerDirection::Right && Input::GetKeyUp(eKeyCode::RIGHT))) //捞悼捞 场抄 版快
		{
			_state = ePlayerState::Idle;
			return;
		}
		
		if (Input::GetKey(eKeyCode::SHIFT))
			_state = ePlayerState::Run;
		else
			_state = ePlayerState::Walk;

		constexpr const wchar_t* animPreset[2][2] = { {L"LeftWalk", L"LeftRun"}, {L"RightWalk", L"RightRun"} };
		const float speed = _state == ePlayerState::Walk ? 100.f : 200.f;
		const float dx = _direction == ePlayerDirection::Left ? -1.f : 1.f;

		_animator->PlayAnimation(animPreset[(uint8)_direction][(uint8)_state - (uint8)ePlayerState::Walk]);
		_transform->Move(dx * speed * Time::DeltaTime(), 0);
	}


	void PlayerScript::Jump()
	{
	}

	void PlayerScript::Attack()
	{
	}

	void PlayerScript::Hurt()
	{
	}
}
