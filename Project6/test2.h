#pragma once
#include"test1.h"

class B {
public:
	static void funA()
	{
		A a;
		a.func1();
		//a.func3();
		//sa.func3();
		A::func3();
	}
};