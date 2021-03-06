/* Demetra Drizis
   Project 2
   10/09/19
*/


using namespace std; 

template<typename T>   
List<T> :: const_iterator :: const_iterator() : current{nullptr}
{
					// public constructor for const_iterator
}

template<typename T>   
const T & List<T> :: const_iterator :: operator*() const
{
	return retrieve();			//returns object stored at current position
}

template<typename T>
typename List<T> :: const_iterator & List<T> :: const_iterator :: operator++()
{
	current = current->next;
  	return *this;
}

template<typename T>
typename List<T> :: const_iterator List<T> :: const_iterator :: operator++(int)
{
  	auto old = *this;
 	++(*this);
  	return old;
}

template<typename T>
typename List<T> :: const_iterator & List<T> :: const_iterator :: operator--()
{
  	current = current->prev;
  	return *this;
}

template<typename T>
typename List<T> :: const_iterator List<T> :: const_iterator :: operator--(int)
{
  	auto old = *this;
  	--(*this);
  	return *this;
}

template<typename T>
bool List<T> :: const_iterator :: operator==(const typename List<T> :: const_iterator & rhs) const
{
  	return current == rhs.current;
}

template<typename T>
bool List<T> :: const_iterator :: operator!=(const typename List<T> :: const_iterator & rhs) const
{
  	return current != rhs.current;
}

template<typename T>
T & List<T> :: const_iterator :: retrieve() const
{
	return current->data;			//returns object at current position
}


template<typename T>   
List<T> :: const_iterator :: const_iterator(typename List<T> :: Node * p) : current{p}
{
						//protected constructor
}

template<typename T>    
List<T> :: iterator :: iterator()
{
					//no parameter iterator constructor 
}


template<typename T>
T & List<T> :: iterator :: operator*()
{
  	return this->current->data;		//returns object at current position
}

template<typename T>
const T & List<T> :: iterator :: operator*() const  
{
  	return this->retrieve();
}

template<typename T>
typename List<T> :: iterator & List<T> :: iterator :: operator++()
{
  	this->current = this->current->next;
  	return *this;
}

template<typename T>
typename List<T> :: iterator List<T> :: iterator :: operator++(int)
{
  	iterator old = *this;
  	++(*this);
  	return old;
}

template<typename T>
typename List<T> :: iterator & List<T> :: iterator :: operator--()
{
  	this->current = this->current->prev;
  	return *this;
}

template<typename T>
typename List<T> :: iterator List<T> :: iterator :: operator--(int)
{
  	auto old = *this;
  	--(*this);
  	return *this;
}

template<typename T> 
List<T> :: iterator :: iterator(typename List<T> :: Node * p) : List<T> :: const_iterator{p}
{
						//protected iterator constructor
}

template<typename T>    
List<T> :: List()
{
  	init();				//zero parameter constructor
}

template<typename T>    
List<T> :: List(const List<T> & rhs)
{
  	init(); 			//copy constructor
  	for(auto & x : rhs)
    	{
		push_back(x);
	}
}

template<typename T>   
List<T> :: List(List<T> && rhs) : theSize(rhs.theSize), head{rhs.head}, tail{rhs.tail}
{
  	rhs.theSize = 0;			//move constructor
  	rhs.head = nullptr;
  	rhs.tail = nullptr;
}

template<typename T>    
List<T> :: List(int num, const T & val)
{
  	init();					//int type constructor
  	for(int i = 0; i < num; i++)
    	{
		push_back(val);
	}
}

template<typename T>   
List<T> :: List(typename List<T> :: const_iterator start, typename List<T> :: const_iterator end)
{
  	init();						//constructs with elements start to end
  	for(auto itr = start; itr != end; ++itr)
    	{
		push_back(*itr);
	}
}

template <typename T>
List<T> :: List(std :: initializer_list<T> iList)
{
	init();

	for (auto i = iList.begin(); i != iList.end(); i++)
        {
                push_back(*i);
        }
}
template<typename T>    //destructor
List<T> :: ~List()
{
	clear();
	delete head;
	delete tail;
}

template<typename T>                            
List<T> & List<T> :: operator=(const List<T> & rhs)
{
  	auto copy = rhs;				//copy assignment
  	std::swap(*this, copy);
  	return *this;
}

template<typename T>
List<T> & List<T> :: operator=(List<T> && rhs)   
{
  	init();				//move assignment
  	*this = std::move(rhs);
  	return *this;
}

template <typename T>
List<T> & List <T> :: operator= (std::initializer_list<T> iList)
{
	clear(); 

        for (auto i = iList.begin(); i != iList.end(); i++)
        {
                push_back(*i);
        }
	return *this; 
}

template<typename T>
int List<T> :: size() const
{
 	 return theSize;		//returns number of elements
}

template<typename T>
bool List<T> :: empty() const
{
  	return size() == 0;		//checks if list is empty
}

template<typename T>
void List<T> :: clear()
{
    	while(!empty())
	{			//deletes all elements
	   pop_front( );
	}
}

template<typename T>    
T & List<T> :: front()
{
  	return *begin();		//reference to first element
}

