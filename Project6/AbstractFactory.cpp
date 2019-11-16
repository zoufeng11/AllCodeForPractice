#include "AbstractFactory.h"

int AbstractFactorymain()
{
	PCFactory* Dell = new DellFactory();
	Mouse* m_Dell = Dell->createMouse();
	Keyboard* k_Dell = Dell->createKeyboard();
	m_Dell->sayHi();
	k_Dell->sayHi();

	PCFactory* Hp = new HpFactory();
	Mouse* m_Hp = Hp->createMouse();
	Keyboard* k_Hp = Hp->createKeyboard();
	m_Hp->sayHi();
	k_Hp->sayHi();
	system("pause");
	return 0;
}

