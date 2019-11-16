#pragma once
#include<iostream>
#include<list>
using namespace std;
class A
{
public:
	virtual void hello()
	{
		cout << "A hello" << endl;
	}
};

class B :public A
{
	virtual void hello()
	{
		cout << "B hello" << endl;
	}

};

class C :public B
{
	virtual void hello()
	{
		cout << "C hello" << endl;
	}

};

class D
{
private:
	list<A*> *items = new list<A*>();
public:
	void show(A* point)
	{
		point->hello();
	}
	void addItem(A* point)
	{
		items->push_back(point);
	}
	void show()
	{
		list<A*>::iterator it = items->begin();
		while (it != items->end())
		{
			(*it)->hello();
			it++;
		}
	}

};


