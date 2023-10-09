// Created by Ed Garcia on 10/5/23.
// CS 302
// HW 3

#include <iostream>
#include <string>

#include "arrayStack.h"

using namespace std;

const string PROGRAMMER_NAME = "Eduardo Garcia";	//Programmer's Name

/*
bool isOperator(char symbol)
{
    if(symbol == '+' || symbol =='-' || symbol == '*' || symbol == '/' || symbol == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}
*/

int precedence (char symbol)
{
    if(symbol == '^')                           // '^' takes highest precedence
        return 3;

    else if(symbol == '*' || symbol =='/')           // '*' && '/' 2nd highest
        return 2;

    else if(symbol == '+' || symbol =='-')           // '+' && '-' take 3rd
        return 1;

    else                                        // return 0;
        return -1;
}

bool operands(char ch)
{
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))                // for inputting characters...
    {
        return true;                                                                        // ...for infix expression
    }

    else
        return false;
}

string inToPost(ArrayStack<char> s, string infix)                               // <char> s for implementing ArrayStack
{
    int i = 0;                              // for index infix[i]
    string postfix;                         //

    while(infix[i] != '\0')                 // While loop until infix[i] = '\0' (end of string)
    {
        if(operands(infix[i]))          //  if statement for implementing the bool operands into infix[i];
        {
            postfix += infix[i];
            i++;
        }

        else if(infix[i] == '(')            // opening bracket is pushed to stack
        {
            s.push(infix[i]);
            i++;
        }

        else if (infix[i] == ')')
        {
            while ((s.peek() != '(') && (!s.isEmpty())) {
                postfix += s.peek();
                s.pop();
            }
            s.pop();
            i++;
        }

        else
        {
            while(!s.isEmpty() && precedence(infix[i]) <= precedence(s.peek()))         //
            {
                postfix += s.peek();
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }

    while(!s.isEmpty())
    {
        postfix += s.peek();
        s.pop();
    }

    return postfix;                                         // postfix expression set
}

int main()                                                  // main function
{
    string infix_express, postfix_express;
    cout << "Enter inFix expression: ";
    getline(cin, infix_express);                        // user input expression for infix

    ArrayStack<char> stack;

    postfix_express = inToPost(stack, infix_express);       // postfix output from inToPost function
    cout << "Postfix expression: " << postfix_express;

    cout << "\n\nProgrammed by: " << PROGRAMMER_NAME << " -- ";     // Programmer username
    cout << __DATE__ << "  " __TIME__ << endl;
    cout << endl;

    return 0;
}

