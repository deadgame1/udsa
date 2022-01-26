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
    while(p!=head || flag==0)
    {
        flag++;
        count++;
        p=p->next;
    }

    return count;
}


int main()
{
    int A[5]={3,5,7,9,11};
    createList(A,5);
    display(first);
    cout<<count(first)<<endl;
    return 0;
}