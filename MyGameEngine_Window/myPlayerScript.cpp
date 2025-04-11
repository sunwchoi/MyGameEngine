#include "myPlayerScript.h"
#include "myRenderer.h"
#include "../MyGameEngine_Source/myGameObject.h"
#include "../MyGameEngine_Source/Transform.h"
#include "../MyGameEngine_Source/Input.h"
#include "../MyGameEngine_Source/myTime.h"
#include "myAnimator.h"
#include "myResources.h"
#include "myAssert.h"
#include <functional>

namespace my
{
	void PlayerScript::Initialize()
	{
		_transform = GetOwner()->GetComponent<Transform>();
		_animator = GetOwner()->GetComponent<Animator>();
		//_animator->BindCompleteEvent(L"LeftJump", std::bind(&PlayerScript::JumpEnd, this));
		//_animator->BindCompleteEvent(L"RightJump", std::bind(&PlayerScript::JumpEnd, this));
		_animator->BindCompleteEvent(L"LeftAttack1", std::bind(&PlayerScript::AttackEnd, this));
		_animator->BindCompleteEvent(L"RightAttack1", std::bind(&PlayerScript::AttackEnd, this));
		_animator->BindCompleteEvent(L"LeftAttack2", std::bind(&PlayerScript::AttackEnd, this));
		_animator->BindCompleteEvent(L"RightAttack2", std::bind(&PlayerScript::AttackEnd, this));
		_animator->BindCompleteEvent(L"LeftAttack3", std::bind(&PlayerScript::AttackEnd, this));
		_animator->BindCompleteEvent(L"RightAttack3", std::bind(&PlayerScript::AttackEnd, this));
		//_animator->BindCompleteEvent(L"LeftHurt", std::bind(&PlayerScript::HurtEnd, this));
		//_animator->BindCompleteEvent(L"RightHurt", std::bind(&PlayerScript::HurtEnd, this));
		_speed = 100.f;
	}

	void PlayerScript::Update()
	{
		if (_comboIndex) //콤보 공격 중 일때
		{
			_comboTime -= Time::DeltaTime();
			if (_comboTime <= 0)
				_comboIndex = 0;
		}

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
		//Attack 우선 처리
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
		
		if (Input::GetKey(eKeyCode::A)) //Attack 우선 처리
		{
			_state = ePlayerState::Attack;
			return;
		}
		else if ((_direction == ePlayerDirection::Left && Input::GetKeyUp(eKeyCode::LEFT))
				|| (_direction == ePlayerDirection::Right && Input::GetKeyUp(eKeyCode::RIGHT))) //이동이 끝난 경우
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
		constexpr const wchar_t* animPreset[2][3] = { {L"LeftAttack1", L"LeftAttack2", L"LeftAttack3"}, {L"RightAttack1", L"RightAttack2", L"RightAttack3"} };

		if (_bAttack == false)
		{
			_animator->PlayAnimation(animPreset[(uint8)_direction][_comboIndex]);
			_bAttack = true;
			_comboTime = 3.f;
		}
	}

	void PlayerScript::Hurt()
	{
	}

	void PlayerScript::JumpEnd()
	{
		_state = ePlayerState::Idle;
	}

	void PlayerScript::AttackEnd()
	{
		_comboTime = 1.f;
		if (++_comboIndex == 3)
			_comboIndex -= 3;

		_bAttack = false;
		_state = ePlayerState::Idle;
	}

	void PlayerScript::HurtEnd()
	{
		_state = ePlayerState::Idle;
	}
}
