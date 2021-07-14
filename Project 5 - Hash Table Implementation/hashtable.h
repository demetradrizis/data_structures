/* Demetra Drizis 
   Project 5
   11/27/19
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include <string>     // string.c_str(), string();
#include <algorithm>  // std::find
#include <functional> // std::hash
#include <iostream>   // std::cout, std::cerr
#include <fstream>    // ifstream and ofstream
#include <string.h>   // strcpy, strtok, 

using namespace std;

// max_prime is used by the helpful functions provided to you.
static const unsigned int max_prime = 1301081;
 
// SeparateChaining Hash table class
namespace cop4530 {
   template <typename K, typename V>
      class HashTable
      {
         public:
            explicit HashTable(size_t size = 101 ) ; 
	    size_t size() const;
	    //HashTable(size_tsize = 101);			// constructor
	    ~HashTable(); 					// destructor
	    bool contains(const K & x);				// check if key k is in the hash table 	
            bool match(const std::pair<K, V> & kv) const; 	// check if key-value pair is in the hash table.
	    bool insert(const std::pair<K, V> & kv); 		// add the key-value pair kv into the hash table. Don't add if kv is already in the hash table.
	    bool insert(std::pair<K, V> && kv); 		// move version of insert.
       	    bool remove(const K & k); 				// delete the key k and the corresponding value if it is in the hash table. 
	    void clear();					// delete all elements in the hash table
	    bool load(const char *filename);			// load the content of the file with name filename into the hash table. 
            void dump(); 					// display all entries in the hash table.
	    bool write_to_file(const char *filename); 		// write all elements in the hash table into a file with name filename. 
	
	private:
            size_t currentSize;
            void makeEmpty(); 					// delete all elements in the hash table
	    void rehash(); 					// called when num of elements is greater than size of vector
	    size_t myhash(const K & x) const;			// return index where k is stored
	    unsigned long prime_below(unsigned long x);		// two helper functions to determine the prime number	 	
	    void setPrimes(std::vector<unsigned long>& );
	    vector<list<pair<K, V>>> h_table;			// vector of list to make hash table
	    string customGetLine();
	};

} // end of namespace cop4530

#include "hashtable.hpp"

#endif

