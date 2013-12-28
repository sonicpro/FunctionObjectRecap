#include "vectorPrinter.h"
#include "oddityPrinter.h"
#include <algorithm>

using std::for_each;

void vectorPrinter::print(vector<int> vecInt)
{
	for_each(vecInt.begin(), vecInt.end(), oddityPrinter());
}
