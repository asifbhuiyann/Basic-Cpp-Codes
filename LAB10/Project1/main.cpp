#include <iostream>
#include <string>
#include "stacktype.h"
#include "stacktype.cpp"

using namespace std;

bool operand(char c) 
{
    if (c >= '0' && c <= '9')
    return true;
    return false;
}

int operatorr(char c)
{
    if (c == '+' || c == '-')
    {
        return(1);
    }

    if (c == '*' || c == '/')
    {
        return(2);
    }

    if (c == '^')
    {
        return(3);
    }

    return 0;
}

string infixToPostfix(string infix) 
{
    string postfix = "";
    StackType< char > stack;

    int i = 0;
    while (i < infix.length()) 
    {
        if (infix[i] == ' ') {
            i++;
            continue;
        }
        if (operand(infix[i]))
        {
            postfix += infix[i];
            i++;
        }
        else if (infix[i] == '(')
        {
            stack.Push(infix[i]);
            i++;
        }
        else if (infix[i] == ')')
        {
            while (stack.Top() != '(')
            {
                if (stack.IsEmpty()) {
                    cout << "Invalid expression\n";
                    return "";
                }
                postfix += stack.Top();
                stack.Pop();
            }
            stack.Pop();
            i++;
        }
        else
        {
            if (stack.IsEmpty())
            {
                stack.Push(infix[i]);
                i++;
            }
            else if (operatorr(infix[i]) > operatorr(stack.Top()))
            {
                stack.Push(infix[i]);
                i++;
            }
            else {

                while (operatorr(infix[i]) <= operatorr(stack.Top()))
                {
                    postfix += stack.Top();
                    stack.Pop();
                    if (stack.IsEmpty())break;
                }
                stack.Push(infix[i]);
                i++;
            }
        }
    }
    while (!stack.IsEmpty())
    {
        postfix += stack.Top();
        stack.Pop();
    }
    return postfix;
}

bool isOperator(char ch) 
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return true;   
    return false;  
}
char operation(int a, int b, char op)
{
    int ans;
    if (op == '+')
        ans = b + a;
    else if (op == '-')
        ans = b - a;
    else if (op == '*')
        ans = b * a;
    else
        ans = b / a;
    return ans;
}

int postfixe(string postfix) 
{
    int a, b;
    StackType<int> stack;

    for (int i = 0; i < postfix.length(); i++) 
    {
        char x = postfix[i];
        if (isOperator(x)) {
            a = stack.Top();
            stack.Pop();
            b = stack.Top();
            stack.Pop();
            stack.Push(operation(a, b, x));

        }
        else if (operand(x)) {
            stack.Push(x - '0');
        }
    }
    int ans = stack.Top();
    stack.Pop();
    if (!stack.IsEmpty()) {
        cout << "Invalid expression\n";
        return -1;
    }
    return ans;
}
int main() 
{
    string infix, postfix;
    cout << "Please Enter The Infix Expression: : "; 
    getline(cin, infix);
    postfix = infixToPostfix(infix);
    cout << "Postfix = " << postfix << endl;
    cout << "Expected Output = " << postfixe(postfix) << endl;
    return 0;
}