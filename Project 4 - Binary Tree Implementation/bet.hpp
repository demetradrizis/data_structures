/* Demetra Drizis 
   Project 4
   11/12/19 
*/

using namespace std;

enum elementType { OPERATOR, OPERAND = 2};        // Enumeration for getType() 

template <typename T>
BET <T> :: BET()
{
	root = nullptr;
}
template <typename T>
BET <T> :: BET (const list<Token> &  postfix)                    // single parameter constructor
{
	buildFromPostfix(postfix);
}
template <typename T>
BET <T> :: BET(const BET & btree)                        // copy constructor
{
	root = clone(btree.root);
}
template <typename T>
BET <T> :: ~BET()                                       // destructor
{
    	makeEmpty(root);
}

template <typename T>
bool BET <T> :: buildFromPostfix(const list<Token> & postfix)
{
    if(!empty())
    {
        makeEmpty(root);
    }

    root = nullptr; 
    stack <BinaryNode*> tempStack;
    int operandCnt = 0;
    int operatorCnt = 0;
    list<Token> templist;

    for(auto itr = postfix.begin(); itr != postfix.end(); itr++)         
    {
	templist.clear();
	string temp = (string)(*itr).getValue();
	Token tempt(temp, (*itr).getType());

        if ( (getType(temp.c_str()) == OPERATOR) && (tempStack.size() >= 2))
	{
	    temp.clear();
	    templist.push_back(tempt);
	    BinaryNode * right = tempStack.top();
	    tempStack.pop();
	    BinaryNode * left = tempStack.top();
	    tempStack.pop();
	    BinaryNode* ptr = new BinaryNode{templist, left, right};
	    tempStack.push(ptr);            
	    operatorCnt++;
        }
	else if ( ( getType(temp.c_str()) == OPERATOR) && (tempStack.size() < 2))
	{
		cout << "Error: Operator [" << (*itr).getValue() << "] has only one operand: " << *itr << endl;
		operandCnt--;
		return false;	
	}
        else if( ( getType(temp.c_str()) == OPERAND)) 
	{
	   	temp.clear();
		templist.push_back(tempt);

	  	BinaryNode* newptr = new BinaryNode{templist, nullptr, nullptr};
            	operandCnt++;
	      	tempStack.push(newptr);
        }
	else 
	{	
		continue; 
	}

	templist.clear();
    }


	swap(root, tempStack.top()); //copy node to root 
	operandCnt == 1; 
	
	return true;
}

template <typename T>
const BET <T> & BET <T> :: operator= (const BET & btree)
{
 	root = clone(btree.root);
 	return *this;
}

template <typename T>
void BET <T> :: printInfixExpression()
{
	printInfixExpression(root);
     	cout << endl;
}

template <typename T>
void BET <T> :: printPostfixExpression()
{
	printPostfixExpression(root);
    	cout << endl;
}

template <typename T>
size_t BET <T> :: size()
{
	return size(root); 
}

template <typename T>
size_t BET <T> :: leaf_nodes()
{
	return leaf_nodes(root); 
}

template <typename T>
bool BET <T> :: empty()
{
	if (size() == 0)
	{
		return true; 
	}
	else
	{
		return false; 
	}
}

template <typename T>
void BET <T> :: printInfixExpression(BinaryNode *n)
{
	if (root == nullptr)
	    return; 

	if (n->left != nullptr || n->right != nullptr)
	{
           string temp = (string)n->element.back().getValue();
           string temp_left = (string)n->left->element.back().getValue();
           string temp_right = (string)n->right->element.back().getValue();

		if (getPrec(temp) > getPrec(temp_left))
		{
		   	cout << "( ";
			printInfixExpression(n->left);
		    	cout << ") ";	     	   
		}
		else
		{
		     if (n->left == nullptr)
		     {
			return; 
		     }
		     else
		     {
			printInfixExpression(n->left);
		     }	  
		}
		    cout << n->element;

		if (getPrec(temp) >= getPrec(temp_right))
		{
		    cout << "( ";
		    printInfixExpression(n->right);
                    cout << ") ";
		}
		else
		{
		     if (n->right == nullptr)
                     {  
			return;
                     }
		     else
		     {
		        printInfixExpression(n->right);
		     }
		}
	}
	else
		   cout << n->element;
}

template <typename T>
void BET <T> :: makeEmpty(BinaryNode* &t)
{
	if (t != nullptr)
	{
		makeEmpty(t -> left); 
		makeEmpty(t -> right); 
		
		delete t;
	}

	t = nullptr; 
}

template <typename T>
typename BET <T> :: BinaryNode *  BET <T> :: clone(BinaryNode *t)
{
	if (t == nullptr)
	{
		return nullptr; 
	}
	else 
	{
		BinaryNode * node = new BinaryNode{t -> element, clone(t -> left), clone(t -> right)};
		return node; 
	}
}

template <typename T>
void BET <T> :: printPostfixExpression(BinaryNode * n)
{
	if(n != nullptr)
    	{
        	printPostfixExpression(n -> left);
        	printPostfixExpression(n -> right);
        	cout << n -> element << " ";
    	}

}

template <typename T>
size_t BET <T> :: size(BinaryNode * t)
{
   	size_t retsize = 0;

    	if(t != nullptr)
    	{
        	retsize = retsize + size(t -> left);
        	retsize = retsize + size(t -> right);
        	retsize++;
    	}

    	return retsize;
}

template <typename T>
size_t BET <T> :: leaf_nodes(BinaryNode * t)
{
   	size_t leaves = 0;

    	if(t != nullptr && (t -> left == nullptr && t -> right == nullptr))     
    	{
        	leaves++;				//coutn leaves with no children
        	return leaves;
    	}
    	else                                                      
    	{
        	leaves = leaves + leaf_nodes(t -> left);
        	leaves = leaves + leaf_nodes(t -> right);
        	return leaves;
    	}

}

int getType (const char * x)
{
    if(strcmp(x, "+") == 0 || strcmp(x, "-") == 0 || strcmp(x, "/") == 0 || strcmp(x, "*") == 0)
        return OPERATOR;
    else
        return OPERAND;
}

int getPrec(string x)
{

    if(x == "+" || x == "-")
    {
        return 1;
    }
    else if(x == "*" || x == "/")
    {
        return 2;
    }
    else
        return 3;
}

