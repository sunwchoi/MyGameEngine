#pragma once
#include <windows.h>

namespace my
{
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		
		static float DeltaTime() { return _deltaTime; };

	private:
		static LARGE_INTEGER _cpuFrequency;
		static LARGE_INTEGER _prevFrequency;
		static LARGE_INTEGER _curFrequency;
		static float _deltaTime;
	};
}

