#include "Input.h"
#include <Windows.h>

namespace my
{
	std::vector<Input::Key> Input::_keys = {};

	int ASCII[(size_t)eKeyCode::Count] = {
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
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
	}
}
