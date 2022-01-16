#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};
struct Node *first=NULL; //global pointer
void create(int A[],int n)
{
    int i;
    struct Node *last;
    struct Node *newNode;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last=first;
    for(i=1;i<n;i++)
    {
      newNode = new Node;
      newNode->data = A[i];
      newNode->next = NULL;
      last->next = newNode;
      last=newNode;  
    }
}
void display(struct Node *p)
{
    while(p)
    {
        cout<<p->data<<endl;
        p = p->next;
    }
}
int main()
{
    int A[] = {3,5,7,9,11,13};
    create(A,6);
    display(first);

    return 0;
}
