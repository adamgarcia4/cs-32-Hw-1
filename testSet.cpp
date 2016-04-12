#include "Set.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
	Set uls;
	assert(uls.insert(10));
	assert(uls.insert(20));
	assert(uls.size() == 2);
	assert(uls.contains(20));
	ItemType x = 30;
	assert(uls.get(0, x) && (x == 10 || x == 20));
	ItemType x2 = 40;
	assert(uls.get(1, x) && (x == 10 || x == 20) &&
		x != x2);
}

int main()
{
	test();
	cout << "Passed all tests" << endl;
}