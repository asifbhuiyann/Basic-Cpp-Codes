#include<iostream>
#include "unsortedtype.cpp"
using namespace std;

int main()
{
    UnsortedType<int> list1,list2;
    int m, n;
    cout << "Please Enter Input: "<<endl;;
    cin >> m;

    for(int i=0; i<m; i++)
    {
        int data;
        cin >> data;
        list1.InsertItem(data);
    }

    cin >> n;
    for(int i=0; i<n; i++)
    {
        int data;
        cin >> data;
        list2.InsertItem(data);
    }

    UnsortedType<int> List;
    int item1,item2;
    int len1=0,len2=0;

    list1.GetNextItem(item1);
    list2.GetNextItem(item2);

    while(len1 < list1.LengthIs() && len2 < list2.LengthIs())
    {
        if (item1 > item2)
        {
            List.InsertItem(item1);
            len1++;

            if (len1 < list1.LengthIs())
            {
                 list1.GetNextItem(item1);
            }
        }

        else
        {
            List.InsertItem(item2);
            len2++;

            if (len2 < list2.LengthIs())
            {
                 list2.GetNextItem(item2);
            }
        }
    }

    while (len1 < list1.LengthIs())
    {
        List.InsertItem(item1);
        len1++;

        if (len1 < list1.LengthIs())
        {
             list1.GetNextItem(item1);
        }
    }

    while (len2 < list2.LengthIs())
    {
        List.InsertItem(item2);
        len2++;

        if (len2 < list2.LengthIs())
        {
             list2.GetNextItem(item2);
        }
    }

    int item;
    int i =0;

    cout <<endl;
    cout << "Expected Output: ";

    while (i < List.LengthIs())
    {
        List.GetNextItem(item);
        cout << item <<" ";
        i++;
    }

    cout << endl << endl;
    return 0;
}
