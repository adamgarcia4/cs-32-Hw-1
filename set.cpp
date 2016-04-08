#include "set.h"

Set::Set() : m_arrayPosition(0)
{

}

Set::~Set()
{
}

// Return true if the set is empty, otherwise false.
bool Set::empty() const
{
	if (m_arrayPosition == 0)
		return true;
	else
		return false;
}

// Return the number of items in the set.
int Set::size() const
{
	return m_arrayPosition;
}

// Insert value into the set if it is not already present.  Return
// true if the value was actually inserted.  Leave the set unchanged
// and return false if the value was not inserted (perhaps because it
// is already in the set or because the set has a fixed capacity and
// is full).
bool Set::insert(const ItemType & value)
{

	if (m_arrayPosition >= 100) //Already Full
		return false;
	for (int i = 0; i < m_arrayPosition; i++) //check to see if value is already in set
	{
		if (m_set[i] == value)
			return false;
	}
	m_set[m_arrayPosition] = value;
	m_arrayPosition += 1;
	return true;
}

// Remove the value from the set if present.  Return true if the
// value was removed; otherwise, leave the set unchanged and
// return false.
bool Set::erase(const ItemType & value)
{
	for (int i = 0; i < m_arrayPosition; i++) //Check if value in set.  If so, shift everything else forward.
	{
		if (m_set[i] == value)//value in set.  Forward shift all by 1.
		{
			for (int j = i; j < m_arrayPosition; j++)
			{
				m_set[j] = m_set[j + 1];
			}
			m_arrayPosition -= 1;
			return false;
		}
	}

	return false;
}

// Return true if the value is in the set, otherwise false.
bool Set::contains(const ItemType & value) const
{
	for (int i = 0; i < m_arrayPosition; i++)
	{
		if (m_set[i] == value)
			return true;
	}
	return false;
}

// If 0 <= i < size(), copy into value an item in the set and
// return true.  Otherwise, leave value unchanged and return false.
// (See below for details about this function.)
bool Set::get(int i, ItemType & value)
{
	if (i < 0 || i > size())
		return false;
	else
	{
		value = m_set[i];
		return true;
	}
}

// Exchange the contents of this set with the other one.
void Set::swap(Set & other)
{
	//Set temp;
	//temp = other;
	//int firstSize = this->size();
	//int secondSize = other.size();
	
	//for (int i = 0; i < secondSize; i++) //Iterate and erase all members of other's set.
	//{
	//	ItemType tempValue;
	//	other.get(i, tempValue);
	//	other.erase(tempValue);
	//	other.insert(m_set[i]);
	//}

	//for (int i = 0; i < firstSize; i++) //Iterate and erase all members of other's set.
	//{
	//	ItemType tempValue;
	//	other.get(i, tempValue);
	//	other.erase(tempValue);
	//	other.insert(m_set[i]);
	//}
	
	Set* temp = &other; //temporary pointer holds the address of other, which is b.
	other = *this; //other gets assigned the dereference of this a.  Other should hold 'a'.
	*this = *temp;




}

void Set::dump() const
{
	for (int i = 0; i < m_arrayPosition; i++)
	{
		cerr << "array pos: " << i << endl;
		cerr << "set element is: " << m_set[i]<< endl;
	}



	system("pause");
}