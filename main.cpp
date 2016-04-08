#include "set.h"
#include "SSNSet.h"
#include <string>
#include <assert.h>

void adamTest();
void adamTestSet();
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();

int main()
{
	//s.add(2);
	//s.add(3);
	//s.add(1);
	//s.add(2);
	//s.add(3);
	//s.print();
	//adamTestSet();
	test4();
	system("pause");
}



//void adamTest()
//{
//	Set s;
//	s.insert("one");
//	s.insert("two");
//	s.insert("three");
//	s.dump();
//	cout << endl << endl;
//	s.erase("two");
//	s.dump();
//
//}
//
//void adamTestSet()
//{
//	Set a, b;
//	a.insert("a1");
//	b.insert("b1");
//	a.swap(b);
//	cerr << "A set is: " << endl;
//	a.dump();
//	cerr << endl << "B set is: " << endl;
//	b.dump();
//
//}

////passed insertion
//void test1()
//{
//	
//	Set ss;
//	ss.insert("A");
//	ss.insert("C");
//	ss.insert("A");
//	ss.insert("B");
//	string all;
//	for (int k = 0; k < ss.size(); k++)
//	{
//		string x;
//		ss.get(k, x);
//		all += x;
//	}
//	cerr << "all is: "<<all << endl;
//	ss.dump();
//}
//
////Passed insert and get functions
//void test2()
//{
//	Set ss;
//	ss.insert("pita");
//	ss.insert("roti");
//	string s1;
//	assert(ss.get(1, s1) && (s1 == "roti" || s1 == "pita"));
//	string s2;
//	assert(ss.get(1, s2) && s2 == s1);
//}
//
////Passed contains function
//void test3()
//{
//	Set ss;
//	ss.insert("focaccia");
//	assert(!ss.contains(""));
//	ss.insert("tortilla");
//	ss.insert("");
//	ss.insert("lavash");
//	assert(ss.contains(""));
//	ss.erase("focaccia");
//	assert(ss.size() == 3 && ss.contains("lavash") && ss.contains("tortilla") &&
//		ss.contains(""));
//}
//
//failed swap function.
void test4()
{
	Set ss1;
	ss1.insert(1);
	Set ss2;
	ss2.insert(2);
	ss2.insert(3);
	ss1.swap(ss2);
	assert(ss1.size() == 2 && ss1.contains(2) && ss1.contains(3) &&
		ss2.size() == 1 && ss2.contains(1));
}
//
////passed
//void test5()
//{
//	Set s;
//	assert(s.empty());
//	ItemType x = "arepa";
//	assert(!s.get(42, x) && x == "arepa"); // x unchanged by get failure
//	s.insert("chapati");
//	assert(s.size() == 1);
//	assert(s.get(0, x) && x == "chapati");
//	cout << "Passed all tests" << endl;
//}
//
////passed switching ItemType typedef
//void test6()
//{
//	//Set s;
//	//assert(s.empty());
//	//ItemType x = 9876543;
//	//assert(!s.get(42, x) && x == 9876543); // x unchanged by get failure
//	//s.insert(123456789);
//	//assert(s.size() == 1);
//	//assert(s.get(0, x) && x == 123456789);
//	//cout << "Passed all tests" << endl;
//}

