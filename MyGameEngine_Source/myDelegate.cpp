#include "myDelegate.h"
#include "myAssert.h"

namespace my
{
	void Delegate::Bind(const std::function<void()>& func)
	{
		_func = func;
	}

	void Delegate::UnBind(const std::function<void()>& func)
	{
		_func = nullptr;
	}

	void Delegate::Excute()
	{
		if (_func == nullptr)
			return;
		
		_func();
	}
}
