#pragma once
#include<string>
#include<iostream>
#include<list>

using namespace std;
class Resume
{
private:
	string m_name;
	string m_sex;
	string m_workexper;
	int m_age;
	string m_worktime;
public:
	Resume(string name) { m_name = name; }
	Resume() {}
	void SetSex_Age(string sex, int age) { this->m_sex = sex; this->m_age = age; }
	void Set_Workexper(string exper, string worktime) { this->m_workexper = exper;  this->m_worktime = worktime; }
	void Display() {
		cout << "name:" << m_name << endl
			<< "sex:" << m_sex << endl
			<< "age:" << m_age << endl;
		cout << "Working exp" << endl << m_worktime << "," << m_workexper << endl;
	}
	virtual  Resume* clone() = 0;    
	~Resume() {}
};

class ResumeA : public Resume
{
public:
	ResumeA(string s) :Resume(s) {}
	ResumeA() {}
	~ResumeA() {}
	Resume* clone() {
		ResumeA* p = new ResumeA();  
		*p = *this;
		return p;
	}
};

class ResumeB :public Resume {
public:
	ResumeB(string s) :Resume(s) {}
	ResumeB() {}
	~ResumeB() {}
	Resume* clone() {
		ResumeB* p = new ResumeB();
		*p = *this;
		return p;
		// return new ResumeB(*this);    //could repace the above 3 lines
	}
};


