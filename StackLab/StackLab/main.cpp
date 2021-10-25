#include<iostream>
#include"stacktype.h"
#include"stacktype.cpp"
#include<string>
using namespace std;
bool isBalanced(string);
int main()
{
    StackType<int>stack;
    if (stack.IsEmpty())
        cout << "Stack is Empty." << endl;
    else
        cout << "Stack is not Empty." << endl;

    stack.Push(5);
    stack.Push(7);
    stack.Push(4);
    stack.Push(2);

    if (stack.IsEmpty())
        cout << "Stack is Empty." << endl;
    else
        cout << "\nStack is not Empty." << endl;

    if (stack.IsFull())
        cout << "\nStack is full." << endl;
    else
        cout << "\nStack is not full." << endl;

    stack.Push(3);

    if (stack.IsFull())
        cout << "\nStack is full." << endl;
    else
        cout << "\nStack is not full." << endl;

    stack.Pop();
    stack.Pop();

    cout << endl << stack.Top() << endl;

    string str1 = "()";
    cout << endl;
    cout << str1 << " : ";

    if (isBalanced(str1))
        cout << "Balanced." << endl;
    else
        cout << "Not Balanced." << endl;


    str1 = "(())()(()())()";
    cout << endl;
    cout << str1 << " : ";

    if (isBalanced(str1))
        cout << "Balanced." << endl;
    else
        cout << "Not Balanced." << endl;


    str1 = "(())()((()";
    cout << endl;
    cout << str1 << " : ";

    if (isBalanced(str1))
        cout << "Balanced." << endl;
    else
        cout << "Not Balanced." << endl;

    str1 = "(())))((()";
    cout << endl;
    cout << str1 << " : ";

    if (isBalanced(str1))
        cout << "Balanced." << endl;
    else
        cout << "Not Balanced." << endl;

    system("pause");
    return 1;
}

bool isBalanced(string exp)
{
    StackType<char> s;
    char x;

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '['
            || exp[i] == '{')
        {
            s.Push(exp[i]);
            continue;
        }

        if (s.IsEmpty())
            return false;

        switch (exp[i])
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
    return (s.IsEmpty());
}
