/*
Name: Asif Bhuiyan
ID: 2011941642
Course Name: CSE-225
Section: 4
*/

#include <iostream>
#include "unsortedtype.h"
#include "unsortedtype.cpp"
using namespace std;

int main()
{
	int item;
	int retrieve;
	UnsortedType <int> unsortedarray;
	cout << "Please Enter The Values: " << endl;
	for (int i = 0; i < 4; i++)
	{
		cin >> item;
		unsortedarray.InsertItem(item);
	}
	unsortedarray.ResetList();
	cout << endl;
	cout << "Inserted Iteams Are: ";
	for (int i = 0; i < 4; i++)
	{
		unsortedarray.GetNextItem(item);
		cout << item << " ";
	}
	cout << endl;
	unsortedarray.ResetList();


	int l = unsortedarray.LengthIs();
	cout << endl << "The Lenght Of The List Is: " << l << endl;
	unsortedarray.ResetList();
	cout << endl;

	unsortedarray.InsertItem(1);
	cout << "After Inserting A New Value The New List Is: ";
	for (int i = 0; i < 5; i++)
	{
		unsortedarray.GetNextItem(item);
		cout << item << " ";
	}
	cout << endl;
	unsortedarray.ResetList();
	cout << endl;

	int m;
	bool x;
	cout << "Please Enter How Many Items You Want To Search: ";
	int a;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
        cout<<endl;
		cout << "Please Enter The Item You Want To Search: ";
		cin >> m;
		cout << endl;
		unsortedarray.RetrieveItem(m, x);
		if (x == true)
		{
			cout << m << " Is In The List!" << endl;
			cout << endl;
		}
		else
		{
			cout << m << " Is Not In The List!!" << endl;
			cout << endl;
		}
	}
	unsortedarray.ResetList();
	//cout<<endl;

	cout << "If The List is Full The Output Will be 1 otherwise 0. " << endl;
	bool check = unsortedarray.IsFull();
	cout << endl;
	cout << "Output is: " << check << endl;

	unsortedarray.ResetList();
    cout<<endl;


    unsortedarray.DeleteItem(5);
    unsortedarray.ResetList();
    cout<<"After removing 5 the list is :"<<endl;
    for(int i=0; i<unsortedarray.LengthIs(); i++)
    {
        unsortedarray.GetNextItem(item);
        cout << item;
    }
    cout << "\n\n";

    cout << "If The List is Full The Output Will be 1 otherwise 0. " << endl;
	bool check1 = unsortedarray.IsFull();
	cout << endl;
	cout << "Output is: " << check1 << endl;

	unsortedarray.ResetList();
    cout<<endl;

	unsortedarray.DeleteItem(1);
    unsortedarray.ResetList();
    cout<<"After removing 1 the list is :"<<endl;
    for(int i=0; i<unsortedarray.LengthIs(); i++)
    {
        unsortedarray.GetNextItem(item);
        cout << item;
    }

    cout << "\n\n";

    unsortedarray.DeleteItem(6);
    unsortedarray.ResetList();
    cout<<"After removing 6 the list is :"<<endl;
    for(int i=0; i<unsortedarray.LengthIs(); i++)
    {
        unsortedarray.GetNextItem(item);
        cout << item;
    }
    return 0;
}

