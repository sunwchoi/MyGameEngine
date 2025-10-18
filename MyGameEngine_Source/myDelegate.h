#pragma once

#include "myAssert.h"
#include <functional>


#define INTERNAL_DECLARE_DELEGATE(DelegateName, DelegateSignature) \
class DelegateName : public my::Delegate<DelegateSignature> \
{ \
};

#define DECLARE_DELEGATE(DelegateName) INTERNAL_DECLARE_DELEGATE(DelegateName, void(void))

namespace my
{
	template<typename Signature>
	class Delegate;

	template<typename Ret, typename... Args> 
	class Delegate<Ret(Args...)>
	{
	public:
		void Bind(const std::function<Ret(Args...)>& function)
		{
			_function = function;
		}

		void UnBind()
		{
			_function = nullptr;
		}

		bool isBind()
		{
			if (_function == nullptr)
				return false;

			return true;
		}

		Ret Execute(Args... args)
		{
			MY_ASSERT_MSG(_function, "바인딩된 함수가 없는데 Execute 호출중.");

			return _function(std::forward<Args>(args)...);
		}

	private:
		std::function<Ret(Args...)>	_function = nullptr;
	};
}

