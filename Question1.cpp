#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node* next;
};

Node* newNode(int data)
{
    Node* newnode = new Node();
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void push(Node** head_ref, int new_data)
{

    Node* newnode = newNode(new_data);

    newnode->next = (*head_ref);

    (*head_ref) = newnode;
}

Node* addlist(Node* first, Node* second)
{

    Node* res = NULL;
    Node *temp, *prev = NULL;
    int carry = 0, sum;

    while (first != NULL || second != NULL)
    {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);

        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = newNode(sum);

        if (res == NULL)
            res = temp;
        else
            prev->next = temp;

        prev = temp;

        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }

    if (carry > 0)
        temp->next = newNode(carry);

    return res;
}

void printList(Node* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main(void)
{
    Node* res = NULL;
    Node* first = NULL;
    Node* second = NULL;

    push(&first, 1);
    push(&first, 5);
    push(&first, 6);
    push(&first, 7);
    push(&first, 1);
    printf("List A: ");
    printList(first);

    push(&second, 2);
    push(&second, 5);
    push(&second, 6);
    push(&second, 7);
    push(&second, 2);
    cout << "List B: ";
    printList(second);

    res = addlist(first, second);
    cout << "List C is:  ";
    printList(res);

    return 0;
}

