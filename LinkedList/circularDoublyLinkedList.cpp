#include <iostream>

using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void createList(int A[], int n)
{
    int i;
    first->data=A[0];
    first->next=NULL;
    struct Node *t=first;
    for(i=1;i<n;i++)
    {
        struct Node *newNode = new Node;
        newNode->data=A[i];
        newNode->prev=t;
        newNode->next=NULL;
        t=newNode;
    }
    t->next=first;
    //first->prev=??
}

int main()
{
    int A[5]={3,5,7,9,11};
    createList(A,5);
    //display(first);

    return 0;
}