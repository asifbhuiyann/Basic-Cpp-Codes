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

void Intersection(int A[], int B[], int a, int b)
{
    int i = 0, j = 0;
    cout << "Intersection of Array A and B is : "<<endl;
    while (i<a && j<b)
    {
        if (A[i] < B[j])
            i++;
        else if (B[j] < A[i])
            j++;
        else
        {
            cout <<B[j] << " ";
            i++;
            j++;
        }
    }
}
int main()
{
    int A[] = { 1, 2, 4, 5, 6 };
    int B[] = { 2, 3, 5, 7 };

    int a = sizeof(A) / sizeof(A[0]);
    int b = sizeof(B) / sizeof(B[0]);

    Intersection(A, B, a, b);

    return 0;
}
