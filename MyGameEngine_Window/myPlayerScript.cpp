#include "myPlayerScript.h"
#include "myRenderer.h"
#include "Transform.h"
#include "myGameObject.h"
#include "Input.h"
#include "myTime.h"
#include "myAnimator.h"
#include "myResources.h"
#include "myAssert.h"
#include "myBoxCollider2D.h"
#include "myCircleCollider2D.h"

#include <functional>

namespace my
{
	void PlayerScript::Initialize()
	{
			
		// Animator
		//_animator = GetOwner()->GetComponent<Animator>();
		//_animator->BindCompleteEvent(L"LeftJump", std::bind(&PlayerScript::JumpEnd, this));
		//_animator->BindCompleteEvent(L"RightJump", std::bind(&PlayerScript::JumpEnd, this));
		//_animator->BindCompleteEvent(L"LeftAttack1", std::bind(&PlayerScript::AttackEnd, this));
		//_animator->BindCompleteEvent(L"RightAttack1", std::bind(&PlayerScript::AttackEnd, this));
		//_animator->BindCompleteEvent(L"LeftAttack2", std::bind(&PlayerScript::AttackEnd, this));
		//_animator->BindCompleteEvent(L"RightAttack2", std::bind(&PlayerScript::AttackEnd, this));
		//_animator->BindCompleteEvent(L"LeftAttack3", std::bind(&PlayerScript::AttackEnd, this));
		//_animator->BindCompleteEvent(L"RightAttack3", std::bind(&PlayerScript::AttackEnd, this));
		//_animator->BindCompleteEvent(L"LeftHurt", std::bind(&PlayerScript::HurtEnd, this));
		//_animator->BindCompleteEvent(L"RightHurt", std::bind(&PlayerScript::HurtEnd, this));

		// Collider
		//_bodyCollider = GetOwner()->AddComponent<BoxCollider2D>();
		//_bodyCollider->SetSize(Vector2(50.f, 128.f));
		//_bodyCollider->SetDebugDraw(true);

		//_attackCollider = GetOwner()->AddComponent<CircleCollider2D>();
		//_attackCollider->SetRadius(30.f);
		//_attackCollider->SetDebugDraw(true);
		//_attackCollider->Disable();

	}

	void PlayerScript::Update()
	{
		//if (_comboIndex) //콤보 공격 중 일때
		//{
		//	_comboTime -= Time::DeltaTime();
		//	if (_comboTime <= 0)
		//		_comboIndex = 0;
		//}

		//switch (_state)
		//{
		//case ePlayerState::Idle:
		//	Idle();
		//	break;
		//case ePlayerState::Walk:
		//case ePlayerState::Run:
		//	Move();
		//	break;
		//case ePlayerState::Jump:
		//	Jump();
		//	break;
		//case ePlayerState::Attack:
		//	Attack();
		//	break;
		//case ePlayerState::Hurt:
		//	Hurt();
		//	break;
		//}

		Transform& transform = GetOwner()->GetComponentMust<Transform>();

		if (Input::GetKey(eKeyCode::A))
		{
			transform.SetRotation(transform.GetRotation() + Rotator(0, 0.1, 0));
		}
		else if (Input::GetKey(eKeyCode::D))
		{
			transform.SetRotation(transform.GetRotation() - Rotator(0, 0.1, 0));
		}

		if (Input::GetKey(eKeyCode::W))
		{
			transform.SetRotation(transform.GetRotation() + Rotator(0.1, 0, 0));
			
			//tf.SetRotation(tf.GetRotation() + Rotator(0.1, 0, 0));
			//renderer::mainCamera->SetTransform(tf);
		}
		else if (Input::GetKey(eKeyCode::S))
		{
			transform.SetRotation(transform.GetRotation() - Rotator(0.1, 0, 0));
			//transform.SetPosition(transform.GetPosition() + Vector3(0, 0, -10));
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
	}


	void PlayerScript::Jump()
	{

	}

	void PlayerScript::Attack()
	{
		constexpr const wchar_t* animPreset[2][3] = { {L"LeftAttack1", L"LeftAttack2", L"LeftAttack3"}, {L"RightAttack1", L"RightAttack2", L"RightAttack3"} };
		constexpr const float offsetPreset[2] = { -25.f, 25.f };
		
		if (_bAttack == false)
		{
			_attackCollider->SetOffset(Vector2(offsetPreset[(uint8)_direction], 10.f));
			_attackCollider->Enable();
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
		_attackCollider->Disable();
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
