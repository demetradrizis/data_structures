/* Demetra Drizis 
   Project 3
   10/29/19 */

using namespace std;

template<typename T>    
Stack<T> :: Stack(int initSize)
{
		// 0 argument constructor
}

template<typename T>
Stack<T> :: ~Stack()
{
  	clear();		// destructor
}

template<typename T>
Stack<T> :: Stack(const Stack<T> & s) 
{
  	val = s.val;  		// copy constructor
}

template<typename T>
Stack<T> :: Stack(Stack<T> && s)
{
  	val = move(s.val);	// move constructor
}

template<typename T>
Stack<T> & Stack<T> :: operator=(const Stack <T> & s)
{
  	if(*this != s)
  	{
           val = s.val;		// copy assignment operator
  	}

  	return *this;
}

template<typename T>
Stack<T> & Stack<T> :: operator=(Stack<T> && s)
{
  	val = move(s.val);	// move assignment operator
  
	return *this;
}

template<typename T>
bool Stack<T> :: empty() const
{
  	return val.size() == 0;		// returns true if empty, else false
}

template<typename T>
void Stack<T> :: clear()
{
  	val.clear();			// delete all elements from stack
}

template<typename T>
int Stack<T> :: size() const
{
  	return val.size();		// returns number of elements stored in stack
}

template<typename T>
void Stack<T> :: push(const T & x)
{
  	val.push_back(x);		// adds x to stack (copy version)
}

template<typename T>
void Stack<T> :: push(T && x)
{
  	val.push_back(move(x));		// adds x to stack (move version)
}

template<typename T>
void Stack<T> :: pop()
{
  	if(val.size() != 0)
  	{
	    val.pop_back();	// remove and disgard most recently added element
  	}
}

template<typename T>
T & Stack<T> :: top()
{
    	return val.back();		// returns reference to most recently added element
}

template<typename T>
const T & Stack<T> :: top() const
{
  	return val.back();		// accessor that returns most recently added element
}


template<typename T>
void Stack<T> :: print(std :: ostream & os, char ofc) const
{
  	for(int i = 0; i < val.size(); i++)
  	{					// print stack elements to os,	
 	   os << val[i] << ofc;			// ofc is the seperator between elements
  	}
}

template<typename T>
std :: ostream& operator<< (std :: ostream & os, const Stack<T> & x)
{
  	x.print(os);		// invokes the print() method to print the Stack<T>
  	return os;
}

template<typename T>
bool operator== (const Stack<T> & x, const Stack <T> & y)
{
  	bool flag = true;

  	if(y.size() != x.size())
	{    
	    return false;
	}
  	else
 	{			// returns true if comapred Stack have same elements, else false
    	   bool flag = true;
    	   Stack<T> x_i;
    	   Stack<T> y_i;
   	   x_i = x;
    	   y_i = y;
    	  while(flag && !(y_i.empty()))
    	  {
      		if(x_i.top() != y_i.top())
     		{
        	  bool flag = false;
        	  break;
      		}
      	  x_i.pop();
      	  y_i.pop();
   	 }
  	  return flag;
  	}
}

template<typename T>
bool operator!= (const Stack<T> & x, const Stack<T> & y)
{
  	return !(x == y);		// opposite of operator ==()
}

template<typename T>
bool operator<= (const Stack<T> & x, const Stack <T> & y)
{
  	bool flag = true;

	if(y.size() < x.size())
  	{
    	    return false;
	}
  	else			// returns true if every element is smaller than or equal
  	{			// to corresponding element, else false			
    	   bool flag = true;
    	   Stack<T> x_i;
    	   Stack<T> y_i;
    	   x_i = x;
    	   y_i = y;

    	 while(flag && !(y_i.empty()))
    	 {
      	    	if(x_i.top() <= y_i.top())
      		{

      		}
      		else
      		{
        		flag = false;
        		break;
      		}
 	   x_i.pop();
      	   y_i.pop();
    	 }
  	   return flag;
  	}
}
