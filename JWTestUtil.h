#pragma once

#include <string>
#include <windows.h>

enum {
		black=0,
		dark_white=7,
		grey=8,
		blue=9,
		green=10,
		red=12,
		pink=13,
		yellow=14,
		white=15
};

namespace JWTestUtil
{
			
	void setcolor(int color, int bgcolor=black) 
	{
		color &= 0xf;
		bgcolor &= 0xf;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
	}
}

//W: Word Color
#define SETCOLOR(W) setcolor(W)