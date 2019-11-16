#pragma once
#include<string>
#include<iostream>
#include<list>

using namespace std;

class ObserverInterface
{
public:
	virtual void update() = 0;
};
class Subject
{
private:
	list<ObserverInterface*> *observers = new list<ObserverInterface*>();
	int state;
public:
	int getState()
	{
		return state;
	}
	void setState(int state)
	{
		this->state = state;
		notifyAllobservers();
	}
	void attach(ObserverInterface* observer)
	{
		observers->push_back(observer);
	}
	void notifyAllobservers()
	{
		list<ObserverInterface*>::iterator it = observers->begin();
		while (it != observers->end())
		{
			(*it)->update();
			it++;
		}
	}

};




class Observer : public ObserverInterface
{
protected:
	Subject* subject;
public:
	virtual void update() = 0;
};




class BinaryObserver :public Observer
{

public:
	BinaryObserver(Subject *Subj)
	{
		this->subject = Subj;
		subject->attach(this);
	}

	void update()
	{
		cout << "Binary string ";
		cout <<  subject->getState() << endl;
	}
};


class OctalObserver :public Observer
{

public:
	OctalObserver(Subject* Subj)
	{
		this->subject = Subj;
		subject->attach(this);
	}

	void update()
	{
		cout << "OctalObserver string ";
		cout << subject->getState() << endl;
	}
};


class HexObserver :public Observer
{

public:
	HexObserver(Subject *Subj)
	{
		this->subject = Subj;
		subject->attach(this);
	}

	void update()
	{
		cout << "Hex string ";
		cout << subject->getState() << endl;
	}
};


