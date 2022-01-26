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
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    struct Node *t=first;
    for(i=1;i<n;i++)
    {
        struct Node *n = new Node;
        n->data=A[i];
        n->prev=t;
        n->next=NULL;
        t->next=n;
        t=n;
    }
    first->prev=t;
    t->next=first;
}

void display(struct Node* head)
{
    struct Node* p=head;
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    } while (p!=head);
    cout<<endl;
}

int count(struct Node* head)
{
    int count=0;
    struct Node *p=head;
    int flag=0;
    while((p!=head || flag==0) && p)
    {
        flag++;
        count++;
        p=p->next;
    }

    return count;
}

/**
 * @brief insert fn for circular doubly linked list
 * please note that in contrast to doubly linked list
 * doesnt matter where you insert 4 links are modified.
 * whereas in doubly linked list inserting at position 0 only resulted in 3 links being modified.
 * 
 * @param head 
 * @param pos 
 * @param x 
 */
void insert(struct Node* head, int pos, int x)
{
    int i;
    struct Node *p=head;
    if(pos < 0 || pos > count(head))
        return;
    struct Node* t=new Node;
    t->data=x;
    if(pos==0)
    {
        t->prev=head->prev;
        head->prev->next=t;
        t->next=head;
        head->prev=t;
        first=t; //head=t is wrong doesnt modify the actual header so directly have to use global pointer
    }
    else
    {
        for(i=0;i<pos-1;i++)
            p=p->next;
        t->next=p->next;
        t->prev=p;
        p->next->prev=t;
        p->next=t;
    }
}

int main()
{
    int A[5]={3,5,7,9,11};
    createList(A,5);
    display(first); 
    insert(first,5,14);
    display(first);
    //cout<<count(first)<<endl;
    return 0;
}