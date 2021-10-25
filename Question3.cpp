#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

};

void insert(Node** root, int item)
{
    Node* demo = new Node;
    demo->data = item;
    demo->next = *root;
    *root = demo;
}

void display(Node* root)
{
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->next;
    }
}

void eobin(Node* root)
{
    while (root != NULL)
    {
        if(root->data%2!=0)root->data=0;
        else root->data=1;
        root = root->next;
    }
}
long long bintodec (Node* root)
{
    long long dec =0;
    int p =9;
    while (root != NULL)
    {
        dec+=(root->data)*pow(2,p);
        p--;
        root = root->next;
    }
    return dec;
}

Node *arrayToList(int arr[], int n)
{
    Node *root = NULL;
    for (int i = n-1; i >= 0 ; i--)
    {
        insert(&root, arr[i]);
    }
    return root;
}

int main()
{
    int arr[] = {7,8,9,2,4,5,7,3,8,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = arrayToList(arr, n);
    display(root);
    cout<<endl;
    eobin(root);
    display(root);
    cout<<endl;
    cout<<bintodec(root)<<endl;

    return 0;
}
