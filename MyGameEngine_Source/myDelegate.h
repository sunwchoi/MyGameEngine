#pragma once

#include <vector>
#include <functional>

namespace my
{
	class Delegate
	{
		struct DelegateEntry
		{
			size_t _id;

		};
	public:
		void Bind(const std::function<void()>& func);
		void UnBind(const std::function<void()>& func);
		void Excute();

	private:
		std::function<void()>	_func;
	};
}

