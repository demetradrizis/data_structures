/* Demetra Drizis 
   Project 3
   10/29/19 */
#include <iostream>
#include <fstream>
#include <string>
#include "stack.h"

using namespace std;
using namespace cop4530;

int getPrecedence(char x);

int main(int argc, char **argv)
{
    string input = "";
    string infix = "";
    string tempp = "";
    ifstream temp;
    bool go = true;
    bool noV = true;
    bool valid = true;
    double lhscnt = 0;
    double rhscnt = 0;
    double numcnt = 0;
    double operands = 0;
    auto prev = '\0';
    
    Stack<char> operators;
    Stack<float> equals;
    
    temp.open(argv[1]);
    while(go == true && getline(temp, input))
    {
        cout << endl;
        
        for(int i = 0; i < input.length(); i++)
        {
            while(i >= input.length() &&(iswspace(input.at(i)))!= '\0')
            {
                    i++;
                    if(i >= input.length())
                    {
                        break;
                        valid = false;
                    }
            }
            
            if(isalnum(input.at(i)) != '\0' || input.at(i) =='_' && valid)
            {
                    while((isalnum(input.at(i)) != '\0' || input.at(i) == '_' ) && input.at(i) != '\0' && input.at(i) != ' ')
                    {
                        if(isdigit(input.at(i)) == '\0')
                        {
                            noV = false;
                        }
                        
                        if(i == (input.length() - 1))
                        {
                            break;
                        }
                        if(input.at(i) != ' ')
                        {
                            infix = infix + input.at(i);
                        }
                        i++;
                    }
                    if(input.at(i) != ' ')
                    {
                        infix = infix + input.at(i);
                    }
                    infix = infix + " ";
            }
            else if(input.at(i) == '(' || input.at(i) == ')' && valid)
            {
                    if(input.at(i) == '(')
                    {
                        operators.push(input.at(i));
                        lhscnt++;
                    }
                
                    else if(input.at(i)==')')
                    {
                        rhscnt++;       // when there is an operator and a parenthesis throw an error message
                        if(prev == '*' || prev == '/' || prev == '+' || prev == '-')
                        {
                            cout << "Error: Missing operands in the expression" << endl;
                            break;
                            
                        }
                        else
                        {
                            while(operators.top() != '(' && (!operators.empty()))
                            {
                                if(operators.top() != ' ')
                                {
                                    infix = infix + operators.top();
                                    infix = infix + " ";
                                }
                                operators.pop();
                            }
                        }
                        operators.pop();  // pop parenthesis
                    }
            }
            else if(input.at(i) == '+' || input.at(i) == '-' || input.at(i) == '*' || input.at(i) == '/' && valid)
            {
                    while(!(operators.empty()) && (operators.top() != '(') && !(getPrecedence(operators.top()) < getPrecedence(input.at(i))))
                    {
                        if(operators.top() != ' ')
                        {
                            infix = infix + operators.top();
                            infix = infix + " ";
                        }
                        operators.pop();
                    }
                    operators.push(input.at(i));
            }

            /* else if (input.at(i) == '.')
             {
                 //tempp = input;
                 //cout << prev << endl;
                 if (isalnum(prev - 1))
                 {
                     cout << "Consecutive Numbers: ";
                     cout << input[i-2] << input[i-1] << input[i] << input[i+1] << endl;
                 }
                 else
                    cout << input[i] << input[i+1] << endl;
             }
             else if (isalnum(input.at(i)))
             {
                 if (isalnum(prev))
                 {
                     cout << "Error" << endl;
                 }
             }*/
            //create temp string variable to add on temp.find() if is digit and != space
            // check temp to find the . after print out the whole number
            //use += add to infix if its a regular number
            
            
                prev = input.at(i);
            
        }
        while(!(operators.empty()))
        {
                if(operators.top() != ' ')
                {
                    infix = infix + (operators.top());
                    infix = infix + " ";
                }
                operators.pop();
        }
        if(lhscnt != rhscnt && input.length() > 0 )
                valid = false;
        
        if(!valid)
        {
            cout<< "Error: Infix expression: " << input << " is missing an operand" << endl;
            cout << "Found in input: " << endl << input << endl;
        }
        
        /*if(valid)
        {
           // cout << "Postfix expression: " << infix << endl;
  	     //cout << infix << endl; 
        }*/
        
        
        if(!noV && valid)
        {
           // cout << "Postfix evaluation: " << infix << " = " << infix << endl;
       	     cout << infix << endl; 
	}
        else
        {
            //cout << "Postfix evaluation: " << infix << " = ";
            
                for(int i = 0; i < infix.length(); i++)
                {
                
                    if(infix.at(i) == ' ') //leave it
                    {
                    
                    }
                    else if((!(infix.at(i) == '+' || infix.at(i) == '-' || infix.at(i) == '*' || infix.at(i) == '/')))
                    {
                        string numbers = "";
                        double operand = 0;
                        
                        while(infix.at(i) != ' ')
                        {
                            numbers = numbers + infix.at(i);
                            i++;
                        }
                    
                        if(numbers != "")
                        {
                            operand = stod(numbers, nullptr);
                            equals.push(operand);
                            numcnt++;
                        }
                }
                else if(infix.at(i) == '+' || infix.at(i) == '-' || infix.at(i) == '*' || infix.at(i) == '/')
                {
                        operands++;
                    
                        double x,y;
                    
                        if(!equals.empty())
                        {
                            x = equals.top();
                            equals.pop();
                        }
                        if(!equals.empty())
                        {
                            y = equals.top();
                            equals.pop();
                        }
                    
                        if(infix.at(i)=='*')
                        {
                            equals.push(x * y);
                        }
                        else if(infix.at(i)=='/')
                        {
                            equals.push(y / x);
                        }
                        else if(infix.at(i) == '+')
                        {
                            equals.push(x + y);
                        }
                        else if(infix.at(i)=='-')
                        {
                            equals.push(y - x);
                        }


                }
                
            }
                double done;
           
                if(equals.empty())
                {
                    done = 0;
                }
                else
                {
                    done = equals.top();
                    equals.pop();
                }
            
            if(operands > numcnt)
            {
		cout << endl;
		cout << "Consecutive Numbers or Opcodes: " << endl; 
                //cout << endl << "Error: Missing operands in the expression" << endl;
                cout << "Found in input: " << endl << input << endl;
            }
            else if(operands != (numcnt - 1))
            {
		cout << endl; 
		cout << "Consecutive Numbers or Opcodes: " << endl;
               // cout  <<endl<< "Error: Missing operand in postfix string. Unable to evaluate postfix string!" << endl;
                cout << "Found in input: " << endl << input << endl;
            }
            else if(equals.empty())
            {
                cout << done << endl;
            }
            else
            {
                cout << done << endl;
                cout << "Error: Unexpected operand in stack: " << equals << endl;
                cout << "Found in input: " << endl << input << endl;
            }
            //cout << endl;
            //cout << userIn<<endl;
        }
       
        cout << endl;
      
        infix = "";
        input = "";
        prev = '\0';
        operators.clear();
        equals.clear();             //reset the variables back to intial values
        valid = true;
        noV = true;
        go = true;
        numcnt = 0;
        operands = 0;
        
    }
    return 0;
}
int getPrecedence(char x)
{
    if(x == '-' || x == '+')
    {
        return 0;
    }
    else if(x == '*' || x =='/')
    {
        return 1;
    }
    else if(x == '(')
    {
        return 2;
    }
    else if(x == ')')
    {
        return 3;
    }
    else
    {
        return -1;
    }
}
