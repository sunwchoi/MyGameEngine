#include "myTime.h"

namespace my
{

	LARGE_INTEGER Time::_cpuFrequency = {};
	LARGE_INTEGER Time::_prevFrequency = {};
	LARGE_INTEGER Time::_curFrequency = {};
	float Time::_deltaTime = 0;
	
	void Time::Initialize()
	{
		QueryPerformanceFrequency( &_cpuFrequency );
		QueryPerformanceCounter( &_prevFrequency );
	}

	void Time::Update()
	{
		QueryPerformanceCounter( &_curFrequency );

		_deltaTime = (float)( _curFrequency.QuadPart - _prevFrequency.QuadPart ) / _cpuFrequency.QuadPart;
		
		_prevFrequency = _curFrequency;
	}

}
