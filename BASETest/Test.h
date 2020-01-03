#pragma once
#include <iostream>
using namespace std;
class Test
{
	char a;
	int b;
	//static int c;
};

class sample
{

public:
	int* ptr;
	sample()
	{
		cout << "I am sample class" << endl;
	}
	sample(const sample& c)
	{
		ptr = c.ptr;
		cout << "copy constrcut" << endl;
	}
	sample(int i)
	{
		ptr = new int(i);
	}
	~sample()
	{
		cout << "the value is deleted ";
		cout << *ptr << endl;
	}
	void printval()
	{
		cout << "the value is  ";
		cout << *ptr << endl;
	}
};

class A
{
public:
	const int number;

public:
	A(int n) :number(n)
	{
		if (n == 0)
			throw std::logic_error("0");
	}
	~A()
	{
		cout << number << endl;
	}
};

class solutionA
{
public:
	solutionA()
	{
		func();
	}

	virtual ~solutionA()
	{
		func();
	}
	virtual void func()
	{
		cout << "I am slnA" << endl;
	}
};

class solutionB :public solutionA
{
public:
	~solutionB()
	{
		func();
	}
	void func()
	{
		cout << "I am solutionB" << endl;
	}

};

