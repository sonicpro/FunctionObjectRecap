#include "oddityPrinter.h"
#include "parseNumericalInput.h"
#include "vectorPrinter.h"
#include <iostream>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::getchar;

int main()
{
	vector<int> vec = vector<int>();
	cout << "Enter three numbers one by one pressing Enter key after each of them" << endl;
	// If input stream is in a bad state, clear it first
	if(!cin)
		cin.clear();
	// If a last entered country name was incorrect, 
	// we must skip the rest of the data entered.
	if(cin.rdbuf()->in_avail() > 0)
		cin.ignore(cin.rdbuf()->in_avail());
	for(int i = 0; i != 3; ++i)
	{
		parseNumericalInput aNumber;
		bool inputResult = false;
		while(!inputResult)
		{
			// Read numvers one at a time, although it is possible to read them at once specifying their number in the second parseNonNegativeNumbers argument.
			try
			{
				const istream& tempIn = aNumber.parseNonNegativeNumbers(cin, 1);
				inputResult = !(tempIn.fail() || tempIn.eof());
			}
			catch(domain_error e)
			{
				cout << e.what() << endl;
				continue;
			}
		}
		vec.push_back(aNumber.getValues()[0]);
	}

	vectorPrinter vp = vectorPrinter();
	vp.print(vec);
	cout << "Press Enter key to exit";
	getchar();
}