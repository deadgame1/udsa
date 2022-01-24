#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node *globalList = NULL;
void createCircularList(int *A, int n)
{
    int i;
    struct Node *tail = NULL;
    globalList = new Node;

    globalList->data = A[0];
    globalList->next = globalList;
    tail=globalList;

    for(i=1;i<n;i++)
    {
        struct Node *p = new Node;
        p->data = A[i];
        p->next = tail->next;
        tail->next = p;
        tail = p;
    }
}

void displayCircularList(struct Node *head)
{
    struct Node *p = head;
    do
    {
        cout<<p->data<<" ";
        p = p->next;
    } while (p != head);
    cout<<endl;
}


void displayCircularListUsingRecursion(struct Node *p)
{
    static int flag = 0;
    if(p != globalList || flag == 0){
        flag = 1;
        cout<<p->data<<" ";
        displayCircularListUsingRecursion(p->next);
    }
    flag = 0;
}

int main()
{
    int A[5] = {3,5,7,9,11};
    createCircularList(A,5);
    displayCircularListUsingRecursion(globalList);
    cout<<endl;

    return 0;
}