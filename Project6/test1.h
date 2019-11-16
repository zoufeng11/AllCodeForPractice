#pragma once
#include <iostream>
using namespace std;


class A
{
public:
	static int count ;
	void func1()
	{
		cout << "ClassA func1";
	}

	void func2()
	{
		cout << "ClassA func2";
	}
	static void func3()
	{
		cout << "ClassA func3";
	}
private:

};