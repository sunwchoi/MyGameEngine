#pragma once

#include "Common.h"
#include "myMath.h"
#include <vector>

namespace my
{
	enum class eKeyState : uint8
	{
		None,
		Down,
		Pressed,
		Up,

		Count
	};

	enum class eKeyCode : uint8
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		LEFT, RIGHT, UP, DOWN,
		LBUTTON, MBUTTON, RBUTTON,
		SPACE, SHIFT,
		
		Count
	};

	class Input
	{
	public:
		struct Key
		{
			Key(uint8 code);
			
			eKeyCode	_code;
			eKeyState	_state;
			bool		_bPressed;
		};

		static void Initialize();
		static void Update();

		static bool GetKey(eKeyCode code) { return _keys[(uint8)code]._state == eKeyState::Pressed; };
		static bool GetKeyDown(eKeyCode code) { return _keys[(uint8)code]._state == eKeyState::Down; };
		static bool GetKeyUp(eKeyCode code) { return _keys[(uint8)code]._state == eKeyState::Up; };

		static const Vector2& GetMousePosition() { return _mousePosition; }
		static const Vector2& GetMouseDelta() { return _preMousePosition - _mousePosition; }

	private:
		static void UpdateMousePosition();

	private:
		static Vector2					_preMousePosition;
		static Vector2					_mousePosition;
		static std::vector<Input::Key>	_keys;
	};
}

