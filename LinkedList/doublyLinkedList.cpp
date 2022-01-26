#include <iostream>

using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

struct Node * intializeDoublyLinkedList(struct Node *f, int A[], int n)
{
    int i;
    struct Node *t;
    first=new Node;
    first->prev=first->next = NULL;
    first->data=A[0];
    t=first;
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

void insert(struct Node* f, int position, int value)
{
    int i;
    struct Node *t=new Node;

    struct Node *p=f;
    if(position < 0 || position > length(f))
        return;

    if(position==0)
    {
        if(f->data==-1)
        {
            f->data=value;
            f->next=f->prev=NULL;
        }
        else
        {
            t->data=value;
            t->next=f;
            t->prev=NULL;
            f->prev=t;
            f=t;
        }
    }
    else
    {
        for(i=0;i<position-1;i++)
            p=p->next;
        t->data=value;
        t->prev=p;
        t->next=p->next;
        if(p->next)
            p->next->prev=t;
        p->next=t;
    }
}

int deleteNode(struct Node* p, int position)
{
    int x=-1;
    if(position<1 || position>length(p))
        return x;
    if(position==1)
    {
        x=first->data;
        first=first->next;
        if(first)
            first->prev=NULL;
        delete p;
    }
    else
    {
        for(int i=0;i<position-1;i++)
            p=p->next;
        x=p->data;
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        delete p;
    }

    return x;
}
int main()
{
    int A[6]={1,3,5,7,9,11};
    intializeDoublyLinkedList(first,A,6);
    displayList(first);
    cout<<length(first)<<endl;

    deleteNode(first,1);
    displayList(first);
    // insert(first,0,5);
    // insert(first,1,15);
    // insert(first,2,25);
    // cout<<length(first)<<endl;
    // displayList(first);

    return 0;
}