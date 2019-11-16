#include "externTest.h"
#include <iostream>
using namespace std;

externTest::externTest(const int& i)
{
	cout << "externTest Construct" << endl;
}

externTest::~externTest()
{
	cout << "~externTest" << endl;
}
