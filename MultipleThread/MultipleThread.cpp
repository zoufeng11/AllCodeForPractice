#include <iostream>
// 必须的头文件
#include <windows.h>

#include <thread>
 
using namespace std;
 
#define NUM_THREADS 5
 
// 线程的运行函数
DWORD WINAPI say_hello(void* args)
{
	for (int i = 0; i < 10; i++)
	{
		cout << "Hello Runoob！" << endl;
	}

    return 0L;
}
 
int main()
{
    // 定义线程的 id 变量，多个变量使用数组
	HANDLE hThread = CreateThread(NULL, 0, say_hello, NULL, 0, NULL);
	CloseHandle(hThread);
	for (int i = 0; i < 10; i++)
	{
		cout << "Main thread Display!" << endl;
	}
	return 0;
}