#include "Test.h"
#include <iostream>
using namespace std;

sample funcSample(sample x)
{
	cout << "I am a funcSample" << endl;
	return x;
}
void func(char* p1, char* p2)
{
	p1 = p2;
	(*p1)++;
}
int main()
{
	cout << sizeof(Test) << endl;
	sample s1(10);
	sample s2 = funcSample(s1);
	s1.printval();
	try
	{
		A a(1);
		A b(0);
		A c(5);
	}
	catch(...)
	{
		cout << "ffff";
		cout << "3" << endl;
	}

	char s11 = 'A';
	char s12 = 'a';
	char* p1 = &s11;
	char* p2 = &s12;
	func(p1, p2);

	solutionB* slna = new solutionB;
	slna->func();
	delete slna;	

	int hhh = 0;
	char t = static_cast<char>(hhh);

	return 0;

}
