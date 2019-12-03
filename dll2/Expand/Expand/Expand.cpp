﻿// Expand.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// MathClient.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// MathClient.cpp : Client app for MathLibrary DLL.
// #include "pch.h" Uncomment for Visual Studio 2017 and earlier
#include <iostream>
#include "windows.h"
using namespace std;

typedef void (*PINIT)(const unsigned long long a, const unsigned long long b);
typedef bool (*PNEXT)();
typedef unsigned long long (*PCURRENT)();
typedef int (*PINDEX)();
int main()
{
	HMODULE hDLL = LoadLibrary(L"../../MathLibrary/Debug/MathLibrary.dll");
	if (hDLL == NULL) {
		cout << "获取动态连接库失败";
		return 0;
	}
	PINIT fibonacci_init = (PINIT)GetProcAddress(hDLL, "fibonacci_init");
	PNEXT fibonacci_next = (PNEXT)GetProcAddress(hDLL, "fibonacci_next");
	PCURRENT fibonacci_current = (PCURRENT)GetProcAddress(hDLL, "fibonacci_current");
	PINDEX fibonacci_index = (PINDEX)GetProcAddress(hDLL, "fibonacci_index");

	// Initialize a Fibonacci relation sequence.
	fibonacci_init(1, 1);
	// Write out the sequence values until overflow.
	do {
		std::cout << fibonacci_index() << ": "
			<< fibonacci_current() << std::endl;
	} while (fibonacci_next());
	// Report count of values written before overflow.
	std::cout << fibonacci_index() + 1 <<
		" Fibonacci sequence values fit in an " <<
		"unsigned 64-bit integer." << std::endl;

	FreeLibrary(hDLL);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
