#include "Factory.h"

int Factorymain()
{
	MouseFactory* mf_Dell = new DellMouseFactory();
	Mouse *m_Dell = mf_Dell->createMouse();
	m_Dell->sayHi();

	MouseFactory* mf_Hp = new HpMouseFactory();
	Mouse* m_Hp = mf_Hp->createMouse();
	m_Hp->sayHi();
	system("pause");
	return 0;
}
