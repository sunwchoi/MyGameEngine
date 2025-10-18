#pragma once

#ifdef NDEBUG

#define MY_ASSERT(expr) ((void)0)
#define MY_ASSERT_MSG(expr, msg) ((void)0)

#else

#define MY_ASSERT(expr) expr ? (void)0 : my::Assert(#expr, "Assertion Failed", __FUNCTION__, __FILE__, __LINE__)
#define MY_ASSERT_MSG(expr, msg) expr ? (void)0 :my::Assert(#expr, msg, __FUNCTION__, __FILE__, __LINE__)

#endif

namespace my
{
	void Assert(const char* expr, const char* msg, const char* function, const char* file, long line);
}
