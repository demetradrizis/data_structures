/* Demetra Drizis 
   Project 5
   11/27/19
*/

#ifndef PASS_SERVER_H
#define PASS_SERVER_H

#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <functional>

#include "hashtable.h"
 
using namespace cop4530;

template <typename K, typename V>
class PassServer : public HashTable <K, V>
{
   public:
      explicit PassServer(size_t size = 101); 				// constructor to create a hash table of the specified size
      ~PassServer(); 							// destructor
      bool load (const char * filename); 				// load a password file into the hsatable object
      bool addUser(std::pair<string, string> & kv);			// add a new username and password
      bool addUser(std::pair<string, string> && kv); 			// move version of addUser
      bool removeUser(const string & k);					// delete an existing user with username k
      bool changePassword(const pair<string, string> & p, const string & newpassword);  // change an existings users password
      bool find(const string & user);					// check if user exists
      void dump();    							// show the structure and contents of the hashtable object to the screen 
      size_t size(); 							// return the size of the hashtable
      bool write_to_file(const char * filename);				// save username and password combo into a file 

    private:
      string encrypt(const string & str); 				// encrypt the parameter str and return the encrypted string
      HashTable <string, string> h_table;
};

#endif
