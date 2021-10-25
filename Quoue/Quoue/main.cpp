#include <iostream>
#include "quetype.h"
#include "quetype.cpp"

using namespace std;

int main()
{
    QueType <int> Que(5);
    if (Que.IsEmpty())
        cout << "Queue is Empty" << endl;
    else
        cout << "Queue is Not Empty" << endl;
    Que.Enqueue(5);
    Que.Enqueue(7);
    Que.Enqueue(4);
    Que.Enqueue(2);

    if (Que.IsEmpty())
        cout << "Queue is Empty" << endl;
    else
        cout << "Queue is Not Empty" << endl;

    if (Que.IsFull())
        cout << "Queue is Full" << endl;
    else
        cout << "Queue is Not Full" << endl;

    Que.Enqueue(6);
    int temp;
    QueType <int> TempQueue(5);

    for (int i = 0; i < 5; i++) 
    {
        Que.Dequeue(temp);
        TempQueue.Enqueue(temp);
    }

    for (int i = 0; i < 5; i++) 
    {
        TempQueue.Dequeue(temp);
        cout << temp << endl;
    }

    if (Que.IsFull())
        cout << "Queue is Full" << endl;
    else
        cout << "Queue is Not Full" << endl;

    Que.Enqueue(5);
    Que.Enqueue(7);
    Que.Enqueue(4);
    Que.Enqueue(2);
    Que.Enqueue(6);

    if (Que.IsFull())
        cout << "Queue OverFlow" << endl;
    else
        Que.Enqueue(8);

    Que.Dequeue(temp);
    Que.Dequeue(temp);
    for (int i = 0; i < 3; i++) 
    {
        Que.Dequeue(temp);
        TempQueue.Enqueue(temp);
    }
    for (int i = 0; i < 3; i++) 
    {
        TempQueue.Dequeue(temp);
        cout << temp << endl;
    }

    if (Que.IsEmpty())
        cout << "Queue is Empty" << endl;
    else
        cout << "Queue is Not Empty" << endl;

    if (Que.IsEmpty())
        cout << "Queue UnderFlow" << endl;
    else
        Que.Dequeue(temp);

    int n;
    cout << "Please Enter The Value of N: " << endl;
    cin >> n;
    cout << "The Binary Values Are:"<<endl;
    QueType<string> que;
   
    que.Enqueue("1");

    while (n--) 
    {
        string s1;
        que.Dequeue(s1);
        cout << s1 << "\n";
        string s2 = s1;
        que.Enqueue(s1.append("0"));
        que.Enqueue(s2.append("1"));
    }
    return 0;
}
