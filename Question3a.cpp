#include <iostream>
using namespace std;

struct Node {
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
    while (root != NULL) {
        cout << root->data << " ";
        root = root->next;
    }
}

Node *arrayToList(int arr[], int n)
{
    Node *root = NULL;
    for (int i = n-1; i >= 0 ; i--)
        insert(&root, arr[i]);
    return root;
}

int main()
{
    int arr[] = {7,8,9,2,4,5,7,3,8,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = arrayToList(arr, n);
    display(root);
    return 0;
}
