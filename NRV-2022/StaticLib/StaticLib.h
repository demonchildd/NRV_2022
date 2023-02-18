#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <ctime>

extern "C"
{
	char* Date();


	char* Time();


	void _stdcall OutputInt(unsigned int a);

	void _stdcall OutputStr(char* ptr);
}

