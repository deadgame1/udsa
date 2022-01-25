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

int main()
{
    struct Node *first=new Node;
    first->data=-1;//first node is unitialized

    int A[6]={1,3,5,7,9,11};
    //first=intializeDoublyLinkedList(first,A,6);
    //cout<<length(first)<<endl;

    insert(first,0,5);
    insert(first,1,15);
    insert(first,2,25);
    cout<<length(first)<<endl;
    displayList(first);

    return 0;
}