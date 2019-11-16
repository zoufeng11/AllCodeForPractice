#pragma once

#include <iostream>
using namespace std;
class Mouse
{
public:
	virtual void sayHi() = 0;
};

class DellMouse:public Mouse
{
	virtual void sayHi()
	{
		cout << "Hi , this is a DellMouse" << endl;
	}
};

class HpMouse :public Mouse
{
	virtual void sayHi()
	{
		cout << "Hi , this is a HpMouse" << endl;
	}
};
/*Below is Factory*/

class MouseFactory
{
public:
	virtual Mouse* createMouse() = 0;
};

class HpMouseFactory :public MouseFactory
{
	virtual Mouse* createMouse()
	{
		return (new HpMouse());
	}
};

class DellMouseFactory :public MouseFactory
{
public:
	virtual Mouse* createMouse()
	{
		return (new DellMouse());
	}
};
