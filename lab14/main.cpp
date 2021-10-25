#include <iostream>
#include "pqtype.h"
#include "pqtype.cpp"

using namespace std;

int main()
{
    PQType<int>pq = PQType<int>(15);

    if (pq.IsEmpty())
        cout << "Queue is Empty." << endl;
    else
        cout << "Queue is not Empty." << endl;

    cout << endl;

    cout << "Please Enter 10 Items: " << endl;

    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        pq.Enqueue(x);
    }
    cout << endl;

    if (pq.IsEmpty())
        cout << "Queue is Empty." << endl;
    else
        cout << "Queue is not Empty." << endl;
    cout << endl;

    int x;
    pq.Dequeue(x);
    cout << "The First Dequeued Value is: " << x << endl;
    cout << endl;

    pq.Dequeue(x);
    cout << "The Second Dequeued Value is: " << x << endl;
    cout << endl;

    int n, k;
    cout << "Please Enter The Value of N and K: " << endl;
    cin >> n >> k;

    PQType<int>pq2 = PQType<int>(n + 5);
    cout << endl;

    cout << "Enter Candies: ";
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        pq2.Enqueue(x);
    }

    int candy = 0;

    while (k)
    {
        int x;
        pq2.Dequeue(x);
        candy += x;
        x = floor(x / 2.0);
        pq2.Enqueue(x);
        k--;
    }
    cout << endl;
    cout << "Maximum Number Of Eatable Candies : " << candy << endl;
    return 0;
}
