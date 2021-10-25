/*
Name: Asif Bhuiyan
ID: 2011941642
Course Code: CSE 225
Section: 04
*/
#include <iostream>
#include "sortedtype.h"
#include "sortedtype.cpp"

using namespace std;

class timeStamp {

public:

    int sec;
    int min;
    int hr;

    timeStamp()
    {
        sec = min = hr = 0;
    }

    timeStamp(int s, int m, int h)
    {
        sec = s;
        min = m;
        hr = h;
    }

    timeStamp(timeStamp& ts)
    {
        sec = ts.sec;
        min = ts.min;
        hr = ts.hr;
    }

    bool operator == (timeStamp& ts)
    {
        return sec == ts.sec && min == ts.min && hr == ts.hr;
    }

    bool operator != (timeStamp& ts)
    {
        return sec != ts.sec || min != ts.min || hr != ts.hr;
    }

    bool operator <(timeStamp& ts)
    {
        return hr < ts.hr || (hr == ts.hr && min < ts.min) || (hr == ts.hr && min == ts.min && sec < ts.sec);
    }

    bool operator >(timeStamp& ts)
    {
        return hr > ts.hr || (hr == ts.hr && min > ts.min) || (hr == ts.hr && min == ts.min && sec > ts.sec);
    }

    friend ostream& operator<<(ostream& ts, const timeStamp& t);
};

ostream& operator<<(ostream& ts, const timeStamp& t)
{
    return ts << (t.sec < 10 ? "0" : "") << t.sec << ":" << (t.min < 10 ? "0" : "") << t.min << ":" <<
        (t.hr < 10 ? "0" : "") << t.hr << endl;
}
int main()
{
    SortedType<int> sortedlist;
    cout << "Length of the list is : " << sortedlist.LengthIs() << endl;
    cout << endl;

    sortedlist.InsertItem(5);
    sortedlist.InsertItem(7);
    sortedlist.InsertItem(4);
    sortedlist.InsertItem(2);
    sortedlist.InsertItem(1);

    int x;

    cout << "Inserted items are : ";
    for (int i = 0; i < sortedlist.LengthIs(); i++)
    {
        sortedlist.GetNextItem(x);
        cout << x << " ";
    }
    cout << endl;
    cout << endl;

    bool b;

    x = 6;

    sortedlist.RetrieveItem(x, b);

    if (b) cout << x << " Item is found" << endl;
    else cout << x << " Item is not found" << endl;
    cout << endl;

    x = 5;

    sortedlist.RetrieveItem(x, b);

    if (b)
        cout << x << " Item is found" << endl;
    else
        cout << x << " Item is not found" << endl;

    cout << endl;

    if (sortedlist.IsFull())
        cout << "List is full" << endl;
    else
        cout << "List is not full" << endl;

    sortedlist.DeleteItem(1);
    sortedlist.ResetList();
    cout << endl;

    cout << "After deleting 1 the list is : ";

    for (int i = 0; i < sortedlist.LengthIs(); i++)
    {
        sortedlist.GetNextItem(x);
        cout << x << " ";
    }

    cout << endl;
    cout << endl;


    if (sortedlist.IsFull())
        cout << "List is full" << endl;
    else
        cout << "List is not full" << endl;;
    cout << endl;

    SortedType<timeStamp> times;

    timeStamp t1(15, 34, 23);
    timeStamp t2(13, 13, 02);
    timeStamp t3(43, 45, 12);
    timeStamp t4(25, 36, 17);
    timeStamp t5(52, 02, 20);

    times.InsertItem(t1);
    times.InsertItem(t2);
    times.InsertItem(t3);
    times.InsertItem(t4);
    times.InsertItem(t5);

    times.DeleteItem(t4);

    timeStamp t;
    times.ResetList();

    for (int i = 0; i < times.LengthIs(); i++)
    {
        times.GetNextItem(t);
        cout << t;
    }
    cout << endl;
}
