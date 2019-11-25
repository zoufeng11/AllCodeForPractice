#include "Proxy.h"
#include <iostream>

using namespace std;

int  main()
{
	Image* Image = new ProxyImage("ImageProxy");

	Image->display();
	Image->display();
	return 1;
}
