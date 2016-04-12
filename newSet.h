#ifndef NEWSET_H
#define NEWSET_H

#include <string>
#include <cstring>
#include <iostream>
using namespace std;
typedef unsigned long ItemType;

const int DEFAULT_MAX_ITEMS = 100;

class Set
{
public:

	Set(int setSize);  //default constructor

	Set();  //default constructor

	Set(const Set& other); //copy constructor.  Used to perform a deep copy of dynamically allocated information.

	~Set(); //destructor for set.  Free up set resources to prevent memory leak.

	Set& operator=(const Set& rhs);  //Set up assignment 

	bool empty() const;  // Return true if the set is empty, otherwise false.

	int size() const;    // Return the number of items in the set.

	bool insert(const ItemType& value);
	// Insert value into the set if it is not already present.  Return
	// true if the value was actually inserted.  Leave the set unchanged
	// and return false if the value was not inserted (perhaps because it
	// is already in the set or because the set has a fixed capacity and
	// is full).

	bool erase(const ItemType& value);
	// Remove the value from the set if present.  Return true if the
	// value was removed; otherwise, leave the set unchanged and
	// return false.

	bool contains(const ItemType& value) const; //Doesn't modify member vars.
												// Return true if the value is in the set, otherwise false.

	bool get(int i, ItemType& value) const;
	// If 0 <= i < size(), copy into value an item in the set and
	// return true.  Otherwise, leave value unchanged and return false.
	// (See below for details about this function.)

	void swap(Set& other);
	// Exchange the contents of this set with the other one.

	void dump() const;

private:

	ItemType* m_set;  //create a pointer to an ItemType.  This will hold array.
					  //http://www.cplusplus.com/doc/tutorial/dynamic/
	int m_arrayPosition;
	int m_maxSize;
};

#endif