/*
   Demetra Drizis
   Project 1
   09/24/19
*/

#include "Cell.h"

using namespace std; 

IntCell :: IntCell (int initialValue)
{
   this-> storedValue = initialValue; 
}

int IntCell :: size() const
{
   return this->storedValue; 
}

int IntCell :: read() const
{
    return this->storedValue;
}

void IntCell :: write (int x)
{
    this->storedValue = x;  
}

bool IntCell :: operator < (const IntCell & rhs) const
{
       if (this->storedValue < rhs.storedValue)
          return true;
       else 
          return false;
}

int IntCell :: operator - (const IntCell & rhs) const
{
	return this->storedValue - rhs.storedValue; 
} 
