/* Demetra Drizis 
   Project 5
   11/27/19
*/

#include <vector>
#include <list>
#include <string>     // string.c_str(), string();
#include <algorithm>  // std::find
#include <functional> // std::hash
#include <iostream>   // std::cout, std::cerr
#include <fstream>    // ifstream and ofstream
#include <string.h>   // strcpy, strtok, 
#include <unistd.h>   // crypt()
#include <stdlib.h>   
#include <cstring>

#include "hashtable.h"
#include "pass_server.h"

using namespace std;
using namespace cop4530;
 
template <typename K, typename V>
size_t PassServer<K,V>::size()
{
  // return HashTable<K,V>::size();
	return (h_table.size());
}

template <typename K, typename V>
PassServer<K,V> :: PassServer(size_t size) : h_table(size)
{
	//constructor
}

template <typename K, typename V>
PassServer<K,V> :: ~PassServer()
{				//destructor
	h_table.clear(); 
}

template <typename K, typename V>
bool PassServer<K,V> :: load(const char * filename)
{								//load password into the file object
	return h_table.load(filename);
}

template <typename K, typename V>		
bool PassServer<K,V> :: addUser(std :: pair<string, string> & kv)
{							//add new username and password
	string temp_encrypt = encrypt(kv.second); 	//encrypt password first

	pair <string, string> encrypt_pair (kv.first, temp_encrypt); 

	return h_table.insert(encrypt_pair);
}

template <typename K, typename V>
bool PassServer<K,V> :: addUser(std :: pair<string, string> && kv )
{								//move version of adduser
	string move_encrypt = encrypt(kv.second);
	
	pair <string, string> copy(kv.first, move_encrypt);
	
	return addUser(kv);
}

template <typename K, typename V>
bool PassServer<K,V> :: removeUser(const string & k)		//delete user
{
	return h_table.remove(k);
}

template <typename K, typename V>
bool PassServer<K,V> :: changePassword(const pair<string, string> & p, const string & newpassword)
{								//change a users password
	string oldencrypt =  encrypt(p.second);
	string newencrypt = encrypt(newpassword);

	if (p.second == newpassword)
	{
		return false;		//passwords cant be the same
	}
	else if (!h_table.contains(p.first))
	{
		return false; 		//if user isn't in table
	}
	else
	{
		pair <string, string> oldpass(p.first, oldencrypt);
	
		if (!h_table.match(oldpass))
		{
			return false;		// if old password doesn't match input
		}
		else
		{
			pair <string, string> newpass(p.first, newencrypt);
			h_table.insert(newpass);
			return true;
		}
	}

}

template <typename K, typename V>
bool PassServer<K,V> :: find(const string & user)		//check if user exists
{
	return h_table.contains(user);
}

template <typename K, typename V>
void PassServer<K,V> :: dump()				//basically same as hash table dump
{							//show structure and contents to screen
	return h_table.dump();
}

template <typename K, typename V>
bool PassServer<K,V> :: write_to_file(const char * filename)
{							//save username and pass combo into file
	return h_table.write_to_file(filename);
}

template <typename K, typename V>
string PassServer<K,V> :: encrypt(const string & str) 
{						//encrypt parameter and return the string
	char salt [] = "$1$########";
    	string encrypted = crypt(str.c_str(), salt);
  
	return encrypted.substr(12);
}


/* XXX: Please keep this line at the very end */
template class PassServer<string, string>;

