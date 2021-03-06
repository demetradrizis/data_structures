/* 
   Demetra Drizis 
   Project 1
   09/24/19
*/

using namespace std; 

template <typename T>
NSequence<T> :: NSequence(int initSize)
{
	if (initSize <= 0)
          initSize = 1;
	
	numOfItems = initSize;
	totalCapacity = initSize + 5;
	items = new T [totalCapacity];       
}

template <typename T>
NSequence<T> :: NSequence(const NSequence & rhs) : numOfItems {rhs.numOfItems},
	totalCapacity{rhs.totalCapacity}, items{nullptr}
{
      items = new T[totalCapacity];
      for (int i = 0; i < numOfItems; i++)
	 items[i] = rhs.items[i];
}

template <typename T>
NSequence<T> & NSequence<T> :: operator= (const NSequence & rhs)
{
   NSequence copy = rhs;
   std::swap (*this, copy); 
   return *this;   
}

template <typename T>
NSequence<T> :: ~NSequence()
{
   delete [] items; 
} 

template <typename T>
NSequence<T> :: NSequence(NSequence && rhs) : numOfItems {rhs.numOfItems}, 
     totalCapacity{rhs.totalCapacity}, items{rhs.items}
{
   rhs.items = nullptr; 
   rhs.numOfItems = 0; 
   rhs.totalCapacity = 0; 
}

template <typename T>
NSequence<T> & NSequence<T> :: operator= (NSequence && rhs)
{
    std::swap(numOfItems, rhs.numOfItems);
    std::swap(totalCapacity, rhs.totalCapacity);
    std::swap(items, rhs.items); 

    return *this; 
}

template <typename T>
bool NSequence<T> :: isEmpty() const
{
    return getSize() == 0; 
}

template <typename T>
int NSequence<T> :: getSize() const
{
   return numOfItems;
}

template <typename T>
int NSequence<T> :: getCapacity() const
{
   return totalCapacity;
}

template <typename T>
T & NSequence<T> :: operator[] (int index)
{
   return items[index]; 
}

template <typename T>
const T & NSequence<T> :: operator[] (int index) const
{
   return items[index];
} 

template <typename T>
T & NSequence<T> :: getFirst() const
{
     return items[0];  
}

template <typename T>
T & NSequence<T> :: getLast() const
{
    return items[getSize() - 1]; 
}

template <typename T>
void NSequence<T> :: insert (const int pos, const T & d)
{
   if (numOfItems == totalCapacity)
       growCapacity(2 * totalCapacity);

   for (int i = numOfItems; i > pos; i--)
      items[i] = items[i-1];

      items[pos] = d;   
      numOfItems++;		
}

template <typename T>
void NSequence<T> :: insert (const int pos, T && d)
{
     if (numOfItems == totalCapacity)
       growCapacity(2 * totalCapacity);

     for (int i = numOfItems; i > pos; i--)
      items[i] = items[i-1];

      items[pos] = std::move(d);
      numOfItems++;
}

template <typename T>
void NSequence<T> :: remove (const int pos)
{
      for (int i = pos; i < numOfItems - 1; i++)
         items[i] = items[i+1]; 

	numOfItems--;
}

template <typename T>
void NSequence<T> :: push_back (const T & x)
{ 
    if (numOfItems == totalCapacity) 
	growCapacity(2 * totalCapacity + 1);
    items[numOfItems++] = x;
}

template <typename T>
void NSequence<T> :: push_back(T && x)
{
    if (numOfItems == totalCapacity)
	growCapacity(2 * totalCapacity + 1);
    items[numOfItems++] = std::move(x);
}

template <typename T>
void NSequence<T> :: pop_back()
{
   --numOfItems; 
}

template <typename T>
void NSequence<T> :: growCapacity (int newCapacity) 
{
    if (newCapacity <= numOfItems) 
	newCapacity = totalCapacity * 2;
 
    T *newArray = new T[newCapacity];

    for (int i = 0; i < numOfItems; i++)
        newArray[i] = std :: move(items[i]); 

    totalCapacity = newCapacity; 
    std :: swap(items, newArray); 
    delete [] newArray;
}

template <typename T>
void NSequence<T> :: printout (int begin, int end)
{
   if (begin == end)
     return; 
   
  int temp = begin + 50; 
  int i = begin; 

  while (i <= end && i <= temp)
  {
     cout << " [" << i << "]" << "=" << items[i];
     i++;
  } 
     cout << endl;
}

