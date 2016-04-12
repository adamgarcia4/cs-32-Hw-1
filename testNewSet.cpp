#include "newSet.h"

int main()
{
	Set a(2);
	a.insert(1);
	a.insert(2);
	cerr << "ssnset length is: " << a.size() << endl;
	a.dump();



}