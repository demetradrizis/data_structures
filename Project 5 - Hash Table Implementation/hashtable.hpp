/* Demetra Drizis 
   Project 5
   11/27/19
*/

using namespace cop4530;

// returns largest prime number <= n or zero if input is too large
// This is likely to be more efficient than prime_above(), because
// it only needs a vector of size n
template <typename K, typename V>
unsigned long HashTable<K, V>::prime_below (unsigned long n)
{
   if (n > max_prime)
   {
      std::cerr << "** input too large for prime_below()\n";
      return 0;
   }
   if (n == max_prime)
   {
      return max_prime;
   }
   if (n <= 1)
   {
      std::cerr << "** input too small \n";
      return 0;
   }

   // now: 2 <= n < max_prime
   std::vector <unsigned long> v (n+1);
   setPrimes(v);
   while (n > 2)
   {
      if (v[n] == 1)
         return n;
      --n;
   }

   return 2;
}

//Sets all prime number indexes to 1. Called by method prime_below(n) 
template <typename K, typename V>
void HashTable<K, V>::setPrimes(std::vector<unsigned long>& vprimes)
{
   int i = 0;
   int j = 0;

   vprimes[0] = 0;
   vprimes[1] = 0;
   int n = vprimes.capacity();

   for (i = 2; i < n; ++i)
      vprimes[i] = 1;

   for( i = 2; i*i < n; ++i)
   {
      if (vprimes[i] == 1)
         for(j = i + i ; j < n; j += i)
            vprimes[j] = 0;
   }
}

template <typename K, typename V>
size_t HashTable<K,V>::size() const
{
   return currentSize;
}

template <typename K, typename V>
HashTable <K, V> :: HashTable (size_t size)	// constructor
{
	currentSize = 0; 
	h_table.resize(prime_below(size));
}

template <typename K, typename V>
HashTable <K, V> :: ~HashTable()		// destructor
{
	clear();
}

template <typename K, typename V>
bool HashTable <K, V> :: contains(const K & x)		// check if K is in table
{
	for (auto itr = h_table[myhash(x)].begin(); itr != h_table[myhash(x)].end(); itr++)
	{
		if (itr->first == x)
		{
			return true;
		}
	}
		return false; 
}

template <typename K, typename V>
bool HashTable <K, V> :: match(const std :: pair <K, V> & kv) const	//check if pair is a match in the hash table
{
	auto & whichList = h_table[myhash(kv.first)];
	return find(whichList.begin(), whichList.end(), kv) != whichList.end();
}

template <typename K, typename V>
bool HashTable <K, V> :: insert(const std :: pair <K,V> & kv)		// add pair into hash table
{									//don't add if already in the table
	auto & whichList = h_table [myhash(kv.first)];
	
	for(auto & thisList : whichList)
	{
		if(thisList.first == kv.first)
                { 
			return false;
		}
	}
	
	if (contains(kv.first) == false)
	{
		whichList.push_back(kv);
	}
	else
	{
		for (auto itr = h_table[myhash(kv.first)].begin(); itr != h_table[myhash(kv.first)].end(); itr++)
        	{
                	if ((*itr).first == kv.first)
                	{
				(*itr).second = kv.second;
                		break;
			}
        	}
	}
	
	if (++currentSize > h_table.size())
	{
		rehash();
	}

	return true; 
}

template <typename K, typename V>
bool HashTable <K,V> :: insert(std :: pair <K,V> && kv)		//move version of the insert function
{
	const std :: pair <K,V> kvpair = std :: move (kv);
	return insert (kvpair); 
}

template <typename K, typename V>
bool HashTable <K, V> :: remove(const K & k)		//deletes pair
{
	auto & whichList = h_table[myhash(k)];
	for (auto itr = whichList.begin(); itr != whichList.end(); itr++)
	{
		if (itr == end (whichList))
		{
			return false; 
		}
		if (itr -> first == k)
		{
			whichList.erase(itr); 
			--currentSize;
			return true; 
		} 
	}
}

template <typename K, typename V>
void HashTable <K, V> :: clear()		//deletes all elements
{
	makeEmpty(); 
}

template <typename K, typename V>
bool HashTable <K,V> :: load(const char * filename)
{
	ifstream in;
	K hash_key;			//load from file
	V hash_value;

	char salt [] = "$1$########";

	in.clear(); 
	in.open(filename);
	
	if (!in)
	{
		return false;
	}
	else
	{
		while(!in.eof())
		{
			
			in >> hash_key >> hash_value;
		        string encrypted = crypt(hash_value.c_str(), salt);
			insert(make_pair(hash_key, encrypted.substr(12)));
		};
		
		in.close();
		return true; 
	}

	
}

template <typename K, typename V>
void HashTable <K,V> :: dump()			//display all hash table entries
{			
	for (int i = 0; i < h_table.size(); i++)
	{
		for (auto itr = h_table[i].begin(); itr != h_table[i].end(); ++itr)
		{
			if (itr != h_table[i].begin())
			{
				cout << " | ";
			}

			if (itr -> second != "")
			{
				cout << itr->first << " " << itr->second;
			}
			
			if(itr == --h_table[i].end())
	    		{	
				cout << endl;
			}
		}
	}
}

template <typename K, typename V>
bool HashTable <K,V> :: write_to_file(const char * filename)
{							//transfer table to a file
	ofstream out; 
	out.open(filename); 

	if (!out)
	{
		return false; 
	}

	for (int i = 0; i < h_table.size(); i++)
	{
		for (auto itr = h_table[i].begin(); itr != h_table[i].end(); itr++)
		{
			out << itr -> first << " " << itr -> second << endl; 
		}
	}
	out.close();
	return true;
}

template <typename K, typename V>
void HashTable <K,V> :: makeEmpty()		//delete all elements
{
	for (auto & thisList : h_table)
	{
		h_table.clear();
	}
	currentSize = 0; 
}

template <typename K, typename V>
void HashTable <K,V> :: rehash()
{					//resizing the vector
	auto oldLists = h_table; 

	h_table.resize(prime_below(2 * h_table.size()));
	
	for (auto & thisList : h_table)
	{
		h_table.clear();
	}

	currentSize = 0; 

	for (auto & thisLists : oldLists)
	{
		for (auto & x : thisLists)
		{
			insert (move(x)); 
		}
	}
}

template <typename K, typename V>
size_t HashTable <K,V> :: myhash(const K & x) const
{						//return index of where element k is stored
	static hash <K> hash_func;
	return hash_func(x) % h_table.size(); 
}


