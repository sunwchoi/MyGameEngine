#include "myPlayerScript.h"
#include "../MyGameEngine_Source/myGameObject.h"
#include "../MyGameEngine_Source/Transform.h"
#include "../MyGameEngine_Source/Input.h"
#include "../MyGameEngine_Source/myTime.h"

namespace my
{
	void PlayerScript::Initialize()
	{
		_playerTransform = GetOwner()->GetComponent<Transform>();
		_speed = 100.f;
	}

	void PlayerScript::Update()
	{
		if (Input::GetKey(eKeyCode::A))
			_playerTransform->Move(-1 * _speed * Time::DeltaTime(), 0);
		if (Input::GetKey(eKeyCode::D))
			_playerTransform->Move(_speed * Time::DeltaTime(), 0);
		if (Input::GetKey(eKeyCode::W))
			_playerTransform->Move(0, -1 * _speed * Time::DeltaTime());
		if (Input::GetKey(eKeyCode::S))
			_playerTransform->Move(0, _speed * Time::DeltaTime());
	}

	void PlayerScript::LateUpdate()
	{
	}

	void PlayerScript::Render(HDC hdc)
	{
	}
}
