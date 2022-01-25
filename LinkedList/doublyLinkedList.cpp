#include <iostream>

using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node * intializeDoublyLinkedList(struct Node *f, int A[], int n)
{
    int i;
    struct Node *t;
    f->prev=f->next = NULL;
    f->data=A[0];
    t=f;
    for(i=1;i<n;i++)
    {
        struct Node *n=new Node;
        n->data=A[i];
        n->next=NULL;
        n->prev=t;
        t->next=n;
        t=n;
    }

    return f;
}

void displayList(struct Node* f)
{
    while(f)
    {
        cout<<f->data<<" ";
        f=f->next;
    }
    cout<<endl;
}

int length(struct Node* f)
{
    int count=0;
    while(f)
    {
        count++;
        f=f->next;
    }
    return count;
}
int main()
{
    struct Node *first = new Node;
    int A[6]={1,3,5,7,9,11};
    first=intializeDoublyLinkedList(first,A,6);
    cout<<length(first)<<endl;
    displayList(first);

    return 0;
}