#include "Input.h"
#include "myApplication.h"
#include <Windows.h>

extern my::Application application;

namespace my
{
	Vector2					Input::_mousePosition;
	Vector2					Input::_preMousePosition;
	std::vector<Input::Key> Input::_keys = {};

	int ASCII[(size_t)eKeyCode::Count] = {
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M', 

		VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
		VK_LBUTTON, VK_MBUTTON, VK_RBUTTON,
		VK_SPACE, VK_SHIFT 
	};

	Input::Key::Key(uint8 code)
		: _code((eKeyCode)code)
		, _state(eKeyState::None)
		, _bPressed(false)
	{
	}

	void Input::Initialize()
	{
		_keys.reserve((size_t)eKeyCode::Count);

		size_t count = (size_t)eKeyCode::Count;
		for (size_t i = 0; i < count; i++)
			_keys.emplace_back(i);
	}

	void Input::Update()
	{
		size_t count = _keys.size();
		for (size_t i = 0; i < count; i++)
		{
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (_keys[i]._bPressed)
					_keys[i]._state = eKeyState::Pressed;
				else
					_keys[i]._state = eKeyState::Down;
				
				_keys[i]._bPressed = true;
			}
			else
			{
				if (_keys[i]._bPressed)
					_keys[i]._state = eKeyState::Up;
				else
					_keys[i]._state = eKeyState::None;

				_keys[i]._bPressed = false;
			}
		}

		UpdateMousePosition();
	}



	void Input::UpdateMousePosition()
	{
		POINT mousePoint = {};

		GetCursorPos(&mousePoint);
		ScreenToClient(application.GetHWND(), &mousePoint);

		_preMousePosition = _mousePosition;
		_mousePosition._x = mousePoint.x;
		_mousePosition._y = mousePoint.y;
	}
}
