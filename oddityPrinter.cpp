#include "oddityPrinter.h"
#include <iostream>

using std::cout;
using std::endl;

 void oddityPrinter::operator()(int a) const
{
	cout << (a % 2 == 0 ? "even" : "odd") << endl;
}
