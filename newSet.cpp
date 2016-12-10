#include "newSet.h"

Set::Set(int setSize)
{
	m_arrayPosition = 0;
	m_maxSize = setSize;
	m_set = new ItemType[setSize];
}

Set::Set()
{
	m_arrayPosition = 0;
	m_maxSize = DEFAULT_MAX_ITEMS;
	m_set = new ItemType[m_maxSize];
}

Set::Set(const Set & other) :m_arrayPosition(other.m_arrayPosition), m_maxSize(other.m_maxSize)
{
	m_set = new ItemType[m_maxSize];
	memcpy(m_set, other.m_set, m_maxSize);
}

Set::~Set()
{
	delete[] m_set;
}

Set & Set::operator=(const Set & rhs)
{
	if (this != &rhs)
	{
		Set temp(rhs);
		swap(temp);
	}
	return *this;
}

// Return true if the Set is empty, otherwise false.
bool Set::empty() const
{
	if (m_arrayPosition == 0)
		return true;
	else
		return false;
}

// Return the number of items in the Set.
int Set::size() const
{
	return m_arrayPosition;
}

// Insert value into the Set if it is not already present.  Return
// true if the value was actually inserted.  Leave the Set unchanged
// and return false if the value was not inserted (perhaps because it
// is already in the Set or because the Set has a fixed capacity and
// is full).
bool Set::insert(const ItemType & value)
{

	if (m_arrayPosition >= m_maxSize) //Already Full
		return false;
	for (int i = 0; i < m_arrayPosition; i++) //check to see if value is already in Set
	{
		if (m_set[i] == value)
			return false;
	}
	m_set[m_arrayPosition] = value;
	m_arrayPosition += 1;
	return true;
}

// Remove the value from the Set if present.  Return true if the
// value was removed; otherwise, leave the Set unchanged and
// return false.
bool Set::erase(const ItemType & value)
{
	for (int i = 0; i < m_arrayPosition; i++) //Check if value in Set.  If so, shift everything else forward.
	{
		if (m_set[i] == value)//value in Set.  Forward shift all by 1.
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

// Return true if the value is in the Set, otherwise false.
bool Set::contains(const ItemType & value) const
{
	for (int i = 0; i < m_arrayPosition; i++)
	{
		if (m_set[i] == value)
			return true;
	}
	return false;
}

// If 0 <= i < size(), copy into value an item in the Set and
// return true.  Otherwise, leave value unchanged and return false.
// (See below for details about this function.)
bool Set::get(int i, ItemType & value) const
{
	if (i < 0 || i > size())
		return false;
	else
	{
		value = m_set[i];
		return true;
	}
}

// Exchange the contents of this Set with the other one.
void Set::swap(Set & other)
{
	//swap m_arrayPosition
	int tempArrPos = m_arrayPosition;
	m_arrayPosition = other.m_arrayPosition;
	other.m_arrayPosition = tempArrPos;

	//swap m_maxSize
	int tempMaxSize = m_maxSize;
	m_maxSize = other.m_maxSize;
	other.m_maxSize = tempMaxSize;

	//swap m_set
	ItemType* tempSet = new ItemType[m_maxSize];
	tempSet = m_set;
	m_set = other.m_set;
	other.m_set = tempSet;
}

void Set::dump() const
{
	for (int i = 0; i < m_arrayPosition; i++)
	{
		cerr << "array pos: " << i << endl;
		cerr << "Set element is: " << m_set[i] << endl;
	}


}