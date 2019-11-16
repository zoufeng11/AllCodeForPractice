#include "Prototype.h"
#include <iostream>

using namespace std;
int Prototypemain()
{

	Resume* pp = new ResumeA("pp");
	pp->SetSex_Age("male", 16);
	pp->Set_Workexper("action", "1998-2010");

	Resume* qq = (ResumeB*)pp->clone();
	qq->SetSex_Age("female", 16);
	qq->Set_Workexper("hah", "2001-2019");

	Resume* ss = qq->clone();

	pp->Display();
	qq->Display();
	delete pp;
	delete qq;

	ss->Display();
	delete ss;


	return 0;
}


