#include "SSNSet.h"

int main()
{
	SSNSet a;
	a.add(1);
	a.add(2);
	cerr << "ssnset length is: " << a.size() << endl;
	a.print();



}