#include <iostream>
#include "chapter1.h"

#ifdef _WIN32
#include <windows.h>
#endif

int main() 
{
#ifdef _WIN32
    // 设置win控制台输出编码为UTF-8，以支持中文字符的正确显示
    SetConsoleOutputCP(CP_UTF8);
#endif

    chapter1::run();
    return 0;
}
