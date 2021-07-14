/* Demetra Drizis 
   Project 5
   11/27/19
*/

#include <iostream>
#include <string>

#include "hashtable.h"
#include "pass_server.h"

void menu()
{
   cout << "\n\n";
   cout << "l - Load From File" << endl;
   cout << "a - Add User" << endl;
   cout << "r - Remove User" << endl;
   cout << "c - Change User Password" << endl;
   cout << "f - Find User" << endl;
   cout << "d - Dump HashTable" << endl;
   cout << "s - HashTable Size" << endl;
   cout << "w - Write to Password File" << endl;
   cout << "x - Exit program" << endl;
   cout << "\nEnter choice : ";
}

int main()
{
   bool toexit = false;
   string line;
   char choice; 

   PassServer<string, string> ps{};

   menu();

   while (choice != 'x')
   {
	cin >> choice;

	string file;	

     	if (choice == 'l')
	{
		cout << endl << "Please enter a filename: ";

		while (isspace(cin.peek()) && !cin.eof())
		{
			cin.get();
		}

		getline(cin, file);
		
		cout << endl;

		if (ps.load(file.c_str()) == true)
		{
			cout << "	Success loading file." << endl;  
		}
		else
		{
			cout << "	Failure loading file." << endl;
		}

	}
	else if (choice == 'a')
	{
		string username;
		string password;
	
		cout << endl << "Please enter a username: ";
		cin >> username;

		cout << endl;
		cout << "Please enter a new password: ";
		cin >> password; 
		cout << endl;

		if (ps.addUser(make_pair(username, password)) == true)
		{
			cout << " 	Success adding " << username << endl; 	
		}
		else 
		{
			cout << "	Failure adding " << username << endl; 
		}
	}
	else if (choice == 'r')
	{
		string rm_name;

		cout << endl << "Please enter a username: ";
		cin >> rm_name;
	
		if (ps.removeUser(rm_name))
		{
			cout << endl << "	Success removing " << rm_name << endl;
		}
		else
		{
			cout << endl << "	Failure removing " << rm_name << endl;
		}
	}
	else if (choice == 'c')
	{
		string user_nm;
		string pass_wd;
		string new_pass;

		cout << endl << "Please enter a username: ";
		cin >> user_nm;
		cout << endl;

		cout << "Please enter the current password: ";
		cin >> pass_wd;
		cout << endl;
		
		cout << "Please enter a new password: "; 
		cin >> new_pass;
		cout << endl;

		if (ps.changePassword(pair<string, string>(user_nm, pass_wd), new_pass))
		{
			cout << "	Success changing " << user_nm << endl;
		} 
		else
		{
			cout << " 	Failure changing " << user_nm << endl;
		}

	}
	else if (choice == 'f')
	{
		string user;

		cout << endl << "Please enter a username: ";
		cin >> user; 
		cout << endl;

		if (ps.find(user) == true)
		{
			cout << "	Success finding " << user << endl; 
		}
		else
		{
			cout << "	Failure finding " << user << endl;
		}
		

	}
	else if (choice == 'd')
	{
		cout << endl;
		cout << "----- Beginning the dump -----" << endl;

		ps.dump();

		cout << "----- End -----" << endl;	

	}
	else if (choice == 's')
	{
		if (ps.size() == 0)
		{
			cout << endl << "       The current size is 101" << endl;
		}
		else
		{
			cout << endl << " 	The current size is " << ps.size() << endl; 
		}
	}
	else if (choice == 'w')
	{
		string file_name;

		cout << endl << "Please enter a filename: ";
		cin >> file_name;
		cout << endl; 

		if (ps.write_to_file(file_name.c_str()) == true)
		{
			cout << "	Success writing " << file_name << endl; 
		}
		else
		{
			cout << "	Failure writing " << file_name << endl;   
		}
	}
	else if (choice == 'x')
	{
		cout << endl << "	Exiting ..." << endl; 
		toexit = true;
		break;
	}
	else if (choice != 'l' || choice != 'a' || choice != 'r' || choice != 'c' || choice != 'f' || 
		choice != 'd' || choice != 's' || choice != 'w' || choice != 'x')
	{
		cout << endl; 
		cout << "	Invalid selection." << endl;
	}

	menu(); 

   }

   return 0;
}