template<typename T>   
const T & List<T> :: front() const
{
  	return *begin();		//non modifiable reference to first element
}

template<typename T>    
T & List<T> :: back()
{				//reference to last element
  	return *(--end());    
}

template<typename T>    
const T & List<T> :: back() const
{
  	return *(--end());		//non modifiable reference to last element
}

template<typename T>
void List<T> :: push_front(const T & val)
{
  	insert(begin(), val);			//insert at beginning
}

template<typename T>
void List<T> :: push_front(T && val)
{
  	insert(begin(), std::move(val));		//move version of insert
}

template<typename T>
void List<T> :: push_back(const T & val)
{
  	insert(end(), val);				//insert at end
}

template<typename T>
void List<T> :: push_back(T && val)
{
  	insert(end(), std::move(val));		//move version of insert at end
}

template<typename T>
void List<T> :: pop_front()
{
  	erase(begin());		//delete first element
}

template<typename T>
void List<T> :: pop_back()
{
  	erase(--end());		//delete last element
}

template<typename T>
void List<T> :: remove(const T & val)
{
	for(auto itr = begin(); itr != end(); itr++)
  	{
    		if(*itr == val)
      		{
			erase(itr);			//remove all elements with value val
		} 
 	}
}

template<typename T>
template<typename PREDICATE>
void List<T> :: remove_if(PREDICATE pred)
{
	for(auto itr = begin(); itr != end(); itr++)
	{
		if (pred(*itr))
		{
		   erase(itr);
		}
	}
}

template<typename T>
void List<T> :: print(std::ostream& os, char ofc) const
{
  	for(auto itr = begin(); itr != end(); itr++)
    	{
		os << *itr << ofc;			//print elements
	}
}

template<typename T>
typename List<T> :: iterator List<T> :: begin()
{
  	return {head->next};				//mutator version of begin
}

template<typename T>
typename List<T> :: const_iterator List<T> :: begin() const
{
  	return{head->next};				//accessor version of begin
}

template<typename T>
typename List<T> :: iterator List<T> :: end()
{
  	return tail;					//mutator version of end
}

template<typename T>
typename List<T> :: const_iterator List<T> :: end() const
{
  	return tail;					//accesor version of end
}

template<typename T>    
typename List<T> :: iterator List<T> :: insert(typename List<T> :: iterator itr, const T & val)
{
  	auto *p = itr.current;							//insert val ahead of iterator
  	theSize++;
  	return {p->prev = p->prev->next = new Node{val, p->prev, p}};
}

template<typename T>    
typename List<T> :: iterator List<T> :: insert(typename List<T> :: iterator itr, T && val)
{
  	auto *p = itr.current;
  	theSize++;									//move version of insert
 	return {p->prev = p->prev->next = new Node{std::move(val), p->prev, p}};
}

template<typename T>
typename List<T> :: iterator List<T> :: erase(typename List<T> :: iterator itr)
{
  	auto *p = itr.current;
  	typename List<T>::iterator retVal{p->next};
  	p->prev->next = p->next;
 	p->next->prev = p->prev;				//erase one element
  	delete p;
  	theSize--;
  	return retVal;
}

template<typename T>
typename List<T> :: iterator List<T> :: erase(typename List<T> :: iterator start, typename List<T> :: iterator end)
{
  	for(auto itr = start; itr != end;)
    	{
		itr = erase(itr);
	}  
							//erase from beginning to end
	return end;
}


template<typename T>
void List<T> :: reverse()
{
  	if(!empty())
  	{
    		auto itr = head;
    							//reverses order of elements
		while(itr != nullptr)
    		{
      			std::swap(itr->next, itr->prev);
      			itr = itr->prev;
    		}
  	}
  	
	std::swap(head,tail); 
}

template <typename T>
void List<T> :: deduplicate()
{
	for(auto itr = begin(); itr != end(); itr++)  
        {
	    	  T val = *itr;

		  for (auto j = itr; j != end(); j++)
               	  {
			 if(val == *j && j != itr)
                       	 {
			   erase(j);
			 }
                  }
        }
}

template<typename T>
void List<T> :: init()
{
  	theSize = 0;
  	head = new Node;
  	tail = new Node;
  	head->next = tail;
  	tail->prev = head;
}

template <typename T>   
bool operator==(const List<T> & lhs, const List<T> & rhs)
{
  	bool ans = true;
  	if(lhs.size() == rhs.size())		//compares 2 lists 
  	{
    		auto itrR = rhs.begin();
    		for(auto itrL = lhs.begin(); itrL != lhs.end(); itrL++)
    		{
      		     if(*itrL != *itrR) 		//return false if an element isnt equal
      		     {
        		ans = false;
        		break;
      			}
      		itrR++;
    		}
    		return ans;
  	}
  	else    		// Lists are assumed to be non-equal if their sizes are different
    	    return false;
}

template<typename T>    
bool operator!=(const List<T> & lhs, const List<T> &rhs)
{
  	return !(rhs == lhs);				//!= operator overload
}

template<typename T>    
std::ostream & operator<<(std :: ostream & os, const List<T> & l)
{
  	l.print(os);
  	return os;		//print list elements 
}

