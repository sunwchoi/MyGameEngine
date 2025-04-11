#include "myAssert.h"
#include <iostream>
#include <Windows.h>

namespace my
{
	void Assert(const char* expr, const char* msg, const char* function, const char* file, long line)
	{
        char buffer[512];
        snprintf(buffer, sizeof(buffer),
            "%s\n\nExpression: %s\nFunction: %s\nFile: %s\nLine: %ld\n\n"
            "Press Abort to exit, Retry to debug, Ignore to continue.",
            msg, expr, function, file, line);

        int result = MessageBoxA(NULL, buffer, "MY_ASSERT Failed",
            MB_ABORTRETRYIGNORE | MB_ICONERROR | MB_DEFBUTTON3);

        switch (result) {
        case IDABORT:
            std::exit(EXIT_FAILURE);
        case IDRETRY:
            __debugbreak();
        case IDIGNORE:
            return;
        }
	}
}
