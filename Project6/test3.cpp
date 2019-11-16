#include "test3.h"
#include<iostream>
using namespace std;

int test3main()
{
	D *clasD = new D();
	B* clasB = new B();
	C* clasC = new C();
	clasD->show(clasC);
	clasD->addItem(clasB);
	clasD->addItem(clasB);
	clasD->show();
	return 0;
}