#include "Decrator.h"

int Decortormain()
{
	phone* Nokiaphone = new NokiaPhone("5300");
	phone* dpa = new DecoratorPhoneA(Nokiaphone);
	phone* dpb = new DecoratorPhoneB(dpa);
	dpb->ShowDecorate();
	delete dpa;
	delete dpb;
	delete Nokiaphone;
	return 0;
}