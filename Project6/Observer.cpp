#include "Observer.h"
#include<string>
#include<iostream>
#include<list>

using namespace std;

int Observermain()
{
	Subject* subject = new Subject();

	new HexObserver(subject);
	new OctalObserver(subject);
	new BinaryObserver(subject);

	cout << "First state change: 15" << endl;
	subject->setState(15);
	cout << "Second state change: 10" << endl;
	subject->setState(10);
	return 0;
}