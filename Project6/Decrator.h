#pragma once
#include<string>
#include<iostream>

using namespace std;

class phone
{
public:
	phone() {}
	virtual ~phone() {}
	virtual void ShowDecorate()
	{

	}
};

class iPhone :public phone
{
private:
	string m_name;
public:
	iPhone(string name) :m_name(name) {}
	~iPhone() {}
	void ShowDecorate()
	{
		cout << m_name << "'s Decrator" << endl;
	}

};

class NokiaPhone :public phone
{

private:
	string m_name;
public:
	NokiaPhone(string name) :m_name(name) {}
	~NokiaPhone() {}
	void ShowDecorate(){
		cout << m_name << "'s decrator" << endl;
	}
};

class DecoratorPhone :public phone
{

private:
	phone* m_phone;
public:
	DecoratorPhone(phone* phone) :m_phone(phone) {}
	virtual void ShowDecorate()
	{
		m_phone->ShowDecorate();
	}
};

class DecoratorPhoneA :public DecoratorPhone
{

public:
	DecoratorPhoneA(phone* phone) : DecoratorPhone(phone) {}
	void ShowDecorate() { DecoratorPhone::ShowDecorate(); AddDecorate(); }
private:
	void AddDecorate() { cout << "add 1 decrator" << endl; }
};

class DecoratorPhoneB : public DecoratorPhone
{
public:
	DecoratorPhoneB(phone* phone) : DecoratorPhone(phone) {}
	void ShowDecorate() { DecoratorPhone::ShowDecorate(); AddDecorate(); }
private:
	void AddDecorate() { cout << "add 2 decrator" << endl; }
};


