#include<iostream>
#include"stacktype.h"
#include"stacktype.cpp"
#include<string>
using namespace std;
bool isBalanced(string);
int main()
{
    StackType<int>stack;
    if (stack.isEmpty())
        cout << "Stack is Empty" << endl;
    else
        cout << "Stack is not Empty" << endl;
    stack.Push(5);
    stack.Push(7);
    stack.Push(4);
    stack.Push(2);
    if (stack.isEmpty())
        cout << "Stack is Empty" << endl;
    else
        cout << "\nStack is not Empty" << endl;
    if (stack.isFull())
        cout << "\nStack is full" << endl;
    else
        cout << "\nStack is not full" << endl;

    stack.Push(3);
    if (stack.isFull())
        cout << "\nStack is full" << endl;
    else
        cout << "\nStack is not full" << endl;
    stack.Pop();
    stack.Pop();
    cout << endl<<stack.Top() << endl;

    string str1 = "()";
    cout << endl;
    cout << str1<<": ";
    if (isBalanced(str1))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;


    str1 = "(())()(()())()";
    cout << endl;
    cout << str1<<": ";
    if (isBalanced(str1))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;


    str1 = "(())()((()";
    cout << endl;
    cout << str1 << ": ";
    if (isBalanced(str1))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    str1 = "(())))((()";
    cout << endl;
    cout << str1 << ": ";
    if (isBalanced(str1))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    system("pause");
    return 1;
}

bool isBalanced(string expr)
{
    StackType<char> s;
    char x;

    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '['
                || expr[i] == '{')
        {
            s.Push(expr[i]);
            continue;
        }

        if (s.isEmpty())
            return false;

        switch (expr[i])
        {
        case ')':
            x = s.Top();
            s.Pop();
            if (x == '{' || x == '[')
                return false;
            break;

        case '}':
            x = s.Top();
            s.Pop();
            if (x == '(' || x == '[')
                return false;
            break;

        case ']':
            x = s.Top();
            s.Pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }
    return (s.isEmpty());
}
