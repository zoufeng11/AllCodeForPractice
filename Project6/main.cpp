#include <iostream>
//#include "test2.h"
//#include "Singleton.h"
using namespace std;
class Singleton
{

private:
	Singleton()
	{
		cout << "construct Singleton" << endl;
	}
	Singleton(const Singleton& other);
public:
	static Singleton* m_Instance;
	static Singleton* getInstance();

};

Singleton* Singleton::m_Instance = NULL;

Singleton* Singleton::getInstance() {
	if (m_Instance == NULL) {
		m_Instance = new Singleton();
	}
	return m_Instance;
}
int mainSingleton()
{
	Singleton *objInstance = Singleton::getInstance();
	Singleton* objInstance1 = Singleton::getInstance();
	Singleton* objInstance2 = Singleton::getInstance();
	Singleton* objInstance3 = Singleton::getInstance();
	//B::funA();
	return 0;
}