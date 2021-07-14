/* Demetra Drizis
   Project 4
   11/12/19
*/


#ifndef BET_H
#define BET_H
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <list>
#include "token.h"

using namespace std;

template <typename T>
class BET
{
	struct BinaryNode
	{
		list<Token> element; //list<Token> & element
		BinaryNode *left;
    		BinaryNode *right;
		
		BinaryNode() : left{nullptr}, right{nullptr}{}
                BinaryNode(list<Token> & elm, BinaryNode * ll, BinaryNode * rr)
                    : element{elm}, left{ll},right{rr}{}

	};

public:
	BET(); 							//default zero-parameter constructor. Builds an empty tree.
	BET(const list<Token> & postfix); 			//one-parameter constructor, where parameter "postfix" is a list representing a postfix expression. The tree should be built based on the postfix expression.
	BET(const BET&); 					// copy constructor
	~BET(); 						// destructor 
	bool buildFromPostfix(const list<Token> & postfix); 	//parameter "postfix" is a list representing a postfix expression.
	const BET & operator= (const BET &); 			//assignment operator
	void printInfixExpression(); 				//Print out the infix expression. Should do this by making use of the private (recursive) version
	void printPostfixExpression(); 				//Print the postfix form of the expression. Use the private recursive function to help
	size_t size(); 						//Return the number of nodes in the tree
	size_t leaf_nodes(); 					//Return the number of leaf nodes in the tree
	bool empty(); 						// return true if tree is empty
private: 
	void printInfixExpression(BinaryNode *n); 		//print to the standard output the corresponding infix expression
	void makeEmpty(BinaryNode* &t); 			//delete all nodes in the subtree pointed to by t
	BinaryNode * clone(BinaryNode *t); 			//clone all nodes in the subtree pointed to by t
	void printPostfixExpression(BinaryNode *n); 		//print to the standard output the corresponding postfix expression.
	size_t size(BinaryNode *t); 				//return the number of nodes in the subtree pointed to by t
	size_t leaf_nodes(BinaryNode *t); 			//return the number of leaf nodes in the subtree pointed to by t.
	BinaryNode* root;    // Private root node is used to determine the top of the tree. A tree is empty if root ==NULL.

};

int getType(const char * x);
int getPrec(string c);

#include "bet.hpp"
#endif
