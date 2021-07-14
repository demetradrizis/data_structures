/* Demetra Drizis 
   Project 3
   10/29/19 */

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>

namespace cop4530
{
    template <typename T>
    class Stack
   {
    public:
    	explicit Stack(int initSize = 0);	     // zero-argument constructor
	~Stack();				     // destructor
    	Stack(const Stack<T> &);                     // copy constructor
   	Stack(Stack<T> &&);                         // move constructor
    	Stack<T> & operator=(const Stack<T> &);    // copy assignment operator=
    	Stack<T> & operator=(Stack<T> &&);           // move assignment operator=
    	bool empty() const;                         // returns true if empty, else false
    	void clear();                               // delete all elements from stack
    	int size() const;                           // returns number of elements stored in stack  
    	void push(const T & x);                     // adds x to stack (copy version)
    	void push(T && x);                          // adds x to stack (move version)
    	void pop();                                 // remove and disgard most recently added element
    	T & top();                                  // returns reference to most recently added element
    	const T & top() const;                      // accessor that returns most recently added element 
    	void print(std :: ostream & os, char ofc = ' ') const;  // print stack elements to os, ofc is the seperator between elements
	
     protected:
	std :: vector<T> val;
   };

  	template<typename T>    // invokes the print() method to print the Stack<T>
  	std :: ostream& operator<< (std :: ostream& os, const Stack<T> & a);

  	template<typename T> // returns true if comapred Stack have same elements, else false
  	bool operator== (const Stack<T> &, const Stack <T> &);

  	template<typename T> // opposite of operator ==()
  	bool operator!= (const Stack<T> &, const Stack <T> &);

  	template<typename T> // returns true if every element is smaller than or equal to corresponding element, else false 
  	bool operator<= (const Stack<T> & a, const Stack <T> & b);

  #include "stack.hpp"
}

#endif
