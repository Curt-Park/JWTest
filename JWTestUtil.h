#pragma once

#ifdef _WIN32
    #include <windows.h>
    #define BLACK       0
    #define GREEN       10
    #define RED         12
    #define YELLOW      14
    #define WHITE       15
#else // __APPLE__ || __linux__
    #include <iostream>
    #define BLACK        "\033[30m"
    #define GREEN        "\033[32m"
    #define RED          "\033[31m"
    #define YELLOW       "\033[33m"
    #define WHITE        "\033[37m"
#endif

namespace JWTestUtil
{
#ifdef _WIN32
	void setcolor(int color, int bgcolor=BLACK) 
	{
		color &= 0xf;
		bgcolor &= 0xf;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
	}
#else // __APPLE__ || __linux__
	void setcolor(const char* color) 
	{
        std::cout<<color;
	}
#endif
}

//W: Word Color
#define SETCOLOR(W) setcolor(W)
