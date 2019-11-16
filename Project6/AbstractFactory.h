#pragma once

#include <iostream>
using namespace std;
class Mouse
{
public:
	virtual void sayHi() = 0;
};

class Keyboard
{
public:
	virtual void sayHi() = 0;
};

class DellMouse :public Mouse
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

class HpKeyborad :public Keyboard
{
	virtual void sayHi()
	{
		cout << "Hi , this is a HpKeyboard" << endl;
	}
};

class DellKeyborad :public Keyboard
{
	virtual void sayHi()
	{
		cout << "Hi , this is a DellKeyboard" << endl;
	}
};
/*Below is Factory*/

class PCFactory
{
public:
	virtual Mouse* createMouse() = 0;
	virtual Keyboard* createKeyboard() = 0;
};

class HpFactory :public PCFactory
{
	virtual Mouse* createMouse()
	{
		return (new HpMouse());
	}
	virtual Keyboard* createKeyboard()
	{
		return (new HpKeyborad());
	}
};

class DellFactory :public PCFactory
{
public:
	virtual Mouse* createMouse()
	{
		return (new DellMouse());
	}
	virtual Keyboard* createKeyboard()
	{
		return (new DellKeyborad());
	}
};
